//
// Created by David on 4/4/2023.
//

#include "../Headers/Tren.h"
#include "../Headers/Firma.h"
#include "iostream"

// Constructor Tren
Tren::Tren(string model_, int putereDeTractiune_) : model{std::move(model_)}, putereDeTractiune{putereDeTractiune_} {
    string log = "A fost adaugat cu succes trenul " + model + ", ce poate transporta " + to_string(putereDeTractiune) +
                 " vagoane!\n";
    cout << log;
}

// Deconstructor tren
Tren::~Tren() {
    cout << "S-a vandut locomotiva " << model << endl;
    for(auto i : incarcaturaInt)
        delete(i);

    for(auto i : incarcaturaFloat)
        delete(i);
}

// Functie prin care se adauga in vectorul de incarcatura, adrese ale vagoanelor noi create
void Tren::cuplareVagone(int const numarVagoane, Firma *myCompany, int const indexTren, int const tipVagon) {

    // verific bugetul companiei
    if (numarVagoane * 100 > myCompany->getMoney()) {
        string log = "Nu dispui de suficienti bani pentru a achizitiona " + to_string(numarVagoane) + " vagoane!\n";
        cout << log;
        // verific daca locomotiva mai poate adauga vagoane
    } else if (numarVagoane + int(incarcaturaInt.size() + incarcaturaFloat.size()) > putereDeTractiune) {
        string log = "Locomotiva " + model + '(' + to_string(indexTren + 1) + ')' +
                     " nu are suficienta putere pentru a mai adauga inca " + to_string(numarVagoane) + " vagoane!\n";
        cout << log;
    } else {
        // efectuez debitarea contului
        myCompany->buyWithMoney(numarVagoane * 100);

        // adaug referintele vagoanelor in vectorul incarcatura
        for (int i = 0; i < numarVagoane; i++) {
            if (tipVagon == 1)
                incarcaturaFloat.push_back(new Vagon<float>(5252.6, "Lichide"));
            else if (tipVagon == 2)
                incarcaturaInt.push_back(new Vagon<int>(73, "Calatori"));
            else if (tipVagon == 3)
                incarcaturaFloat.push_back(new Vagon<float>(70.5, "Marfa"));
            else if (tipVagon == 4)
                incarcaturaInt.push_back(new Vagon<int>(49, "Lemn"));
        }
    }
}

// Functie prin care efectuez stergerea obiectelor "vagon" si scoaterea adreselor din vectorul "incarcatura"
void Tren::decuplareVagone(int numarVagoane, Firma *myCompany, int indexTren) {
    // Verific cazul daca sterg mai multe vagoane decat sunt atasate trenului
    if (numarVagoane > int(incarcaturaInt.size() + incarcaturaFloat.size())) {
        string log = "S-au vandut toate vagoanele trenului " + model + '(' + to_string(indexTren + 1) + ')' + '\n';
        cout << log;
        // returnez banii pentru toate vagoanele
        myCompany->addMoney(int(incarcaturaInt.size() + incarcaturaFloat.size()) * 70);

        // sterg toate instantele de vagoane
        while (!incarcaturaInt.empty()) {
            delete incarcaturaInt[incarcaturaInt.size() - 1];
            incarcaturaInt.pop_back();
        }

        while (!incarcaturaFloat.empty()) {
            delete incarcaturaFloat[incarcaturaFloat.size() - 1];
            incarcaturaFloat.pop_back();
        }
    } else {
        string log = "S-au vandut " + to_string(numarVagoane) + " vagoane\n";
        cout << log;

        //returnez banii pentru vagoanele vandute
        myCompany->addMoney(numarVagoane * 70);

        // sterg instantele vagoanelor
        while (numarVagoane) {
            if (!incarcaturaInt.empty()) {
                delete incarcaturaInt[incarcaturaInt.size() - 1];
                incarcaturaInt.pop_back();
            } else {
                delete incarcaturaFloat[incarcaturaFloat.size() - 1];
                incarcaturaFloat.pop_back();
            }
            numarVagoane--;
        }
    }
}

// operator pentru afisare
ostream &operator<<(ostream &out, const Tren &myTren) {
    out << myTren.model << " | Putere de tractiune: " << myTren.putereDeTractiune << " | Vagoane conectate: "
        << myTren.incarcaturaInt.size() + myTren.incarcaturaFloat.size();
    return out;
}

int Tren::getPutereDeTractiune() const {
    return putereDeTractiune;
}

string Tren::getModel() const {
    return model;
}

Tren &Tren::operator=(const Tren &tren) {
    if (this != &tren) {
        model = tren.model;
        putereDeTractiune = tren.putereDeTractiune;
        //pentru fiecare vagon se creaaza o noua instanta cu aceleasi caracteristici
        for (auto i : tren.incarcaturaInt) {
            incarcaturaInt.push_back(new Vagon(*i));
        }
        for (auto i : tren.incarcaturaFloat) {
            incarcaturaFloat.push_back(new Vagon(*i));
        }
    }
    return *this;
}

Tren::Tren(const Tren &tren) : model{tren.model}, putereDeTractiune{tren.putereDeTractiune} {
    //pentru fiecare vagon se creaaza o noua instanta cu aceleasi caracteristici
    for (auto i : tren.incarcaturaInt) {
        incarcaturaInt.push_back(new Vagon(*i));
    }
    for (auto i : tren.incarcaturaFloat) {
        incarcaturaFloat.push_back(new Vagon(*i));
    }
}

void Tren::afisareDetaliiVagoane() {
    cout << "Vagoanele trenului " << model << " sunt:\n";
    for (auto i : incarcaturaInt) {
        cout << "Vagon pentru " + i->getDenumireMarfa() + " cu capacitatea de " + to_string(i->getCantitateMarfaMaxima()) + " unitati" << endl;
    }
    for (auto i : incarcaturaFloat) {
        cout << "Vagon pentru " + i->getDenumireMarfa() + " cu capacitatea de " + to_string(i->getCantitateMarfaMaxima()) + " unitati" << endl;
    }

    if (incarcaturaInt.empty() && incarcaturaFloat.empty())
        cout << "Trenul nu are vagoane\n";
}
