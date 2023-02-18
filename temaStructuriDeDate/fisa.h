#include <iostream>

#include <fstream>

#include "lista.h";

using namespace std;

#pragma once


void citireLista(Lista& lista) {

	ifstream f("lista.txt");

	int n, x;

	f >> n;

	for (int i = 0; i < n; i++) {

		f >> x;

		lista.addSfarsit(x);

	}
	
}

void citireLista2(Lista& lista) {

	ifstream f("lista2.txt");

	int n, x;

	f >> n;

	for (int i = 0; i < n; i++) {

		f >> x;

		lista.addSfarsit(x);

	}
	
}



//exercitiul 31


//todo functie ce sterge elementele unei liste pentru a obtine un sir strict cresc

void stergereCresc(Lista& lista) {

	for (int i = 1; i < lista.size(); i++) {

		if (lista.getNode(i) <= lista.getNode(i - 1)) {

			lista.stergerePozitie(i);

			i--;
		}

	}

}


void sol31() {

	Lista x;

	citireLista(x);

	cout << "Lista initiala: " << endl << endl;

	x.afisare();

	cout << endl << endl;

	cout << "Lista finala: " << endl << endl;

	stergereCresc(x);

	x.afisare();

	cout << endl << endl;

}


//exercitiul 32


//todo functie ce returneaza prima cifra

int primaCifra(int n) {

	while (n > 9) {

		n /= 10;

	}

	return n % 10;
}


//todo functie ce afiseaza elementele grupate dupa cifra dominanta

void afisareElemCifrDom(Lista lista) {

	int ct = 0;

	for (int c = 1; c < 10 && ct < lista.size(); c++) {

		for (int i = 0; i < lista.size(); i++) {

			if (primaCifra(lista.getNode(i)->data) == c) {

				cout << lista.getNode(i)->data << " ";

				ct++;

			}

		}

		cout << endl;

	}

}


void sol32() {

	Lista x;

	citireLista(x);

	cout << "Lista: " << endl << endl;

	x.afisare();

	cout << endl << endl;

	cout << "Grupuri: " << endl << endl;

	afisareElemCifrDom(x);

	cout << endl;

}


//exercitiul 33


//todo functie ce memoreaza fr cifelor unui nr

void frecventaCifre(int fr[], int n) {

	while (n) {

		fr[n % 10]++;

		n /= 10;

	}
}


//todo functie ce returneaza nr de cifre distincte a unui nr

int nrCifreDistincte(int n) {

int ct = 0, fr[100]{};

frecventaCifre(fr, n);

for (int i = 0; i < 10; i++) {

	if (fr[i] != 0) {

		ct++;

	}
}

return ct;

}


//todo functie ce sorteaza elem desc in fucntie ce nr de cifre distincte

void sortDesc(Lista& lista) {

	bool flag = 0;

	do {

		flag = 1;

		for (int i = 0; i < lista.size() - 1; i++) {

			if (nrCifreDistincte(lista.getNode(i)->data) < nrCifreDistincte(lista.getNode(i + 1)->data)) {

				int data = lista.getNode(i)->data;

				lista.setareValoarePoz(i, lista.getNode(i + 1)->data);

				lista.setareValoarePoz(i + 1, data);

				flag = 0;

			}

		}

	} while (flag == 0);
}


void sol33() {

	Lista x;

	citireLista(x);

	cout << "Lista initiala: " << endl << endl;

	x.afisare();

	cout << endl << endl;

	cout << "Lista finala: " << endl << endl;

	sortDesc(x);

	x.afisare();

	cout << endl << endl;
}


//exercitiul 34


//todo functtie ce ordoneaza cresc nr din lista


void sortCresc(Lista& lista) {

	bool flag = 0;

	do {

		flag = 1;

		for (int i = 0; i < lista.size() - 1; i++) {

			if (int(lista.getNode(i)->data) > int(lista.getNode(i + 1)->data)) {

				int data = lista.getNode(i)->data;

				lista.setareValoarePoz(i, lista.getNode(i + 1)->data);

				lista.setareValoarePoz(i + 1, data);

				flag = 0;

			}
			else {

				if (int(lista.getNode(i)->data) == int(lista.getNode(i + 1)->data)) {

					if (lista.getNode(i)->data - int(lista.getNode(i)->data) < lista.getNode(i + 1)->data - int(lista.getNode(i + 1)->data)) {

						int data = lista.getNode(i)->data;

						lista.setareValoarePoz(i, lista.getNode(i + 1)->data);

						lista.setareValoarePoz(i + 1, data);

						flag = 0;

					}
}
			}

		}

	} while (flag == 0);
}


void sol34() {

	Lista x;

	citireLista(x);

	cout << "Lista initiala: " << endl << endl;

	x.afisare();

	cout << endl << endl;

	cout << "Lista finala: " << endl << endl;

	sortCresc(x);

	x.afisare();

	cout << endl << endl;
}



//exercitiul 35


//todo functie ce afiseaza perechile de fr cu val max

void afisareFractii(Lista lista) {

	for (int i = lista.size() - 1, j = 0; i != j; i--, j++) {

		cout << lista.getNode(i) << " " << lista.getNode(j) << endl;

	}

}



void sol35() {

	Lista x;

	citireLista(x);

	cout << "Lista: " << endl << endl;

	x.afisare();

	cout << endl << endl;

	cout << "Perechi (numarator - numitor): " << endl << endl;

	x.sortCrescator();

	afisareFractii(x);

	cout << endl << endl;
}




//exercitiul 41


//todo functie ce interclaseaza valorile pare din liste


void interclasareListe(Lista l1, Lista l2, Lista& l3) {

	int i = 0, j = 0;

	int n = l1.size(), m = l2.size();

	while (i < n && j < m) {

		if (l1.getNode(i)->data < l2.getNode(j)->data) {

			if (l1.getNode(i)->data % 2 == 0) {

				l3.addSfarsit(l1.getNode(i)->data);

			}

			i++;
		}
		else {

			if (l2.getNode(i)->data % 2 == 0) {

				l3.addSfarsit(l2.getNode(i)->data);

			}

			j++;

		}

	}

	if (j >= m) {

		while (i < n) {

			if (l1.getNode(i)->data % 2 == 0) {

				l3.addSfarsit(l1.getNode(i)->data);

			}

			i++;
		}

	}

	if (i >= n) {

		while (j < m) {

			if (l2.getNode(j)->data % 2 == 0) {

				l3.addSfarsit(l2.getNode(j)->data);

			}

			j++;

		}

	}
}



void sol41() {

	Lista x, y, z;

	citireLista(x);

	x.sortCrescator();

	citireLista2(y);

	y.sortCrescator();

	cout << "Lista 1: " << endl << endl;

	x.afisare();

	cout << endl << endl;
	
	cout << "Lista 2: " << endl << endl;

	y.afisare();

	cout << endl << endl;

	cout << "Lista finala: " << endl << endl;

	interclasareListe(x, y, z);
	
	z.afisare();

	cout << endl << endl;

}


