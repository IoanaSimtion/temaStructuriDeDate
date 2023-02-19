#include <iostream>

using namespace std;

#pragma once

/*S2, 2:
O listă liniară simplu înlănţuită cu
cel puţin două elemente, alocată
dinamic, reţine în câmpul info al
fiecărui element câte un număr
natural de maximum 4 cifre, iar în
câmpul urm adresa elementului
următor din listă sau NULL dacă nu
există un element următor.
Dacă variabila p reţine adresa primului element al listei atunci, în urma executării secvenţei
de program de mai sus se afişează întotdeauna:
a. cea mai mică dintre valorile memorate de
elementele din listă
b. cea mai mare dintre valorile memorate de
elementele din listă
c. valoarea memorată de penultimul
element din listă
d. valoarea memorată de primul element din
listă*/

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
	
	while (p->urm != NULL){

		if (p->urm->info < p->info) {

			p->urm->info = p->info;

		}

		p = p->urm;

	}

	cout << p->info;

}


void solutie() {

	Lista lista;

	lista.addSfarsit(12);

	lista.addSfarsit(100);

	lista.addSfarsit(11);

	lista.addSfarsit(200);

	lista.addSfarsit(2);

	Node* p = lista.head;

	functie(p);
	
	//lista.afisare();
	
}

