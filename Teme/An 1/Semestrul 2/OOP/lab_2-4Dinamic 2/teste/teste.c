//
// Created by Știube Denis on 09.03.2024.
//
#include <string.h>
#include <assert.h>
#include "../utils/utils.h"
#include "../list/lista.h"
#include "../service/service.h"
#include "../teste/teste.h"


void test_creare(){
    Oferta* oferta = CreeazaOferta("munte", "Bucegi", "12-10-2021", 2000);
    assert(get_pret(oferta) == 2000);
    assert(strcmp((get_tip(oferta)), "munte") == 0);
    char zi[4], luna[4], an[6];
    assert(strcmp(get_zi(get_data(oferta), zi), "12") == 0);
    assert(strcmp(get_luna(get_data(oferta), luna), "10") == 0);
    assert(strcmp(get_an(get_data(oferta), an), "2021") == 0);
    DistrugeOferta(oferta);
}

void test_distrugere(){
    ListaOferte* lista = CreeazaVid();
    assert(lista->cp == 2);
    Oferta* oferta = CreeazaOferta("city break", "Londra", "10-08-2019", 3400);
    AdaugaOferta(lista, oferta);
    assert(lista->n == 1);
    DistrugeLista(lista);
}

void test_redimensionare(){
    ListaOferte* lista = CreeazaVid();
    assert(lista->cp == 2);
    Oferta* oferta1 = CreeazaOferta("munte", "Bucegi", "12-10-2023", 2000);
    Oferta* oferta2 = CreeazaOferta("mare", "Bucegi", "10-09-2021", 3000);
    AdaugaOferta(lista, oferta2);
    AdaugaOferta(lista, oferta1);
    Oferta *oferta3 = CreeazaOferta("city-break", "Paris", "16-12-2024", 1000);
    AdaugaOferta(lista, oferta3);
    assert(lista->cp == 4);
    assert(lista->n == 3);
    DistrugeLista(lista);
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
    Oferta* oferta1, *oferta2;
    oferta1 = CreeazaOferta(tip, destinatie, data, pret);
    oferta2 = CreeazaOferta(tip1, destinatie1, data1, pret1);
    assert(Egalitate(oferta1, oferta2) == 1);
    DistrugeOferta(oferta1);
    DistrugeOferta(oferta2);
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
    assert(!Cronologic(data2, data1));
    data1 = "14-10-2018";
    data2 = "24-11-2018";
    assert(Cronologic(data1, data2));
    assert(!Cronologic(data2, data1));
}

void test_gasit(){
    ListaOferte* lista = CreeazaVid();
    Oferta *oferta1, *oferta2, *oferta3;
    oferta1 = CreeazaOferta("munte", "Bucegi", "12-10-2021", 2000);
    oferta2 = CreeazaOferta("mare", "Bucegi", "12-10-2021", 2000);
    oferta3 = CreeazaOferta("munte", "Bucegi", "12-10-2021", 3000);
    AdaugaOferta(lista, oferta2);
    AdaugaOferta(lista, oferta1);
    assert(GasesteOferta(lista, *oferta1) == 1);
    assert(GasesteOferta(lista, *oferta2) == 0);
    assert(GasesteOferta(lista, *oferta3) == -1);
    DistrugeLista(lista);
    DistrugeOferta(oferta3);
}

void test_adaugare(){
    ListaOferte* lista = CreeazaVid();
    assert(lista->n == 0);
    Oferta* oferta1 = CreeazaOferta("mare", "Spania", "10-10-2020", 1000);
    AdaugaOferta(lista, oferta1);
    assert(lista->n == 1);
    assert(!strcmp(get_tip(lista->oferte[0]), "mare"));
    assert(get_pret(lista->oferte[0]) == 1000);
    int adaugare = AdaugaOferta(lista, oferta1);
    assert(adaugare == -1);
    DistrugeLista(lista);
}

