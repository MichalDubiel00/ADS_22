/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

// Ihr Code hier:



//
////////////////////////////////////

Ring::Ring()
{
	anker = new RingNode;
	countNodes = 0;
}

void Ring::addNewNode(std::string descrition, std::string symbolicData)
{
	
	RingNode* ptr = new RingNode(0,descrition,symbolicData);
	if (countNodes == 0)
	{
		anker = ptr;
		anker->setNext(ptr);
		countNodes++;
	}
	else if (countNodes == 6)
	{
		RingNode* del = anker->getNext();
		ptr->setNext(anker->getNext()->getNext());
		anker->setNext(ptr);
		anker = ptr;
		delete  del;

	}
	else
	{
		ptr->setNext(anker->getNext());
		anker->setNext(ptr);
		anker = ptr;
		countNodes++;
	}
	RingNode* node = anker;
	for (int i = countNodes - 1; i > 0; i--)
	{
		node = node->getNext();
		node->setAge(i);
	}
}

bool Ring::search(std::string search)
{
	RingNode* ptr = anker;
	while (ptr->getData() != search && ptr->getNext() != anker)
		ptr = ptr->getNext();
	if (ptr->getData() == search)
	{
		std::cout << "Alter: " << ptr->getAge() << ", Beschreibung: " << ptr->getDescription() << ", Daten: " << ptr->getData() << std::endl;
		return true;
	}
	return false;
}
void Ring::print(RingNode* ptr)
{
	if (ptr == anker->getNext())
	{
		std::cout << "Alter: " << anker->getAge() << ", Beschreibung: " << anker->getDescription() << ", Daten: " << anker->getData() << std::endl;

	}
	if (ptr == nullptr)
		return;
	if (ptr->getNext() == anker->getNext())
		return;
		this->print(ptr->getNext());
	std::cout << "Alter: " << ptr->getAge() << ", Beschreibung: " << ptr->getDescription() << ", Daten: " << ptr->getData() << std::endl;
}
