#pragma once
#include <iostream>
#include <vector>

class Items
{
public:
	Items(std::string,double,double);
	~Items();

	std::string name;
	double value;
	double weight;

private:

};

Items::Items(std::string name,double value,double weight)
{
	this->name = name;
	this->value = value;
	this->weight = weight;
}

Items::~Items()
{
}
