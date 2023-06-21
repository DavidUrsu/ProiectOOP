//
// Created by David on 6/20/2023.
//

#include <utility>

#include "../Headers/BuilderFabrica.h"
#include "utility.cpp"

BuilderFabrica::BuilderFabrica() : materialProdus("nedefinit"), materialCerut("-"), denumire("nedefinit"), stocMaterialNecesar(0), orase({"Bucuresti", "Cluj", "Timisoara", "Iasi", "Constanta", "Brasov", "Galati", "Ploiesti", "Oradea", "Braila"}) {}

BuilderFabrica *BuilderFabrica::setMaterialProdus(string materialProdus_) {
    materialProdus = std::move(materialProdus_);
    return this;
}

BuilderFabrica *BuilderFabrica::setMaterialCerut(string materialCerut_) {
    materialCerut = std::move(materialCerut_);
    return this;
}

BuilderFabrica *BuilderFabrica::setDenumire(string denumire_) {
    denumire = std::move(denumire_);
    return this;
}

BuilderFabrica *BuilderFabrica::setStocMaterialNecesar(int stocMaterialNecesar_) {
    stocMaterialNecesar = stocMaterialNecesar_;
    return this;
}

Fabrica *BuilderFabrica::build() {
    // daca materialul cerut este diferit de "-" atunci se creeaza o fabrica de prelucrare

    if (materialCerut != "-") {
        return new FabricaPrelucrare(materialProdus, materialCerut, denumire + " " + orase[my_rand(9)], stocMaterialNecesar);
    }
    // altfel se creeaza o fabrica de material prim
    return new FabricaMaterialPrim(materialProdus, materialCerut, denumire + " " + orase[my_rand(9)]);
}
