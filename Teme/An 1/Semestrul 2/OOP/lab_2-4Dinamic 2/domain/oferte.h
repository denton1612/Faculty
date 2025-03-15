#pragma once

typedef struct{
    char* tip;
    char* destinatie;
    char* data;
    int pret;
} Oferta;

/*
 * Returneaza tipul unei oferte
 * param Oferta*: pointer catre o variabile de tip Oferta
 * return: tip (char[])
 */
char* get_tip(Oferta*);

/*
 * Returneaza destinatia unei oferte
 * param Oferta*: pointer catre o variabile de tip Oferta
 * return: destiantie (char[])
 */
char* get_destinatie(Oferta*);

/*
 * Returneaza data unei oferte
 * param Oferta*: pointer catre o variabile de tip Oferta
 * return: data (char[])
 */
char* get_data(Oferta*);

/*
* Returneaza ziua unei date
* param char[]: sir de caractere ce reprezinta data
* param char*: pointer catre char (pointer catre zona unde se salveaza ziua)
* return: ziua (char*)
*/
char* get_zi(char*, char*);

/*
* Returneaza luna unei date
* param char[]: sir de caractere ce reprezinta data
* param char*: pointer catre char (pointer catre zona unde se salveaza luna)
* return: luna (char*)
*/
char* get_luna(char*, char*);

/*
* Returneaza anul unei date
* param char[]: sir de caractere ce reprezinta data
* param char*: pointer catre char (pointer catre zona unde se salveaza anul)
* return: an (char*)
*/
char* get_an(char*, char*);

/*
 * Returneaza pretul unei oferte
 * param Oferta*: pointer catre o variabile de tip Oferta
 * return: pret (int) > 0
 */
int get_pret(Oferta*);

/*
 * Seteaza tipul unei oferte cu o noua valoare
 * param1 Oferta*: referinta catre oferta
 * param2 char[]: char ce contine noul tip
 * return: -
 */
void set_tip(Oferta*, char*);

/*
 * Seteaza destinatia unei oferte cu o noua valoare
 * param1 Oferta*: referinta catre oferta
 * param2 char[]: char ce contine noua destinatie
 * return: -
 */
void set_destinatie(Oferta*, char*);

/*
 * Seteaza data unei oferte cu o noua valoare
 * param1 Oferta*: referinta catre oferta
 * param2 char[]: char ce contine noua data
 * return: -
 */
void set_data(Oferta*, char*);

/*
 * Seteaza pretul unei oferte cu o noua valoare
 * param1 Oferta*: referinta catre oferta
 * param2 int: char ce contine noul pret
 * return: -
 */
void set_pret(Oferta*, int);

/*
 * Creeaza o oferta cu parametrii dati functiei
 * param1 char[]: sir de caractere ce contine tipul
 * param2 char[]: sir de caractere ce contine destinatia
 * param3 char[]: sir de caractere ce contine data
 * param4 int: pretul
 * return: oferta (Oferta)
 */
Oferta* CreeazaOferta(char[], char[], char[], int);

/*
 * Distruge o oferta
 * param 1 Oferta*: referinta catre oferta (stocata pe heap)
 * return: -
 */
void DistrugeOferta(Oferta*);
