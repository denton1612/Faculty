#pragma once

typedef int TElem;
#include <iostream>
using namespace std;
typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {

	friend class IteratorColectie;

private:
	TElem * val;
    int* st;
    int* dr;
    int rad;
    int primLiber;
    int cp;
    int lg;

    void initSpLiber();

    int aloca();

    void dealoca(int i);

    void redim();

    int creeazaNod(TElem e);

    int minim(int p) const;

    int maxim(int p) const;

    int adaugaRec(int p, int e);

    int stergeRec(int p, int e);

    int cautaRec(int p, int e) const;

public:

    //constructorul implicit
		Colectie();

    //adauga un element in colectie
    // Complexitate:
    /*
     * Theta(log2(h)) - h = inaltimea arborelui
     */
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
        /*
         * Complexitate:
         * Theta(log2(h)) - h = inaltimea arborelui
         */
		bool sterge(TElem e);

        // Complexitate:
        /*
        * Theta(log2(h)) - h = inaltimea arborelui
        */
		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

        int diferenta() const;

        void valori() {
            for (int i = 0; i < lg; i++)
                cout << val[i] << " ";
            cout << endl;
        }

        void stanga() {
            for (int i = 0; i < lg; i++)
                cout << st[i] << " ";
            cout << endl;
        }

        void dreapta() {
            for (int i = 0; i < lg; i++)
                cout << dr[i] << " ";
            cout << endl;
        }

        void get_rad() {
            cout << rad << endl;
        }

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();


};

