#include "Albero_B.h"
#include <iostream>
#include <queue>
using namespace std;



template <typename T>
void stampa_albero_ric(const AlberoB<T>& tree, unsigned liv=0) {
	// Qui che dobbiamo fare
	// Vediamo che la prima stampa nell'esempio è la "radice"
	// Poi stampa tutto ciò che viene dal ramo "SIN"
	// e poi tutto quello che viene dal ramo "DES"
	// Chiaramente, se sono "nullo()" ritorno e basta

	if (tree.nullo()) {
		return;
	}

	for (unsigned i=0 ; i < liv ; i++ ) {
		cout << "  ";
	}
	// Per prima cosa stampiamo la "radice"
	cout << tree.radice() << endl;

	// Poi richiamiamo la stampa sul figlio "sin"
	// passando liv incrementato così riusciamo a 
	// dare la "spaziatura" giusta

	liv++;

	stampa_albero_ric(tree.figlio(SIN),liv);
	stampa_albero_ric(tree.figlio(DES),liv);

	

	// Successivamente sul figlio "des"
	
}


template <typename T>
void stampa_albero(const AlberoB<T>& tree) {
	stampa_albero_ric(tree,0);
}


template <typename T>
void stampa_per_livelli(const AlberoB<T>& tree) {
	queue<AlberoB<T>> m_queue;
	cout << "[";
	m_queue.push(tree);
	while (!m_queue.empty()) {
		const AlberoB<T> current = m_queue.front();
		m_queue.pop();
		cout << " " << current.radice() ;
		if (!current.figlio(SIN).nullo()) {
			m_queue.push(current.figlio(SIN));
		}
		if (!current.figlio(DES).nullo()) {
			m_queue.push(current.figlio(DES));
		}
	}
	cout << " ]" << endl;
}


int main () {
	AlberoB<int> A(1);
	AlberoB<int> B(7);
	AlberoB<int> C(9);
	AlberoB<int> D(2);
	AlberoB<int> E(6);
	AlberoB<int> F(9);
	AlberoB<int> G(5);
	AlberoB<int> H(11);
	AlberoB<int> I(5);

	A.insFiglio(SIN,B);
	A.insFiglio(DES,C);
	B.insFiglio(SIN,D);
	B.insFiglio(DES,E);
	C.insFiglio(SIN,F);
	E.insFiglio(SIN,G);
	E.insFiglio(DES,H);
	F.insFiglio(SIN,I);


	stampa_per_livelli(A);
	return 0;
}
