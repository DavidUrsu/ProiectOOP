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
}

// Functie prin care se adauga in vectorul de incarcatura, adrese ale vagoanelor noi create
void Tren::cuplareVagone(int numarVagoane, Firma *myCompany, int indexTren) {

    // verific bugetul companiei
    if (numarVagoane * 100 > myCompany->getMoney()) {
        string log = "Nu dispui de suficienti bani pentru a achizitiona " + to_string(numarVagoane) + " vagoane!\n";
        cout << log;
        // verific daca locomotiva mai poate adauga vagoane
    } else if (numarVagoane + int(incarcatura.size()) > putereDeTractiune) {
        string log = "Locomotiva " + model + '(' + to_string(indexTren + 1) + ')' +
                     " nu are suficienta putere pentru a mai adauga inca " + to_string(numarVagoane) + " vagoane!\n";
        cout << log;
    } else {
        // efectuez debitarea contului
        myCompany->buyWithMoney(numarVagoane * 100);

        // adaug referintele vagoanelor in vectorul incarcatura
        for (int i = 0; i < numarVagoane; i++) {
            incarcatura.push_back(new Vagon());
        }
    }
}

// Functie prin care efectuez stergerea obiectelor "vagon" si scoaterea adreselor din vectorul "incarcatura"
void Tren::decuplareVagone(int numarVagoane, Firma *myCompany, int indexTren) {
    // Verific cazul daca sterg mai multe vagoane decat sunt atasate trenului
    if (numarVagoane > int(incarcatura.size())) {
        string log = "S-au vandut toate vagoanele trenului " + model + '(' + to_string(indexTren + 1) + ')' + '\n';
        cout << log;
        // returnez banii pentru toate vagoanele
        myCompany->addMoney(int(incarcatura.size()) * 70);

        // sterg toate instantele de vagoane
        while (!incarcatura.empty()) {
            delete incarcatura[incarcatura.size() - 1];
            incarcatura.pop_back();
        }
    } else {
        string log = "S-au vandut " + to_string(numarVagoane) + " vagoane\n";
        cout << log;

        //returnez banii pentru vagoanele vandute
        myCompany->addMoney(numarVagoane * 70);

        // sterg instantele vagoanelor
        while (numarVagoane) {
            delete incarcatura[incarcatura.size() - 1];
            incarcatura.pop_back();
            numarVagoane--;
        }
    }
}

// operator pentru afisare
ostream &operator<<(ostream &out, const Tren &myTren) {
    out << myTren.model << " | Putere de tractiune: " << myTren.putereDeTractiune << " | Vagoane conectate: "
        << myTren.incarcatura.size();
    return out;
}
