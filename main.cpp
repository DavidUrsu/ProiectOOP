#include "Headers/rlutil/rlutil.h"

//g++ main.cpp Sources/CaleFerata.cpp Sources/Fabrica.cpp Sources/Firma.cpp Sources/Harta.cpp Sources/Tren.cpp Sources/Vagon.cpp -o main.exe

//Clase
#include "Headers/Harta.h"
#include "Headers/Firma.h"
#include "Headers/Tren.h"

using namespace std;

void afisareLogo() {
    cout << R"( _______        _         __  __             _       )" << endl;
    cout << R"(|__   __|      (_)       |  \/  |           (_)      )" << endl;
    cout << R"(   | |_ __ __ _ _ _ __   | \  / | __ _ _ __  _  __ _ )" << endl;
    cout << R"(   | | '__/ _` | | '_ \  | |\/| |/ _` | '_ \| |/ _` |)" << endl;
    cout << R"(   | | | | (_| | | | | | | |  | | (_| | | | | | (_| |)" << endl;
    cout << R"(   |_|_|  \__,_|_|_| |_| |_|  |_|\__,_|_| |_|_|\__,_|)" << endl;
}

void delimitareSectiune(const string &subtitlu) {
    for (int i = 0; i < 10; i++)
        cout << '-';
    cout << subtitlu;
    for (unsigned int i = 0; i < 90 - subtitlu.size(); i++)
        cout << '-';
    cout << endl;
}

void afisareComenzi(){
    delimitareSectiune("Comenzi");
    cout << "P - Iesire joc" << endl;
    cout << "U - Update harta si stergere log-uri" << endl;
    cout << "C - Construieste o cale fereta intre doua fabrici" << endl;
    cout << "L - Modifica vagoanele unei locomotive" << endl;
}

void updateInterfata(Firma *myCompany, Harta *hartaJoc, int codAfisare = 0) {
    // clear screen
    // rlutil::cls();
    afisareLogo();

    delimitareSectiune("");

    cout << "Companie: " << *myCompany << endl;
    cout << "Buget disponibil: " << myCompany->getMoney() << '$' << endl;

    delimitareSectiune("");

    hartaJoc->afisareHarta();
    // Delimitare sectiune
    delimitareSectiune("Fabrici");
    hartaJoc->afisareListaFabrici();

    // In functie de codul primit se afiseaza detaliile hartii
    // cod 0 - afiseaza lista comenzi si delimitarea sectiunii de log-uri, default case
    // cod 1 - afiseaza subtitlul pentru locomotive
    if (codAfisare == 0) {
        afisareComenzi();

        // Delimitare sectiune
        delimitareSectiune("Log-uri");
    } else if (codAfisare == 1) {
        delimitareSectiune("Locomotive");
    }
}

int asteptareInput(Firma *myCompany, Harta *hartaJoc) {
    while (true) {
        int key = rlutil::getkey(); // apel blocant; apelează kbhit și getch
        key = tolower(key);

        if (key == 'p') {
            // Se inchide jocul
            rlutil::cls();
            return 0;
        }
        if (key == 'u') {
            updateInterfata(myCompany, hartaJoc);
        }
        if (key == 'c') {
            // Se citeste numele fabricilor intre care se construieste drumul
            string fabrica1, fabrica2;
            cout << "Prima fabrica: ";
            cin >> fabrica1;
            cout << "A doua fabrica: ";
            cin >> fabrica2;
            // Se construieste calea ferata si se verifica daca s-a efectuat cu succes
            if(hartaJoc->construireCaleFerata(fabrica1, fabrica2) == 0)
                // In cazul in care s-a reusit constructia, se face refresh la interfata
                updateInterfata(myCompany, hartaJoc);
        }
        if (key == 'l') {
            // Refresh interfata, ramane doar harta si lista de fabrici
            updateInterfata(myCompany, hartaJoc, 1);

            // Se obtine vectorul ce contine adresele tuturor locomotivelor
            vector<Tren *> flota = myCompany->getFlota();
            // Se afiseaza detaliile tuturor locomotivelor
            for (unsigned int i = 0; i < flota.size(); i++)
                cout << i + 1 << ". " << *flota[i] << endl;

            cout << "Introdu indicele locomotivei pe care doresti sa o modifici: ";
            int selectLocomotiva;
            cin >> selectLocomotiva;

            // Selectarea comenzii de modificat locomotiva
            delimitareSectiune("Comenzi");
            cout << "C - Cumpara vagoane pentru locomotiva - pret 100$/vagon" << endl;
            cout << "V - Vinde vagoanele locomotivei - ramburs: 70$/vagon" << endl;
            while (true) {
                key = rlutil::getkey(); // apel blocant; apelează kbhit și getch
                key = tolower(key);
                if (key == 'c') {
                    // Cumparare vagoane
                    cout << "Numarul de vagoane pe care doresti sa-l cumperi: ";
                    int aux;
                    cin >> aux;
                    delimitareSectiune("Logs");
                    flota[selectLocomotiva - 1]->cuplareVagone(aux, myCompany, selectLocomotiva - 1);
                    break;
                }
                if (key == 'v') {
                    // Vindere vagoane
                    cout << "Numarul de vagoane pe care doresti sa-l vinzi: ";
                    int aux;
                    cin >> aux;
                    delimitareSectiune("Logs");
                    flota[selectLocomotiva - 1]->decuplareVagone(aux, myCompany, selectLocomotiva - 1);
                    break;
                }
            }
            afisareComenzi();
            delimitareSectiune("Logs");
        }
    }
}

int main() {
    rlutil::setConsoleTitle("Train Mania");
    rlutil::saveDefaultColor();
    rlutil::setColor(rlutil::WHITE);

    Firma myCompany("Deivid Transportation");
    Harta hartaJoc;

    Tren tren1("Phoenix", 15);
    myCompany.adaugareLocomotiva(&tren1);
    Tren tren2("Poseidon", 20);
    myCompany.adaugareLocomotiva(&tren2);

    Fabrica Lumbermill("Lemn", "-", "Lumbermill");
    Fabrica IKEA("Mobila", "Lemn", "IKEA");
    while (IKEA.getX() == Lumbermill.getX() || IKEA.getY() == Lumbermill.getY()) {
        IKEA.regenerareCoordonate();
    }

    hartaJoc.actualizareHarta(&Lumbermill);
    hartaJoc.actualizareHarta(&IKEA);

    updateInterfata(&myCompany, &hartaJoc);
    asteptareInput(&myCompany, &hartaJoc);

    return 0;
}
