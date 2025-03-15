//
// Created by Știube Denis on 18.03.2024.
//

#include "../utils/utils.h"
#include "../domain/oferte.h"
#include "../list/lista.h"
#include "../service/service.h"
#include <stdio.h>

void Afisare(ListaOferte lista){
    if (lista.n == 0)
        printf("Lista este goala!\n");
    else
        for (int i = 0; i < lista.n; i++)
            printf("Oferta %d: %s, %s, %s, %d \n", i+1, get_tip(lista.oferte[i]), get_destinatie(lista.oferte[i]), get_data(lista.oferte[i]),
                   get_pret(lista.oferte[i]));
}

void AdaugaOfertaUI(ListaOferte* lista){
    char tip[20], destinatie[50], data[11];
    int pret;
    printf("Introduceti tipul: ");
    scanf(" %s", tip);
    printf("Introduceti destinatia: ");
    scanf(" %s", destinatie);
    printf("Introduceti data: ");
    scanf(" %s", data);
    printf("Introduceti pretul: ");
    scanf(" %d", &pret);
    int adaugare = AdaugaOfertaService(lista, tip, destinatie, data, pret);
    while (adaugare == -1){
        printf("Nu s-a putut efectua adaugarea!\n");
        printf("Introdceti tipul: ");
        scanf(" %s", tip);
        printf("Introduceti destinatia: ");
        scanf(" %s", destinatie);
        printf("Introduceti data: ");
        scanf(" %s", data);
        printf("Introduceti pretul: ");
        scanf(" %d", &pret);
        adaugare = AdaugaOfertaService(lista, tip, destinatie, data, pret);
    }
    printf("Adaugare facuta cu SUCCES!\n");
}

void StergeOfertaUI(ListaOferte* lista){
    int poz;
    printf("Introduceti pozitia ofertei ce va fi stearsa: ");
    scanf(" %d", &poz);
    int stergere = StergeOfertaService(lista, poz);
    while (stergere == -1){
        printf("Nu s-a putut efectua stergerea!\n");
        printf("Introduceti pozitia ofertei ce va fi stearsa: ");
        scanf(" %d", &poz);
        stergere = StergeOfertaService(lista, poz);
    }
    printf("Stergere facuta cu SUCCES!\n");
}

void ModificaOfertaUI(ListaOferte* lista){
    char tip[20], destinatie[50], data[11];
    int pret, poz;
    printf("Introduceti pozitia ofertei ce va fi modificata: ");
    scanf(" %d", &poz);
    printf("Introdceti tipul: ");
    scanf(" %s", tip);
    printf("Introduceti destinatia: ");
    scanf(" %s", destinatie);
    printf("Introduceti data: ");
    scanf(" %s", data);
    printf("Introduceti pretul: ");
    scanf(" %d", &pret);
    int modificare = ModificaOfertaService(lista, tip, destinatie, data, pret, poz);
    while (modificare == -1){
        printf("Nu s-a putut efectua modificarea!\n");
        printf("Introduceti pozitia ofertei ce va fi sterse: ");
        scanf(" %d", &poz);
        printf("Introdceti tipul: ");
        scanf(" %s", tip);
        printf("Introduceti destinatia: ");
        scanf(" %s", destinatie);
        printf("Introduceti data: ");
        scanf(" %s", data);
        printf("Introduceti pretul: ");
        scanf(" %d", &pret);
        modificare = ModificaOfertaService(lista, tip, destinatie, data, pret, poz);
    }
    printf("Modificare facuta cu SUCCES!\n");
}

void SortarePretOfertaUI(ListaOferte* lista){
    char mini_optiune;
    printf("0/1:\n");
    scanf(" %c", &mini_optiune);
    int(*f)(Oferta*, Oferta*) = MaiMic;
    if (mini_optiune == '0'){
        SortareGenerica(lista, f, 0);
        Afisare(*lista);
    }
    else if (mini_optiune == '1'){
        SortareGenerica(lista, f, 1);
        Afisare(*lista);
    }
}

void SortareDataOfertaUI(ListaOferte* lista){
    char mini_optiune;
    printf("0/1:\n");
    scanf(" %c", &mini_optiune);
    if (mini_optiune == '0'){
        SortareGenerica(lista, MaiMicData, 0);
        Afisare(*lista);
    }
    else if (mini_optiune == '1'){
        SortareGenerica(lista, MaiMicData, 1);
        Afisare(*lista);
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
        ListaOferte* lista_filtrata = FiltruPret(lista, PretLimita, 0);
        Afisare(*lista_filtrata);
        DistrugeLista(lista_filtrata);
    }
    else if (mini_optiune == '1'){
        ListaOferte* lista_filtrata = FiltruPret(lista, PretLimita, 1);
        Afisare(*lista_filtrata);
        DistrugeLista(lista_filtrata);
    }

}

void FiltruTipUI(ListaOferte lista){
    char tip[20];
    printf("Introduceti tipul dorit: ");
    scanf(" %s", tip);
    ListaOferte* lista_filtrata = FiltruTip(lista, tip);
    Afisare(*lista_filtrata);
    DistrugeLista(lista_filtrata);
}

void FiltruDataUI(ListaOferte lista){
    char data[11];
    printf("Introduceti data dorita: ");
    scanf(" %s", data);
    ListaOferte* lista_filtrata = FiltruData(lista, data);
    Afisare(*lista_filtrata);
    DistrugeLista(lista_filtrata);
}

void Meniu(){
    printf(" 1. Adaugare oferta\n 2. Stergere oferta\n 3. Modificare oferta\n 4. Afisare dupa pret (cr = 0/descr = 1)\n 5. Afisare dupa "
           "data (cronologic = 0, altfel 1)\n 6. Filtrare pret (minim = 0/maxim = 1)\n 7. Filtrare tip\n 8. Filtrare data\n");
}

void run(ListaOferte* lista){
    Meniu();
    while (1){
        char optiune;
        printf("Introduceti o optiune: ");
        scanf(" %c", &optiune);

        if (optiune == 'e')
            break;

        else if (optiune == 'a')
            Afisare(*lista);

        else if (optiune == 'm')
            Meniu();

        else if (optiune == '1')
            AdaugaOfertaUI(lista);

        else if (optiune == '2')
            StergeOfertaUI(lista);

        else if (optiune == '3')
            ModificaOfertaUI(lista);

        else if (optiune == '4')
            SortarePretOfertaUI(lista);

        else if (optiune == '5')
            SortareDataOfertaUI(lista);

        else if (optiune == '6')
            FiltruPretUI(*lista);

        else if (optiune == '7')
            FiltruTipUI(*lista);

        else if (optiune == '8')
            FiltruDataUI(*lista);

        else
            printf("Nu exista optiunea!\n");

    }
    DistrugeLista(lista);
}
