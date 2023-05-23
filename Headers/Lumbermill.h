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
};


#endif //OOP_LUMBERMILL_H
