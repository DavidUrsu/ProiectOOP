//
// Created by David on 6/20/2023.
//

#include "../Headers/FactoryFabrici.h"
#include "utility.cpp"

FactoryFabrici::FactoryFabrici() {
    orase = {"Bucuresti", "Cluj", "Timisoara", "Iasi", "Constanta", "Brasov", "Galati", "Ploiesti", "Oradea", "Braila"};
}

Fabrica *FactoryFabrici::createFabricaDeCherestea() {
    return new FabricaMaterialPrim("Lemn", "-", "Fabrica de cherestea " + orase[my_rand(9)]);
}

Fabrica *FactoryFabrici::createFabricaDeMobila() {
    return new FabricaPrelucrare("Mobila", "Lemn", "IKEA " + orase[my_rand(9)], 100);
}
