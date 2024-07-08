/**
 * \file telefonkonyv_main.cpp
 *
 * Egyszerű tesztprogram a Jporta "NHF4 - Skeleton" bemutatásához.
 *
 * Feladat:
 *   Dinamikus nyilvántartás megvalósítása heterogén kollekcióval.
 *
 */

#include <iostream>
#include "memtrace.h"
#include "telefonkonyv.h"

/// Kivételosztály a tesztesetekhez.
class Hiba {
public:
    /// @param - nem használjuk semmire
    Hiba(const string&) {}
};

/// TESZT 1
/// fájlból beolvassa a tároló adatait,
/// majd azokat kiírja a standard outputra.
void teszt_1() {
    Telefonkonyv t;
    t.betoltes("teszt.dat");
    t.mentes("real.dat");
    // Itt megtörtént egy mentés is

    Telefonkonyv t2;

    cout << TESZT_1_FAKE;
    t.betoltes("fake.dat");
    // Itt egy nem létező fájlból próbálunk betölteni adatokat, hibaüzenetet fogunk rá kapni

    cout << TESZT_1_REAL;
    t.betoltes("real.dat");
    t.listaz();
}

/// TESZT 2
/// hozzáad a listához néhány kontaktot,
/// ezután kiírja ezeket a standard outputra,
/// majd töröl pár adatot és ismét kiír,
/// végül az egész listát törli és ismét megpróbál kiírni.
void teszt_2() {
    Telefonkonyv t;
    Kontakt* k = new Kontakt("Boro", "Zoltan", "Budapest Szent Gellert ter 91.", "", "+36 31 561 1659");
    Barat* b = new Barat("Bac", "Ilus", "Miske Dayka Gabor utca 46.", "+36 20 792 9904", "+36 70 803 4653", "Baci");
    Munkatars* m = new Munkatars("Bubo", "Bubo", "Vese Nanasi ut 62.", "+36 31 274 8403", "+36 50 193 9592", "Haziorvos");
    Munkatars* m2 = new Munkatars("Lev", "Elek", "Atany Erzsebet ter 90.", "+36 31 292 6696", "+36 20 861 0424", "Postas");

    cout << TESZT_2_ADD;
    t.hozzaad(k);
    // Zoltán jelenleg munkát keres, ezért jelenleg nincsen munkahelyi száma,
    // ezt listázásnál látni is fogjuk
    t.hozzaad(b);
    t.hozzaad(m);
    t.hozzaad(m2);
    t.hozzaad(m2);
    // Eleket szándékosan kétszer próbáljuk meg felvenni a nyilvántartásba,
    // azonban amint majd látjuk is csak egyszer fog szerepelni a listában
    t.listaz();
    cout << endl;

    cout << TESZT_2_REMOVE;
    t.torol(m);
    t.torol(b);
    t.torol(b);
    // Ilust véletlenül ismét törölni próbáljuk, pedig ekkor már nem szerepel a listán, itt is hibaüzenetet kapunk
    t.listaz();
    cout << endl;

    cout << TESZT_2_DELETE;
    t.torol();
    // A nyilvántartás most teljesen üres, itt is hibaüzenetet fogunk kapni
    t.listaz();
    cout << endl;

    delete k;
    delete b;
    delete m;
    delete m2;
}

/// TESZT 3
/// fájlból beolvas egy tárolóba,
/// majd másoló konstuktorral és értékadó operátorral
/// csinál egy-egy új tárolót és mindhárom elemeit kiírja.
void teszt_3() {
    cout << TESZT_3_LOAD;
    Telefonkonyv t;
    t.betoltes("teszt.dat");
    t.listaz();

    cout << TESZT_3_COPY;
    Telefonkonyv t2 = t;
    t2.listaz();

    cout << TESZT_3_VAL;
    Telefonkonyv t3;
    t3 = t;
    t3.listaz();
}


/// TESZT 4
/// fájlból beolvas egy tárolóba, kiírja az adatokat, majd
/// keresi a "B" betűvel kezdődő vezetéknevűeket, kiírja a találatokat
/// aztán azokat a munkatársakat keresi és listázza ki, akik postásként dolgoznak
void teszt_4() {
    Telefonkonyv t;
    t.betoltes("teszt.dat");

    cout << TESZT_4_MIND;
    t.listaz();

    cout << TESZT_4_B;
    t.keres(B_kezd_vez);

    cout << TESZT_4_POSTAS;
    t.keres(postas);

}

/// Fõprogram a standard inputról olvas egy egész számot,
/// majd meghivja az annak megfelelő tesztesetet.
int main() {
    cout << START;
    int teszteset;
    while (cin >> teszteset && teszteset > 0) {
        try {
            switch (teszteset) {
                case 1:
                    cout << "TESZT 1." << endl; // mentés, betöltés és kiírás tesztelése
                    teszt_1();
                    cout << endl;
                    break;
                case 2:
                    cout << "TESZT 2." << endl; // hozzáadás és törlés tesztelése
                    teszt_2();
                    cout << endl;
                    break;
                case 3:
                    cout << "TESZT 3." << endl; // másolás és értékadás tesztelése
                    teszt_3();
                    cout << endl;
                    break;
                case 4:
                    cout << "TESZT 4." << endl; // generikus keresés tesztelése
                    teszt_4();
                    cout << endl;
                    break;
                default:
                    cout << NINCS_TESZT;
            }
        // kivételkezelés
        } catch (std::exception& e) {
            cerr << e.what() << endl;
        } catch (Hiba&) {
            cerr << SAJAT_KIVETEL << endl;
        } catch (...) {
            cerr << NAGY_BAJ << endl;
        }
    }

	return 0;
}
