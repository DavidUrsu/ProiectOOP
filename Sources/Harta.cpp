//
// Created by David on 4/4/2023.
//

#include "../Headers/Harta.h"
#include "../Headers/FabricaMaterialPrim.h"
#include "../Headers/FabricaPrelucrare.h"

// constructor harta
Harta::Harta() : caracterBackgrond{'.'}, vectorHarta(20, vector<char>(100, caracterBackgrond)){}

Harta::~Harta() {
    for(auto i : listaCaleFerata)
        delete(i);

    for(auto i : listaFabrici)
        delete(i);
}

// Functie prin care afisez harta
void Harta::afisareHarta() {
    for (int i = int(vectorHarta.size())-1; i >= 0; i--) {
        for (int j = 0; j < int(vectorHarta[0].size()); j++) {
            cout << vectorHarta[i][j];
        }
        cout << endl;
    }
}

// Actualizez simbolul unei entitati pe harta si adaug entitatea in vectorul ei specific
// Suprascriere functie
[[maybe_unused]] void Harta::actualizareHarta(Fabrica *myFabrica) {
    // Se adauga fabrica in vectorul ce le tine evidenta
    listaFabrici.push_back(myFabrica);

    adaugareSimbolHarta(myFabrica);
}

// Suprascriere functie
[[maybe_unused]] void Harta::actualizareHarta(CaleFerata *myCaleFerata) {
    // Se adauga calea ferata in vectorul ce le tine evidenta
    listaCaleFerata.push_back(myCaleFerata);

    adaugareSimbolHarta(myCaleFerata);
}

// Functie template prin care se plaseaza semnul unui obiect pe harta
template<typename T> T Harta::adaugareSimbolHarta(T x){
    // se adauga obiectul pe harta
    vectorHarta[x->getY()][x->getX()] = x->getSimbol();
    return x;
}

// Functie prin care se afiseaza lista tuturor fabricilor de pe harta
void Harta::afisareListaFabrici() {
    // Se parcurge vectorul de fabrici
    for (auto &i: listaFabrici) {
        cout << i->getDenumire() << " || Cere: " << i->getMaterialCerut() << " | Stoc: " << i->getStocMaterialNecesar() << " || Ofera: " << i->getMaterialOferit() << " | Stoc: " << i->getStocProdusFinal() << " || X: " << i->getX() << " Y: " << i->getY() << endl;
    }
}

// Functia ce construieste calea ferata de la o fabrica la alta
// Returneaza
// - 0 daca reuseste sa construiasca calea ferata
// - 1 daca nu reuseste sa construiasca calea ferata
int Harta::construireCaleFerata(const string &fabrica1, const string &fabrica2) {
    // Se verifica daca fabricile sunt distincte
    if (fabrica1 == fabrica2) return 0;
    // Se initializeaza coordonatele cu valori negative pentru a facilita gasirea erorilor
    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    // Se gasesc coordonatele fabricilor intre care se construieste calea ferata
    for (unsigned int i = 0; i < size(listaFabrici); i++) {
        // Se verifica denumirea fabricii cu denumirea introdusa de la tastatura
        if (listaFabrici[i]->getDenumire() == fabrica1) {
            // Se atribuie valorile
            x1 = listaFabrici[i]->getX();
            y1 = listaFabrici[i]->getY();
        }
        // Se verifica denumirea fabricii cu denumirea introdusa de la tastatura
        if (listaFabrici[i]->getDenumire() == fabrica2) {
            // Se atribuie valorile
            x2 = listaFabrici[i]->getX();
            y2 = listaFabrici[i]->getY();
        }
    }

    // Se verifica daca fabricile exista
    if (x1 != -1 && x2 != -1 && y1 != -1 && y2 != -1) {
        // Se verifica care fabrica se situaza cea mai in stanga, apoi primul set de coordonate ii va apartine celei mai din stanga fabrici (x1,y1)
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        // Se itereaza de la cel mai mic X, spre cel mai mare X
        for (int i = x1 + 1; i < x2; i++)
            // Se creaza o noua instanta pe drum la coordonatele aferente
            actualizareHarta(new CaleFerata(i, y1, '-')); // ═ char(205)

        // Se verifica in ce directie trebuie continuata calea ferata, in sus sau in jos pe axa Y
        if (y1 < y2) {
            // Se adauga coltul
            actualizareHarta(new CaleFerata(x2, y1, '/')); // ╝ char(188)
            for (int j = y1 + 1; j < y2; j++)
                // Se creaza o noua instanta pe drum la coordonatele aferente
                actualizareHarta(new CaleFerata(x2, j, '|')); // ║ char(186)
        } else {
            // Se adauga coltul
            actualizareHarta(new CaleFerata(x2, y1, '\\')); // ╗ char(187)
            for (int j = y1 - 1; j > y2; j--)
                // Se creaza o noua instanta pe drum la coordonatele aferente
                actualizareHarta(new CaleFerata(x2, j, '|')); // ║ char(186)
        }

        return 0;
    } else {
        // Daca o fabrica nu exista, se verifica care nu exista
        if (x1 == -1 && y1 == -1)
            cout << "Fabrica " << fabrica1 << " nu exista!\n";
        else {
            cout << "Fabrica " << fabrica2 << " nu exista!\n";
        }
        return 1;
    }
}

