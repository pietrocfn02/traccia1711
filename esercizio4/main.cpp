#include "Albero_B.h"
#include <iostream>
using namespace std;



bool path_disgiunzione_rec(const AlberoB<bool>& tree) {
	// Dobbiamo controllare che in questo "path" esiste un true
	// Quindi dobbiamo controllare il path fino alla "fine" (cioe fino alle foglie)
	// oppure, se io sono "true", tutti i path che passano da "me" sono true

	if (tree.nullo()) {
		return false;
	}
	if (tree.radice()) {
		return true;
	}
	// Ricordiamoci che il true deve esistere "PER OGNI PATH"
	// quindi voglio "propagare" true solo se esiste in tutti i miei figli
	// per cui "&&"

	return path_disgiunzione_rec(tree.figlio(SIN)) && path_disgiunzione_rec(tree.figlio(DES));
}



bool path_disgiunzione(const AlberoB<bool>& tree) {
	// Per ogni percorso radice - foglia esiste almeno un "true"
	return path_disgiunzione_rec(tree);
}


bool path_congiunzione_rec(const AlberoB<bool>& tree) {

	if (tree.nullo()) {
		return true;	
	}
	// Se sono "false" questo path non va bene
	if (!tree.radice()) {
		return false;
	}

	// Arrivo qui se sono un nodo valido e "true"
	// A questo punto devo controllare se almeno uno dei miei figli è "tutto true"
	// fino alla fine
	// Per cui, cosa faccio?
	// chiamo ricorsivamente i miei figli
	// e controllo che ne esista almeno uno di tutti true
	// quindi "||"


	return path_congiunzione_rec(tree.figlio(SIN)) || path_congiunzione_rec(tree.figlio(DES));
}


bool path_congiunzione(const AlberoB<bool>& tree) {

	// Esiste almeno un percorso di tutti true
	return path_congiunzione_rec(tree);
	
}

int main () {

	AlberoB<bool> A(true);
	AlberoB<bool> B(false);
	AlberoB<bool> C(false);
	AlberoB<bool> D(false);

	A.insFiglio(SIN,B);
	A.insFiglio(DES,C);
	C.insFiglio(DES,D);

	if (path_disgiunzione(A)) {
		cout << "SI DISJ" << endl;
	}

	if (path_congiunzione(A)) {
		cout << "SI CONJ" << endl;
	}

	
	return 0;
}
