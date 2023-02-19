#include <iostream>

using namespace std;

#pragma once


/*S2, 2:
Într-o listă liniară simplu înlănţuită, alocată dinamic, fiecare element reţine în câmpul inf
un număr întreg, iar în câmpul ref adresa următorului nod din listă sau NULL în cazul
ultimului element al listei.
2.
Adresa primului element al listei este reţinută în
variabila prim, iar variabila p este de acelaşi tip cu
prim. Dacă în listă sunt memorate, în această
ordine, numerele 3, 5, 18, 20, ce se va afişa pe
ecran în urma executării secvenţei alăturate de
program?
a. 21 
b. 25 
c. 5
d. 46
*/


struct Node {

	int inf;

	Node* ref;

};

struct Lista {

	Node* head = NULL;

	void addSfarsit(int data) {

		if (head == NULL) {

			head = new Node();

			head->inf = data;

			head->ref = NULL;

		}
		else {


			Node* nou = new Node();

			Node* aux = head;

			while (aux->ref != NULL) {

				aux = aux->ref;
			}

			aux->ref = nou;

			nou->inf = data;

			nou->ref = NULL;

		}

	}

	void afisare() {

		Node* aux = head;

		while (aux != NULL) {

			cout << aux->inf << ' ';

			aux = aux->ref;

		}
	}

};


void functie(Node* prim) {

	Node* p;
	
	int s = 0;

	p = prim; 
	
	while (p->ref != NULL){

		if (p->inf % 5 == 0) {

			s = s + p->inf;

		}

		p = p->ref;

	}

	cout << s;

}


void solutie() {

	Lista lista;

	lista.addSfarsit(3);

	lista.addSfarsit(5);

	lista.addSfarsit(18);

	lista.addSfarsit(20);

	Node* prim = lista.head;

	functie(prim);

	//lista.afisare();

}