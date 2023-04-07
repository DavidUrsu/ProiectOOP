//
// Created by David on 4/4/2023.
//

#pragma once
#ifndef OOP_VAGON_H
#define OOP_VAGON_H

#include "iostream"

using namespace std;

class Vagon {
    // capacitatea maxima reprezinta tonajul maxim de marfa pe care un vagon il poate transporta
    int capacitateMaxima;
    string denumireMarfa;
    // momentan nu au nicio utilizare variabilele

public:
    // Constructor vagon
    explicit Vagon();

    // Constructor de copiere vagon
    Vagon(const Vagon &vagonVechi);

    // Deconstructor vagon
    ~Vagon();

    // Operator de copiere
    Vagon &operator=(const Vagon &vagonVechi);

    // operator pentru afisare
    friend ostream &operator<<(ostream &out, const Vagon &myVagon);
};


#endif //OOP_VAGON_H
