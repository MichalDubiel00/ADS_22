/*************************************************
 * ADS Praktikum 2.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <queue>
#include <iomanip>
#include <iostream>

using namespace std;

////////////////////////////////////
// Ihr Code hier:

//
////////////////////////////////////

Tree::Tree()
{
	//anker = new TreeNode(0,0," ",0, 0.0,0);
	anker = nullptr;
	currentNodeChronologicalID = 0;
}

Tree::~Tree()
{
	deleteAll(anker);
}

void Tree::addNode(std::string Name, int Age,  double Income, int PostCode)
{
	int newOrderID = Age + Income + PostCode;
	TreeNode* newNode = new TreeNode(newOrderID,currentNodeChronologicalID,Name, Age, Income, PostCode);
	currentNodeChronologicalID++;
 
    TreeNode* x = anker;
	TreeNode* y = nullptr;
	while (x)
	{
		y = x;
		if (newOrderID < x->getNodeOrderID())
		{
			x = x->getLeft();
		}
		else
		{
			x = x->getRight();
		}
	}
	if (!y)
	{
		anker = newNode;
	}
	else
	{
		if (newOrderID < y->getNodeOrderID())
		{
			y->setLeft(newNode);
		}
		else
		{
			y->setRight(newNode);
		}
	}
}

bool Tree::deleteNode(int delID)
{
	//Knoten suchen
	TreeNode* del  = anker;
	TreeNode* p = nullptr;
	TreeNode* x, * y;
	while (del && delID != del->getNodeOrderID())
	{
		p = del;
		if (delID < del->getNodeOrderID())
			del = del->getLeft();
		else
			del = del->getRight();
	}

	if (delID != del->getNodeOrderID())
		return false;

	if (!del->getRight() && !del->getLeft()) {
		x = nullptr;
	}
	else if (!(del->getLeft() && del->getRight()))
	{
		if (del->getLeft())
		{
			x = del->getLeft();
		}
		else
			x = del->getRight();
	}
	else
	{
		y = del;
		x = del->getRight();
		while (x->getLeft())
		{
			y = x;
			x = x->getLeft();
		}
		x->setLeft(del->getLeft());
		if (y != del)
		{
			y->setLeft(x->getRight());
			x->setRight(del->getRight());
		}
	}

	if (p == nullptr)
	{
		anker = x;
	}
	else
		if (p->getLeft() == del)
			p->setLeft(x);
		else
			p->setRight(x);
	delete del;
	return true;
}

bool Tree::searchNode(std::string search)
{

	if (searchRekursive(anker, search))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tree::printAll(void)
{
	cout <<"    ID  |           Name     | Age  | Income |PostCode| OrderID"<<endl;
	cout <<"--------+--------------------+------+--------+--------+---------" << endl;
	printAllRekursiv(anker);
}

void Tree::levelOrder(void)
{
	
		if (!anker)
			return;
		cout <<endl<< "    ID  |           Name     | Age  | Income |PostCode| OrderID  | LvL" << endl;
		cout << "--------+--------------------+------+--------+--------+----------+----" << endl;
		printLevelOrde(anker);

}

void Tree::deleteAll(TreeNode* ptr)
{
	if (ptr)
	{
		if (ptr->getLeft())
		{
			deleteAll(ptr->getLeft());
		}
		if (ptr->getRight())
		{
			deleteAll(ptr->getRight());
		}
		delete ptr;
	}
	return;
}

bool Tree::searchRekursive(TreeNode* ptr, std::string search)
{
	if (!ptr)
	{
		return false;
	}

	if (ptr->getName() == search)
	{
		std::cout << "Node ID: " << ptr->getNodeChronologicalID() << " Name: " << ptr->getName() << ", Alte: r" << ptr->getAge() << "Einkomen: " << ptr->getIncome() << ", PLZ: " << ptr->getPostCode() << std::endl;
		return true;
	}
	if (searchRekursive(ptr->getLeft(), search))
	{

		return true;
	}
	if (searchRekursive(ptr->getRight(), search))
	{
		return true;
	}


	return false;
}
void Tree::printAllRekursiv(TreeNode* ptr)
{
	if (ptr == nullptr)
		return;
	
	std::cout << setw(8) << ptr->getNodeChronologicalID() << "|"<<setw(20) << ptr->getName() << "|" << setw(6) << ptr->getAge()<<"|" << setw(8) << ptr->getIncome() << "|" << setw(8) <<ptr->getPostCode() <<"|"<<setw(8) <<ptr->getNodeOrderID()<< std::endl;

	printAllRekursiv(ptr->getLeft());

	printAllRekursiv(ptr->getRight());
}

void Tree::printLevelOrde(TreeNode* k)
{
	// Ausgabe in Levelorder
	std::queue<TreeNode*> q;
	std::queue<int> nq;
	int prev_nv = -1;
	int nv;
	int temp_nv;
	TreeNode* ptr;
	if (k != nullptr) {
		q.push(k);
		nq.push(0);
		while (!q.empty()) {
			ptr = q.front();
			q.pop();
			nv = nq.front();
			nq.pop();
			if (prev_nv != nv)
			{
				temp_nv = nv;
				prev_nv = nv;
			}
			std::cout << setw(8) << ptr->getNodeChronologicalID() << "|" << setw(20) << ptr->getName() << "|" << setw(6) << ptr->getAge() << "|" << setw(8) << ptr->getIncome() << "|" << setw(8) << ptr->getPostCode() << "|" << setw(10) << ptr->getNodeOrderID() << "|" << setw(8)<<temp_nv+1 <<std::endl;

			if (ptr->getLeft())
			{
				q.push(ptr->getLeft());
				nq.push(nv + 1);
			}
			if (ptr->getRight())
			{
				q.push(ptr->getRight());
				nq.push(nv + 1);

			}
		}
	}
}
