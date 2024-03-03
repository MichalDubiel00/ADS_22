#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size, double threshold) 
{
	this->size = size;
	hashTable = new vector<int>(size, -1);
	collisionCount = 0;
	elements = 0;
	threshold_rehashing = threshold;
}

HashTable::~HashTable()
{
	delete this->hashTable;
}

// Berechnung des Hashwertes mit quadr. Sondieren
int HashTable::hashValue(int item,int hV) 
{
	int value = 0;
	int i = 0;
	// Lineares Sondieren
	// Quadratisches Sondieren (standardmäßig)
	// Doppeltes Hashing
	switch (hV)
	{
	

	case 1:
		
		value = (item + i * i) % size;


		while (hashTable->at(value) != -1) {
			i++;
			value = (item + i * i) % size;
			collisionCount++;
		}
		return value;
	case 2:
		value = (item + i) % size;


		while (hashTable->at(value) != -1) {
			i++;
			value = (item + i) % size;
			collisionCount++;
		}
		return value;
	case 3:
		i = -1;
		while (hashTable->at((item + i * (get_next_Prime(size) - (item % get_next_Prime((hashTable->size() - 1))))) % (hashTable->size() - 1)) != -1)
		{
			i++;
			collisionCount++;
		}
		return (item + i * (get_next_Prime(size) - (item % get_next_Prime((size))))) % (size);
	}
}

void HashTable::rehashing()
{

	cout << "rehashing!! " << elements << "/" << size << "||" << (double)elements / (double)size << endl;

	HashTable* newHash = new HashTable(get_next_Prime(this->size * 2));


	cout << "Rehashing" << newHash->getSize() << endl;

	for (int i = 0; i < this->size; i++) {
		if (this->hashTable->at(i) != -1)
			newHash->insert(this->hashTable->at(i));
	}

	this->size = newHash->getSize();
	this->elements = newHash->getElements();
	this->collisionCount = newHash->getCollisionCount();
	this->hashTable = newHash->hashTable;
}

int HashTable::insert(int item) 
{
	hashTable->at(hashValue(item,hV)) = item;

	if (elements + 1 >= (this->size * 0.7) && get_next_Prime(this->size) < 1000) {
		rehashing();
	}
	else {
		elements++;
	}
	

	return 0;
}


int HashTable::at(int i) 
{
	return hashTable->at(i);
}

int HashTable::getCollisionCount() 
{
	return this->collisionCount;
}

int HashTable::getSize() 
{
	return this->size;
}

int HashTable::getHv()
{
	return this->hV;
}

void HashTable::setHv(int hv)
{
	this->hV = hV;
}

int HashTable::getElements() 
{
	return this->elements;
}

void HashTable::print()
{
	for (int i = 0; i < size; i++)
	{
		if (hashTable->at(i)!= -1)
			cout << "[" << i<< "] -->" << hashTable->at(i) << endl;
	}
}

int get_next_Prime(int x)
{
	x = x + 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x += 1;
	}
}

int get_prev_Prime(int x)
{
	if (x==0)
	{
		return 0;
	}
	x = x - 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x -= 1;
	}
}

