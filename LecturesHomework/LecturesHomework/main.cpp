#include <iostream>
#include "Dictionary.h"
#include "Contact.h"
#include "ContactBook.h"

using namespace std;

int main()
{
	Dictionary<int, int> d;
	d.add(1, 11);
	d.add(5, 15);
	d.add(2, 12);
	d.add(3, 13);
	d.printSorted();
	cout << *(d.find(3)) << endl;

	ContactBook cb;
	Contact a = Contact("Zdravko", "+359867123123");
	cb.addContact(a);
	cout << cb.findContact("Zdravko")->getId() << endl;
	Contact b = Contact("Pesho", "++35900000");
	cb.addContact(b);
	cout << cb.findContact("++35900000")->getId() << endl;
	cb.printSorted(ContactBook::prop::NAME);
	cout << cb.findContact("++35900000")->getName() << endl;
	cout << cb.findContact("++35900000")->getTelephone() << endl;
	cb.removeContact(1);
	cb.printSorted(ContactBook::prop::NAME);

	getchar();
	return 0;
}