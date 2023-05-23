//
// Created by David on 5/22/2023.
//

#include <utility>

#include "../Headers/Lumbermill.h"
#include <iostream>
#include <random>

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
Lumbermill::Lumbermill(string materialProdus_, string materialCerut_, string denumire_) : Fabrica(std::move(materialProdus_), std::move(materialCerut_), std::move(denumire_)) {}

void Lumbermill::produce(){
    // Se adauga 10 la Stoc
    int stoc = this->getStocProdusFinal();
    this->setStocProdusFinal(stoc + 10);
}