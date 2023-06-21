//
// Created by David on 5/22/2023.
//

#include <utility>

#include "../Headers/FabricaPrelucrare.h"
#include "iostream"

// Constructor al fabricii
FabricaPrelucrare::FabricaPrelucrare(string materialProdus_, string materialCerut_, string denumire_, int stocMaterialNecesar_) :
    Fabrica(
            std::move(materialProdus_),
            std::move(materialCerut_),
            std::move(denumire_),
            stocMaterialNecesar_) {}

void FabricaPrelucrare::produce(){
    int stoc = this->getStocMaterialNecesar();
    // Verificare stoc
    if (stoc >= 10) {
        this->setStocMaterialNecesar(stoc - 10);
        int stocMaterialProdus = this->getStocProdusFinal();
        // Produce o unitate finala pentru 10 unitati din stoc
        this->setStocProdusFinal(stocMaterialProdus + 1);
    }
}

FabricaPrelucrare &FabricaPrelucrare::operator=(const FabricaPrelucrare &fabricaPrelucrare) {
    if (this != &fabricaPrelucrare) {
        this->setDenumire(fabricaPrelucrare.getDenumire());
        this->setMaterialCerut(fabricaPrelucrare.getMaterialCerut());
        this->setMaterialProdus(fabricaPrelucrare.getMaterialOferit());
        this->setStocMaterialNecesar(fabricaPrelucrare.getStocMaterialNecesar());
        this->setStocProdusFinal(fabricaPrelucrare.getStocProdusFinal());
        this->setCoordonateX(fabricaPrelucrare.getX());
        this->setCoordonateY(fabricaPrelucrare.getY());
    }
    return *this;
}

// Constructor de copiere
FabricaPrelucrare::FabricaPrelucrare(const FabricaPrelucrare &fabricaPrelucrare) : Fabrica(fabricaPrelucrare.getMaterialOferit(), fabricaPrelucrare.getMaterialCerut(), fabricaPrelucrare.getDenumire(), fabricaPrelucrare.getStocMaterialNecesar()){
    this->setStocProdusFinal(fabricaPrelucrare.getStocProdusFinal());
    this->setCoordonateX(fabricaPrelucrare.getX());
    this->setCoordonateY(fabricaPrelucrare.getY());
    cout << "Constructor de copiere FabricaPrelucrare" << endl;
}