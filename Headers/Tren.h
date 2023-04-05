//
// Created by David on 4/4/2023.
//
#pragma once

#ifndef OOP_TREN_H
#define OOP_TREN_H

class Firma; // forward declaration, pentru a evita circular dependency
#include "Vagon.h"
#include "iostream"
#include "vector"

using namespace std;

class Tren {
    string model;
    int putereDeTractiune;
    vector<Vagon *> incarcatura;

public:
    // Constructor Tren
    Tren(string model_, int putereDeTractiune_);

    // Deconstructor tren
    ~Tren();

    //
    void cuplareVagone(int numarVagoane, Firma *myCompany, int indexTren);

    //
    void decuplareVagone(int numarVagoane, Firma *myCompany, int indexTren);

    // operator pentru afisare
    friend ostream &operator<<(ostream &out, const Tren &myTren);
};


#endif //OOP_TREN_H
