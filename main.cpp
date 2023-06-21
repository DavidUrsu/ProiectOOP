#include "Headers/rlutil/rlutil.h"

//Clase
#include "Headers/Harta.h"
#include "Headers/Firma.h"
#include "Headers/Tren.h"
#include "Headers/ExceptieJoc.h"
#include "Headers/FactoryFabrici.h"
#include "Headers/BuilderFabrica.h"

#include<string>

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
    cout << "K - Vizualizare configuratie locomotiva" << endl;
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
    // Ultima data cand au fost rulate functiile periodice
    time_t lastUpdate = long(time(nullptr));
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
            char fabrica1aux[200], fabrica2aux[200];
            cout << "Prima fabrica: ";
            //citeste tot input-ul pana la enter
            cin.get(fabrica1aux, 200);
            cin.ignore();
            fabrica1 = fabrica1aux;

            //citeste tot input-ul pana la enter
            cout << "A doua fabrica: ";
            cin.get(fabrica2aux, 200);
            cin.ignore();
            fabrica2 = fabrica2aux;
            // Se construieste calea ferata si se verifica daca s-a efectuat cu succes
            if(hartaJoc->construireCaleFerata(fabrica1, fabrica2) == 0)
                // In cazul in care s-a reusit constructia, se face refresh la interfata
                updateInterfata(myCompany, hartaJoc);
            else
                // In caz contrar se afiseaza din nou comenzile
                afisareComenzi();
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
            string selectLocomotivaString;
            cin >> selectLocomotivaString;

            int selectLocomotiva;
            // Se verifica input-ul
            try{
                // se incearca sa se foloseasca functia stoi, iar in cazul intrarii unui string se arunca o exceptie
                selectLocomotiva = stoi(selectLocomotivaString);
                // Se verifica daca indicele este valid
                if(selectLocomotiva < 1 || selectLocomotiva > int(flota.size()))
                    throw ExceptieLocomotiva();
            } catch(ExceptieLocomotiva& error){
                cout << error.what() << endl;
                afisareComenzi();
                continue;
            } catch (...){
                cout << "Valoarea introdusa nu este un numar!" << endl;
                afisareComenzi();
                continue;
            }

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
                    string auxString;
                    cin >> auxString;
                    // Se verifica input-ul
                    int aux;

                    try {
                        aux = stoi(auxString);
                    } catch (...){
                        cout << "Valoarea introdusa nu este un numar!" << endl;
                        break;
                    }

                    delimitareSectiune("Tipul de vagoane");
                    cout << "1 - Vagoane de lichide (petrol)" << endl;
                    cout << "2 - Vagoane de calatori" << endl;
                    cout << "3 - Vagoane de marfa (jucarii, mobila)" << endl;
                    cout << "4 - Vagoane de lemne " << endl;
                    while(true) {
                        key = rlutil::getkey(); // apel blocant; apelează kbhit și getch
                        if(key == '1' || key == '2' || key == '3' || key == '4')
                            break;
                    }
                    delimitareSectiune("Logs");
                    flota[selectLocomotiva - 1]->cuplareVagone(aux, myCompany, selectLocomotiva - 1, int(key) - int('0'));
                    break;
                }
                if (key == 'v') {
                    // Vindere vagoane
                    cout << "Numarul de vagoane pe care doresti sa-l vinzi: ";
                    string auxString;
                    cin >> auxString;
                    // Se verifica input-ul
                    int aux;

                    try {
                        aux = stoi(auxString);
                    } catch (...){
                        cout << "Valoarea introdusa nu este un numar!" << endl;
                        break;
                    }

                    delimitareSectiune("Logs");
                    flota[selectLocomotiva - 1]->decuplareVagone(aux, myCompany, selectLocomotiva - 1);
                    break;
                }
            }
            afisareComenzi();
            delimitareSectiune("Logs");
        }
        if (key == 'k'){
            // Refresh interfata, ramane doar harta si lista de fabrici
            updateInterfata(myCompany, hartaJoc, 1);

            // Se obtine vectorul ce contine adresele tuturor locomotivelor
            vector<Tren *> flota = myCompany->getFlota();
            // Se afiseaza detaliile tuturor locomotivelor
            for (unsigned int i = 0; i < flota.size(); i++)
                cout << i + 1 << ". " << *flota[i] << endl;

            cout << "Introdu indicele locomotivei pe care doresti sa o vizualizezi: ";
            string selectLocomotivaString;
            cin >> selectLocomotivaString;

            int selectLocomotiva;
            // Se verifica input-ul
            try{
                // se incearca sa se foloseasca functia stoi, iar in cazul intrarii unui string se arunca o exceptie
                selectLocomotiva = stoi(selectLocomotivaString);
                // Se verifica daca indicele este valid
                if(selectLocomotiva < 1 || selectLocomotiva > int(flota.size()))
                    throw ExceptieLocomotiva();
            } catch(ExceptieLocomotiva& error){
                cout << error.what() << endl;
                afisareComenzi();
                continue;
            } catch (...){
                cout << "Valoarea introdusa nu este un numar!" << endl;
                afisareComenzi();
                continue;
            }

            flota[selectLocomotiva - 1]->afisareDetaliiVagoane();

            afisareComenzi();
            delimitareSectiune("Logs");
        }

        // Functii periodice
        // Timpul de cand a inceput jocul in secunde
        time_t timpScursDeLaUltimulUpdate = time(nullptr) - lastUpdate;

        if (timpScursDeLaUltimulUpdate >= 10){
            // Se executa functiile periodice de atatea ori de cate intervale au trecut
            for(int i=1; i<=timpScursDeLaUltimulUpdate/10; i++){
                hartaJoc->produceFabrici();
            }
            lastUpdate = time(nullptr);
        }
    }
}

