//
// Created by David on 4/4/2023.
//

#pragma once
#ifndef OOP_FABRICA_H
#define OOP_FABRICA_H

#include "iostream"
#include "string"

using namespace std;

class Fabrica {
    string materialProdus, materialCerut, denumire;
    int coordonateX, coordonateY;
    char simbolHarta = '#'; // ■ char(254)

public:
    // Constructor al fabricii
    explicit Fabrica(string materialProdus_ = "nedefinit", string materialCerut_ = "nedefinit",
                     string denumire_ = "nedefinit");

    // Deconstructor al fabricii
    ~Fabrica();

    // Getter coordonate X ale fabricii
    [[nodiscard]] int getX() const;

    // Getter coordonate Y ale fabricii
    [[nodiscard]] int getY() const;

    // Getter simbol pentru harta al fabricii
    [[nodiscard]] char getSimbol() const;

    // Getter denumire a fabricii
    string getDenumire();

    // Getter material oferit
    string getMaterialOferit();

    // Getter material cerut
    string getMaterialCerut();

    // Regenerare coordonate ale fabricii
    void regenerareCoordonate();

    // operator pentru afisare
    friend ostream &operator<<(ostream &out, const Fabrica &myFabrica);
};


#endif //OOP_FABRICA_H
