//
// Created by David on 5/23/2023.
//

#ifndef OOP_EXCEPTIE_H
#define OOP_EXCEPTIE_H

#include <iostream>
using namespace std;

class Exceptie : public std::exception {
private:
    char *message;

public:
    explicit Exceptie(char *msg) : message(msg) {}

    using exception::what;
    [[maybe_unused]]virtual char* what () {
        return message;
    }
};


#endif //OOP_EXCEPTIE_H
