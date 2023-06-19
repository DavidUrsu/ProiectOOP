//
// Created by David on 4/4/2023.
//

#pragma once
#ifndef OOP_FABRICA_H
#define OOP_FABRICA_H

#include "iostream"
#include "string"

using namespace std;

class Fabrica{
    string materialProdus, materialCerut, denumire;
    int coordonateX, coordonateY, stocMaterialNecesar, stocProdusFinal;
    char simbolHarta = '#'; // ■ char(254)

protected:
    // Setter stocMaterialNecesar
    void setStocMaterialNecesar(int newVal);

    // Setter stocProdusFinal
    void setStocProdusFinal(int newVal);

    // Setter materialProdus
    void setMaterialProdus(string newVal);

    // Setter materialCerut
    void setMaterialCerut(string newVal);

    // Setter denumire
    void setDenumire(string newVal);

    // Setter coordonateX
    void setCoordonateX(int newVal);

    // Setter coordonateY
    void setCoordonateY(int newVal);

public:
    // Constructor al fabricii
    explicit Fabrica(string materialProdus_ = "nedefinit", string materialCerut_ = "nedefinit",
                     string denumire_ = "nedefinit", int stocMaterialNecesar_ = 0);

    // Deconstructor al fabricii
    virtual ~Fabrica();

    // Functie virtuala pura de produs
    virtual void produce() = 0;

    // Getter coordonate X ale fabricii
    [[nodiscard]] int getX() const;

    // Getter coordonate Y ale fabricii
    [[nodiscard]] int getY() const;

    // Getter simbol pentru harta al fabricii
    [[nodiscard]] char getSimbol() const;

    // Getter denumire a fabricii
    [[nodiscard]] string getDenumire() const;

    // Getter material oferit
    [[nodiscard]] string getMaterialOferit() const;

    // Getter material cerut
    [[nodiscard]] string getMaterialCerut() const;

    // Getter stocMaterialNecesar
    [[nodiscard]] int getStocMaterialNecesar() const;

    // Getter stocProdusFinal
    [[nodiscard]] int getStocProdusFinal() const;

    // Regenerare coordonate ale fabricii
    void regenerareCoordonate();

    // operator pentru afisare
    friend ostream &operator<<(ostream &out, const Fabrica &myFabrica);

    // suprascriere operator =
    Fabrica &operator=(const Fabrica &myFabrica);

    // suprascriere copy constructor
    Fabrica(const Fabrica &myFabrica);

};


#endif //OOP_FABRICA_H
