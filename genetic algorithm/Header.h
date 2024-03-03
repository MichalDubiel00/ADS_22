#pragma once
#include <math.h>
#include <float.h>
#include <iostream>
#include <float.h>
#include "Items.h"

#define ITEMS_CNT 10

class Solution
{
public:
	Solution(std::vector<bool>);
	~Solution();
	void fitness(std::vector<bool>);
	void print();
	double value,weight;
	std::vector<bool> backpack;
	std::vector<Items> items = {
		{"Laptop", 800.0, 2.5},
		{"Smartphone", 500.0, 0.5},
		{"Headphones", 150.0, 0.2},
		{"Camera", 900.0, 1.5},
		{"Tablet", 600.0, 1.0},
		{"TV", 1200.0, 5.5},
		{"Game console", 700.0, 2.0},
		{"Book", 25.0, 0.5},
		{"Jacket", 150.0, 0.8},
		{"Shoes", 100.0, 0.6},
	};

	
private:
	

};

Solution::Solution(std::vector<bool> backpack)
{
	value = 0;
	weight = 0;
	this->backpack = backpack;
	fitness(backpack);
}

Solution::~Solution()
{
}
void Solution::fitness(std::vector<bool> backpack) {
	
	//double ans = (2.0 * pow(x, 5) - 3.0 * pow(x, 4) + 6.0 * pow(x, 3) + 2.0 * pow(x, 2) - 7.0 * x + 9.0);
	//double ans = (3+x)-255;
	//double ans = (2.0 * pow(x, 3) + 1.0 * pow(x, 2) - 3.0 * x + 4.0);
	for (int i = 0; i < ITEMS_CNT; i++)
	{
		if (backpack[i] == true)
		{
			weight += items[i].weight;
			value += items[i].value;
		}
	}
	value = (weight > 15) ? 0 : value;

}
void Solution::print()
{
	std::cout << "rank:" << (int)value << " weight:" << weight << std::endl;
	for (int i = 0; i < ITEMS_CNT; i++)
	{
		if (backpack[i] == true)
		{
			std::cout << "name: " << items[i].name << std::endl;
		}
	}
	std::cout << std::endl;
}

