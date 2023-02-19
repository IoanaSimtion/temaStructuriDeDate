#include <iostream>

using namespace std;

#pragma once


/*S2, 4:
Într-o listă liniară simplu înlănţuită, alocată dinamic, cu cel puţin 3 noduri, fiecare element 
reţine în câmpul nr un număr real, iar în câmpul urm adresa următorului element din listă
sau valoarea NULL în cazul în care este ultimul nod al listei. Dacă p reţine adresa primului 
element din listă, scrieţi o expresie C/C++ a cărei valoare este egală cu suma valorilor reale 
reţinute în primele trei noduri ale listei. */

struct Node {

	float info;

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


void functie(Node* p, float& suma) {

	int ct = 0;

	suma = 0;

	while (ct != 3) {

		suma = suma + p->info;

		p = p->urm;

		ct++;

	}

}


void solutie() {

	Lista lista;

	lista.addSfarsit(43.3);

	lista.addSfarsit(78.88);

	lista.addSfarsit(4);

	lista.addSfarsit(521);

	lista.addSfarsit(6.098);

	Node* p = lista.head;

	float s;

	functie(p, s);

	cout << s;

	//lista.afisare();

}