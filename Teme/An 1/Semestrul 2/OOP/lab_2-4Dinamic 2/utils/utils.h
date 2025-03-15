//
// Created by Știube Denis on 08.03.2024.
//
#include "../domain/oferte.h"
#ifndef UTILS_H_
#define UTILS_H_

/*
 * Verifica daca 2 oferte sunt egale (toate campurile au valori egale)
 * param1 Oferta*: pointer catre prima oferta de comparat
 * param2 Oferta*: pointer catre a doua oferta de comparat
 * return: 1 daca sunt egale sau 0 daca nu sunt egale
 */
int Egalitate(Oferta*, Oferta*);

/*
 * Verifica daca 2 date sunt cronologic ordonate
 * param1 char[]: un sir de caractere ce reprezinta o data
 * param2 char[]: un sir de caractere ce reprezinta o data
 * return: 1 daca sunt ordonate cronologic, 0 in caz contrar
 */
int Cronologic(char[], char[]);

/*
 * Comapara 2 date a 2 oferte
 * param1 Oferta*: pointer catre prima oferta
 * param2 Oferta*: pointer catre a doua oferta
 * return: 1 daca param1 < param2, 0 altfel
 */
int MaiMicData(Oferta*, Oferta*);

/*
 * Comapara 2 numere intregi
 * param1 Oferta*: pointer catre prima oferta
 * param2 Oferta*: pointer catre a doua oferta
 * return: 1 daca param1 < param2, 0 altfel
 */
int MaiMic(Oferta*, Oferta*);

/*
 * Creeaza o copie pe heap a unei oferte
 * param1 Oferta*: adresa din memorie a ofertei de copiat
 * return: pointer catre noua adres
 */
Oferta* CopieOferta(Oferta*);

#endif