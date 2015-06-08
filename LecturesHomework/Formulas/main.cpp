#include <iostream>
#include "Formula.h"
#include "Constant.h"
#include "BinaryOperation.h"
#include "Read.h"
#include "Conditional.h"

int main()
{
	Constant c1 (1);
	Constant* c2 = new Constant (2);
	BinaryOperation f1 ('+', &c1, c2);
	BinaryOperation f2 = f1;    // копиране
	f2 = f1;         // присвояване
	delete c2;

	Formula *f = readFormula();
	f->print();
	cout << f->value();
	delete f;

	getchar();
	return 0;
}