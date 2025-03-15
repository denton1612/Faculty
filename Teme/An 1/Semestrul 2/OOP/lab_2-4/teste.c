//
// Created by Știube Denis on 09.03.2024.
//
#include <string.h>
#include <assert.h>
#include "utils.h"


void test_creare(){
    char tip[] = "munte";
    char destinatie[10] = "Bucegi";
    char data[] = "12-10-2021";
    int pret = 2000;
    char zi[4], luna[4], an[10];
    Oferta oferta = CreeazaOferta(tip, destinatie, data, pret);
    Oferta* pnt = &oferta;
    assert(get_pret(pnt) == 2000);
    assert(strcmp((get_tip(pnt)), "munte") == 0);
    assert(strcmp(get_zi(get_data(pnt), zi), "12") == 0);
    assert(strcmp(get_luna(get_data(pnt), luna), "10") == 0);
    assert(strcmp(get_an(get_data(pnt), an), "2021") == 0);
}

void test_egalitate(){
    char tip[] = "munte";
    char destinatie[] = "Bucegi";
    char data[] = "12-10-2021";
    int pret = 2000;
    char tip1[] = "munte";
    char destinatie1[] = "Bucegi";
    char data1[] = "12-10-2021";
    int pret1 = 2000;
    Oferta oferta1, oferta2;
    oferta1 = CreeazaOferta(tip, destinatie, data, pret);
    oferta2 = CreeazaOferta(tip1, destinatie1, data1, pret1);
    assert(Egalitate(&oferta1, &oferta2) == 1);
}

void test_cronologic(){
    char* data1 = "10-12-2020";
    char* data2 = "11-09-2023";
    assert(Cronologic(data1, data2));
    data1 = "24-12-2004";
    data2 = "09-07-2019";
    assert(!Cronologic(data2, data1));
    data1 = "10-06-2017";
    data2 = "13-06-2017";
    assert(Cronologic(data1, data2));
    data1 = "14-10-2018";
    data2 = "24-11-2018";
    assert(Cronologic(data1, data2));
}

void test_gasit(){
    ListaOferte lista = CreeazaVid();
    Oferta oferta1, oferta2, oferta3;
    char tip[] = "munte";
    char destinatie[] = "Bucegi";
    char data[] = "12-10-2021";
    int pret = 2000;
    char tip1[] = "mare";
    char destinatie1[] = "Bucegi";
    char data1[] = "12-10-2021";
    int pret1 = 2000;
    char tip2[] = "munte";
    char destinatie2[] = "Bucegi";
    char data2[] = "12-10-2021";
    int pret2 = 3000;
    oferta1 = CreeazaOferta(tip, destinatie, data, pret);
    oferta2 = CreeazaOferta(tip1, destinatie1, data1, pret1);
    oferta3 = CreeazaOferta(tip2, destinatie2, data2, pret2);
    AdaugaOferta(&lista, tip1, destinatie1, data1, pret1);
    AdaugaOferta(&lista, tip, destinatie, data, pret);
    assert(GasesteOferta(&lista, oferta1) == 1);
    assert(GasesteOferta(&lista, oferta2) == 0);
    assert(GasesteOferta(&lista, oferta3) == -1);
}

void test_stergere(){
    ListaOferte lista = CreeazaVid();
    char tip[20] = "munte";
    char destinatie[] = "Bucegi";
    char data[] = "12-10-2021";
    int pret = 2000;
    char tip1[20] = "mare";
    char destinatie1[] = "Bucegi";
    char data1[] = "12-10-2021";
    int pret1 = 2000;
    char tip2[] = "munte";
    char destinatie2[] = "Bucegi";
    char data2[] = "12-10-2021";
    int pret2 = 3000;
    AdaugaOferta(&lista, tip1, destinatie1, data1, pret1);
    AdaugaOferta(&lista, tip, destinatie, data, pret);
    assert(lista.n == 2);
    StergeOferta(&lista, tip, destinatie, data, pret);
    assert(lista.n == 1);
    assert(get_pret(&lista.oferte[0]) == 2000);
    assert(strcmp(get_tip(&lista.oferte[0]), "mare") == 0);
}

void test_modificare(){
    ListaOferte lista = CreeazaVid();
    Oferta oferta1, oferta2;
    char tip[20] = "munte";
    char destinatie[] = "Bucegi";
    char data[] = "12-10-2021";
    int pret = 2000;
    oferta1 = CreeazaOferta(tip, destinatie, data, pret);
    char tip1[20] = "mare";
    char destinatie1[] = "Bucegi";
    char data1[] = "12-10-2021";
    int pret1 = 2000;
    AdaugaOferta(&lista, tip1, destinatie1, data1, pret1);
    AdaugaOferta(&lista, tip, destinatie, data, pret);
    assert(lista.n == 2);
    oferta2 = CreeazaOferta("city break", "Londra", "22-09-2024", 3600);
    ModificaOferta(&lista, oferta1, oferta2);
    assert(get_pret(&lista.oferte[1]) == 3600);
    assert(!strcmp(get_tip(&lista.oferte[1]), "city break"));
    assert(lista.n == 2);
}

