#include <string.h>
#include <stdlib.h>
#include "../utils/utils.h"


char* get_tip(Oferta* oferta)
{
    return oferta->tip;
}

char* get_destinatie(Oferta* oferta)
{
    return oferta->destinatie;
}

char* get_data(Oferta* oferta)
{
    return oferta->data;
}

char* get_zi(char* data, char* zi){
    strncpy(zi, data, 2);
    zi[2] = '\0';
    return zi;
}

char* get_luna(char* data, char* luna){
    strncpy(luna, data+3, 2);
    luna[2] = '\0';
    return luna;
}

char* get_an(char* data, char* an){
    strcpy(an, data+6);
    return an;
}

int get_pret(Oferta* oferta)
{
    return oferta->pret;
}

void set_tip(Oferta* oferta, char* tip){
    //oferta->tip = tip;
    strcpy(oferta->tip, tip);
}

void set_destinatie(Oferta* oferta, char* destinatie){
    //oferta->destinatie = destinatie;
    strcpy(oferta->destinatie, destinatie);
}

void set_data(Oferta* oferta, char* data){
    //oferta->data = data;
    strcpy(oferta->data, data);
}

void set_pret(Oferta* oferta, int pret){
    oferta->pret = pret;
}

Oferta* CreeazaOferta(char tip[], char destinatie[], char data[], int pret)
{
    Oferta* oferta = (Oferta*) malloc(sizeof(Oferta));
    oferta->tip = (char*)malloc(40);
    oferta->destinatie = (char*) malloc(40);
    oferta->data = (char*)malloc(11);
    set_tip(oferta, tip);
    set_destinatie(oferta, destinatie);
    set_data(oferta, data);
    set_pret(oferta, pret);
    return oferta;
}

void DistrugeOferta(Oferta* oferta){
    free(oferta->tip);
    free(oferta->destinatie);
    free(oferta->data);
    free(oferta);
}


