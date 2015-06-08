#include <iostream>
#include <string>
#include <cstdlib>
#include "Formula.h"
#include "Constant.h"
#include "BinaryOperation.h"
#include "Read.h"
#include "Conditional.h"

using std::cin;
using std::string;

Formula* readFormula()
{
	Formula *result;
	string s;
	cin >> s;
	if ((s[0] >= '0' && s[0] <= '9') || s[0] == '-')
		return new Constant(atof(s.c_str()));
	if (s == "(")
	{
		// read binary operation
		Formula *f1 = readFormula();
		char c;
		cin >> c;
		Formula *f2 = readFormula();
		string endBrace;
		cin >> endBrace;
		return new BinaryOperation(c, f1, f2);
	}
	if (s == "Read")
		return new Read();
	if (s == "if")
	{
		// read conditional statement
		Formula *cond, *f1, *f2;
		cond = readFormula();
		string thenSkip;
		cin >> thenSkip;
		f1 = readFormula();
		string elseSkip;
		cin >> elseSkip;
		f2 = readFormula();
		return new Conditional(cond, f1, f2);
	}
}