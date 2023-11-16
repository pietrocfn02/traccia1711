#include "Albero_B.h"
#include <iostream>
using namespace std;


// Perche questo esercizio è maledettamente scomodo se volessimo farlo con la visita per livelli?

int somma_path_ric(const AlberoB<int>& tree, int current_sum, int total) {

	if (tree.nullo()) {
		return 0;
	}
	if (tree.foglia()) {
		// Siamo "oltre" una foglia per cui abbiamo finito un "path" e dobbiamo quindi incrementare il 
		// "total" con il valore che ha il path "corrente"
		total+=10* current_sum + tree.radice();
		return total;
	}
	// se invece il sottoalbero è "buono"
	// dobbiamo incrementare il valore che abbiamo all'interno del "path corrente"

	int updated_sum = 10*current_sum + tree.radice();
	return somma_path_ric(tree.figlio(SIN),updated_sum,total) + somma_path_ric(tree.figlio(DES),updated_sum,total);
}



int somma_path(const AlberoB<int>& tree) {
	return somma_path_ric(tree,0,0);
	
}


int main() {
	AlberoB<int> A(1);
	AlberoB<int> B(2);
	AlberoB<int> C(3);
	AlberoB<int> D(4);

	A.insFiglio(SIN,B);
	A.insFiglio(DES,C);
	C.insFiglio(DES,D);

	cout << somma_path(A) << endl;
	
	return 0;
}
