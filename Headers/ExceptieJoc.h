//
// Created by David on 5/23/2023.
//

#ifndef OOP_EXCEPTIEJOC_H
#define OOP_EXCEPTIEJOC_H

#include <iostream>
using namespace std;

class ExceptieJoc : public std::exception {
private:
    const char *message;

public:
    explicit ExceptieJoc(const char *msg) : message(msg) {}

    using exception::what;
    [[maybe_unused]]virtual const char* what () {
        return message;
    }
};

//clasa noua care mosteneste clasa ExceptieJoc si care va fi folosita pentru a trata exceptiile de tipul "Locomotiva introdusa nu face parte din flota!"
class ExceptieLocomotiva : public ExceptieJoc {
public:
    explicit ExceptieLocomotiva() : ExceptieJoc("Locomotiva introdusa nu face parte din flota!") {}
};

#endif //OOP_EXCEPTIEJOC_H
