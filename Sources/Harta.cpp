//
// Created by David on 4/4/2023.
//

#include "../Headers/Harta.h"

// constructor harta
Harta::Harta() {
    for (int i = 0; i < 20; i++) {
        vector<char> linie;
        // Adaug caracterul standard al hartii
        linie.reserve(100);
        for (int j = 0; j < 100; j++) {
            linie.push_back(caracterBackgrond);
        }
        vectorHarta.push_back(linie);
    }
}

// Functie prin care afisez harta
[[maybe_unused]] void Harta::afisareHarta() {
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
    vectorHarta[myFabrica->getY()][myFabrica->getX()] = myFabrica->getSimbol();
    listaFabrici.push_back(myFabrica);
}

void Harta::actualizareHarta(CaleFerata *myCaleFerata) {
    vectorHarta[myCaleFerata->getY()][myCaleFerata->getX()] = myCaleFerata->getSimbol();
}

// Functie prin care se afiseaza lista tuturor fabricilor de pe harta
[[maybe_unused]] void Harta::afisareListaFabrici() {

    for (auto &i: listaFabrici) {
        cout << i->getDenumire() << " || Cere: " << i->getMaterialCerut() << " || Ofera: " << i->getMaterialOferit()
             << " || X: " << i->getX() << " Y: " << i->getY() << endl;
    }
}

[[maybe_unused]] void Harta::construireCaleFerata(const string &fabrica1, const string &fabrica2) {
    // Gasesc coordonatele fabricilor intre care vreau sa construiesc calea ferata
    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    for (unsigned int i = 0; i < size(listaFabrici); i++) {
        if (listaFabrici[i]->getDenumire() == fabrica1) {
            x1 = listaFabrici[i]->getX();
            y1 = listaFabrici[i]->getY();
        }
        if (listaFabrici[i]->getDenumire() == fabrica2) {
            x2 = listaFabrici[i]->getX();
            y2 = listaFabrici[i]->getY();
        }
    }

    // Verific daca fabricile exista
    if (x1 != -1 || x2 != -1 || y1 != -1 || y2 != -1) {
        // verific care fabrica se situaza cea mai in stanga, apoi in primul set de coordonate ii va apartine celei mai din stanga (x1,y1)
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        // plec de la cel mai mic X, spre cel mai mare X
        for (int i = x1 + 1; i < x2; i++)
            listaCaleFerata.push_back(new CaleFerata(i, y1, '-')); // ═ char(205)

        // verific in ce directie trebuie continuata calea ferata, in sus sau in jos pe axa Y
        if (y1 < y2) {
            // adaug coltul
            listaCaleFerata.push_back(new CaleFerata(x2, y1, '/')); // ╝ char(188)
            for (int j = y1 + 1; j < y2; j++)
                listaCaleFerata.push_back(new CaleFerata(x2, j, '|')); // ║ char(186)
        } else {
            // adaug coltul
            listaCaleFerata.push_back(new CaleFerata(x2, y1, '\\')); // ╗ char(187)
            for (int j = y1 - 1; j > y2; j--)
                listaCaleFerata.push_back(new CaleFerata(x2, j, '|')); // ║ char(186)
        }

        for (CaleFerata *i: listaCaleFerata) {
            actualizareHarta(i);
        }
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
