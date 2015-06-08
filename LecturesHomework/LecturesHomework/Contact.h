#pragma once
#include <string>

using std::string;
using std::ostream;

class Contact
{
private:
	string name;
	string telephone;
	int id;

public:
	Contact(string name, string telephone)
		: name(name), telephone(telephone)
	{ 
		// default id
		id = -1;
	}
	Contact(const Contact& other)
	{
		name = other.name;
		telephone = other.telephone;
		id = other.id;
	}
	string getName() const
	{
		return name;
	}
	string getTelephone() const
	{
		return telephone;
	}
	int getId() const
	{
		return id;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setTelephone(string telephone)
	{
		this->telephone = telephone;
	}
	void setId(int id)
	{
		this->id = id;
	}
	friend ostream& operator<<(ostream &out, const Contact *contact);
};

