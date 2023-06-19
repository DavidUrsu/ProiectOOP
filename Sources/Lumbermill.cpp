//
// Created by David on 5/22/2023.
//

#include <utility>

#include "../Headers/Lumbermill.h"
#include <iostream>
#include <random>

// Constructor al fabricii
Lumbermill::Lumbermill(string materialProdus_, string materialCerut_, string denumire_) : Fabrica(std::move(materialProdus_), std::move(materialCerut_), std::move(denumire_)) {}

void Lumbermill::produce(){
    // Se adauga 10 la Stoc
    int stoc = this->getStocProdusFinal();
    this->setStocProdusFinal(stoc + 10);
}

Lumbermill &Lumbermill::operator=(const Lumbermill &lumbermill) {
    if (this != &lumbermill) {
        this->setDenumire(lumbermill.getDenumire());
        this->setMaterialCerut(lumbermill.getMaterialCerut());
        this->setMaterialProdus(lumbermill.getMaterialOferit());
        this->setStocMaterialNecesar(lumbermill.getStocMaterialNecesar());
        this->setStocProdusFinal(lumbermill.getStocProdusFinal());
        this->setCoordonateX(lumbermill.getX());
        this->setCoordonateY(lumbermill.getY());
    }
    return *this;
}

// Constructor de copiere
[[maybe_unused]] Lumbermill::Lumbermill(const Lumbermill &lumbermill) : Fabrica(lumbermill) {
    cout << "Constructor de copiere Lumbermill" << endl;
}