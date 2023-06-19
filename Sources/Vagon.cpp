//
// Created by David on 4/4/2023.
//

#include "iostream"
#include "../Headers/Vagon.h"

// Constructor vagon
Vagon::Vagon() : capacitateMaxima{15}, denumireMarfa{"-"} {
    string log = "Vagon nou\n";
    cout << log;
}

// Constructor de copiere vagon
Vagon::Vagon(const Vagon &vagonVechi) : capacitateMaxima{vagonVechi.capacitateMaxima},
                                        denumireMarfa(vagonVechi.denumireMarfa) {
    cout << "Vagon nou" << endl;
}

// Operator de copiere
Vagon &Vagon::operator=(const Vagon &vagonVechi) = default;

// operator pentru afisare
ostream &operator<<(ostream &out, const Vagon &myVagon) {
    out << myVagon.denumireMarfa;
    return out;
}

// Deconstructor vagon
Vagon::~Vagon() {
    cout << "Vagon vandut!\n";
}
