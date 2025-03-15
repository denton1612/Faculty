//
// Created by Știube Denis on 12.03.2024.
//

#include "lista.h"
#include "../utils/utils.h"
#include <stdlib.h>
#include <stdio.h>


ListaOferte* CreeazaVid(){
    ListaOferte* lista = (ListaOferte*)malloc(sizeof(ListaOferte));
    lista->cp = 2;
    lista->oferte = (Oferta**)malloc(lista->cp*sizeof(Oferta*));
    lista->n = 0;
    return lista;
}

void DistrugeLista(ListaOferte* lista){
    for (int i = 0; i < lista->n; i++){
        DistrugeOferta(lista->oferte[i]);
    }
    free(lista->oferte);
    free(lista);
}

void RedimensionareLista(ListaOferte* lista){
    Oferta** oferte = (Oferta**)malloc(2*(lista->cp)*sizeof(Oferta*));
    for (int i = 0; i < lista->cp; i++){
        oferte[i] = lista->oferte[i];
    }
    lista->cp *= 2;
    free(lista->oferte);
    lista->oferte = oferte;
}

int AdaugaOferta(ListaOferte* l, Oferta* oferta){
    for (int i = 0; i < l->n; i++)
        if (Egalitate(l->oferte[i], oferta))
            return -1;
    if (l->n <= l->cp-1)
        l->oferte[l->n] = oferta;
    else{
        RedimensionareLista(l);
        l->oferte[l->n] = oferta;
    }
    (l->n)++;
    return 0;
}

int GasesteOferta(ListaOferte* l, Oferta oferta){
    int gasit = -1;
    int i;
    for (i = 0; i < l->n; i++)
    {
        if(Egalitate(l->oferte[i], &oferta))
            gasit = i;
    }
    return gasit;
}
/*
int StergeOferta(ListaOferte* l, Oferta oferta){
    int poz = GasesteOferta(l, oferta);
    if (poz == -1)
        return -1; // nu exista oferta
    DistrugeOferta(l->oferte[poz]);
    for (int i = poz; i < (l->n) - 1; i++)
        l->oferte[i] = l->oferte[i+1];
    l->n--;
    return 0;
}
*/

int StergeOferta(ListaOferte* l, int poz){
    if (poz < 1 || poz > l->n)
        return -1; // nu este o pozitie valida in lista
    DistrugeOferta(l->oferte[poz-1]);
    for (int i = poz-1; i < (l->n) - 1; i++)
        l->oferte[i] = l->oferte[i+1];
    l->n--;
    return 0;
}

/*
int ModificaOferta(ListaOferte* l, Oferta* oferta_veche, Oferta* oferta_noua) {
    if (GasesteOferta(l, *oferta_veche) == -1 || GasesteOferta(l, *oferta_noua) != -1)
        return -1;
    set_tip(oferta_veche, get_tip(oferta_noua));
    set_destinatie(oferta_veche, get_destinatie(oferta_noua));
    set_data(oferta_veche, get_data(oferta_noua));
    set_pret(oferta_veche, get_pret(oferta_noua));
    return 0;
}
*/

int ModificaOferta(ListaOferte* l, int poz, Oferta* oferta_noua){
    if (poz < 1 || poz > l->n || GasesteOferta(l, *oferta_noua) != -1)
        return -1; // nu este o pozitie valida in lista
    Oferta* oferta_veche = l->oferte[poz-1];
    set_tip(oferta_veche, get_tip(oferta_noua));
    set_destinatie(oferta_veche, get_destinatie(oferta_noua));
    set_data(oferta_veche, get_data(oferta_noua));
    set_pret(oferta_veche, get_pret(oferta_noua));
    return 0;
}
