//
// Created by Știube Denis on 31.03.2024.
//

#include "UI.h"
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
        s.addMedicamentFarmacie(denumire, pret, producator, subst);
        cout << "\nAdaugat cu SUCCES!";
    }
    catch (Error& error){
        cout << error.getMesaj();
    }
}

void UI::addMedicamentReteta(){
    string denumire, producator;
    cout << "Introduceti denumirea medicamentului: ";
    cin >> producator;
    cout << "Introduceti producatorul medicamentului: ";
    cin >> denumire;
    try{
        s.addMedicamentReteta(denumire, producator);
        cout << "\nAdaugat cu SUCCES!\n";
        cout << "Reteta: " << s.getSizeReteta() << " medicamente\n";
    }
    catch (Error& error){
        cout << error.getMesaj();
    }
}

void UI::addMedicamentRandomReteta() {
    int nr;
    cout << "Introduceti un numar natural nenul: ";
    cin >> nr;
    try{
        s.addMedicamenteRandom(nr);
        cout << "Reteta: " << nr << " medicamente\n";
    }
    catch (Error& error){
        cout << error.getMesaj();
    }
}

void UI::deleteMedicament() {
    printAll(s.getAll());
    string denumire, producator;
    cout << "Introduceti denumirea medicamentului: ";
    cin >> denumire;
    cout << "Introduceti producatorul medicamentului: ";
    cin >> producator;
    try{
        s.deleteMedicamentFarmacie(denumire, producator);
        cout << "\nSters cu SUCCES!";
    }
    catch (Error& error){
        cout << error.getMesaj();
    }
}

void UI::deleteAllReteta() {
    s.deleteAllReteta();
    cout << "\nReteta: " << s.getSizeReteta() << " medicamente\n";
}

void UI::findMedicament() {
    string denumire, producator;
    cout << "Introduceti denumirea medicamentului ce va fi cautat: ";
    cin >> denumire;
    cout << "Introduceti producatorul medicamentului ce va fi cautat: ";
    cin >> producator;
    if (s.findMedicament(denumire, producator))
        cout << "\nMedicamentul cautat exista!";
    else
        cout << "\nMedicamentul cautat nu exista!";
}

void UI::updatePret() {
    printAll(s.getAll());
    int poz;
    double newPret;
    cout << "Introduceti noul pret al medicamentului: ";
    cin >> newPret;
    string denumire, producator;
    cout << "Introduceti denumirea medicamentului: ";
    cin >> denumire;
    cout << "Introduceti producatorul medicamentului: ";
    cin >> producator;
    try{
        s.updatePret(denumire, producator, newPret);
        cout << "\nModificat cu SUCCES!";
    }
    catch (Error& error){
        cout << error.getMesaj();
    }
}

void UI::updateSubst(){
    printAll(s.getAll());
    int poz;
    string newSubst;
    cout << "Introduceti noua substanta al medicamentului: ";
    cin >> newSubst;
    string denumire, producator;
    cout << "Introduceti denumirea medicamentului: ";
    cin >> denumire;
    cout << "Introduceti producatorul medicamentului: ";
    cin >> producator;
    try{
        s.updateSubst(denumire, producator, newSubst);
        cout << "\nModificat cu SUCCES!";
    }
    catch (Error& error){
        cout << error.getMesaj();
    }
}

void UI::filtruPret() {
    printAll(s.getAll());
    double pret;
    cout << "Introduceti pretul dorit pentru medicamente: ";
    cin >> pret;
    vector<Medicament> listaFiltrata = s.filtruPret(pret);
    if (listaFiltrata.empty())
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
    printAll(s.getAll());
    string subst;
    cout << "Introduceti substanta dorit pentru medicamente: ";
    cin >> subst;
    vector<Medicament> listaFiltrata = s.filtruSubst(subst);
    if (listaFiltrata.empty())
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
    string ordine;
    cout << "Doriti sortarea crescator sau descrescator?" << '\n';
    cin >> ordine;
    vector<Medicament> sortat;
    if (ordine == "crescator"){
        sortat = s.sortareMedicamenteDenumire(true);
    }
    else
    {
        sortat = s.sortareMedicamenteDenumire(false);
    }
    printAll(sortat);
}

