//
// Created by David on 4/4/2023.
//

#pragma once
#ifndef OOP_HARTA_H
#define OOP_HARTA_H

#include<iostream>
#include<vector>
#include<ctime>

#include "CaleFerata.h"
#include "Fabrica.h"

class Harta {
    // definesc caracterele pentru harta
    char caracterBackgrond = '.'; // ▒ char(176) - daca reusesc sa fac unicode-ul sa mearga

    // Harta este de dimensiunea 20 pe 100
    // un vector bidimensional de caractere ce reprezinta harta
    vector<vector<char>> vectorHarta;

    // Vector prin care se memoreaza toate fabricile de pe harta
    vector<Fabrica *> listaFabrici;
    // Vector prin care se memoreaza adresele tuturor cailor ferate de pe harta
    vector<CaleFerata *> listaCaleFerata;

public:
    // constructor harta
    Harta();

    // Deconstructor harta
    ~Harta();

    // Functie prin care afisez harta
    void afisareHarta();

    // Actualizez simbolul unei entitati pe harta si adaug entitatea in vectorul ei specific
    // Suprascriere functie
    [[maybe_unused]] void actualizareHarta(Fabrica *myFabrica);

    // Suprascriere functie
    [[maybe_unused]] void actualizareHarta(CaleFerata *myCaleFerata);

    // Functie template prin care se plaseaza semnul unui obiect pe harta
    template<typename T> T adaugareSimbolHarta(T x);

    // Verificare daca toate fabricile sunt pe axe diferite ale vectorului vectorHarta
    bool verificarePozitiiFabrici();

    // Functie prin care se regenereaza coordonatele fabricilor
    void regenerareCoordonateFabrici();

    // Functie prin care se afiseaza lista tuturor fabricilor de pe harta
    void afisareListaFabrici();

    // Functia ce construieste calea ferata de la o fabrica la alta
    int construireCaleFerata(const string &fabrica1, const string &fabrica2);

    // Functie periodica ce initiaza functia de producere a fabricilor
    [[maybe_unused]] void produceFabrici();

    // operator pentru afisare
    friend ostream &operator<<(ostream &out, const Harta &myHarta);

    // Suprascriere operator =
    Harta &operator=(const Harta &myHarta);

    // Suprascriere copy constructor
    [[maybe_unused]] Harta(const Harta &myHarta);
};

#endif //OOP_HARTA_H
