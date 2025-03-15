//
// Created by Știube Denis on 31.03.2024.
//

#include "ui.h"
#include <iostream>
using std::cin;
using std::cout;

void UI::addMedicament() {
    string denumire, producator, subst;
    double pret;
    cout << "Introduceti denumirea medicamentului: ";
    cin >> denumire;
    cout << "Introduceti pretul medicamentului: ";
    cin >> pret;
    cout << "Introduceti producatorul medicamentului: ";
    cin >> producator;
    cout << "Introduceti substanta medicamentului: ";
    cin >> subst;
    try{
        s.addMedicament(denumire, pret, producator, subst);
        cout << "\nAdaugat cu SUCCES!";
    }
    catch (Error& err){
        cout << err.getMesaj() << '\n';
    }
}

void UI::deleteMedicament() {
    int poz;
    cout << "Introduceti pozitia medicamentului ce va fi sters: ";
    cin >> poz;
    try{
        s.deleteMedicament(poz);
        cout << "\nSters cu SUCCES!";
    }
    catch (Error err){
        cout << err.getMesaj() << '\n';
    }
}

void UI::findMedicament() {
    string denumire, producator;
    cout << "Introduceti denumirea medicamentului ce va fi cautat: ";
    cin >> denumire;
    cout << "Introduceti producatorul medicamentului ce va fi cautat: ";
    cin >> producator;
    if (s.findMedicament(denumire, producator))
        cout << "Medicamentul cautat exista!";
    else
        cout << "\nMedicamentul cautat nu exista!";
}

void UI::updatePret() {
    int poz;
    double newPret;
    cout << "Introduceti pozitia medicamentului ce va fi modificat: ";
    cin >> poz;
    if (poz < 1 || poz > s.getSize())
        cout << "Pozitie invalida!";
    else{
        cout << "Introduceti noul pret al medicamentului: ";
        cin >> newPret;
        s.updatePret(poz, newPret);
        cout << "\nModificat cu SUCCES!";
    }
}

void UI::updateSubst(){
    int poz;
    string newSubst;
    cout << "Introduceti pozitia medicamentului ce va fi modificat: ";
    cin >> poz;
    if (poz < 1 || poz > s.getSize())
        cout << "Pozitie invalida!";
    else{
        cout << "Introduceti noua substanta al medicamentului: ";
        cin >> newSubst;
        s.updateSubst(poz, newSubst);
        cout << "\nModificat cu SUCCES!";
    }
}

void UI::filtruPret() {
    double pret;
    cout << "Introduceti pretul dorit pentru medicamente: ";
    cin >> pret;
    VectorDinamic<Medicament> listaFiltrata = s.filtruPret(pret);
    if (listaFiltrata.getSize() == 0)
        cout << "Nu exista medicamente la acest pret!";
    else{
        int poz = 1;
        for (Medicament& med: listaFiltrata) {
            cout << poz;
            cout << ". ";
            printMedicament(med);
            cout << '\n';
            poz++;
        }
        cout << '\n';
    }
}

void UI::filtruSubst() {
    string subst;
    cout << "Introduceti substanta dorit pentru medicamente: ";
    cin >> subst;
    VectorDinamic<Medicament> listaFiltrata = s.filtruSubst(subst);
    if (listaFiltrata.getSize() == 0)
        cout << "Nu exista medicamente cu aceasta substanta!";
    else{
        int poz = 1;
        for (Medicament& med: listaFiltrata) {
            cout << poz;
            cout << ". ";
            printMedicament(med);
            cout << '\n';
            poz++;
        }
        cout << '\n';
    }
}

void UI::sortareDenumire() {
    VectorDinamic<Medicament> sortat = s.sortareDenumire();
    if (sortat.getSize() == 0)
        cout << "Nu exista medicamente cu aceasta substanta!";
    else{
        int poz = 1;
        for (Medicament& med: sortat) {
            cout << poz;
            cout << ". ";
            printMedicament(med);
            cout << '\n';
            poz++;
        }
        cout << '\n';
    }
}

void UI::sortareProducator() {
    VectorDinamic<Medicament> sortat = s.sortareProducator();
    if (sortat.getSize() == 0)
        cout << "Nu exista medicamente cu aceasta substanta!";
    else{
        int poz = 1;
        for (Medicament& med: sortat) {
            cout << poz;
            cout << ". ";
            printMedicament(med);
            cout << '\n';
            poz++;
        }
        cout << '\n';
    }
}

void UI::sortareSubstPret() {
    VectorDinamic<Medicament> sortat = s.sortareSubstPret();
    if (sortat.getSize() == 0)
        cout << "Nu exista medicamente cu aceasta substanta!";
    else{
        int poz = 1;
        for (Medicament& med: sortat) {
            cout << poz;
            cout << ". ";
            printMedicament(med);
            cout << '\n';
            poz++;
        }
        cout << '\n';
    }
}

void UI::printMedicament(const Medicament& med){
    cout << "Denumire: " << med.getDenumire() << " | Pret: " << med.getPret() << " | Producator: " << med.getProducator() << " | Substanta: " << med.getSubst();
}

void UI::printAll() {
    if (s.getSize() == 0)
        cout << "Nu exista medicamente in lista!";
    else {
        int poz = 1;
        for (Medicament& med: s.getAll()) {
            cout << poz;
            cout << ". ";
            printMedicament(med);
            cout << '\n';
            poz++;
        }
        cout << '\n';
    }
}

void UI::addDefault() {
    s.addMedicament("d1", 45.30, "p1", "s1");
    s.addMedicament("d2", 50, "p2", "s1");
    s.addMedicament("d3", 45.30, "p5", "s4");
    s.addMedicament("d4", 74, "p7", "s1");
    s.addMedicament("d1", 50, "p3", "s3");
}

void UI::Meniu() {
    cout << "1. Adauga medicament\n2. Sterge medicament\n3. Modifica pretul unui medicament\n4. Modifica substanta unui medicament\n5. Cauta un medicament\n6. Filtrati dupa pret\n7. Filtrati dupa substanta activa\n8. Sortare dupa denumire\n9. Sortare dupa producator\n10. Sortare dupa substanta si pret\n11. Adaugare automat cinci medicamente\n12. Afisare toate medicamentele\n13. Iesire\n";
}

void UI::Run() {
    while (true){
        cout << '\n';
        Meniu();
        int optiune;
        cout << "Introduceti o optiune: ";
        cin >> optiune;
        switch (optiune){
            case 1:
                addMedicament();
                break;
            case 2:
                deleteMedicament();
                break;
            case 3:
                updatePret();
                break;
            case 4:
                updateSubst();
                break;
            case 5:
                findMedicament();
                break;
            case 6:
                filtruPret();
                break;
            case 7:
                filtruSubst();
                break;
            case 8:
                sortareDenumire();
                break;
            case 9:
                sortareProducator();
                break;
            case 10:
                sortareSubstPret();
                break;
            case 11:
                addDefault();
                break;
            case 12:
                printAll();
                break;
            case 13:
                return;
        }
    }
}