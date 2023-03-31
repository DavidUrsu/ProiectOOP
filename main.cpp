#include<iostream>
#include<vector>
#include<cmath>
#include<random>
#include<time.h>
#include<conio.h>
using namespace std;

class Tren;
void delimitareSectiune(string subtitlu);

class caleFerata{
    int coordonateX, coordonateY;
    char simbol;
    private:
        caleFerata(int coordonateX_, int coordonateY_): coordonateX{coordonateX_}, coordonateY{coordonateY_}, simbol{char(206)} {}
};

class Fabrica{
    string materialProdus, materialCerut, denumire;
    int coordonateX, coordonateY;
    char simbolHarta = char(254);

    public:
        // Constructor al fabricii
        Fabrica(string materialProdus_ = "nedefinit", string materialCerut_ = "nedefinit", string denumire_ = "nedefinit"): materialProdus{materialProdus_}, materialCerut{materialCerut_}, denumire{denumire_}, coordonateX{rand()%100}, coordonateY{rand()%20}{
            cout << "S-a creat o fabrica " << denumire << " ce produce " << materialProdus << ", avand nevoie de " << materialCerut << ", la coordonatele " << coordonateX << " " << coordonateY << "." << endl;
        }

        // Getter coordonate X ale fabricii
        int getX(){
            return coordonateX;
        }

        // Getter coordonate Y ale fabricii
        int getY(){
            return coordonateY;
        }

        // Getter simbol pentru harta al fabricii
        char getSimbol(){
            return simbolHarta;
        }

        // Getter denumire a fabricii
        string getDenumire(){
            return denumire;
        }

        // Getter material oferit
        string getMaterialOferit(){
            return materialProdus;
        }

        // Getter material cerut
        string getMaterialCerut(){
            return materialCerut;
        }
};

class Vagon{
    Fabrica *destinatar, *producator;
    int capacitateMaxima, incarcaturaCurenta;
    string denumireMarfa;
    Tren *locomotiva;

    public:
        // Constructor vagon
        Vagon(Fabrica *destinatar_ = nullptr, Fabrica *producator_ = nullptr, int capacitateMaxima_ = 0): capacitateMaxima{capacitateMaxima_}, incarcaturaCurenta{0}, destinatar{destinatar_}, producator{producator_}, denumireMarfa{"-"} {
            cout << "Vagon nou, ce merge de la " << producator << " la " << destinatar << "." << endl; 
        }

        // Constructor de copiere vagon
        Vagon(Vagon &vagonVechi){
            destinatar = vagonVechi.destinatar;
            producator = vagonVechi.producator;
            capacitateMaxima = vagonVechi.capacitateMaxima;
            destinatar = vagonVechi.destinatar;
            incarcaturaCurenta = 0;

            cout << "Vagon nou, ce merge de la " << producator->getDenumire() << " la " << destinatar->getDenumire() << "." << endl;
        }

        // Operator de copiere
        Vagon& operator= (const Vagon& vagonVechi){
            destinatar = vagonVechi.destinatar;
            producator = vagonVechi.producator;
            capacitateMaxima = vagonVechi.capacitateMaxima;
            destinatar = vagonVechi.destinatar;
            incarcaturaCurenta = 0;

            return *this;
        }

        // Functie de golire a pointer-ului catre locomotiva
        void eliberareVagon(){
            locomotiva = nullptr;
        }

        // Functie de atribuire a pointer-ului locomotivei
        void conectareVagon(Tren *locomotiva_){
            locomotiva = locomotiva_;
        }

};

class Tren{
    string model;
    int putereDeTractiune, vagoaneConectate;
    vector<Vagon*> incarcatura;

    public:
        // Constructor Tren
        Tren(string model_, int putereDeTractiune_) :  model{model_}, putereDeTractiune{putereDeTractiune_}{
            cout << "A fost adaugat cu succes trenul " << model << ", ce poate transporta " << putereDeTractiune << " vagoane!\n";
        }

        // Deconstructor tren
        ~Tren(){
            cout << "S-a vandut locomotiva " << model << endl;
            // Trece prin toate vagoanele atribuite acestui tren si le sterge referinta catre acesta
            for(int i=0; i<incarcatura.size(); i++)
                incarcatura[i]->eliberareVagon();
        }

        // Adaugarea referintei a unui vagon la incarcatura trenului
        void cuplareVagon(Vagon myVagon){
            incarcatura.push_back(&myVagon);
        }

        // Scoaterea referintei a unui vagon de la incarcatura trenului
        void decuplareVagon(int index){
            incarcatura.erase(incarcatura.begin()+index-1);
        }
};

class Firma{
    string denumire;
    vector<Tren*> flota;

    public:
        // Constructor firma
        Firma(string denumire_ = "Unnamed Company") : denumire{denumire_}{
            cout << "A fost creata firma " << denumire << endl;
        }