void test_sortare(){
    ListaOferte lista = CreeazaVid();
    Oferta oferta1, oferta2;
    char tip[20] = "munte";
    char destinatie[] = "Bucegi";
    char data[] = "12-10-2023";
    int pret = 2000;
    char tip1[20] = "mare";
    char destinatie1[] = "Bucegi";
    char data1[] = "10-09-2021";
    int pret1 = 3000;
    AdaugaOferta(&lista, tip1, destinatie1, data1, pret1);
    AdaugaOferta(&lista, tip, destinatie, data, pret);
    strcpy(tip, "city break");
    strcpy(destinatie, "Paris");
    strcpy(data, "16-12-2024");
    pret = 1000;
    AdaugaOferta(&lista, tip, destinatie, data, pret);
    assert(lista.n == 3);
    ListaOferte lista_sortata_pret0 = SortarePret(lista, 0);
    ListaOferte lista_sortata_pret1 = SortarePret(lista, 1);
    assert(get_pret(&lista_sortata_pret0.oferte[0]) == 1000);
    assert(get_pret(&lista_sortata_pret0.oferte[1]) == 2000);
    assert(get_pret(&lista_sortata_pret0.oferte[2]) == 3000);
    ListaOferte lista_sortata_data1 = SortareData(lista, 1);
    ListaOferte lista_sortata_data0 = SortareData(lista, 0);
    assert(get_pret(&lista_sortata_data1.oferte[0]) == 1000);
    assert(strcmp(get_tip(&lista_sortata_data1.oferte[2]), "mare") == 0);
    assert(get_pret(&lista_sortata_pret1.oferte[0]) == 3000);
    assert(get_pret(&lista_sortata_pret1.oferte[2]) == 1000);
    assert(!strcmp(get_data(&lista_sortata_data0.oferte[0]), "10-09-2021"));
    assert(!strcmp(get_data(&lista_sortata_pret0.oferte[1]), "12-10-2023"));
}

void test_filtrare(){
    ListaOferte lista = CreeazaVid();
    char tip[20] = "munte";
    char destinatie[] = "Bucegi";
    char data[] = "12-10-2023";
    int pret = 2000;
    char tip1[20] = "mare";
    char destinatie1[] = "Bucegi";
    char data1[] = "10-09-2021";
    int pret1 = 3000;
    AdaugaOferta(&lista, tip1, destinatie1, data1, pret1);
    AdaugaOferta(&lista, tip, destinatie, data, pret);
    strcpy(tip, "city break");
    strcpy(destinatie, "Paris");
    strcpy(data, "16-12-2024");
    pret = 1000;
    AdaugaOferta(&lista, tip, destinatie, data, pret);
    ListaOferte lista_filtrata_pret1 = FiltruPret(lista, 2000, 1);
    ListaOferte lista_filtrata_pret0 = FiltruPret(lista, 2500, 0);
    assert(lista_filtrata_pret1.n == 2);
    assert(get_pret(&lista_filtrata_pret1.oferte[0]) + get_pret(&lista_filtrata_pret1.oferte[1]) == 3000);
    ListaOferte lista_filtrata_tip = FiltruTip(lista, "munte");
    assert(lista_filtrata_tip.n == 1);
    assert(!strcmp(get_tip(&lista_filtrata_tip.oferte[0]), "munte"));
    ListaOferte lista_filtrata_data = FiltruData(lista, "12-10-2023");
    assert(lista_filtrata_data.n == 1);
    assert(!strcmp(get_tip(&lista_filtrata_data.oferte[0]), "munte"));
    assert(lista_filtrata_pret0.n == 1);
    assert(get_pret(&lista_filtrata_pret0.oferte[0]) == 3000);
}

void test_validare_tip() {
    char tip1[10] = "munte";
    char tip2[10] = "mare";
    char tip3[20] = "vacanta";
    assert(ValidareTip(tip1));
    assert(ValidareTip(tip2));
    assert(!ValidareTip(tip3));
}

void test_validare_data(){
    char data1[11] = "10-12-2023";
    char data2[11] = "35-10-2011";
    char data3[11] = "10-14-2019";
    char data4[11] = "10-11-04";
    char data5[11] = "1020";
    char data6[11] = "34-11-2024";
    char data7[11] = "30-02-2017";
    assert(ValidareData(data1));
    assert(!ValidareData(data2));
    assert(!ValidareData(data3));
    assert(!ValidareData(data4));
    assert(!ValidareData(data5));
    assert(!ValidareData(data6));
    assert(!ValidareData(data7));
}

void test_validare_oferta(){
    char tip[10] = "munte";
    char destinatie[20] = "Bucegi";
    char data[11] = "40-03-2010";
    int pret = 3000;
    Oferta oferta = CreeazaOferta(tip, destinatie, data, pret);
    assert(!ValidareOferta(oferta));
}

void test_dublura(){
    ListaOferte lista = CreeazaVid();
    Oferta oferta1, oferta2;
    char tip[20] = "munte";
    char destinatie[] = "Bucegi";
    char data[] = "12-10-2023";
    int pret = 2000;
    char tip1[20] = "mare";
    char destinatie1[] = "Bucegi";
    char data1[] = "10-09-2021";
    int pret1 = 3000;
    AdaugaOferta(&lista, tip1, destinatie1, data1, pret1);
    AdaugaOferta(&lista, tip, destinatie, data, pret);
    oferta1 = CreeazaOferta(tip, destinatie, data, pret);
    assert(Dublura(&lista, oferta1));
}

void AllTests(){
    test_creare();
    test_egalitate();
    test_cronologic();
    test_gasit();
    test_stergere();
    test_modificare();
    test_sortare();
    test_filtrare();
    test_validare_tip();
    test_validare_data();
    test_validare_oferta();
    test_dublura();
}
