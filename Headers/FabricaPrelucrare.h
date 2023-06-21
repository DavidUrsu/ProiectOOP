//
// Created by David on 5/22/2023.
//

#pragma once
#ifndef OOP_FABRICAPRELUCRARE_H
#define OOP_FABRICAPRELUCRARE_H

#include "Fabrica.h"

class FabricaPrelucrare : public Fabrica {
public:
    // Constructor al fabricii
    explicit FabricaPrelucrare(string materialProdus_ = "nedefinit", string materialCerut_ = "nedefinit",
                               string denumire_ = "nedefinit", int stocMaterialNecesar_ = 0);

    // Definire functie virtuala
    void produce() override;

    // Suprascriere operator =
    FabricaPrelucrare &operator=(const FabricaPrelucrare &fabricaDeMobila);

    // Suprascriere copy constructor
    [[maybe_unused]] FabricaPrelucrare(const FabricaPrelucrare &fabricaDeMobila);
};

#endif //OOP_FABRICAPRELUCRARE_H
