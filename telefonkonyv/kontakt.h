/**
 * \file kontakt.h
 *
 * Telefonkonyv
 *   Jporta "NHF4 - Skeleton" feladatnak bemutatáshoz.
 *
 * Feladat:
 *   Dinamikus nyilvántartás megvalósítása heterogén kollekcióval.
 */

#ifndef KONTAKT_H_INCLUDED
#define KONTAKT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> /// csak a hibajelzés miatt kell
#include "memtrace.h"
#include "szovegek.h"

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::fstream;
using std::ios_base;
using std::stringstream;

class Kontakt {
protected:
    string vezeteknev;
    string keresztnev;
    string cim;
    string munkahelyi_szam;
    string privat_szam;
public:
    /// Konstruktor.
    Kontakt(string v = "",
            string k = "",
            string c = "",
            string m = "",
            string p = "") : vezeteknev(v), keresztnev(k), cim(c), munkahelyi_szam(m), privat_szam(p) {}

    /// Adatok lekérdezése.
    string get_vez();
    string get_ker();
    string get_cim();
    string get_mun();
    string get_pri();

    /// Egy kontakt adatainak kiírása.
    /// @param os - output stream, default: cout
    virtual void kiir(ostream& os = cout);

    /// Másolat készítése (deep copy).
    virtual Kontakt* clone();

    /// Értékek összehasonlítása.
    /// @param k - kontakt pointere
    virtual bool operator==(Kontakt* k);

    /// Destruktor.
    virtual ~Kontakt() {}
    // a leszármazottaknak külön nem is kell
    // ez is csak azért van, mert az eltérő adatstruktúrák miatt
    // virtuálisnak kell lennie a kontakt destruktorának

    /// Szöveg összehasonlító függvény, ami
    /// igazat ad vissza, ha az adat része a tipus
    /// által jelölt adatnak.
    /// @param adat - szöveg
    /// @param tipus - ahol keressük (vez, ker, cim, mun, pri, bec, beo)
    virtual bool string_keres(string adat, string tipus);
};

class Barat:public Kontakt {
    string becenev;
public:
    /// Konstruktor.
    Barat(string v = "",
          string k = "",
          string c = "",
          string m = "",
          string p = "",
          string b = "") : Kontakt(v, k, c, p, m), becenev(b) {}

    /// Speciális adat lekérdezése.
    string get_bec();

    /// Egy barát adatainak kiírása.
    /// @param os - output stream, default: cout
    void kiir(ostream& os = cout);

    /// Másolat készítése (deep copy).
    Barat* clone();

    /// Értékek összehasonlítása.
    /// @param k - kontakt pointere
    bool operator==(Kontakt* k);

    /// Szöveg összehasonlító függvény, ami
    /// igazat ad vissza, ha az adat része a tipus
    /// által jelölt adatnak.
    /// @param adat - szöveg
    /// @param tipus - ahol keressük (vez, ker, cim, mun, pri, bec, beo)
    bool string_keres(string adat, string tipus);
};

class Munkatars:public Kontakt {
    string beosztas;
public:
    /// Konstruktor.
    Munkatars(string v = "",
              string k = "",
              string c = "",
              string m = "",
              string p = "",
              string b = "") : Kontakt(v, k, c, p, m), beosztas(b) {}

    /// Speciális adat lekérdezése.
    string get_beo();

    /// Egy munkatárs adatainak kiírása.
    /// @param os - output stream, default: cout
    void kiir(ostream& os = cout);

    /// Másolat készítése (deep copy).
    Munkatars* clone();

    /// Értékek összehasonlítása.
    /// @param k - kontakt pointere
    bool operator==(Kontakt* m);

    /// Szöveg összehasonlító függvény, ami
    /// igazat ad vissza, ha az adat része a tipus
    /// által jelölt adatnak.
    /// @param adat - szöveg
    /// @param tipus - ahol keressük (vez, ker, cim, mun, pri, bec, beo)
    bool string_keres(string adat, string tipus);
};

/// Fájlba írás.
/// @param f - output stream
/// @param k - kontakt pointere
ostream& operator<<(ostream& f, Kontakt* k);

#endif // KONTAKT_H_INCLUDED
