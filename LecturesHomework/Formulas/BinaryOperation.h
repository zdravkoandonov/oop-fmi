#pragma once
#include "Formula.h"

using std::cout;

class BinaryOperation : public Formula
{
	char op;
	Formula *c1, *c2;
	double calcOp(double a, double b, char operation) const
	{
		switch (operation)
		{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '<':
			return a < b;
		case '=':
			return a == b;
		default:
			return 0;
			break;
		}
	}
public:

	BinaryOperation(char op, Formula *c1, Formula *c2)
		: op(op)
	{
		this->c1 = c1->clone();
		this->c2 = c2->clone();
	}

	BinaryOperation(const BinaryOperation& other)
	{
		this->op = other.op;
		this->c1 = other.c1->clone();
		this->c2 = other.c2->clone();
	}

	BinaryOperation& operator=(const BinaryOperation& other)
	{
		if (this != &other)
		{
			this->op = other.op;
			delete[] c1;
			delete[] c2;
			this->c1 = other.c1->clone();
			this->c2 = other.c2->clone();
		}
		return *this;
	}

	virtual ~BinaryOperation()
	{
		delete[] c1;
		delete[] c2;
	}

	double value() const
	{
		return calcOp(c1->value(), c2->value(), op);
	}

	void print() const
	{
		cout << "( ";
		c1->print();
		cout << " " << op << " ";
		c2->print();
		cout << " )";
	}

	Formula* clone() const
	{
		return new BinaryOperation(*this);
	}
};

