#pragma once
#include "Formula.h"

using std::cin;

class Read :
	public Formula
{
public:

	Read()
	{
	}

	virtual ~Read()
	{
	}

	double value() const
	{
		double d;
		cin >> d;
		return d;
	}

	void print() const
	{
		cout << "Read";
	}

	Formula* clone() const
	{
		return new Read(*this);
	}
};

