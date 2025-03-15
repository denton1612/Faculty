/*
 * 9. Agentie de turism

Creati o aplicatie care permite gestiunea ofertelor de la o agentie de turism.
Fiecare oferta are: tip (munte, mare, city break), destinatie, data plecare, pret
Aplicatia permite:
 a) Adaugarea de noi oferte.
 b) Actualizare oferte
 c) Stergere oferta
 d) Vizualizare oferte ordonat dupa pret, destinatie (crescator/descrescator)
 e) Vizualizare oferta filtrate dupa un criteriu (destinatie, tip, pret)
 */

#include <stdio.h>
#include "oferte.h"
#include "teste.h"

void Afisare(ListaOferte lista){
    /*
 * Afiseaza continutul listei de oferte
 * param1 ListaOferte: lista de oferte
 * return: -
 */
    if (lista.n == 0)
        printf("Lista este goala! ");
    else
        for (int i = 0; i < lista.n; i++)
            printf("Oferta %d: %s, %s, %s, %d \n", i+1, get_tip(&lista.oferte[i]), get_destinatie(&lista.oferte[i]), get_data(&lista.oferte[i]),
                   get_pret(&lista.oferte[i]));
}

void AdaugaOfertaUI(ListaOferte* lista){
    char tip[20], destinatie[50], data[11];
    int pret;
    printf("Introdceti tipul: ");
    scanf(" %s", tip);
    printf("Introduceti destinatia: ");
    scanf(" %s", destinatie);
    printf("Introduceti data: ");
    scanf(" %s", data);
    printf("Introduceti pretul: ");
    scanf(" %d", &pret);
    Oferta oferta = CreeazaOferta(tip, destinatie, data, pret);
    int valid = ValidareOferta(oferta);
    int dublura = Dublura(lista, oferta);
    if (valid == 0 || dublura == 1)
        printf("Oferta nu este valida!");
    else
        AdaugaOferta(lista, tip, destinatie, data, pret);
}

void StergeOfertaUI(ListaOferte* lista){
    char tip[20], destinatie[50], data[11];
    int pret;
    printf("Introdceti tipul: ");
    scanf(" %s", tip);
    printf("Introduceti destinatia: ");
    scanf(" %s", destinatie);
    printf("Introduceti data: ");
    scanf(" %s", data);
    printf("Introduceti pretul: ");
    scanf(" %d", &pret);
    Oferta oferta = CreeazaOferta(tip, destinatie, data, pret);
    if (GasesteOferta(lista, oferta) != -1)
        StergeOferta(lista, tip, destinatie, data, pret);
    else
        printf("Nu exista oferta in lista de oferte!\n");
}

void ModificaOfertaUI(ListaOferte* lista){
    char tip[20], destinatie[50], data[11];
    int pret;
    printf("Introdceti tipul: ");
    scanf(" %s", tip);
    printf("Introduceti destinatia: ");
    scanf(" %s", destinatie);
    printf("Introduceti data: ");
    scanf(" %s", data);
    printf("Introduceti pretul: ");
    scanf("% d", &pret);
    Oferta oferta_veche = CreeazaOferta(tip, destinatie, data, pret); // !! de modificat - nu este pt ui
    printf("Introdceti tipul nou: ");
    scanf(" %s", tip);
    printf("Introduceti destinatia nou: ");
    scanf(" %s", destinatie);
    printf("Introduceti data nou: ");
    scanf(" %s", data);
    printf("Introduceti pretul nou: ");
    scanf(" %d", &pret);
    Oferta oferta_noua = CreeazaOferta(tip, destinatie, data, pret); // !! de modificat - nu este pt ui
    if (GasesteOferta(lista, oferta_veche) != -1 && ValidareOferta(oferta_noua) == 1)
        ModificaOferta(lista, oferta_veche, oferta_noua);
    else if (GasesteOferta(lista, oferta_veche) == -1)
        printf("Nu exista oferta in lista de oferte!");
    else if (ValidareOferta(oferta_noua) == 0)
        printf("Valorile nu sunt valide pentru oferta noua!");
}

void SortarePretOfertaUI(ListaOferte lista){
    char mini_optiune;
    printf("0/1:\n");
    scanf(" %c", &mini_optiune);
    if (mini_optiune == '0'){
        ListaOferte lista_sortata = SortarePret(lista, 0);
        Afisare(lista_sortata);
    }
    else if (mini_optiune == '1'){
        ListaOferte lista_sortata = SortarePret(lista, 1);
        Afisare(lista_sortata);
    }
}

void SortareDataOfertaUI(ListaOferte lista){
    char mini_optiune;
    printf("0/1:\n");
    scanf(" %c", &mini_optiune);
    if (mini_optiune == '0'){
        ListaOferte lista_sortata = SortareData(lista, 0);
        Afisare(lista_sortata);
    }
    else if (mini_optiune == '1'){
        ListaOferte lista_sortata = SortareData(lista, 1);
        Afisare(lista_sortata);
    }
}

void FiltruPretUI(ListaOferte lista){
    char mini_optiune;
    int PretLimita;
    printf("0/1:\n");
    scanf(" %c", &mini_optiune);
    printf("Introduceti pretul limita:\n");
    scanf(" %d", &PretLimita);
    if (mini_optiune == '0'){
        ListaOferte lista_filtrata = FiltruPret(lista, PretLimita, 0);
        Afisare(lista_filtrata);
    }
    else if (mini_optiune == '1'){
        ListaOferte lista_filtrata = FiltruPret(lista, PretLimita, 1);
        Afisare(lista_filtrata);
    }
}

void FiltruTipUI(ListaOferte lista){
    char tip[20];
    printf("Introduceti tipul dorit: ");
    scanf(" %s", tip);
    ListaOferte lista_filtrata = FiltruTip(lista, tip);
    Afisare(lista_filtrata);
}

void FiltruDataUI(ListaOferte lista){
    char data[11];
    printf("Introduceti data dorita: ");
    scanf(" %s", data);
    ListaOferte lista_filtrata = FiltruData(lista, data);
    Afisare(lista_filtrata);
}

void Meniu(){
    printf(" 1. Adaugare oferta\n 2. Stergere oferta\n 3. Modificare oferta\n 4. Afisare dupa pret (cr = 0/descr = 1)\n 5. Afisare dupa "
           "data (cronologic = 0, altfel 1\n 6. Filtrare pret (minim = 0/maxim = 1)\n 7. Filtrare tip\n 8. Filtrare data");
}

int main(){
    ListaOferte lista = CreeazaVid();
    AllTests();
    while (1){
        char optiune;
        printf("Introduceti o optiune: \n");
        scanf(" %c", &optiune);

        if (optiune == 'e')
            break;

        if (optiune == 'a')
            Afisare(lista);

        if (optiune == 'm')
            Meniu();

        if (optiune == '1')
            AdaugaOfertaUI(&lista);

        if (optiune == '2')
            StergeOfertaUI(&lista);

        if (optiune == '3')
            ModificaOfertaUI(&lista);

        if (optiune == '4')
            SortarePretOfertaUI(lista);

        if (optiune == '5')
            SortareDataOfertaUI(lista);

        if (optiune == '6')
            FiltruPretUI(lista);

        if (optiune == '7')
            FiltruTipUI(lista);

        if (optiune == '8')
            FiltruDataUI(lista);

        printf("\n");
    }
}
