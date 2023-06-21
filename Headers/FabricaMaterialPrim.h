//
// Created by David on 5/22/2023.
//

#pragma once
#ifndef OOP_FABRICAMATERIALPRIM_H
#define OOP_FABRICAMATERIALPRIM_H

#include "Fabrica.h"

class FabricaMaterialPrim : public Fabrica{
public:
    // Constructor al fabricii
    explicit FabricaMaterialPrim(string materialProdus_ = "nedefinit", string materialCerut_ = "nedefinit",
                                 string denumire_ = "nedefinit");
    void produce() override;

    // Suprascriere operator =
    FabricaMaterialPrim &operator=(const FabricaMaterialPrim &lumbermill);

    // Suprascriere copy constructor
    [[maybe_unused]] FabricaMaterialPrim(const FabricaMaterialPrim &lumbermill);
};


#endif //OOP_FABRICAMATERIALPRIM_H