// operator pentru afisare
ostream &operator<<(ostream &out, const Harta &myHarta) {
    for (int i = 19; i >= 0; i--) {
        for (int j = 0; j < 100; j++) {
            out << myHarta.vectorHarta[i][j];
        }
        out << endl;
    }
    return out;
}

// Functie periodica ce initiaza functia de producere a fabricilor
void Harta::produceFabrici() {
    for(Fabrica *i : listaFabrici){
        //folosire dynamic_cast pentru a verifica daca obiectul este FabricaPrelucrare sau FabricaMaterialPrim, apoi apeleaza functia de producere virtuala specifica fiecarei clase

        if(dynamic_cast<FabricaPrelucrare*>(i))
            dynamic_cast<FabricaPrelucrare*>(i)->produce();

        if(dynamic_cast<FabricaMaterialPrim*>(i))
            dynamic_cast<FabricaMaterialPrim*>(i)->produce();
    }
}

Harta &Harta::operator=(const Harta &myHarta) {
    if (this != &myHarta) {
        vectorHarta = myHarta.vectorHarta;
        // pentru fiecare fabrica se creeaza o noua fabrica cu aceleasi caracteristici
        for (auto &i: myHarta.listaFabrici) {
            //verificare tip fabrica cu dynamic_cast
            if (dynamic_cast<FabricaPrelucrare *>(i))
                actualizareHarta(new FabricaPrelucrare(*dynamic_cast<FabricaPrelucrare *>(i)));

            if (dynamic_cast<FabricaMaterialPrim *>(i))
                actualizareHarta(new FabricaMaterialPrim(*dynamic_cast<FabricaMaterialPrim *>(i)));
        }

        // pentru fiecare cale ferata se creeaza o noua cale ferata cu aceleasi caracteristici
        for (auto &i: myHarta.listaCaleFerata) {
            actualizareHarta(new CaleFerata(*i));
        }
    }
    return *this;
}

[[maybe_unused]] Harta::Harta(const Harta &myHarta) : vectorHarta(myHarta.vectorHarta) {
    // pentru fiecare fabrica se creeaza o noua fabrica cu aceleasi caracteristici
    for (auto &i: myHarta.listaFabrici) {
        //verificare tip fabrica cu dynamic_cast
        if (dynamic_cast<FabricaPrelucrare *>(i))
            actualizareHarta(new FabricaPrelucrare(*dynamic_cast<FabricaPrelucrare *>(i)));

        if (dynamic_cast<FabricaMaterialPrim *>(i))
            actualizareHarta(new FabricaMaterialPrim(*dynamic_cast<FabricaMaterialPrim *>(i)));
    }

    // pentru fiecare cale ferata se creeaza o noua cale ferata cu aceleasi caracteristici
    for (auto &i: myHarta.listaCaleFerata) {
        actualizareHarta(new CaleFerata(*i));
    }
}

bool Harta::verificarePozitiiFabrici() {
    // se itereaza prin lista de fabrici
    for (int i = 0 ; i < int(listaFabrici.size()) - 1; i++)
        // se verifica toate fabricile care urmeaza in vector
        for (int j = i + 1; j < int(listaFabrici.size()); j++)
            // se verifica daca exista fabrici cu aceleasi coordonate
            if (listaFabrici[i]->getX() == listaFabrici[j]->getX() || listaFabrici[i]->getY() == listaFabrici[j]->getY()) {
                cout << "Fabricile " << listaFabrici[i]->getDenumire() << " si " << listaFabrici[j]->getDenumire()
                     << " au aceleasi coordonate pe o axa!\n";
                return false;
            }

    return true;
}

void Harta::regenerareCoordonateFabrici() {
    // se itereaza prin lista de fabrici
    for (auto &i : listaFabrici) {
        vectorHarta[i->getY()][i->getX()] = '.';
        i->regenerareCoordonate();
        vectorHarta[i->getY()][i->getX()] = i->getSimbol();
        cout << "Fabrica " << i->getDenumire() << " a fost mutata pe coordonatele (" << i->getX() << ", " << i->getY() << ")\n";
    }
}