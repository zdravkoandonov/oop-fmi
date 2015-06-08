#pragma once
#include "Formula.h"

using std::cout;

class Constant : public Formula
{
	double c;
public:

	Constant(double c) : c(c)
	{
	}

	virtual ~Constant()
	{
	}

	double value() const
	{
		return c;
	}

	void print() const
	{
		cout << c;
	}

	Formula* clone() const
	{
		return new Constant(*this);
	}
};

