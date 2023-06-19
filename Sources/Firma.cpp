//
// Created by David on 4/4/2023.
//

#include "../Headers/Firma.h"
#include "iostream"

// Constructor firma
[[maybe_unused]] Firma::Firma(string denumire_) : denumire{std::move(denumire_)}, money{15000} {
    string log = "A fost creata firma " + denumire + '\n';
    cout << log;
}

// Deconstructor firma
Firma::~Firma() {
    //distrugere trenuri
    for (auto i : flota)
        delete (i);

    string log = "A fost distrusa firma " + denumire + '\n';
    cout << log;
}

// Adaug referinta trenului in vectorul de flota
void Firma::adaugareLocomotiva(Tren *myTrain) {
    flota.push_back(myTrain);
}

// Returnez vectorul de adrese ale trenurilor
vector<Tren *> Firma::getFlota() const {
    return flota;
}

//Operatorul de accesare prin index, imi returneaza referinta trenului aflat pe pozitia i
Tren *Firma::operator[](int i) {
    return flota[i];
}

// operator pentru afisare
ostream &operator<<(ostream &out, const Firma &myCompany) {
    out << myCompany.denumire;
    return out;
}

// Getter pentru banii firmei
int Firma::getMoney() const {
    return money;
}

// Functie pentru debitarea unei anumite sume din cont-ul firmei
void Firma::buyWithMoney(int sumaDebitata) {
    money = money - sumaDebitata;
}

// Functie pentru adaugare de bani in cont-ul firmei
void Firma::addMoney(int sumaCastigata) {
    money = money + sumaCastigata;
}

Firma &Firma::operator=(const Firma &firma) {
    if (this != &firma) {
        denumire = firma.denumire;
        // fac un nou vector de trenuri si creez un nou tren cu aceleasi caracteristici ca trenul din firma
        for(auto i: firma.flota)
            flota.push_back(new Tren(i->getModel(), i->getPutereDeTractiune()));
        money = firma.money;
    }
    return *this;
}

[[maybe_unused]] Firma::Firma(const Firma &firma) : denumire{firma.denumire}, money{firma.money} {
    // fac un nou vector de trenuri si creez un nou tren cu aceleasi caracteristici ca trenul din firma
    for(auto i: firma.flota)
        flota.push_back(new Tren(i->getModel(), i->getPutereDeTractiune()));
}
