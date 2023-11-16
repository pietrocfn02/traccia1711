#include "Albero_B.h"
#include <iostream>
#include <queue>
using namespace std;

bool pari_dispari_ric(const AlberoB<int>& tree, int livello) {

	if (tree.nullo()) {
		return true;
	}
	if (tree.radice() % 2 != livello % 2) {
		return false;
	}
	livello++;
	return pari_dispari_ric(tree.figlio(SIN),livello) && pari_dispari_ric(tree.figlio(DES),livello);
} 



bool pari_dispari(const AlberoB<int>& tree) {
	return pari_dispari_ric(tree,1);
}


bool pari_dispari_per_livelli(const AlberoB<int>& tree) {
	queue<pair<AlberoB<int>,int>> q;
	int livello = 1;
	q.push(make_pair(tree,livello));
	
	while (!q.empty()) {

		pair<AlberoB<int>,int> current = q.front();
		q.pop();
		if (current.first.radice() % 2 != current.second % 2) {
			return false;
		}

		if (!current.first.figlio(SIN).nullo()) {
			q.push(make_pair(current.first.figlio(SIN),current.second+1));
		}
		if (!current.first.figlio(DES).nullo()) {
			q.push(make_pair(current.first.figlio(DES), current.second+1));
		}
	}// end while

	return true;
}


int main () {

	AlberoB<int> tree(1);
	AlberoB<int> l_2(2);
	AlberoB<int> r_2(2);
	AlberoB<int> ll_3(3);
	AlberoB<int> lr_3(3);
	AlberoB<int> rl_3(3);
	AlberoB<int> rr_3(3);
	AlberoB<int> rlr_4(4);

	tree.insFiglio(SIN,l_2);
	tree.insFiglio(DES,r_2);

	l_2.insFiglio(SIN,ll_3);
	l_2.insFiglio(DES,lr_3);

	r_2.insFiglio(SIN,rl_3);
	r_2.insFiglio(DES,rr_3);

	rl_3.insFiglio(DES,rlr_4);

	if (pari_dispari_per_livelli(tree)) {
		cout << "Questo albero è ok" << endl;
	}
	else {
		cout << "Questo albero NON è ok " << endl;
	}

	return 0;
	
}
