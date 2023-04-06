//
// Created by David on 4/4/2023.
//

#pragma once
#ifndef OOP_HARTA_H
#define OOP_HARTA_H

#include "iostream"
#include "vector"

#include "CaleFerata.h"
#include "Fabrica.h"

class Harta {
    // definesc caracterele pentru harta
    char caracterBackgrond = '.'; // ▒ char(176) - daca reusesc sa fac unicode-ul sa mearga

    // Harta este de dimensiunea 20 pe 100
    // un vector bidimensionat de caractere ce reprezinta harta bidimensionala
    vector<vector<char>> vectorHarta;

    // Vector prin care se memoreaza toate fabricile de pe harta
    vector<Fabrica *> listaFabrici;
    // Vector prin care se memoreaza adresele tuturor cailor ferate de pe harta
    vector<CaleFerata *> listaCaleFerata;

public:
    // constructor harta
    Harta();

    // Functie prin care afisez harta
    void afisareHarta();

    // Actualizez simbolul unei entitati pe harta si adaug entitatea in vectorul ei specific
    // Suprascriere functie
    void actualizareHarta(Fabrica *myFabrica);

    void actualizareHarta(CaleFerata *myCaleFerata);

    // Functie prin care se afiseaza lista tuturor fabricilor de pe harta
    void afisareListaFabrici();

    void construireCaleFerata(const string &fabrica1, const string &fabrica2);

    // operator pentru afisare
    friend ostream &operator<<(ostream &out, const Harta &myHarta);
};

#endif //OOP_HARTA_H
