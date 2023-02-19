#include <iostream>

using namespace std;

#pragma once


/*S2, 2:
Intr-o listă liniară simplu înlănţuită, alocată dinamic, fiecare element reţine în câmpul info
o valoare întreagă, iar în câmpul urm adresa elementului următor din listă sau NULL dacă
nu există un element următor. Variabila p reţine adresa primului element din listă.
Lista conţine, în această ordine,
pornind de la primul element,
valorile: 2, 3, 4, 5, 6, 7, 8. Ce se va
afişa în urma executării secvenţei
de instrucţiuni alăturată?
a. 2 4 6 
b. 2 4 6 8 
c. 2 4 8
d. 2 5 8
*/

struct Node {

	int info;

	Node* urm;

};

struct Lista {

	Node* head = NULL;

	void addSfarsit(int data) {

		if (head == NULL) {

			head = new Node();

			head->info = data;

			head->urm = NULL;

		}
		else {


			Node* nou = new Node();

			Node* aux = head;

			while (aux->urm != NULL) {

				aux = aux->urm;
			}

			aux->urm = nou;

			nou->info = data;

			nou->urm = NULL;

		}

	}

	void afisare() {

		Node* aux = head;

		while (aux != NULL) {

			cout << aux->info << ' ';

			aux = aux->urm;

		}
	}

};


void functie(Node* p) {

	while (p != NULL && p->urm != NULL) {

		cout << p->info;

		p->urm = p->urm->urm;

		p = p->urm;
	}

}


void solutie() {

	Lista lista;

	lista.addSfarsit(2);

	lista.addSfarsit(3);

	lista.addSfarsit(4);

	lista.addSfarsit(5);

	lista.addSfarsit(6);

	lista.addSfarsit(7);

	lista.addSfarsit(8);

	Node* p = lista.head;

	functie(p);

	//lista.afisare();

}