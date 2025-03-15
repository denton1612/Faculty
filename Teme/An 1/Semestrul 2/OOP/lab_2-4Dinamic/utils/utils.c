#include <string.h>
#include "../domain/oferte.h"

int Egalitate(Oferta* oferta1, Oferta* oferta2){
    int egal = 0;
    if (!strcmp(get_tip(oferta1), get_tip(oferta2)) &&
    !strcmp(get_destinatie(oferta1), get_destinatie(oferta2)) &&
    !strcmp(get_data(oferta1), get_data(oferta2)) &&
    get_pret(oferta1) == get_pret(oferta2))
        egal = 1;
    return egal;
}

int Cronologic(char data1[], char data2[]){
    char an1[10], an2[10], luna1[4], luna2[4], zi1[4], zi2[4];
    if (strcmp(get_an(data1, an1), get_an(data2, an2)) < 0)
        return 1;
    else if (strcmp(get_an(data1, an1), get_an(data2, an2)) > 0)
        return 0;
    else{
        if (strcmp(get_luna(data1, luna1), get_luna(data2, luna2)) < 0)
            return 1;
        else if (strcmp(get_luna(data1, luna1), get_luna(data2, luna2)) > 0)
            return 0;
        else{
            if (strcmp(get_zi(data1, zi1), get_zi(data2, zi2)) <= 0)
                return 1;
            return 0;
        }
    }
}

int MaiMicData(Oferta* o1, Oferta* o2){
    return Cronologic(o1->data, o2->data);
}

int MaiMic(Oferta* o1, Oferta* o2){
    return o1->pret < o2->pret;
}

Oferta* CopieOferta(Oferta* oferta){
    Oferta* oferta_copie = CreeazaOferta(get_tip(oferta), get_destinatie(oferta), get_data(oferta), get_pret(oferta));
    return oferta_copie;
}