//
// Created by David on 4/4/2023.
//

#pragma once
#ifndef OOP_VAGON_H
#define OOP_VAGON_H

#include "iostream"

using namespace std;

template <class T>
class Vagon {
    // capacitatea maxima reprezinta numarul de unitati internationale de marfa pe care le poate transporta un vagon
    T capacitateMaxima;

    string denumireMarfa;
public:
    // Constructor vagon
    explicit Vagon(T capacitateMaxima_, string  denumireMarfa_) : capacitateMaxima(capacitateMaxima_), denumireMarfa(std::move(denumireMarfa_)) {
        string log = "Vagon de " + denumireMarfa + " creat\n";
        cout << log;
    }

    T getCantitateMarfaMaxima() const{
        return capacitateMaxima;
    }

    [[nodiscard]] string getDenumireMarfa() const{
        return denumireMarfa;
    }

    // Deconstructor vagon
    ~Vagon(){
        string log = "Vagon distrus\n";
        cout << log;
    };

    // operator pentru afisare
    friend ostream& operator<<(ostream& os, const Vagon& vagon) {
        os << "Vagon cu capacitatea maxima de " << vagon.capacitateMaxima << " unitati internationale de marfa si cu marfa " << vagon.denumireMarfa << endl;
        return os;
    }
};


#endif //OOP_VAGON_H
