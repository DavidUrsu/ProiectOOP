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
    // Puterea de tractiune se refera la numarul maxim de vagoane pe care un tren il poate transporta
    int putereDeTractiune;
    // In vectorul incarcatura, se vor retine toate adresele vagoanelor trenului
    vector<Vagon *> incarcatura;

public:
    // Constructor Tren
    Tren(string model_, int putereDeTractiune_);

    // Deconstructor tren
    ~Tren();

    // Functie prin care se adauga in vectorul "incarcatura", adresele vagoanelor noi create
    void cuplareVagone(int numarVagoane, Firma *myCompany, int indexTren);

    // Functie prin care se realizeaza stergerea obiectelor "vagon" si scoaterea adreselor din vectorul "incarcatura"
    void decuplareVagone(int numarVagoane, Firma *myCompany, int indexTren);

    // operator pentru afisare
    friend ostream &operator<<(ostream &out, const Tren &myTren);

    // Getter pentru puterea de tractiune
    [[nodiscard]] int getPutereDeTractiune() const;

    // Getter pentru model
    [[nodiscard]] string getModel() const;

    // Suprascriere operator =
    Tren& operator=(const Tren& tren);

    // Suprascriere copy constructor
    Tren(const Tren& tren);
};


#endif //OOP_TREN_H
