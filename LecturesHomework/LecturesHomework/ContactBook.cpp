#include "Contact.h"
#include "ContactBook.h"

int ContactBook::lastId = 0;

ContactBook::ContactBook()
{
}

ContactBook::~ContactBook()
{
}

void ContactBook::addContact(Contact& contact)
{
	// create a copy of the contact
	Contact *c = new Contact(contact);
	c->setId(lastId++);

	// add it to all dictionaries
	names.add(c->getName(), c);
	telephones.add(c->getTelephone(), c);
	ids.add(c->getId(), c);
}

const Contact* ContactBook::findContact(string nameOrTel)
{
	// name first
	Contact **c = names.find(nameOrTel);
	if (c != NULL)
		return *c;

	// telephone second
	c = telephones.find(nameOrTel);
	if (c == NULL)
		return NULL;
	return *c;
}

const Contact* ContactBook::findContact(int id)
{
	Contact **c = ids.find(id);
	if (c == NULL)
		return NULL;
	return *c;
}

void ContactBook::printSorted(prop p)
{
	switch (p)
	{
	case NAME:
		names.printSorted();
		break;
	case TEL:
		telephones.printSorted();
		break;
	case ID:
		ids.printSorted();
		break;
	default:
		break;
	}
}
void ContactBook::removeContact(int id)
{
	Contact **c = ids.find(id);
	if (c != NULL)
	{
		Contact *p = *c;
		names.remove(p->getName());
		telephones.remove(p->getTelephone());
		ids.remove(id);
		delete p;
	}
}