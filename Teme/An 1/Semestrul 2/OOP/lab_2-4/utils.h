//
// Created by Știube Denis on 08.03.2024.
//
#include "oferte.h"
#ifndef UTILS_H_
#define UTILS_H_

int Egalitate(Oferta*, Oferta*);
/*
 * Verifica daca 2 oferte sunt egale (toate campurile au valori egale)
 * param1 Oferta*: pointer catre prima oferta de comparat
 * param2 Oferta*: pointer catre a doua oferta de comparat
 * return: 1 daca sunt egale sau 0 daca nu sunt egale
 */

int Cronologic(char[], char[]);
/*
 * Verifica daca 2 date sunt cronologic ordonate
 * param1 char[]: un sir de caractere ce reprezinta o data
 * param2 char[]: un sir de caractere ce reprezinta o data
 * return: 1 daca sunt ordonate cronologic, 0 in caz contrar
 */

#endif