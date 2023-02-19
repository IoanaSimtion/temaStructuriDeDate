#include <iostream>

using namespace std;

#pragma once


/*S2, 4:
Într-o listă liniară simplu înlănţuită, alocată
dinamic, cu cel puţin 4 elemente, fiecare element 
reţine în câmpul urm adresa elementului următor 
sau NULL dacă nu există un element următor, iar 
în câmpul info o valoare întreagă. Ştiind că
variabila p reţine adresa primului element din listă, 
înlocuiţi punctele de suspensie cu expresiile 
corespunzătoare, astfel încât secvenţa alăturată
să calculeze în variabila s suma tuturor valorilor 
elementelor listei.
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


void functie(Node* p, int& s) {

	s = 0;

	while (p->urm != NULL) {

		p = p->urm;

		s = s + p->info;
		
	}

	cout << s;

}


void solutie() {

	Lista lista;

	lista.addSfarsit(124);

	lista.addSfarsit(1020);

	lista.addSfarsit(511);

	lista.addSfarsit(289);

	lista.addSfarsit(222);

	Node* p = lista.head;

	int s;

	//functie(p, s);
		

	lista.afisare();

}