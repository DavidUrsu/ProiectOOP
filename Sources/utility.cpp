//
// Created by David on 6/19/2023.
//
#include<iostream>
#include<random>

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
