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
#include "domain/oferte.h"
#include "list/lista.h"
#include "service/service.h"
#include "teste/teste.h"
#include "ui/ui.h"

int main(){
    AllTests();
    ListaOferte* lista = CreeazaVid();
    run(lista);
}
