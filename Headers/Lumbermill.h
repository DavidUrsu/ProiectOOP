//
// Created by David on 5/22/2023.
//

#pragma once
#ifndef OOP_LUMBERMILL_H
#define OOP_LUMBERMILL_H

#include "Fabrica.h"

class Lumbermill : public Fabrica{
public:
    // Constructor al fabricii
    explicit Lumbermill(string materialProdus_ = "nedefinit", string materialCerut_ = "nedefinit",
                        string denumire_ = "nedefinit");
    void produce() override;

    // Suprascriere operator =
    Lumbermill &operator=(const Lumbermill &lumbermill);

    // Suprascriere copy constructor
    [[maybe_unused]] [[maybe_unused]] [[maybe_unused]] Lumbermill(const Lumbermill &lumbermill);
};


#endif //OOP_LUMBERMILL_H