int main() {
    rlutil::setConsoleTitle("Train Mania");
    rlutil::saveDefaultColor();
    rlutil::setColor(rlutil::WHITE);

    Firma myCompany("Deivid Transportation");
    Harta hartaJoc;

    //adaugare locomotive
    Tren *tren1 = new Tren("Phoenix", 15);
    myCompany.adaugareLocomotiva(tren1);

    Tren *tren2 = new Tren("Poseidon", 20);
    myCompany.adaugareLocomotiva(tren2);

    auto *FF = new FactoryFabrici();

    //pointer creare si adaugare fabrica de cherestea
    hartaJoc.actualizareHarta(FF->createFabricaDeCherestea());
    hartaJoc.actualizareHarta(FF->createFabricaDeCherestea());

    //creare fabrica de mobila
    hartaJoc.actualizareHarta(FF->createFabricaDeMobila());


    auto *BF = new BuilderFabrica();
    //creare fabrica de jucarii prin builder
    hartaJoc.actualizareHarta(BF->setDenumire("Fabrica de jucarii")->setMaterialProdus("Jucarii")->setMaterialCerut("Plastic")->setStocMaterialNecesar(200)->build());
    //creare fabrica de plastic prin builder
    hartaJoc.actualizareHarta(BF->setDenumire("Fabrica de plastic")->setMaterialProdus("Plastic")->setMaterialCerut("Petrol")->setStocMaterialNecesar(200)->build());
    //creare fabrica de petrol prin builder
    hartaJoc.actualizareHarta(BF->setDenumire("Fabrica de petrol")->setMaterialProdus("Petrol")->build());

    //se verifica daca pozițiile fabricilor sunt unice
    while(!hartaJoc.verificarePozitiiFabrici()){
        hartaJoc.regenerareCoordonateFabrici();
    }

    updateInterfata(&myCompany, &hartaJoc);
    asteptareInput(&myCompany, &hartaJoc);

    delete FF;
    delete BF;

    return 0;
}

// o functie sablon: functia de afisare a hartii
// o clasa sablon: clasa de vagoane