void UI::sortareProducator() {
    string ordine;
    cout << "Doriti sortarea crescator sau descrescator?" << '\n';
    cin >> ordine;
    vector<Medicament> sortat;
    if (ordine == "crescator"){
        sortat = s.sortareMedicamenteProducator(true);
    }
    else
    {
        sortat = s.sortareMedicamenteProducator(false);
    }
    printAll(sortat);
}

void UI::sortareSubstPret() {
    string ordine;
    cout << "Doriti sortarea crescator sau descrescator?" << '\n';
    cin >> ordine;
    vector<Medicament> sortat;
    if (ordine == "crescator"){
        sortat = s.sortareMedicamenteSubstPret(true);
    }
    else
    {
        sortat = s.sortareMedicamenteSubstPret(false);
    }
    printAll(sortat);
}

void UI::undo() {
    try{
        s.undo();
        cout << "Undo efectuat cu SUCCES!\n";
    }
    catch (Error& err){
        cout << err.getMesaj() << '\n';
    }
}

void UI::exportToFile() {
    string filename;
    cout << "Introduceti numele fisierului: ";
    cin >> filename;
    try{
        s.exportToFile(filename);
        cout << "\nReteta: " << s.getSizeReteta() << " medicamente";
    }
    catch (Error error){
        cout << error.getMesaj();
    }
}

void UI::printMedicament(const Medicament& med){
    cout << "Denumire: " << med.getDenumire() << " | Pret: " << med.getPret() << " | Producator: " << med.getProducator() << " | Substanta: " << med.getSubst();
}

void UI::printAll(vector<Medicament>& lista) {
    if (lista.empty())
        cout << "Nu exista medicamente!";
    else {
        for (Medicament& med: lista) {
            printMedicament(med);
            cout << '\n';
        }
    }
}

void UI::printAllDict(map<pair<std::string, std::string>, Medicament> &lista) {
    if (lista.empty())
        cout << "Nu exista medicamente!";
    else{
        for (auto &el : lista){
            printMedicament(el.second);
            cout << '\n';
        }
    }
}

void UI::addDefault() {
    try {
        s.addMedicamentFarmacie("d1", 45.30, "p1", "s1");
        s.addMedicamentFarmacie("d2", 50, "p2", "s1");
        s.addMedicamentFarmacie("d3", 45.30, "p5", "s4");
        s.addMedicamentFarmacie("d4", 74, "p7", "s1");
        s.addMedicamentFarmacie("d5", 50, "p3", "s3");
    }
    catch (Error error){
        cout << error.getMesaj();
    }
}

void UI::Meniu() {
    cout << "1. Adauga medicament\n2. Sterge medicament\n3. Modifica pretul unui medicament\n4. Modifica substanta unui medicament\n5. Adauga un medicament in reteta\n6. Adauga medicamente random in reteta\n7. Goleste reteta\n8. Exporta reteta catre un fisier\n9. Cauta un medicament\n10. Filtrati dupa pret\n11. Filtrati dupa substanta activa\n12. Sortare dupa denumire\n13. Sortare dupa producator\n14. Sortare dupa substanta si pret\n15. Adaugare automat cinci medicamente\n16. Afisare toate medicamentele\n17. Afisare reteta\n18. Undo\n19. Iesire\n";
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
                addMedicamentReteta();
                break;
            case 6:
                addMedicamentRandomReteta();
                break;
            case 7:
                deleteAllReteta();
                break;
            case 8:
                exportToFile();
                break;
            case 9:
                findMedicament();
                break;
            case 10:
                filtruPret();
                break;
            case 11:
                filtruSubst();
                break;
            case 12:
                sortareDenumire();
                break;
            case 13:
                sortareProducator();
                break;
            case 14:
                sortareSubstPret();
                break;
            case 15:
                addDefault();
                break;
            case 16:
                printAll(s.getAll());
                break;
            case 17:
                printAll(s.getAllReteta());
                break;
            case 18:
                undo();
                break;
            case 19:
                return;
            default:
                cout << "Optiune invalida!";
                break;
        }
    }
}