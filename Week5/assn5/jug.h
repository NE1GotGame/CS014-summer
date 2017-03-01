#ifndef _JUG_H_
#define _JUG_H_

#include <cassert>

using namespace std;

class Jug{

public:
	Jug(int Ca, //capacity of jug A
		int Cb,  //capacity of jug B
		int N,  //GOAL
		int fA, // cost to fill A
		int fB,  // cost to fill B
		int eA, // cost to empty A
		int eB,  // cost to empty B
		int pAB,  //cost pour B to A
		int pBA){ // cost pour A to B

		this->Ca = Ca;
		this->Cb = Cb;
		this->N = N;
		this->fA = fA;
		this->fB = fB;
		this->eA = eA;
		this->eB = eB;
		this->pAB = pAB;
		this->pBA = pBA;

		assert(0 < Ca);
		assert(Ca <= Cb);

		assert(N <= Cb);
		assert(Cb <= 1000);


	}

	~Jug(){}

	int Solve();

private:

	int	Ca, //capacity of jug A
		Cb,  //capacity of jug B
		N,  //GOAL
		fA, // cost to fill A
		fB,  // cost to fill B
		eA, // cost to empty A
		eB,  // cost to empty B
		pAB,  //cost pour A to B
		pBA; // cost pour B to A

};

#endif //_JUG_H_