#include "node.h"

#pragma once

struct Lista {

	Node* head = NULL;


	void afisare() {

		Node* aux = head;

		while (aux != NULL) {

			cout << aux->data << ' ';

			aux = aux->next;

		}
	}


	void addStart(int data) {

		if (head == NULL) {

			head = new Node();

			head->data = data;

			head->next = NULL;

		}
		else {

			Node* nou = new Node();

			nou->data = data;

			nou->next = head;

			head = nou;

		}
	}


	void addSfarsit(int data) {

		if (head == NULL) {

			head = new Node();

			head->data = data;

			head->next = NULL;

		}
		else {


			Node* nou = new Node();

			Node* aux = head;

			while (aux->next != NULL) {

				aux = aux->next;
			}

			aux->next = nou;

			nou->data = data;

			nou->next = NULL;

		}

	}


	void addPozitie(int poz, int data) {

		if (poz == 0) {

			addStart(data);

			return;
		}

		Node* aux = head;

		int ct = 0;

		while (aux != NULL && ct != poz - 1) {

			aux = aux->next;

			ct++;
		}

		if (aux == NULL) {

			addSfarsit(data);

			return;
		}

		Node* nou = new Node();

		nou->data = data;

		nou->next = aux->next;

		aux->next = nou;

	}


	void stergereStart() {

		head = head->next;

	}


	void stergereSfarsit() {

		Node* aux = head;

		while (aux->next->next != NULL) {

			aux = aux->next;

		}

		aux->next = NULL;

	}


	void stergerePozitie(int poz) {

		Node* aux = head;

		int ct = 0;

		if (poz == 0) {

			stergereStart();

			return;
		}

		while (aux != NULL && ct != poz - 1) {

			aux = aux->next;

			ct++;

		}

		if (aux == NULL) {

			stergereSfarsit();

			return;

		}

		aux->next = aux->next->next;

	}


	int size() {

		int ct = 0;

		Node* aux = head;

		while (aux != NULL) {

			aux = aux->next;

			ct++;

		}

		return ct;

	}


	void setareValoarePoz(int poz, int data) {

		Node* aux = head;

		int ct = 0;

		while (aux->next != NULL && ct != poz) {

			aux = aux->next;

			ct++;

		}

		aux->data = data;

	}


	void sortCrescator() {

		bool flag = 0;

		do {

			Node* aux = head;

			flag = 1;

			for (int i = 0; i < size() - 1; i++) {

				if (aux->data > aux->next->data) {

					int data = aux->data;

					setareValoarePoz(i, aux->next->data);

					setareValoarePoz(i + 1, data);

					flag = 0;

				}

				aux = aux->next;
			}

		} while (flag == 0);
	}


	Node* iterator() {

		return this->head;
	}


	Node* getNode(int poz) {

		int ct = 0;

		Node* aux = head;

		while (aux != NULL && ct != poz) {

			aux = aux->next;

			ct++;

		}

		return aux;
	}
	
};