void test_stergere(){
    ListaOferte* lista = CreeazaVid();
    Oferta* oferta1 = CreeazaOferta("munte", "Bucegi", "12-10-2021", 2000);
    Oferta* oferta2 = CreeazaOferta("mare", "Bucegi", "12-10-2021", 2000);
    AdaugaOferta(lista, oferta2);
    AdaugaOferta(lista, oferta1);
    assert(lista->n == 2);
    Oferta* oferta3 = CreeazaOferta("city-break", "Madrid", "12-10-2021", 4000);
    AdaugaOferta(lista, oferta3);
    StergeOferta(lista, 2);
    assert(lista->n == 2);
    assert(get_pret(lista->oferte[0]) == 2000);
    assert(strcmp(get_tip(lista->oferte[0]), "mare") == 0);
    int stergere = StergeOferta(lista, 4);
    assert(stergere == -1);
    DistrugeLista(lista);

}

void test_modificare(){
    ListaOferte* lista = CreeazaVid();
    Oferta* oferta1 = CreeazaOferta("munte", "Bucegi", "12-10-2021", 2000);
    Oferta* oferta2 = CreeazaOferta("mare", "Bucegi", "12-10-2021", 2000);
    AdaugaOferta(lista, oferta2);
    AdaugaOferta(lista, oferta1);
    assert(lista->n == 2);
    Oferta* oferta3 = CreeazaOferta("city break", "Londra", "22-09-2024", 3600);
    ModificaOferta(lista, 2, oferta3);
    assert(get_pret(lista->oferte[1]) == 3600);
    assert(!strcmp(get_tip(lista->oferte[1]), "city break"));
    assert(lista->n == 2);
    int modificare = ModificaOferta(lista, -1, oferta1);
    assert(modificare == -1);
    DistrugeOferta(oferta3);
    DistrugeLista(lista);
}

void test_sortare(){
    ListaOferte* lista = CreeazaVid();
    Oferta* oferta1 = CreeazaOferta("munte", "Bucegi", "12-10-2023", 2000);
    Oferta* oferta2 = CreeazaOferta("mare", "Bucegi", "10-09-2021", 3000);
    AdaugaOferta(lista, oferta2);
    AdaugaOferta(lista, oferta1);
    Oferta *oferta3 = CreeazaOferta("city-break", "Paris", "16-12-2024", 1000);
    AdaugaOferta(lista, oferta3);
    assert(lista->n == 3);
    SortareGenerica(lista, MaiMic, 0);
    assert(get_pret(lista->oferte[0]) == 1000);
    assert(get_pret(lista->oferte[1]) == 2000);
    assert(get_pret(lista->oferte[2]) == 3000);
    SortareGenerica(lista, MaiMic, 1);
    assert(get_pret(lista->oferte[0]) == 3000);
    assert(get_pret(lista->oferte[1]) == 2000);
    assert(get_pret(lista->oferte[2]) == 1000);
    SortareGenerica(lista, MaiMicData, 1);
    assert(get_pret(lista->oferte[0]) == 1000);
    assert(strcmp(get_tip(lista->oferte[2]), "mare") == 0);
    SortareGenerica(lista, MaiMicData, 0);
    assert(get_pret(lista->oferte[0]) == 3000);
    assert(get_pret(lista->oferte[2]) == 1000);
    assert(!strcmp(get_data(lista->oferte[0]), "10-09-2021"));
    assert(!strcmp(get_data(lista->oferte[1]), "12-10-2023"));
    DistrugeLista(lista);
}

void test_filtrare(){
    ListaOferte* lista = CreeazaVid();
    Oferta* oferta1 = CreeazaOferta("munte", "Bucegi", "12-10-2023", 2000);
    Oferta* oferta2 = CreeazaOferta("mare", "Bucegi", "10-09-2021", 3000);
    AdaugaOferta(lista, oferta2);
    AdaugaOferta(lista, oferta1);
    Oferta* oferta3 = CreeazaOferta("city break", "Paris", "16-12-2024", 1000);
    AdaugaOferta(lista, oferta3);
    ListaOferte* lista_filtrata_pret1 = FiltruPret(*lista, 2000, 1);
    ListaOferte* lista_filtrata_pret0 = FiltruPret(*lista, 2500, 0);
    assert(lista_filtrata_pret1->n == 2);
    assert(get_pret(lista_filtrata_pret1->oferte[0]) + get_pret(lista_filtrata_pret1->oferte[1]) == 3000);
    ListaOferte* lista_filtrata_tip = FiltruTip(*lista, "munte");
    assert(lista_filtrata_tip->n == 1);
    assert(!strcmp(get_tip(lista_filtrata_tip->oferte[0]), "munte"));
    ListaOferte* lista_filtrata_data = FiltruData(*lista, "12-10-2023");
    assert(lista_filtrata_data->n == 1);
    assert(!strcmp(get_tip(lista_filtrata_data->oferte[0]), "munte"));
    assert(lista_filtrata_pret0->n == 1);
    assert(get_pret(lista_filtrata_pret0->oferte[0]) == 3000);
    DistrugeLista(lista);
    DistrugeLista(lista_filtrata_pret1);
    DistrugeLista(lista_filtrata_tip);
    DistrugeLista(lista_filtrata_pret0);
    DistrugeLista(lista_filtrata_data);
}

