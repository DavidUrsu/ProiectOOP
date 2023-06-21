//
// Created by David on 6/20/2023.
//

#ifndef OOP_FACTORYFABRICI_H
#define OOP_FACTORYFABRICI_H
#include "Fabrica.h"
#include "FabricaMaterialPrim.h"
#include "FabricaPrelucrare.h"

#include<iostream>
#include<vector>
#include<string>


class FactoryFabrici {
    vector<string> orase;
public:
    // Constructor care initializeaza vectorul de orase
    FactoryFabrici();

    Fabrica *createFabricaDeCherestea();

    Fabrica *createFabricaDeMobila();
};


#endif //OOP_FACTORYFABRICI_H
