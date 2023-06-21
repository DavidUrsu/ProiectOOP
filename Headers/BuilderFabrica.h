//
// Created by David on 6/20/2023.
//
#ifndef OOP_BUILDERFABRICA_H
#define OOP_BUILDERFABRICA_H

#include <iostream>
#include <string>
#include <vector>
#include "../Headers/FabricaMaterialPrim.h"
#include "../Headers/FabricaPrelucrare.h"

using namespace std;

class BuilderFabrica {
    string materialProdus, materialCerut, denumire;
    int stocMaterialNecesar;
    vector<string> orase{};
public:
    BuilderFabrica();

    BuilderFabrica* setMaterialProdus(string materialProdus_);

    BuilderFabrica* setMaterialCerut(string materialCerut_);

    BuilderFabrica* setDenumire(string denumire_);

    BuilderFabrica* setStocMaterialNecesar(int stocMaterialNecesar_);

    Fabrica* build();
};


#endif //OOP_BUILDERFABRICA_H
