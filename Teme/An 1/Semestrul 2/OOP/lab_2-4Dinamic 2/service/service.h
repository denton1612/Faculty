//
// Created by Știube Denis on 12.03.2024.
//
#include "../list/lista.h"

#ifndef LAB_2_4_SERVICE_H
#define LAB_2_4_SERVICE_H

/*
* Adauga in lista de oferte o oferta noua
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 char[]: sir de caractere ce contine tipul
* param3 char[]: sir de caractere ce contine destinatia
* param4 char[]: sir de caractere ce contine data
* param5 int: pretul
* return: -
*/
int AdaugaOfertaService(ListaOferte*, char[], char[], char[], int);

/*
* Sterge o oferta din lista de oferte
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 char[]: sir de caractere ce contine tipul
* param3 char[]: sir de caractere ce contine destinatia
* param4 char[]: sir de caractere ce contine data
* param5 int: pretul
* return: -
*/
int StergeOfertaService(ListaOferte*, int);

/*
* Modifica o oferta din lista de oferte
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 Oferta: oferta de modificat
* param3 Oferta: oferta modificata
* return: - (modifica lista de oferte din memorie)
*/
int ModificaOfertaService(ListaOferte*, char[], char[], char[], int, int);

/*
* Sorteaza lista (o copie a ei) dupa pret (cr/descr)
* param1 ListaOferte: copia listei de oferte ce va fi sortata
* param2 int: 0 (cr) sau 1 (descr)
* return: lista de oferte sortata dupa pret (copie)
*/
void SortarePret(ListaOferte*, int);

/*
* Sorteaza lista (o copie a ei) dupa data (cr/descr)
* param1 ListaOferte: copia listei de oferte ce va fi sortata
* param2 int: 0 (cr) sau 1 (descr)
* return: lista de oferte sortata dupa data (copie)
*/
void SortareData(ListaOferte*, int);

/*
 * Sorteaza lista folosind o functie de comparat obiecte
 * param1 ListaOferte*: pointer catre lista de oferte
 * param2 int(*f)(Oferta*, Oferta*): functia de comparatie
 * param3 int: 0 (cr) sau 1 (descr)
 */
void SortareGenerica(ListaOferte*, int(*f)(Oferta*, Oferta*), int);

/*
* Returneaza lista de oferte filtrata dupa pret (maxim/minim)
* param1 ListaOferte: copia listei de oferte filtrata
* param2 int: pretul folosit ca filtru
* param3 int: 0 (pret minim) sau 1 (pret maxim)
* return: pointer catre lista de oferte filtrata dupa pret (copie)
*/
ListaOferte* FiltruPret(ListaOferte, int, int);

/*
* Returneaza lista de oferte filtrata dupa tip
* param1 ListaOferte: copia listei de oferte filtrata
* param2 char[]: sir de caractere ce contine tipul dorit
* return: pointer catre lista de oferte filtrata dupa tip (copie)
*/
ListaOferte* FiltruTip(ListaOferte, char[]);

/*
* Returneaza lista de oferte filtrata dupa data
* param1 ListaOferte: copia listei de oferte filtrata
* param2 char[]: sir de caractere ce contine data dorita
* return: pointer catre lista de oferte filtrata dupa data (copie)
*/
ListaOferte* FiltruData(ListaOferte, char[]);

/*
* Verifica daca o oferta are campurile valide
* param1 Oferta: oferta ce trebuie validata
* return: 1 daca este valida oferta, 0 in caz contrar
*/
int ValidareOferta(Oferta);

/*
 * Verifica daca tipul de oferta este valid
 * param1 tip: tipul de verificat
 * return: 1 daca este valid, 0 altfel
 */
int ValidareTip(char[]);

/*
 * Verifica daca pretul ofertei este valid
 * param1 pret: pretul de verificat
 * return: 1 daca este valid, 0 altfel
 */
int ValidarePret(int);

/*
* Verifica daca data unei oferte este valida
* param1 tip: data de verificat
* return: 1 daca este valida, 0 altfel
*/
int ValidareData(char[]);

/*
* Verifica daca oferta exista deja in lista de oferte
* param1 ListaOferte*: contine adresa din memorie a listei de oferte
* param2 Oferta: oferta de verificat
* return: 1 daca este deja in lista, 0 in caz contrar
*/
int Dublura(ListaOferte*, Oferta);


#endif //LAB_2_4_SERVICE_H
