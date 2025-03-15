#include <iostream>
#include <vector>
#include <fstream>
#include <assert.h>
#include <stack>
#include <algorithm>
#include <exception>
using namespace std;
using std::exception;

class Meniu {
private:
    int pret;
public:
    Meniu(int pret): pret{pret} {

    };
    virtual int getPret() {
        return pret;
    }
    virtual string descriere() = 0;
    virtual ~Meniu() = default;

};

class MicDejun: public Meniu{
private:
    string denumire;
public:
    MicDejun(int pret, string den): Meniu{pret}, denumire{den} {};
    virtual string descriere() override {
        return denumire;
    }
};

class CuRacoritoare: public Meniu{
private:
    Meniu * menu;
public:
    CuRacoritoare(Meniu * m): Meniu(m->getPret()), menu{m} {};
    int getPret() override {
        return menu->getPret() + 4;
    }
    string descriere() override {
        return menu->descriere() + "cu racoritoare";
    }
    ~CuRacoritoare() override{
        delete menu;
    }
};

class CuCafea: public Meniu{
private:
    Meniu* menu;
public:
    CuCafea(Meniu * m): Meniu{m->getPret()}, menu{m} {};
    int getPret() override {
        return menu->getPret() + 5;
    }
    string descriere() override {
        return menu->descriere() + "cu cafea";
    }
    ~CuCafea() override {
        delete menu;
    }
};

vector<Meniu*> f2() {
    vector<Meniu*> meniuri;
    meniuri.push_back(new CuRacoritoare{new CuCafea{new MicDejun{15, "Omleta"}}});
    meniuri.push_back(new CuCafea{new MicDejun{10, "Ochiuri"}});
    meniuri.push_back(new MicDejun{15, "Omleta"});
    return meniuri;
}

template <typename T> class Measurement {
private:
    T val;
public:
    Measurement(const T v): val{v} {};
    Measurement & operator+ (const T v) {
        val += v;
        return *this;
    }
    friend bool operator< (const Measurement & ot1, const Measurement & ot2) {
        return ot1.val < ot2.val;
    }
    T value() {
        return val;
    }
    friend ostream & operator<< (ostream & out, const Measurement & m1) {
        out << m1.val;
    }
};

bool prim(int a) {
    if (a <= 0)
        throw std::exception();
    int d = 2;
    while (d < a and a % d > 0) d++;
    return d == a;
}

void test() {
    try {
        bool b = prim(-2);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
}

class Examen {
private:
    string activitate, ora;
public:
    Examen(const string a, const string ora): activitate{a}, ora{ora} {};
    string getDescriere() {
        return activitate + " ora " + ora;
    }
    ~Examen() = default;
};

template <typename T> class ToDo {
private:
    vector<T> lista;
public:
    ToDo() = default;
    ToDo & operator<< (const T & ex) {
        lista.push_back(ex);
        return *this;
    }
    void printToDoList(ostream & stream) {
        for (Examen & ex : lista) {
            stream << "De facut: " + ex.getDescriere() << '\n';
        }
    }
    ~ToDo() = default;
};

template <typename T> class Expresie {
private:
    T val;
    stack<T> values;
public:
    Expresie(T v): val{v} {}
    T valoare() {
        return val;
    }
    Expresie operator+ (T val1) {
        values.push(val);
        this->val += val1;
        return *this;
    }
    Expresie operator- (T Val1) {
        values.push(val);
        this->val -= Val1;
        return *this;
    }
    Expresie& undo() {
        if (!values.empty()) {
            val = values.top();
            values.pop();
        }
        return *this;
    }
};

template <typename T> class catalog {
private:
    string materie;
    vector<T> note;
public:
    catalog(const string mat): materie{mat} {}
    catalog & operator+ (const T nota) {
        note.push_back(nota);
        return *this;
    }
    typename vector<T>::iterator begin() {
        return note.begin();
    }
    typename vector<T>::iterator end() {
        return note.end();
    }
};

class A {
public:
    virtual void f() {};
};

class B: public A {
public:
    void f() override {
        cout << "f din B" << '\n';
    }
};

class C: public A {
public:
    void f() override {
        cout << "f din C" << '\n';
    }
};

int main() {
    vector<Measurement<int>> v {10, 21, 3};
    std::sort(v.begin(), v.end());
    assert(v[0].value() == 3);
    cout << v[0] << v[1];
    vector<A*> b;

    return 0;
}