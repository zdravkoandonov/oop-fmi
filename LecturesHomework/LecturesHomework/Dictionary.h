#pragma once
#include <iostream>

using std::cout;
using std::endl;

template<typename K, typename V>
class Dictionary
{
private:
	static const int initialMaxSize = 8;
	int maxSize, size;
	K *keys;
	V *values;
	void removeAt(int index);
public:
	Dictionary();
	Dictionary(const Dictionary<K, V>&);
	Dictionary<K, V>& operator=(const Dictionary<K, V>&);
	~Dictionary();
	void copy(const Dictionary<K, V>&);
	void clear();
	void add(K, V);
	void doubleMaxSize();
	V* find(K);
	void sort();
	void printSorted();
	void remove(K);
};

template<typename K, typename V>
Dictionary<K, V>::Dictionary()
{
	maxSize = initialMaxSize;
	keys = new K[maxSize];
	values = new V[maxSize];
	size = 0;
}

template<typename K, typename V>
Dictionary<K, V>::Dictionary(const Dictionary<K, V>& other)
{
	copy(other);
}

template<typename K, typename V>
Dictionary<K, V>& Dictionary<K, V>::operator=(const Dictionary<K, V>& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

template<typename K, typename V>
void Dictionary<K, V>::copy(const Dictionary<K, V>& other)
{
	maxSize = other.maxSize;
	size = other.size;
	keys = new K[maxSize];
	values = new V[maxSize];
	for (int i = 0; i < size; i++)
	{
		keys[i] = other.keys[i];
		values[i] = other.values[i];
	}
}

template<typename K, typename V>
void Dictionary<K, V>::clear()
{
	delete[] keys;
	delete[] values;
}

template<typename K, typename V>
Dictionary<K, V>::~Dictionary()
{
	clear();
}

template<typename K, typename V>
void Dictionary<K, V>::add(K key, V value)
{
	if (size == maxSize)
		doubleMaxSize();
	keys[size] = key;
	values[size] = value;
	size++;
}

template<typename K, typename V>
void Dictionary<K, V>::doubleMaxSize()
{
	maxSize *= 2;
	K *k = new K[maxSize];
	V *v = new V[maxSize];
	for (int i = 0; i < size; i++)
	{
		k[i] = keys[i];
		v[i] = values[i];
	}
	delete keys;
	delete values;
	keys = k;
	values = v;
}

template<typename K, typename V>
V* Dictionary<K, V>::find(K key)
{
	for (int i = 0; i < size; i++)
	{
		if (keys[i] == key)
			return &(values[i]);
	}
	return NULL;
}

template<typename K, typename V>
void Dictionary<K, V>::sort()
{
	// selection sort
	int indMin;
	for (int i = 0; i < size; i++)
	{
		indMin = i;
		for (int j = i+1; j < size; j++)
		{
			if (keys[j] < keys[indMin])
			{
				indMin = j;
			}
		}
		if (i != indMin)
		{
			// swap
			K k;
			V v;
			k = keys[i];
			keys[i] = keys[indMin];
			keys[indMin] = k;
			v = values[i];
			values[i] = values[indMin];
			values[indMin] = v;
		}
	}
}

template<typename K, typename V>
void Dictionary<K, V>::printSorted()
{
	sort();
	for (int i = 0; i < size; i++)
	{
		cout << keys[i] << " " << values[i] << endl;
	}
}

template<typename K, typename V>
void Dictionary<K, V>::remove(K key)
{
	for (int i = 0; i < size; i++)
	{
		if (keys[i] == key)
		{
			removeAt(i);
			return;
		}
	}
}

template<typename K, typename V>
void Dictionary<K, V>::removeAt(int index)
{
	size--;
	for (int i = index; i < size; i++)
	{
		keys[i] = keys[i+1];
		values[i] = values[i+1];
	}
}