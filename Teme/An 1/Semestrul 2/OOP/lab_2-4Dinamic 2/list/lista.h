//
// Created by Știube Denis on 12.03.2024.
//
#include "../domain/oferte.h"

#ifndef LAB_2_4_LISTA_H
#define LAB_2_4_LISTA_H

typedef struct{
    Oferta** oferte;
    int n;
    int cp;
} ListaOferte;

/*
* Creeaza o lista de oferte vida (lungime = 0)
* return: pointer catre lista vida de oferte (ListaOferte)
*/
ListaOferte* CreeazaVid();

/*
 * Distruge lista de oferte
 * return: -
 */
void DistrugeLista(ListaOferte*);

/*
* Adauga in lista de oferte o oferta noua
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 Oferta: oferta ce trebuie adaugata
* return: 0 daca s-a adaugat oferta, -1 altfel (oferta deja era in lista)
*/
int AdaugaOferta(ListaOferte*, Oferta*);

/*
 * Creste capacitatea listei de 2 ori
 * param1 ListaOferte*: referinta catre lista de oferte
 * return: -
 */
void RedimensionareLista(ListaOferte*);

/*
* Sterge o oferta din lista de oferte
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 int: pozitia ofertei ce va fi stearsa in lista (indexare de la 1)
* return: 0 daca oferta a fost stearsa, -1 in caz contrar
*/
int StergeOferta(ListaOferte*, int);

/*
* Modifica o oferta din lista de oferte
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 int: pozitia ofertei ce va fi modificata in lista (indexare de la 1)
* param3 Oferta*: oferta modificata
* return: 0 daca oferta a fost modificata, -1 altfel
*/
int ModificaOferta(ListaOferte*, int, Oferta*);

/*
* Verifica daca o oferta este in lista de oferte
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 Oferta: adresa din memorie a ofertei folosite pentru cautare
* return: 1 daca oferta exista, 0 in caz contrar
*/
int GasesteOferta(ListaOferte*, Oferta);

#endif //LAB_2_4_LISTA_H