        // Adaug referinta trenului in vectorul de flota
        void adaugareLocomotiva(Tren myTrain){
            flota.push_back(&myTrain);
        }

        //Operatorul de accesare prin index, imi returneaza referinta trenului aflat pe pozitia i 
        Tren* operator[](int i)
        {
            return flota[i];
        }

        // 
        friend ostream & operator<<(ostream &out, const Firma &myCompany){
            out << myCompany.denumire;
            return out;
        }
};

class Harta{
    // Harta este de dimensiunea 20 pe 100
    // un vector bidimensionat de caractere ce reprezinta harta bidimensionala
    vector<vector<char>> vectorHarta;
    // Vector prin care se memoreaza toate fabricile de pe harta
    vector<Fabrica*> listaFabrici;

    public:
        // constructor harta
        Harta(){
            for(int i=0; i<20; i++){
                vector<char> linie;
                // Adaug caracterul standard al hartii
                for(int j=0; j<100; j++){
                    linie.push_back(char(176));
                }
                vectorHarta.push_back(linie);
            }
        }

        // Functie prin care afisez harta
        void afisareHarta(){
            for(int i=0; i<20; i++){
                for(int j=0; j<100; j++){
                    cout << vectorHarta[i][j];
                }
                cout << endl;
            }
        }

        // Actualizez simbolul unei entitati pe harta si adaug entitatea in vectorul ei specific
        // Suprascriere functie 
        void actualizareHarta(Fabrica myFabrica){
            vectorHarta[myFabrica.getY()][myFabrica.getX()] = myFabrica.getSimbol();
            listaFabrici.push_back(&myFabrica);
        }

        // Functie prin care se afiseaza lista tuturor fabricilor de pe harta
        void afisareListaFabrici(){
            // Delimitare sectiune
            delimitareSectiune("Fabrici");

            for(int i=0; i<listaFabrici.size(); i++){
                cout << listaFabrici[i]->getDenumire() << " || Cere: " << listaFabrici[i]->getMaterialCerut() << " || Ofera: " << listaFabrici[i]->getMaterialOferit() << " || X: " << listaFabrici[i]->getX() << " Y: " << listaFabrici[i]->getY()  << endl;
            }
        }
};

void afisareLogo(){
    cout << R"( _______        _         __  __             _       )" << endl;
    cout << R"(|__   __|      (_)       |  \/  |           (_)      )" << endl;
    cout << R"(   | |_ __ __ _ _ _ __   | \  / | __ _ _ __  _  __ _ )" << endl;
    cout << R"(   | | '__/ _` | | '_ \  | |\/| |/ _` | '_ \| |/ _` |)" << endl;
    cout << R"(   | | | | (_| | | | | | | |  | | (_| | | | | | (_| |)" << endl;
    cout << R"(   |_|_|  \__,_|_|_| |_| |_|  |_|\__,_|_| |_|_|\__,_|)" << endl;
}

void delimitareSectiune(string subtitlu){
    for(int i=0; i<10; i++)
        cout << '-';
    cout << subtitlu;
    for(int i=0; i<90-subtitlu.size(); i++)
        cout << '-';
    cout << endl;
}

void afisareComenzi(){
    delimitareSectiune("Comenzi");
    cout << "P - Iesire joc" << endl;
    cout << "U - Update harta si stergere log-uri" << endl;
    cout << "C - Construieste o cale fereta intre doua fabrici" << endl;
}

void updateInterfata(Firma *myCompany, Harta *hartaJoc){
    system("cls");
    afisareLogo();
    cout << "Companie: " << *myCompany << endl;
    hartaJoc->afisareHarta();
    hartaJoc->afisareListaFabrici();
    afisareComenzi();

    // Delimitare sectiune
    delimitareSectiune("Log-uri");
}

int asteptareInput(Firma *myCompany, Harta *hartaJoc){
    int key;
    while(1){
        key = getch();
        switch (key) {
            case 'p':
                system("cls");
                return 0;
                break;
            case 'u':
                updateInterfata(myCompany, hartaJoc);
                break;
            default:
                break;
        }
    }
}

int main(){
    srand(time(0));
    Firma myCompany("Deivid Transportation");
    Harta hartaJoc;

    Tren tren1("Phoenix", 15);
    myCompany.adaugareLocomotiva(tren1);

    Fabrica Lumbermill("Lemn", "-", "Lumbermill");
    Fabrica IKEA("Mobila", "Lemn", "IKEA");

    hartaJoc.actualizareHarta(Lumbermill);
    hartaJoc.actualizareHarta(IKEA);

    Vagon marfa1(&IKEA, &Lumbermill, 10), marfa2;
    marfa2 = marfa1;

    updateInterfata(&myCompany, &hartaJoc);
    asteptareInput(&myCompany, &hartaJoc);

    return 0;
}