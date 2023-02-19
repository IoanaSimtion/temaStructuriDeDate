#include <iostream>

using namespace std;

#pragma once


/*S2, 2:
Într-o listă liniară simplu înlănţuită, alocată dinamic, fiecare element reţine în câmpul inf
un număr întreg, iar în câmpul urm adresa următorului nod din listă sau NULL în cazul
ultimului nod al listei. Adresa primului element al listei este reţinută în variabila prim, iar p
este o variabilă de acelaşi tip cu prim. Dacă în listă sunt memorate, în această ordine,
numerele 1, 2, 3, 4 ca în figura de mai jos, care va fi conţinutul listei în urma executării
secvenţei de instrucţiuni alăturate? 
a. 1 3 2 4 
b. 2 3 4 1 
c. 4 1 2 3 
d. 1 4 3 2
*/

struct Node {

	int inf;

	Node* urm;

};

struct Lista {

	Node* head = NULL;

	void addSfarsit(int data) {

		if (head == NULL) {

			head = new Node();

			head->inf = data;

			head->urm = NULL;

		}
		else {


			Node* nou = new Node();

			Node* aux = head;

			while (aux->urm != NULL) {

				aux = aux->urm;
			}

			aux->urm = nou;

			nou->inf = data;

			nou->urm = NULL;

		}

	}

	void afisare() {

		Node* aux = head;

		while (aux != NULL) {

			cout << aux->inf << ' ';

			aux = aux->urm;

		}
	}

};


void functie(Node* prim) {

	Node* p;

	p = prim;

	prim = p->urm;

	p->urm = NULL;

	prim->urm->urm->urm = p;

}


void solutie() {

	Lista lista;

	lista.addSfarsit(1);
	
	lista.addSfarsit(2);

	lista.addSfarsit(3);

	lista.addSfarsit(4);

	Node* prim = lista.head;

	functie(prim);

	lista.afisare();

}