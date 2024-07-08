/**
 * \file telefonkonyv.cpp
 *
 * Telefonkonyv
 *   Jporta "NHF4 - Skeleton" feladatnak bemutatáshoz.
 *
 * Feladat:
 *   Dinamikus nyilvántartás megvalósítása heterogén kollekcióval.
 */

#include "telefonkonyv.h"

Telefonkonyv::Telefonkonyv() {
    meret = 0;
    lista = new Kontakt*[meret];
}

Telefonkonyv::Telefonkonyv(Telefonkonyv& t) {
    meret = 0;
    lista = new Kontakt*[meret];
    *this = t;
}

void Telefonkonyv::hozzaad(Kontakt* k) {
    for(size_t i = 0; i < meret; i++) {
        if(*lista[i] == k) {
            cout << MAR_VAN;
            return;
        }
    }
    Kontakt** uj = new Kontakt*[meret + 1];
    for(size_t i = 0; i < meret; i++) {
        uj[i] = lista[i];
    }
    uj[meret++] = k->clone();
    delete[] lista;
    lista = uj;
}

void Telefonkonyv::torol(Kontakt* k) {
    int index = -1;
    for(size_t i = 0; i < meret; i++) {
        if(*lista[i] == k) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << MEG_NINCS;
        return;
    }
    for(size_t i = index; i < meret - 1; i++) {
        delete lista[index];
        lista[index] = lista[index+1]->clone();
    }
    delete lista[--meret];
}

size_t Telefonkonyv::get_meret() { return meret; }

void Telefonkonyv::listaz(string adat, string tipus, ostream& os) {
    for(size_t i = 0; i < meret; i++) {
        if(lista[i]->string_keres(adat, tipus)) { lista[i]->kiir(os); }
    }
    if(meret == 0) {
        cout << URES_LISTA;
        return;
    }
}

void Telefonkonyv::mentes(const string& fajl) {
    fstream f;
    f.open(fajl, ios_base::out);
    if(!f.is_open()) {
        cout << NINCS_FAJL;
        return;
    }
    for(size_t i = 0; i < meret; i++) {
        f << lista[i];
    }
    f.close();
}

void Telefonkonyv::betoltes(const string& fajl) {
        fstream f;
        f.open(fajl, ios_base::in);
        if(!f.is_open()) {
            cout << NINCS_FAJL;
            return;
        }
        string input, v, k, c, m, p, b;
        bool hibas_bemenet = false;
        while(getline(f, input, ';')) {
            if(input == "Kontakt" || input == "Barat" || input == "Munkatars") {
                getline(f, v, ';');
                getline(f, k, ';');
                getline(f, c, ';');
                getline(f, m, ';');
                if(input == "Kontakt") {
                    getline(f, p);
                    Kontakt* w = new Kontakt(v, k, c, m, p);
                    this->hozzaad(w);
                    delete w;
                }
                else {
                    getline(f, p, ';');
                    getline(f, b);
                    if(input == "Barat") {
                        Barat* w = new Barat(v, k, c, m, p, b);
                        this->hozzaad(w);
                        delete w;
                    }
                    else if(input == "Munkatars") {
                        Munkatars* w = new Munkatars(v, k, c, m, p, b);
                        this->hozzaad(w);
                        delete w;
                    }
                }
            }
            else {
                hibas_bemenet = true;
                break;
            }
        }
        f.close();
        if(hibas_bemenet) {
            this->torol();
            stringstream err;
            err << "Hibas bemenet erkezett, nem sikerult betolteni az adatokat.." << endl;
            throw std::out_of_range(err.str());
        }
}

Telefonkonyv& Telefonkonyv::operator=(const Telefonkonyv& t) {
    if(lista == t.lista) return *this;
    delete[] lista;
    meret = t.meret;
    lista = new Kontakt*[meret];
    for(size_t i = 0; i < meret; i++) {
        lista[i] = t.lista[i]->clone();
    }
    return *this;
}

Kontakt* Telefonkonyv::operator[](size_t i) {
    if(i >= meret) {
        stringstream err;
        err << "Indexelesi hiba.." << endl;
        throw std::out_of_range(err.str());
    }
    return lista[i];
}

void Telefonkonyv::torol() {
    for(size_t i = 0; i < meret; i++){
        delete lista[i];
    }
    meret = 0;
}

Telefonkonyv::~Telefonkonyv() {
    this->mentes();
    this->torol();
    delete[] lista;
}

bool A_kezd_vez(Kontakt* k) { return (k->get_vez()[0] == 'A'); }
bool B_kezd_vez(Kontakt* k) { return (k->get_vez()[0] == 'B'); }
bool K_kezd_vez(Kontakt* k) { return (k->get_vez()[0] == 'K'); }
bool N_kezd_vez(Kontakt* k) { return (k->get_vez()[0] == 'N'); }
bool tanar(Kontakt* k) {
    Munkatars* m = dynamic_cast<Munkatars*>(k);
    return (m && m->get_beo() == "Tanar");
}
bool postas(Kontakt* k) {
    Munkatars* m = dynamic_cast<Munkatars*>(k);
    return (m && m->get_beo() == "Postas");
}
