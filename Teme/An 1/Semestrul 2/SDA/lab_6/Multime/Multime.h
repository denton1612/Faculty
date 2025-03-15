#pragma once

#define MAX 100000
#define NULL_TELEM -1
#define NIL nullptr
typedef int TElem;

class IteratorMultime;
class Nod;

typedef Nod* Pnod;

class Nod{
    friend class Multime;
    friend class IteratorMultime;
private:
    TElem e;
    Pnod urm;
public:
    Nod(TElem& e, Pnod& urm): e{e}, urm{urm} {

    };

};

class Multime {
	friend class IteratorMultime;
    friend class Nod;
    private:
        int m;
        int size;
        Pnod td[MAX];
        int d(TElem e) const;

    public:
 		//constructorul implicit
		Multime();

		//adauga un element in multime
		//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
		bool adauga(TElem e);

		//sterge un element din multime
		//returneaza adevarat daca elementul a existat si a fost sters
		bool sterge(TElem e);

		//verifica daca un element se afla in multime
		bool cauta(TElem elem) const;


		//intoarce numarul de elemente din multime;
		int dim() const;

		//verifica daca multimea e vida;
		bool vida() const;

        // pastreaza doar elementele comune (intersectia multimilor se salveaza)
        void intersectie(const Multime& b);

		//returneaza un iterator pe multime
		IteratorMultime iterator() const;

		// destructorul multimii
		~Multime();
};




