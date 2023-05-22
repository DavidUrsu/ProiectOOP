//
// Created by David on 4/4/2023.
//

#pragma once
#ifndef OOP_CALEFERATA_H
#define OOP_CALEFERATA_H

#include "iostream"

using namespace std;

class CaleFerata {
    int coordonateX, coordonateY;
    char simbolHarta;
public:
    // Constructor CaleFerata
    CaleFerata(int coordonateX_, int coordonateY_, char simbolHarta_ = '+'); //╬ char(206)

    // Deconstructor CaleFerata
    ~CaleFerata();

    // Getter coordonate X ale caii ferate
    [[nodiscard]] int getX() const;

    // Getter coordonate Y ale caii ferate
    [[nodiscard]] int getY() const;

    // Getter simbol pentru harta al caii ferate
    [[nodiscard]] char getSimbol() const;

    // operator pentru afisare
    friend ostream &operator<<(ostream &out, const CaleFerata &myCaleFerata);
};


#endif //OOP_CALEFERATA_H
