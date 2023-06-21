//
// Created by David on 5/22/2023.
//

#include <utility>

#include "../Headers/FabricaMaterialPrim.h"
#include <iostream>
#include <random>

// Constructor al fabricii
FabricaMaterialPrim::FabricaMaterialPrim(string materialProdus_, string materialCerut_, string denumire_) : Fabrica(std::move(materialProdus_), std::move(materialCerut_), std::move(denumire_)) {}

void FabricaMaterialPrim::produce(){
    // Se adauga 10 la Stoc
    int stoc = this->getStocProdusFinal();
    this->setStocProdusFinal(stoc + 10);
}

FabricaMaterialPrim &FabricaMaterialPrim::operator=(const FabricaMaterialPrim &FabricaMaterialPrim) {
    if (this != &FabricaMaterialPrim) {
        this->setDenumire(FabricaMaterialPrim.getDenumire());
        this->setMaterialCerut(FabricaMaterialPrim.getMaterialCerut());
        this->setMaterialProdus(FabricaMaterialPrim.getMaterialOferit());
        this->setStocMaterialNecesar(FabricaMaterialPrim.getStocMaterialNecesar());
        this->setStocProdusFinal(FabricaMaterialPrim.getStocProdusFinal());
        this->setCoordonateX(FabricaMaterialPrim.getX());
        this->setCoordonateY(FabricaMaterialPrim.getY());
    }
    return *this;
}

// Constructor de copiere
[[maybe_unused]] FabricaMaterialPrim::FabricaMaterialPrim(const FabricaMaterialPrim &FabricaMaterialPrim) : Fabrica(FabricaMaterialPrim.getMaterialOferit(), FabricaMaterialPrim.getMaterialCerut(), FabricaMaterialPrim.getDenumire()){
    this->setStocMaterialNecesar(FabricaMaterialPrim.getStocMaterialNecesar());
    this->setStocProdusFinal(FabricaMaterialPrim.getStocProdusFinal());
    this->setCoordonateX(FabricaMaterialPrim.getX());
    this->setCoordonateY(FabricaMaterialPrim.getY());
    cout << "Constructor de copiere FabricaMaterialPrim" << endl;
}