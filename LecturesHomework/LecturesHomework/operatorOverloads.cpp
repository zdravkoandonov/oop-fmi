#include <iostream>
#include "Contact.h"

ostream& operator<<(ostream &out, const Contact *contact)
{
	out << contact->getId() << " " << contact->getName() << " " << contact->getTelephone();
	return out;
}