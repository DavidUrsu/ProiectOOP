//
// Created by David on 4/4/2023.
//
#pragma once

#ifndef OOP_FIRMA_H
#define OOP_FIRMA_H

#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Tren; // forward declaration, pentru a evita circular dependency

class Firma {
    string denumire;
    vector<Tren *> flota;
    int money;

public:
    // Constructor firma
    [[maybe_unused]] explicit Firma(string denumire_ = "Unnamed Company");

    // Adaug referinta trenului in vectorul de flota
    void adaugareLocomotiva(Tren *myTrain);

    // Returnez vectorul de adrese ale trenurilor
    [[nodiscard]] vector<Tren *> getFlota() const;

    //Operatorul de accesare prin index, imi returneaza referinta trenului aflat pe pozitia i
    Tren *operator[](int i);

    // operator pentru afisare
    friend ostream &operator<<(ostream &out, const Firma &myCompany);

    // Getter pentru banii firmei
    [[nodiscard]] int getMoney() const;

    // Functie pentru debitarea unei anumite sume din cont-ul firmei
    void buyWithMoney(int sumaDebitata);

    // Functie pentru adaugare de bani in cont-ul firmei
    void addMoney(int sumaCastigata);
};


#endif //OOP_FIRMA_H
