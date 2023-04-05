//
// Created by David on 4/4/2023.
//

#include "../Headers/Fabrica.h"
#include "random"
#include "iostream"

// A function to return a seeded random number generator.
inline std::mt19937 &generator() {
    // the generator will only be seeded once (per thread) since it's static
    static thread_local std::mt19937 gen(std::random_device{}());
    return gen;
}

// A function to generate integers in the range [min, max]
template<typename T, std::enable_if_t<std::is_integral_v<T>> * = nullptr>
T my_rand(T max) {
    std::uniform_int_distribution<T> dist(0, max);
    return dist(generator());
}

// Constructor al fabricii
Fabrica::Fabrica(string materialProdus_, string materialCerut_, string denumire_) : materialProdus{
        std::move(materialProdus_)}, materialCerut{std::move(materialCerut_)}, denumire{std::move(denumire_)},
                                                                                    coordonateX{
                                                                                            my_rand(100)},
                                                                                    coordonateY{my_rand(20)} {
    // verific daca fabrica nu este fabrica null
    if (materialProdus != "!") {
        string log = "S-a creat o fabrica " + denumire + " ce produce " + materialProdus + ", avand nevoie de " +
                     materialCerut + ", la coordonatele " + to_string(coordonateX) + " " + to_string(coordonateY) +
                     ".\n";
        cout << log;
    }
}

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
string Fabrica::getDenumire() {
    return denumire;
}

// Getter material oferit
string Fabrica::getMaterialOferit() {
    return materialProdus;
}

// Getter material cerut
string Fabrica::getMaterialCerut() {
    return materialCerut;
}

// Regenerare coordonate ale fabricii
[[maybe_unused]] void Fabrica::regenerareCoordonate() {
    coordonateX = my_rand(100);
    coordonateY = my_rand(20);
}

// operator pentru afisare
ostream &operator<<(ostream &out, const Fabrica &myFabrica) {
    out << myFabrica.denumire;
    return out;
}