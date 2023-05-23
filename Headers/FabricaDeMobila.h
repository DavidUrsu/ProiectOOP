//
// Created by David on 5/22/2023.
//

#pragma once
#ifndef OOP_FABRICADEMOBILA_H
#define OOP_FABRICADEMOBILA_H

#include "Fabrica.h"

class FabricaDeMobila : public Fabrica {
public:
    // Constructor al fabricii
    explicit FabricaDeMobila(string materialProdus_ = "nedefinit", string materialCerut_ = "nedefinit",
                             string denumire_ = "nedefinit", int stocMaterialNecesar_ = 0);

    // Definire functie virtuala
    void produce() override;


};

#endif //OOP_FABRICADEMOBILA_H
