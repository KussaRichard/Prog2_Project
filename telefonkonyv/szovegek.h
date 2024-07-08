/**
 * \file szovegek.h
 *
 * Hibajelzések és kommunikáció a felhasználó felé
 *
 */

#ifndef SZOVEGEK_H_INCLUDED
#define SZOVEGEK_H_INCLUDED

#define TESZT_1_FAKE "\n---[Beolvasas egy nem letezo fajlbol]---\n"
#define TESZT_1_REAL "\n---[Beolvasas egy valid fajlbol es listazas]---\n"

#define TESZT_2_ADD "\n---[Uj kontaktok felvetele a listara majd kiiras]---\n"
#define TESZT_2_REMOVE "\n---[Kontaktok torlese listarol majd kiiras]---\n"
#define TESZT_2_DELETE "\n---[Lista torlese majd kiiras]---\n"

#define TESZT_3_LOAD "\n---[Elso tarolo betoltese fajlbol]---\n"
#define TESZT_3_COPY "\n---[Masodik tarolo masolo konstruktorral]---\n"
#define TESZT_3_VAL "\n---[Harmadik tarolo ertekadassal]---\n"

#define TESZT_4_MIND "\n---[B betuvel kezdodo vezeteknevuek]---\n"
#define TESZT_4_B "\n---[B betuvel kezdodo vezeteknevuek]---\n"
#define TESZT_4_POSTAS "\n---[Postas hivatasuak]---\n"

#define START "Kerek egy szamot: "
#define NINCS_TESZT "\nIlyen teszteset nincsen..\n"
#define SAJAT_KIVETEL "\nSajat kivetel jott..\n"
#define NAGY_BAJ "\nIsmeretlen eredetu hiba!\n"
#define MAR_VAN "\nEz a kontakt mar szerepel a listaban..\n"
#define MEG_NINCS "\nEz a kontakt nincs is a listaban..\n"
#define URES_LISTA "\nA nyilvantartasban nincs adat..\n"
#define NINCS_FAJL "\nA fajl nem letezik vagy nem sikerult megnyitni..\n"


#endif // SZOVEGEK_H_INCLUDED
