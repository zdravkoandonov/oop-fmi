#pragma once
#include "Dictionary.h"
#include <string>

using std::string;

class ContactBook
{
private:
	Dictionary<string, Contact*> names;
	Dictionary<string, Contact*> telephones;
	Dictionary<int, Contact*> ids;
	static int lastId;

public:
	enum prop { NAME, TEL, ID };

public:
	ContactBook();
	~ContactBook();
	void addContact(Contact&);
	const Contact* findContact(string);
	const Contact* findContact(int);
	void printSorted(prop);
	void removeContact(int);
};

