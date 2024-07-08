/**
 * \file kontakt.cpp
 *
 * Telefonkonyv
 *   Jporta "NHF4 - Skeleton" feladatnak bemutatáshoz.
 *
 * Feladat:
 *   Dinamikus nyilvántartás megvalósítása heterogén kollekcióval.
 */

#include "kontakt.h"

string Kontakt::get_vez() { return vezeteknev; }
string Kontakt::get_ker() { return keresztnev; }
string Kontakt::get_cim() { return cim; }
string Kontakt::get_mun() { return munkahelyi_szam; }
string Kontakt::get_pri() { return privat_szam; }
string Barat::get_bec() { return becenev; }
string Munkatars::get_beo() { return beosztas; }

void Kontakt::kiir(ostream& os) {
    os << "Kontakt;";
    (vezeteknev != "") ? os << vezeteknev << ";" : os << "nincs;";
    (keresztnev != "") ? os << keresztnev << ";" : os << "nincs;";
    (cim != "") ? os << cim << ";" : os << "nincs;";
    (munkahelyi_szam != "") ? os << munkahelyi_szam << ";" : os << "nincs;";
    (privat_szam != "") ? os << privat_szam : os << "nincs";
    os << endl;
}

void Barat::kiir(ostream& os) {
    os << "Barat;";
    (get_vez() != "") ? os << get_vez() << ";" : os << "nincs;";
    (get_ker() != "") ? os << get_ker() << ";" : os << "nincs;";
    (get_cim() != "") ? os << get_cim() << ";" : os << "nincs;";
    (get_mun() != "") ? os << get_mun() << ";" : os << "nincs;";
    (get_pri() != "") ? os << get_pri() << ";" : os << "nincs;";
    (becenev != "") ? os << becenev : os << "nincs";
    os << endl;
}

void Munkatars::kiir(ostream& os) {
    os << "Munkatars;";
    (get_vez() != "") ? os << get_vez() << ";" : os << "nincs;";
    (get_ker() != "") ? os << get_ker() << ";" : os << "nincs;";
    (get_cim() != "") ? os << get_cim() << ";" : os << "nincs;";
    (get_mun() != "") ? os << get_mun() << ";" : os << "nincs;";
    (get_pri() != "") ? os << get_pri() << ";" : os << "nincs;";
    (beosztas != "") ? os << beosztas : os << "nincs";
    os << endl;
}

ostream& operator<<(ostream& f, Kontakt* k) {
    k->kiir(f);
    return f;
}

bool Kontakt::operator==(Kontakt* k) {
    if(vezeteknev != k->vezeteknev) return false;
    if(keresztnev != k->keresztnev) return false;
    if(cim != k->cim) return false;
    if(munkahelyi_szam != k->munkahelyi_szam) return false;
    if(privat_szam != k->privat_szam) return false;
    return true;
}

bool Barat::operator==(Kontakt* k) {
    Barat* l = dynamic_cast<Barat*> (k);
    if(l == NULL) return false;
    if(vezeteknev != l->vezeteknev) return false;
    if(keresztnev != l->keresztnev) return false;
    if(cim != l->cim) return false;
    if(munkahelyi_szam != l->munkahelyi_szam) return false;
    if(privat_szam != l->privat_szam) return false;
    if(becenev != l->becenev) return false;
    return true;
}

bool Munkatars::operator==(Kontakt* k) {
    Munkatars* l = dynamic_cast<Munkatars*> (k);
    if(l == NULL) return false;
    if(vezeteknev != l->vezeteknev) return false;
    if(keresztnev != l->keresztnev) return false;
    if(cim != l->cim) return false;
    if(munkahelyi_szam != l->munkahelyi_szam) return false;
    if(privat_szam != l->privat_szam) return false;
    if(beosztas != l->beosztas) return false;
    return true;
}

Kontakt* Kontakt::clone() { return new Kontakt(*this); }
Barat* Barat::clone() { return new Barat(*this); }
Munkatars* Munkatars::clone() { return new Munkatars(*this); }

bool Kontakt::string_keres(string adat, string tipus) {
    if(tipus == "vez") return vezeteknev.find(adat) != string::npos;
    else if(tipus == "ker") return keresztnev.find(adat) != string::npos;
    else if(tipus == "cim") return cim.find(adat) != string::npos;
    else if(tipus == "mun") return munkahelyi_szam.find(adat) != string::npos;
    else if(tipus == "pri") return privat_szam.find(adat) != string::npos;
    else {
        if(vezeteknev.find(adat) != string::npos ||
           keresztnev.find(adat) != string::npos ||
           cim.find(adat) != string::npos ||
           munkahelyi_szam.find(adat) != string::npos ||
           privat_szam.find(adat) != string::npos) { return true; }
    }
    return false;
}
bool Barat::string_keres(string adat, string tipus) {
    if(tipus == "vez") return get_vez().find(adat) != string::npos;
    else if(tipus == "ker") return get_ker().find(adat) != string::npos;
    else if(tipus == "cim") return get_cim().find(adat) != string::npos;
    else if(tipus == "mun") return get_mun().find(adat) != string::npos;
    else if(tipus == "pri") return get_pri().find(adat) != string::npos;
    else if(tipus == "bec") return becenev.find(adat) != string::npos;
    else {
        if(get_vez().find(adat) != string::npos ||
           get_ker().find(adat) != string::npos ||
           get_cim().find(adat) != string::npos ||
           get_mun().find(adat) != string::npos ||
           get_pri().find(adat) != string::npos ||
           becenev.find(adat) != string::npos) { return true; }
    }
    return false;
}
bool Munkatars::string_keres(string adat, string tipus) {
    if(tipus == "vez") return get_vez().find(adat) != string::npos;
    else if(tipus == "ker") return get_ker().find(adat) != string::npos;
    else if(tipus == "cim") return get_cim().find(adat) != string::npos;
    else if(tipus == "mun") return get_mun().find(adat) != string::npos;
    else if(tipus == "pri") return get_pri().find(adat) != string::npos;
    else if(tipus == "beo") return beosztas.find(adat) != string::npos;
    else {
        if(get_vez().find(adat) != string::npos ||
           get_ker().find(adat) != string::npos ||
           get_cim().find(adat) != string::npos ||
           get_mun().find(adat) != string::npos ||
           get_pri().find(adat) != string::npos ||
           beosztas.find(adat) != string::npos) { return true; }
    }
    return false;
}
