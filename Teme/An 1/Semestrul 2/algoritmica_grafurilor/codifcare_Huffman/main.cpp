#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Nod;
typedef Nod* PNod;

class Nod{
public:
    int fr;
    char c;
    PNod st;
    PNod dr;
    Nod() = default;
    Nod(int fr, char c): fr{fr}, c{c}, st{NULL}, dr{NULL} {

    }
    void adauga_arbore(PNod st, PNod dr) {
        this->st = st;
        this->dr = dr;
        this->fr = st->fr + dr->fr;
        this->c = '\0';
    }

};

void elibereaza(PNod rad) {
    PNod l = rad->st;
    PNod r = rad->dr;
    delete rad;
    if (r != NULL)
        elibereaza(r);
    if (l != NULL)
        elibereaza(l);
}

char min_ch(PNod r) {
    if (r->c != '\0') {
        return r->c;
    }
    if (min_ch(r->st) < min_ch(r->dr))
        return min_ch(r->st);
    else
        return min_ch(r->dr);
}

string decodificare(PNod rad, string cod) {
    string mesaj = "";
    PNod copie = rad;
    while (!cod.empty()) {
        while (rad->c == '\0') {
            if (cod[0] == '0')
                rad = rad->st;
            else
                rad = rad->dr;
            cod.erase(0, 1);
        }
        mesaj += rad->c;
        rad = copie;
    }
    return mesaj;
}

PNod Huffman(map<char, int> caractere) {
    priority_queue<pair<pair<int, char>, PNod >, vector<pair<pair<int, char>, PNod >>, greater<>> coada;
    for (auto p : caractere){
        PNod pnod = new Nod{p.second, p.first};
        coada.push(make_pair(make_pair(pnod->fr, min_ch(pnod)), pnod));
    }
    int lg = coada.size();
    for (int i = 1; i < lg; i++) {
        auto st = coada.top();
        coada.pop();
        auto dr = coada.top();
        coada.pop();
        PNod nou = new Nod;
        nou->adauga_arbore(st.second, dr.second);
        coada.push(make_pair(make_pair(nou->fr, min_ch(nou)), nou));
    }
    return coada.top().second;
}

void coduri(PNod rad, map<char, string> & codificare, string cod) {
    if (rad->c != '\0') {
        codificare[rad->c] = cod;
    }
    else {
        coduri(rad->st, codificare, cod + "0");
        coduri(rad->dr, codificare, cod + "1");
    }
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    ifstream fin("in1.txt");
    ofstream fout("out1.txt");
    string sir;
    getline(in, sir);
    map<char, int> alfabet;
//    for (auto c : sir){
//        if (alfabet.find(c) == alfabet.end()){
//            alfabet[c] = 1;
//        }
//        else{
//            alfabet[c]++;
//        }
//    }
    alfabet['a'] = 45;
    alfabet['b'] = 13;
    alfabet['c'] = 12;
    alfabet['d'] = 16;
    alfabet['e'] = 9;
    alfabet['f'] = 5;
    out << alfabet.size() << '\n';
    for (auto p : alfabet){
        out << p.first << " " << p.second << '\n';
    }
    PNod rad = Huffman(alfabet);
    map<char, string> codificare;
    coduri(rad, codificare, "");
    for (auto c : sir) {
        out << codificare[c];
    }
    string cod;
    fin >> cod;
    string msj = decodificare(rad, cod);
    fout << msj;
    elibereaza(rad);
    return 0;
}
