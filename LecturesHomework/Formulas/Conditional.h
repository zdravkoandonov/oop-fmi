#pragma once
#include "Formula.h"
class Conditional :
	public Formula
{
	Formula *cond, *f1, *f2;
public:

	Conditional(Formula *cond, Formula *f1, Formula *f2)
	{
		this->cond = cond->clone();
		this->f1 = f1->clone();
		this->f2 = f2->clone();
	}

	Conditional(const Conditional& other)
	{
		this->cond = other.cond->clone();
		this->f1 = other.f1->clone();
		this->f2 = other.f2->clone();
	}

	Conditional& operator=(const Conditional& other)
	{
		if (this != &other)
		{
			delete[] cond;
			delete[] f1;
			delete[] f2;
			this->cond = other.cond->clone();
			this->f1 = other.f1->clone();
			this->f2 = other.f2->clone();
		}
		return *this;
	}

	virtual ~Conditional()
	{
		delete[] cond;
		delete[] f1;
		delete[] f2;
	}

	double value() const
	{
		if (cond->value())
			return f1->value();
		else
			return f2->value();
	}

	void print() const
	{
		cout << "if ";
		cond->print();
		cout << " then ";
		f1->print();
		cout << " else ";
		f2->print();
	}

	Formula* clone() const
	{
		return new Conditional(*this);
	}
};

