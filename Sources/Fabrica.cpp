//
// Created by David on 4/4/2023.
//

#include "../Headers/Fabrica.h"
#include "utility.cpp"

#include "iostream"

// Constructor al fabricii
[[maybe_unused]] Fabrica::Fabrica(string materialProdus_, string materialCerut_, string denumire_, int stocMaterialNecesar_) :
    materialProdus{ std::move(materialProdus_)},
    materialCerut{std::move(materialCerut_)},
    denumire{std::move(denumire_)},
    coordonateX{my_rand(99)},
    coordonateY{my_rand(19)},
    stocMaterialNecesar{stocMaterialNecesar_},
    stocProdusFinal{0} {}

// Deconstructor al fabricii
Fabrica::~Fabrica() {
    cout << denumire << " a dat faliment!" << endl;
}

// Getter coordonate X ale fabricii
int Fabrica::getX() const {
    return coordonateX;
}

// Getter coordonate Y ale fabricii
int Fabrica::getY() const {
    return coordonateY;
}

// Getter simbol pentru harta al fabricii
char Fabrica::getSimbol() const {
    return simbolHarta;
}

// Getter denumire a fabricii
string Fabrica::getDenumire() const{
    return denumire;
}

// Getter material oferit
string Fabrica::getMaterialOferit() const{
    return materialProdus;
}

// Getter material cerut
string Fabrica::getMaterialCerut() const{
    return materialCerut;
}

// Regenerare coordonate ale fabricii
void Fabrica::regenerareCoordonate() {
    coordonateX = my_rand(99);
    coordonateY = my_rand(19);
}

// operator pentru afisare
ostream &operator<<(ostream &out, const Fabrica &myFabrica) {
    out << myFabrica.denumire;
    return out;
}

int Fabrica::getStocMaterialNecesar() const {
    return stocMaterialNecesar;
}

int Fabrica::getStocProdusFinal() const {
    return stocProdusFinal;
}

void Fabrica::setStocMaterialNecesar(int newVal) {
    stocMaterialNecesar = newVal;
}

void Fabrica::setStocProdusFinal(int newVal) {
    stocProdusFinal = newVal;
}

Fabrica &Fabrica::operator=(const Fabrica &myFabrica) {
    if (this != &myFabrica) {
        materialProdus = myFabrica.materialProdus;
        materialCerut = myFabrica.materialCerut;
        denumire = myFabrica.denumire;
        coordonateX = myFabrica.coordonateX;
        coordonateY = myFabrica.coordonateY;
        stocMaterialNecesar = myFabrica.stocMaterialNecesar;
        stocProdusFinal = myFabrica.stocProdusFinal;
        simbolHarta = myFabrica.simbolHarta;
    }
    return *this;
}

Fabrica::Fabrica(const Fabrica &myFabrica) = default;

void Fabrica::setMaterialProdus(string newVal) {
    materialProdus = std::move(newVal);
}

void Fabrica::setMaterialCerut(string newVal) {
    materialCerut = std::move(newVal);
}

void Fabrica::setDenumire(string newVal) {
    denumire = std::move(newVal);
}

void Fabrica::setCoordonateX(int newVal) {
    coordonateX = newVal;
}

void Fabrica::setCoordonateY(int newVal) {
    coordonateY = newVal;
}
