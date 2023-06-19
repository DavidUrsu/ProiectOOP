//
// Created by David on 4/4/2023.
//

#include "../Headers/CaleFerata.h"

// Constructor CaleFerata
CaleFerata::CaleFerata(int coordonateX_, int coordonateY_, char simbolHarta_) : coordonateX{coordonateX_},
                                                                                coordonateY{coordonateY_},
                                                                                simbolHarta{simbolHarta_} {}

// Getter coordonate X ale caii ferate
int CaleFerata::getX() const {
    return coordonateX;
}

// Getter coordonate Y ale caii ferate
int CaleFerata::getY() const {
    return coordonateY;
}

// Getter simbol pentru harta al caii ferate
char CaleFerata::getSimbol() const {
    return simbolHarta;
}

// operator pentru afisare
ostream &operator<<(ostream &out, const CaleFerata &myCaleFerata) {
    out << myCaleFerata.coordonateX << myCaleFerata.coordonateY;
    return out;
}



CaleFerata::~CaleFerata() {
    cout << "S-a distrus o cale ferata!" << endl;
}

CaleFerata::CaleFerata(const CaleFerata &myCaleFerata) {
    coordonateX = myCaleFerata.coordonateX;
    coordonateY = myCaleFerata.coordonateY;
    simbolHarta = myCaleFerata.simbolHarta;
}
