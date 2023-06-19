//
// Created by David on 5/22/2023.
//

#include <utility>

#include "../Headers/FabricaDeMobila.h"
#include "iostream"

// Constructor al fabricii
FabricaDeMobila::FabricaDeMobila(string materialProdus_, string materialCerut_, string denumire_, int stocMaterialNecesar_) :
    Fabrica(
            std::move(materialProdus_),
            std::move(materialCerut_),
            std::move(denumire_),
            stocMaterialNecesar_) {}

void FabricaDeMobila::produce(){
    int stoc = this->getStocMaterialNecesar();
    // Verificare stoc
    if (stoc >= 10) {
        this->setStocMaterialNecesar(stoc - 10);
        int stocMaterialProdus = this->getStocProdusFinal();
        // Produce o unitate finala pentru 10 unitati din stoc
        this->setStocProdusFinal(stocMaterialProdus + 1);
    }
}

FabricaDeMobila &FabricaDeMobila::operator=(const FabricaDeMobila &fabricaDeMobila) {
    if (this != &fabricaDeMobila) {
        this->setDenumire(fabricaDeMobila.getDenumire());
        this->setMaterialCerut(fabricaDeMobila.getMaterialCerut());
        this->setMaterialProdus(fabricaDeMobila.getMaterialOferit());
        this->setStocMaterialNecesar(fabricaDeMobila.getStocMaterialNecesar());
        this->setStocProdusFinal(fabricaDeMobila.getStocProdusFinal());
        this->setCoordonateX(fabricaDeMobila.getX());
        this->setCoordonateY(fabricaDeMobila.getY());
    }
    return *this;
}

// Constructor de copiere
FabricaDeMobila::FabricaDeMobila(const FabricaDeMobila &fabricaDeMobila) : Fabrica(fabricaDeMobila) {
    cout << "Constructor de copiere FabricaDeMobila" << endl;
}