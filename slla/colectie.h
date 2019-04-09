#ifndef COLECTIE_H
#define COLECTIE_H

typedef int TElem;

#define CAPACITATE 100

class Iterator;
class Colectie {
private:
	static const int cp = CAPACITATE;
	//vectorul static de elemente de tip TElem (cu spatiu fix de memorare - CAPACITATE)
	TElem e[cp];
	//vectorul static pentru egaturi
	int urm[cp];
	
	int prim;	
	int primLiber;

	//functii pentru alocarea/dealocarea unui spatiu liber
	//se returneaza pozitia unui spatiu liber in lista
	int aloca();
	//dealoca spatiul de indice i
	void dealoca(int i);
	
	int creeazaNod(TElem e);
public:
	
	friend class Iterator;
	Colectie();
	
	void adauga(TElem elem);

	Iterator iterator() const;	
	~Colectie() {};

};


class Iterator {
private:
	//pentru a construi un iterator pe o colectie este necesar ca un pointer sau referinta la aceasta sa ii fie oferit constructorului
	Iterator(const Colectie& col);
	//contine o referinta catre colectia care se itereaza
	const Colectie& colectie;
	//retine pozitia curenta in interiorul colectiei - referintala nodul curent din lista asociata
	int curent;
public:

	friend class Colectie;

	//reseteaza pozitia iteratorului la inceputul colectiei
	void prim();
	//muta iteratorul pe urmatoarea pozitie in cadrul colectiei
	void urmator();
	//verifica daca iteratorul e valid (indica un element al colectiei)
	bool valid() const;
	//returneaza valoarea curenta a elementului din colectie
	TElem element() const;
};

#endif