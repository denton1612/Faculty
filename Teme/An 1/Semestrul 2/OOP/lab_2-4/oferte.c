#include <string.h>
#include <stdio.h>
#include "utils.h"


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

char* get_zi(char data[], char* zi){
    strncpy(zi, data, 2);
    zi[2] = '\0';
    return zi;
}

char* get_luna(char data[], char* luna){
    strncpy(luna, data+3, 2);
    luna[2] = '\0';
    return luna;
}

char* get_an(char data[], char* an){
    strcpy(an, data+6);
    return an;
}

int get_pret(Oferta* oferta)
{
    return oferta->pret;
}

void set_tip(Oferta* oferta, char tip[]){
    strcpy(oferta->tip, tip);
}

void set_destinatie(Oferta* oferta, char destinatie[]){
    strcpy(oferta->destinatie, destinatie);
}

void set_data(Oferta* oferta, char data[]){
    strcpy(oferta->data, data);
}

void set_pret(Oferta* oferta, int pret){
    oferta->pret = pret;
}

Oferta CreeazaOferta(char tip[], char destinatie[], char data[], int pret)
{
    Oferta oferta;
    strcpy(oferta.tip, tip);
    strcpy(oferta.destinatie, destinatie);
    strcpy(oferta.data, data);
    oferta.pret = pret;
    return oferta;
}

ListaOferte CreeazaVid(){
    ListaOferte lista;
    lista.n = 0;
    return lista;
}

void AdaugaOferta(ListaOferte* l, char tip[], char destinatie[], char data[], int pret){
    l->oferte[l->n] = CreeazaOferta(tip, destinatie, data, pret);
    (l->n)++;
}

int GasesteOferta(ListaOferte* l, Oferta oferta){
    int gasit = -1;
    int i;
    for (i = 0; i < l->n; i++)
    {
        if(Egalitate(&(l->oferte[i]), &oferta))
            gasit = i;
    }
    return gasit;
}

void StergeOferta(ListaOferte* l, char tip[], char destinatie[], char data[], int pret){
    int i;
    Oferta oferta = CreeazaOferta(tip, destinatie, data, pret);
    for (i = GasesteOferta(l, oferta); i < (l->n) - 1; i++)
        l->oferte[i] = l->oferte[i + 1];
    l->n--;
}

/*void StergeOfertaIndice(ListaOferte* l, int poz){
    if (poz >= l->n)
        printf("Nu exista oferta in lista de oferte!\n");
    else{
        for (int i = poz; i < (l->n) - 1; i++)
            l->oferte[i] = l->oferte[i + 1];
        l->n--;
    }
}
*/
void ModificaOferta(ListaOferte* l, Oferta oferta_veche, Oferta oferta_noua) {
    Oferta *o = &(l->oferte[GasesteOferta(l, oferta_veche)]);
    set_tip(o, get_tip(&oferta_noua));
    set_destinatie(o, get_destinatie(&oferta_noua));
    set_data(o, get_data(&oferta_noua));
    set_pret(o, get_pret(&oferta_noua));

}

ListaOferte SortarePret(ListaOferte lista, int crescator){
    int sortat = 0;
    while (!sortat) {
        sortat = 1;
        for (int i = 0; i < lista.n - 1; i++)
            if (crescator == 0) {
                if (get_pret(&lista.oferte[i]) > get_pret(&lista.oferte[i+1])){
                    Oferta aux = lista.oferte[i];
                    lista.oferte[i] = lista.oferte[i+1];
                    lista.oferte[i+1] = aux;
                    sortat = 0;
                }
            }
            else {
                if (get_pret(&lista.oferte[i]) < get_pret(&lista.oferte[i+1])){
                    Oferta aux = lista.oferte[i];
                    lista.oferte[i] = lista.oferte[i+1];
                    lista.oferte[i+1] = aux;
                    sortat = 0;
                }
            }
    }
    return lista;
}

ListaOferte SortareData(ListaOferte lista, int cronologic){
    int sortat = 0;
    while (!sortat) {
        sortat = 1;
        for (int i = 0; i < lista.n - 1; i++)
            if (cronologic == 0) {
                if (!Cronologic(get_data(&lista.oferte[i]), get_data(&lista.oferte[i+1]))){
                    Oferta aux = lista.oferte[i];
                    lista.oferte[i] = lista.oferte[i+1];
                    lista.oferte[i+1] = aux;
                    sortat = 0;
                }
            }
            else if (cronologic == 1){
                if (Cronologic(get_data(&lista.oferte[i]), get_data(&lista.oferte[i+1]))){
                    Oferta aux = lista.oferte[i];
                    lista.oferte[i] = lista.oferte[i+1];
                    lista.oferte[i+1] = aux;
                    sortat = 0;
                }
            }
    }
    return lista;
}

ListaOferte FiltruPret(ListaOferte lista, int PretLimita, int maxim){
    ListaOferte lista_filtrata = CreeazaVid();
    int i;
    for (i = 0; i < lista.n; i++){
        if (maxim == 0) {
            if (get_pret(&lista.oferte[i]) >= PretLimita)
                AdaugaOferta(&lista_filtrata, get_tip(&lista.oferte[i]), get_destinatie(&lista.oferte[i]), get_data(&lista.oferte[i]),
                             get_pret(&lista.oferte[i]));
        }
        else{
            if (get_pret(&lista.oferte[i]) <= PretLimita)
                AdaugaOferta(&lista_filtrata, get_tip(&lista.oferte[i]), get_destinatie(&lista.oferte[i]), get_data(&lista.oferte[i]),
                             get_pret(&lista.oferte[i]));
        }
    }
    return lista_filtrata;
}

ListaOferte FiltruTip(ListaOferte lista, char tip[]){
    ListaOferte lista_filtrata = CreeazaVid();
    for (int i = 0; i < lista.n; i++){
        if (!strcmp(get_tip(&lista.oferte[i]), tip))
            AdaugaOferta(&lista_filtrata, get_tip(&lista.oferte[i]), get_destinatie(&lista.oferte[i]), get_data(&lista.oferte[i]),
                         get_pret(&lista.oferte[i]));
    }
    return lista_filtrata;
}

ListaOferte FiltruData(ListaOferte lista, char data[]){
    ListaOferte lista_filtrata = CreeazaVid();
    for (int i = 0; i < lista.n; i++){
        if (!strcmp(get_data(&lista.oferte[i]), data))
            AdaugaOferta(&lista_filtrata, get_tip(&lista.oferte[i]), get_destinatie(&lista.oferte[i]), get_data(&lista.oferte[i]),
                         get_pret(&lista.oferte[i]));
    }
    return lista_filtrata;
}

int ValidareTip(char tip[]){
    int valid = 1;
    char* tip1, *tip2, *tip3;
    tip1 = "munte";
    tip2 = "mare";
    tip3 = "city break";
    if (strcmp(tip, tip1) != 0 && strcmp(tip, tip2) != 0 && strcmp(tip, tip3) != 0)
        valid = 0;
    return valid;
}

int ValidareData(char data[11]){
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

int ValidareOferta(Oferta oferta){
    return ValidareTip(get_tip(&oferta)) * ValidareData(get_data(&oferta));
}

int Dublura(ListaOferte* lista, Oferta oferta){
    int dublura = 0;
    for (int i = 0; i < lista->n; i++){
        if(Egalitate(&oferta, &lista->oferte[i]))
            dublura = 1;
    }
    return dublura;
}



