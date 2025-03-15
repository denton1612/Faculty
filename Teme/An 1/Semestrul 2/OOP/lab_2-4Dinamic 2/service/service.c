//
// Created by Știube Denis on 12.03.2024.
//

#include "service.h"
#include "../list/lista.h"
#include "../utils/utils.h"
#include <string.h>

int AdaugaOfertaService(ListaOferte* l, char tip[], char destinatie[], char data[], int pret){
    Oferta* oferta = CreeazaOferta(tip, destinatie, data, pret);
    if (!ValidareOferta(*oferta)){
        DistrugeOferta(oferta);
        return -1;
    }
    int adaugare = AdaugaOferta(l, oferta);
    if (adaugare == -1) {
        DistrugeOferta(oferta);
        return -1; // nu a fost validata adaugarea de functia din list
    }
    return 0;
}

int StergeOfertaService(ListaOferte* l, int poz){
    int stergere = StergeOferta(l, poz);
    if (stergere == -1)
        return -1;
    return 0;
}

int ModificaOfertaService(ListaOferte* l, char tip[], char destinatie[], char data[], int pret, int poz) {
    Oferta* oferta = CreeazaOferta(tip, destinatie, data, pret);
    if (!ValidareOferta(*oferta)){
        DistrugeOferta(oferta);
        return -1;
    }
    int modificare = ModificaOferta(l, poz, oferta);
    DistrugeOferta(oferta);
    if (modificare == -1)
        return -1;
    return 0; // oferta modificata s-a pus pe ultima pozitie in lista !! :)))
}

/*
void SortarePret(ListaOferte* lista, int crescator){
    int sortat = 0;
    while (!sortat) {
        sortat = 1;
        for (int i = 0; i < lista->n - 1; i++)
            if (crescator == 0) {
                if (get_pret(lista->oferte[i]) > get_pret(lista->oferte[i+1])){
                    Oferta* aux = lista->oferte[i];
                    lista->oferte[i] = lista->oferte[i+1];
                    lista->oferte[i+1] = aux;
                    sortat = 0;
                }
            }
            else {
                if (get_pret(lista->oferte[i]) < get_pret(lista->oferte[i+1])){
                    Oferta* aux = lista->oferte[i];
                    lista->oferte[i] = lista->oferte[i+1];
                    lista->oferte[i+1] = aux;
                    sortat = 0;
                }
            }
    }
}
void SortareData(ListaOferte* lista, int cronologic){
    int sortat = 0;
    while (!sortat) {
        sortat = 1;
        for (int i = 0; i < lista->n - 1; i++)
            if (cronologic == 0) {
                if (!Cronologic(get_data(lista->oferte[i]), get_data(lista->oferte[i+1]))){
                    Oferta* aux = lista->oferte[i];
                    lista->oferte[i] = lista->oferte[i+1];
                    lista->oferte[i+1] = aux;
                    sortat = 0;
                }
            }
            else {
                if (Cronologic(get_data(lista->oferte[i]), get_data(lista->oferte[i+1]))){
                    Oferta* aux = lista->oferte[i];
                    lista->oferte[i] = lista->oferte[i+1];
                    lista->oferte[i+1] = aux;
                    sortat = 0;
                }
            }
    }
}

*/
void SortareGenerica(ListaOferte* lista, int(*f)(Oferta*, Oferta*), int ordine){
    int sortat = 0;
    while (!sortat) {
        sortat = 1;
        for (int i = 0; i < lista->n - 1; i++)
            if (ordine == 0) {
                if (!f(lista->oferte[i], lista->oferte[i+1])){
                    Oferta* aux = lista->oferte[i];
                    lista->oferte[i] = lista->oferte[i+1];
                    lista->oferte[i+1] = aux;
                    sortat = 0;
                }
            }
            else {
                if (f(lista->oferte[i], lista->oferte[i+1])){
                    Oferta* aux = lista->oferte[i];
                    lista->oferte[i] = lista->oferte[i+1];
                    lista->oferte[i+1] = aux;
                    sortat = 0;
                }
            }
    }
}

ListaOferte* FiltruPret(ListaOferte lista, int PretLimita, int maxim){
    ListaOferte* lista_filtrata = CreeazaVid();
    int i;
    for (i = 0; i < lista.n; i++) {
        if (maxim == 0) {
            if (get_pret(lista.oferte[i]) >= PretLimita) {
                Oferta *oferta = CopieOferta(lista.oferte[i]);
                AdaugaOferta(lista_filtrata, oferta);
            }
        } else {
            if (get_pret(lista.oferte[i]) <= PretLimita) {
                Oferta *oferta = CopieOferta(lista.oferte[i]);
                AdaugaOferta(lista_filtrata, oferta);
            }
        }
    }
    return lista_filtrata;
}

ListaOferte* FiltruTip(ListaOferte lista, char tip[]){
    ListaOferte* lista_filtrata = CreeazaVid();
    for (int i = 0; i < lista.n; i++){
        if (!strcmp(get_tip(lista.oferte[i]), tip)) {
            Oferta *oferta = CopieOferta(lista.oferte[i]);
            AdaugaOferta(lista_filtrata, oferta);
        }
    }
    return lista_filtrata;
}

ListaOferte* FiltruData(ListaOferte lista, char data[]){
    ListaOferte* lista_filtrata = CreeazaVid();
    for (int i = 0; i < lista.n; i++) {
        if (!strcmp(get_data(lista.oferte[i]), data)) {
            Oferta *oferta = CopieOferta(lista.oferte[i]);
            AdaugaOferta(lista_filtrata, oferta);
        }
    }
    return lista_filtrata;
}

int ValidareTip(char tip[]){
    int valid = 1;
    char* tip1, *tip2, *tip3;
    tip1 = "munte";
    tip2 = "mare";
    tip3 = "city-break";
    if (strcmp(tip, tip1) != 0 && strcmp(tip, tip2) != 0 && strcmp(tip, tip3) != 0)
        valid = 0;
    return valid;
}

int ValidareData(char data[]){
    int valid = 1;
    if (strlen(data) != 10)
        valid = 0;
    if (data[2] != '-' || data[5] != '-')
        valid = 0;
    if (strncmp(data+3, "12", 2) > 0)
        valid = 0;
    if (strncmp(data+3, "02", 2) == 0 && strncmp(data, "28", 2) > 0)
        valid = 0;
    if ((data[4]-'0') % 2 == 0){
        if (strncmp(data, "30", 2) > 0)
            valid = 0;
    }
    else{
        if (strncmp(data, "31", 2) > 0)
            valid = 0;
    }
    return valid;
}

int ValidarePret(int pret){
    return pret > 0;
}

int ValidareOferta(Oferta oferta){
    return ValidareTip(get_tip(&oferta)) * ValidareData(get_data(&oferta));
}