void test_validare_pret(){
    int pret = 1000;
    assert(ValidarePret(pret));
    pret = -100;
    assert(!ValidarePret(pret));
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
    Oferta* oferta = CreeazaOferta(tip, destinatie, data, pret);
    assert(!ValidareOferta(*oferta));
    DistrugeOferta(oferta);
}

void test_adauga_service(){
    ListaOferte* lista = CreeazaVid();
    assert(lista->n == 0);
    char tip[20] = "munte";
    char destinatie[20] = "Bucegi";
    char data[11] = "07-07-2023";
    int pret = 2000;
    AdaugaOfertaService(lista, tip, destinatie, data, pret);
    assert(lista->n == 1);
    strcpy(tip, "munt");
    int ok = AdaugaOfertaService(lista, tip, destinatie, data, pret);
    assert(lista->n == 1);
    assert(ok == -1);
    strcpy(tip, "munte");
    ok = AdaugaOfertaService(lista, tip, destinatie, data, pret);
    assert(ok == -1);
    DistrugeLista(lista);
}

void test_sterge_service(){
    ListaOferte* lista = CreeazaVid();
    assert(lista->n == 0);
    char tip[20] = "munte";
    char destinatie[20] = "Bucegi";
    char data[11] = "07-07-2023";
    int pret = 2000;
    AdaugaOfertaService(lista, tip, destinatie, data, pret);
    assert(lista->n == 1);
    StergeOfertaService(lista, 1);
    assert(lista->n == 0);
    AdaugaOfertaService(lista, tip, destinatie, data, pret);
    assert(lista->n == 1);
    int ok = StergeOfertaService(lista, 2);
    assert(lista->n == 1);
    assert(ok == -1);
    DistrugeLista(lista);
}

void test_modifica_service(){
    ListaOferte* lista = CreeazaVid();
    assert(lista->n == 0);
    char tip[20] = "munte";
    char destinatie[20] = "Bucegi";
    char data[11] = "07-07-2023";
    int pret = 2000;
    AdaugaOfertaService(lista, tip, destinatie, data, pret);
    assert(lista->n == 1);
    ModificaOfertaService(lista, "mare", "Spania", "24-10-2021", 3000, 1);
    assert(lista->n == 1);
    assert(strcmp(get_tip(lista->oferte[0]), "mare") == 0);
    assert(get_pret(lista->oferte[0]) == 3000);
    int ok = ModificaOfertaService(lista, "mar", "Spania", "20-10-2019", 3500, 1);
    assert(ok == -1);
    AdaugaOfertaService(lista, "city-break", "Madrid", "07-06-2022", 4500);
    assert(lista->n == 2);
    assert(get_pret(lista->oferte[1]) == 4500);
    int modificare = ModificaOfertaService(lista, "mare", "Spania", "24-10-2021", 3000, 2);
    assert(modificare == -1);
    assert(lista->n == 2);
    assert(get_pret(lista->oferte[1]) == 4500);
    modificare = ModificaOfertaService(lista, "mare", "Spania", "24-10-2021", 3000, 3);
    assert(modificare == -1);
    assert(lista->n == 2);
    DistrugeLista(lista);
}

void AllTests(){
    test_creare();
    test_distrugere();
    test_egalitate();
    test_cronologic();
    test_redimensionare();
    test_gasit();
    test_adaugare();
    test_stergere();
    test_modificare();
    test_sortare();
    test_filtrare();
    test_validare_pret();
    test_validare_tip();
    test_validare_data();
    test_validare_oferta();
    test_adauga_service();
    test_sterge_service();
    test_modifica_service();
}