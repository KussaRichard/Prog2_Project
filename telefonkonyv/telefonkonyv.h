/**
 * \file telefonkonyv.h
 *
 * Telefonkonyv
 *   Jporta "NHF4 - Skeleton" feladatnak bemutatáshoz.
 *
 * Feladat:
 *   Dinamikus nyilvántartás megvalósítása heterogén kollekcióval.
 */

#ifndef TELEFONKONYV_H_INCLUDED
#define TELEFONKONYV_H_INCLUDED

#include <iostream>
#include "memtrace.h"
#include "kontakt.h"

class Telefonkonyv {
    Kontakt** lista;
    size_t meret;
public:
    /// Konstruktor.
    Telefonkonyv();

    /// Másoló konstruktor.
    Telefonkonyv(Telefonkonyv& t);

    /// Elem hozzáadása a nyilvántartáshoz.
    /// @param k - kontakt pointere
    void hozzaad(Kontakt* k);

    /// Egy elem törlése a nyilvántartásból.
    /// @param k - kontakt pointere
    void torol(Kontakt* k);

    /// Egész nyilvántartás törlése.
    void torol();

    /// Méret lekérdezése.
    size_t get_meret();

    /// Nyilvántartás adatainak listázása (kiíratása),
    /// amiben van egy kis kereső is, csak azokat az objektumokat
    /// listázza ki, amiben az "adat" szerepel az objektum "tipus" szerinti
    /// (vez, ker, cim, mun, pri, bec, beo) tulajdonságában.
    /// @param adat - string, default: ""
    /// @param tipus - string, default: ""
    /// @param os - output stream, default: cout
    void listaz(string adat = "", string tipus = "", ostream& os = cout);

    /// Generikus keresőfüggvény.
    /// @param P - predikátumfüggvény típusa
    /// @param pre - predikátumfüggvény
    /// @param os - output stream, default: cout
    template <typename P>
    void keres(P pre, ostream& os = cout) {
        size_t cnt = 0;
        for(size_t i = 0; i < meret; i++) {
            if(pre(lista[i])) {
                lista[i]->kiir(os);
                cnt++;
            }
        }
        if(cnt == 0) cout << "Nincs talalat.." << endl;
    }

    /// Adatok fájlba írása.
    /// @param fajl - fájl neve, default: "nyilvantartas.dat"
    void mentes(const string& fajl = "nyilvantartas.dat");
    /// Adatok betöltése fájlból.
    /// @param fajl - fájl neve, default: "nyilvantartas.dat"
    void betoltes(const string& fajl = "nyilvantartas.dat");
    /// Értékadás.
    /// @param t - telefonkonyv referenciája
    Telefonkonyv& operator=(const Telefonkonyv& t);
    /// Indexelés.
    /// @param i - index
    Kontakt* operator[](size_t i);
    /// Destruktor.
    ~Telefonkonyv();
};
/// Néhány predikátumfüggvény kereséshez.
// vezetéknevének kezdőbetűje ...
bool A_kezd_vez(Kontakt* k);
bool B_kezd_vez(Kontakt* k);
bool N_kezd_vez(Kontakt* k);
bool K_kezd_vez(Kontakt* k);
// foglalkozása ...
bool tanar (Kontakt* k);
bool postas (Kontakt* k);

#endif // TELEFONKONYV_H_INCLUDED
