//
// Created by David on 4/4/2023.
//

#include "../Headers/Harta.h"

// constructor harta
Harta::Harta() : caracterBackgrond{'.'}, vectorHarta(20, vector<char>(100, caracterBackgrond)){}

Harta::~Harta() {
    for(auto i : listaCaleFerata){
        delete(i);
    }
}

// Functie prin care afisez harta
void Harta::afisareHarta() {
    for (int i = 19; i >= 0; i--) {
        for (int j = 0; j < 100; j++) {
            cout << vectorHarta[i][j];
        }
        cout << endl;
    }
}

// Actualizez simbolul unei entitati pe harta si adaug entitatea in vectorul ei specific
// Suprascriere functie
void Harta::actualizareHarta(Fabrica *myFabrica) {
    // Se adauga simbolul fabricii pe harta
    vectorHarta[myFabrica->getY()][myFabrica->getX()] = myFabrica->getSimbol();
    // Se adauga fabrica in vectorul ce le tine evidenta
    listaFabrici.push_back(myFabrica);
}

// Suprascriere functie
void Harta::actualizareHarta(CaleFerata *myCaleFerata) {
    // Se adauga simbolul caii ferate pe harta
    vectorHarta[myCaleFerata->getY()][myCaleFerata->getX()] = myCaleFerata->getSimbol();
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
            listaCaleFerata.push_back(new CaleFerata(i, y1, '-')); // ═ char(205)

        // Se verifica in ce directie trebuie continuata calea ferata, in sus sau in jos pe axa Y
        if (y1 < y2) {
            // Se adauga coltul
            listaCaleFerata.push_back(new CaleFerata(x2, y1, '/')); // ╝ char(188)
            for (int j = y1 + 1; j < y2; j++)
                // Se creaza o noua instanta pe drum la coordonatele aferente
                listaCaleFerata.push_back(new CaleFerata(x2, j, '|')); // ║ char(186)
        } else {
            // Se adauga coltul
            listaCaleFerata.push_back(new CaleFerata(x2, y1, '\\')); // ╗ char(187)
            for (int j = y1 - 1; j > y2; j--)
                // Se creaza o noua instanta pe drum la coordonatele aferente
                listaCaleFerata.push_back(new CaleFerata(x2, j, '|')); // ║ char(186)
        }

        // Se adauga pe harta simbolul cailor ferate
        for (CaleFerata *i: listaCaleFerata) {
            actualizareHarta(i);
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
    for(auto i : listaFabrici){
        i->produce();
    }
}
