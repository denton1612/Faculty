#pragma once

typedef struct{
    char tip[20];
    char destinatie[40];
    char data[11];
    int pret;
} Oferta;

typedef struct{
    Oferta oferte[100];
    int n;
} ListaOferte;

char* get_tip(Oferta*);
/*
 * Returneaza tipul unei oferte
 * param Oferta*: pointer catre o variabile de tip Oferta
 * return: tip (char[])
 */

char* get_destinatie(Oferta*);
/*
 * Returneaza destinatia unei oferte
 * param Oferta*: pointer catre o variabile de tip Oferta
 * return: destiantie (char[])
 */

char* get_data(Oferta*);

/*
 * Returneaza data unei oferte
 * param Oferta*: pointer catre o variabile de tip Oferta
 * return: data (char[])
 */

char* get_zi(char[], char*);
/*
* Returneaza ziua unei date
* param char[]: sir de caractere ce reprezinta data
* param char*: pointer catre char (pointer catre zona unde se salveaza ziua)
* return: ziua (char*)
*/

char* get_luna(char[], char*);
/*
* Returneaza luna unei date
* param char[]: sir de caractere ce reprezinta data
* param char*: pointer catre char (pointer catre zona unde se salveaza luna)
* return: luna (char*)
*/


char* get_an(char[], char*);
/*
* Returneaza anul unei date
* param char[]: sir de caractere ce reprezinta data
* param char*: pointer catre char (pointer catre zona unde se salveaza anul)
* return: an (char*)
*/


int get_pret(Oferta*);
/*
 * Returneaza pretul unei oferte
 * param Oferta*: pointer catre o variabile de tip Oferta
 * return: pret (int) > 0
 */

void set_tip(Oferta*, char[]);

void set_destinatie(Oferta*, char[]);

void set_data(Oferta*, char[]);

void set_pret(Oferta*, int);

Oferta CreeazaOferta(char[], char[], char[], int);
/*
 * Creeaza o oferta cu parametrii dati functiei
 * param1 char[]: sir de caractere ce contine tipul
 * param2 char[]: sir de caractere ce contine destinatia
 * param3 char[]: sir de caractere ce contine data
 * param4 int: pretul
 * return: oferta (Oferta)
 */

ListaOferte CreeazaVid();
/*
* Creeaza o lista de oferte vida (lungime = 0)
* return: o lista vida de oferte (ListaOferte)
*/

void AdaugaOferta(ListaOferte*, char[], char[], char[], int);
/*
* Adauga in lista de oferte o oferta noua
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 char[]: sir de caractere ce contine tipul
* param3 char[]: sir de caractere ce contine destinatia
* param4 char[]: sir de caractere ce contine data
* param5 int: pretul
* return: -
*/

void StergeOferta(ListaOferte*, char[], char[], char[], int);
/*
* Sterge o oferta din lista de oferte
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 char[]: sir de caractere ce contine tipul
* param3 char[]: sir de caractere ce contine destinatia
* param4 char[]: sir de caractere ce contine data
* param5 int: pretul
* return: -
*/

void ModificaOferta(ListaOferte*, Oferta, Oferta);
/*
* Modifica o oferta din lista de oferte
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 Oferta: oferta de modificat
* param3 Oferta: oferta modificata
* return: - (modifica lista de oferte din memorie)
*/

int GasesteOferta(ListaOferte*, Oferta);
/*
* Verifica daca o oferta este in lista de oferte
* param1 ListaOferte*: adresa din memorie a listei de oferte
* param2 Oferta: oferta cautata
* return: 1 daca oferta exista, 0 in caz contrar
*/

ListaOferte SortarePret(ListaOferte, int);
/*
* Sorteaza lista (o copie a ei) dupa pret (cr/descr)
* param1 ListaOferte: copia listei de oferte ce va fi sortata
* param2 int: 0 (cr) sau 1 (descr)
* return: lista de oferte sortata dupa pret (copie)
*/

ListaOferte SortareData(ListaOferte, int);
/*
* Sorteaza lista (o copie a ei) dupa data (cr/descr)
* param1 ListaOferte: copia listei de oferte ce va fi sortata
* param2 int: 0 (cr) sau 1 (descr)
* return: lista de oferte sortata dupa data (copie)
*/

ListaOferte FiltruPret(ListaOferte, int, int);
/*
* Returneaza lista de oferte filtrata dupa pret (maxim/minim)
* param1 ListaOferte: copia listei de oferte filtrata
* param2 int: pretul folosit ca filtru
* param3 int: 0 (pret minim) sau 1 (pret maxim)
* return: lista de oferte filtrata dupa pret (copie)
*/

ListaOferte FiltruTip(ListaOferte, char[]);
/*
* Returneaza lista de oferte filtrata dupa tip
* param1 ListaOferte: copia listei de oferte filtrata
* param2 char[]: sir de caractere ce contine tipul dorit
* return: lista de oferte filtrata dupa tip (copie)
*/

ListaOferte FiltruData(ListaOferte, char[]);
/*
* Returneaza lista de oferte filtrata dupa data
* param1 ListaOferte: copia listei de oferte filtrata
* param2 char[]: sir de caractere ce contine data dorita
* return: lista de oferte filtrata dupa data (copie)
*/

int ValidareOferta(Oferta);
/*
* Verifica daca o oferta are campurile valide
* param1 Oferta: oferta ce trebuie validata
* return: 1 daca este valida oferta, 0 in caz contrar
*/

int ValidareTip(char[]);
/*
 * Verifica daca tipul de oferta este valid
 * param1 tip: tipul de verificat
 * return: 1 daca este valid, 0 altfel
 */


int ValidareData(char[]);
/*
* Verifica daca data unei oferte este valida
* param1 tip: data de verificat
* return: 1 daca este valida, 0 altfel
*/

int Dublura(ListaOferte*, Oferta);
/*
* Verifica daca oferta exista deja in lista de oferte
* param1 ListaOferte*: contine adresa din memorie a listei de oferte
* param2 Oferta: oferta de verificat
* return: 1 daca este deja in lista, 0 in caz contrar
*/

void Afisare(ListaOferte);
/*
* Afiseaza continutul listei de oferte
* param1 ListaOferte: lista de oferte
* return: -
*/