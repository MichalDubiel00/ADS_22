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

void Tree::balance(TreeNode* k)
{
	if (k->getParent() == k->getParent()->getParent()->getRight()) //Fall RR LR oder LR
	{
		if (k == k->getParent()->getLeft()) //Fall RR
		{
			k = k->getParent();
			roatateTreeRight(k, k->getLeft());
		}
		k->getParent()->setRed(0); //LR
		k->getParent()->getParent()->setRed(1);
		roatateTreeLeft(k->getParent()->getParent(), k->getParent()->getParent()->getRight());
	}

	else //Fall LR RR oder RR
	{
		if (k == k->getParent()->getRight())  //Fall LR
		{
			k = k->getParent();
			roatateTreeLeft(k, k->getRight());
		}
		k->getParent()->setRed(0); //RR
		k->getParent()->getParent()->setRed(1);
		roatateTreeRight(k->getParent()->getParent(), k->getParent()->getParent()->getLeft());
	}

	anker->setRed(0);
}

bool Tree::split4Node(TreeNode* node)
{
	if (!node->getRed() && (node->getLeft() && node->getRight()) && (node->getLeft()->getRed() && node->getRight()->getRed())) //check if 4 node und umfarben
	{
		node->setRed(true);
		node->getRight()->setRed(false);
		node->getLeft()->setRed(false);
		anker->setRed(false);
		return true;
	}
	return false;
}

int Tree::proofRBCriterion(TreeNode* p) //kein plan
{
	if (p == nullptr) {
		return -1;
	}

	if (!p->getLeft() && p->getRight()) {								// Nur rechtes Kind
		int rightHeight = proofRBCriterion(p->getRight());
		return p->getRight()->getRed() ? rightHeight : rightHeight + 1;
	}
	else if (p->getLeft() && !p->getRight()) {								// Nur Linkes Kind
		int leftHeight = proofRBCriterion(p->getLeft());
		return p->getLeft()->getRed() ? leftHeight : leftHeight + 1;
	}
	else if (!p->getLeft() && !p->getRight())
		return 0;										// Kein Kind
	else if (p->getLeft() && p->getRight()) {
		if (p->getLeft()->getRed() && p->getRight()->getRed()) {								// Beide Kinder Rot
			int leftHeight = proofRBCriterion(p->getLeft());
			int rightHeight = proofRBCriterion(p->getRight());
			if (leftHeight == rightHeight) return leftHeight;
		}

		else if (!p->getLeft()->getRed() && !p->getRight()->getRed()) {						//Beide Kinder schwarz
			int leftHeight = proofRBCriterion(p->getLeft());
			int rightHeight = proofRBCriterion(p->getRight());
			if (leftHeight == rightHeight) return leftHeight + 1;
		}

		else if (!p->getLeft()->getRed() && p->getRight()->getRed()) {						// Ein Kind Rot
			int heightOfRedChild = proofRBCriterion(p->getRight());
			int heightOfBlackChild = proofRBCriterion(p->getLeft());
			if (heightOfRedChild - heightOfBlackChild == 1) return heightOfRedChild;
		}
		else if (p->getLeft()->getRed() && !p->getRight()->getRed()) {	//Das ander Kind ist Rot
			int heightOfRedChild = proofRBCriterion(p->getLeft());
			int heightOfBlackChild = proofRBCriterion(p->getRight());
			if (heightOfRedChild - heightOfBlackChild == 1) return heightOfRedChild;
		}
	}
}

bool Tree::roatateTreeLeft(TreeNode* x, TreeNode* y)
{
	x->setRight(y->getLeft()); //x recht zeigt auf y links
	if (y->getLeft())
	{
		y->getLeft()->setParent(x); // parent wird neu gesetz
	}
	y->setParent(x->getParent()); //wechsel von parent
	if (!x->getParent()) //anker wird neu gestetz
	{
		this->anker = y;
	}
	else if (x == y->getParent()->getLeft()) //links
	{
		x->getParent()->setLeft(y);
	}
	else // resct
	{
		x->getParent()->setRight(y);
	}
	y->setLeft(x); //y links wird auf x gesetz
	x->setParent(y); //y wird zu x parent
	return true;
}

bool Tree::roatateTreeRight(TreeNode* x, TreeNode* y)
{
	x->setLeft(y->getRight());
	if (y->getRight())
	{
		y->getRight()->setParent(x);
	}
	y->setParent(x->getParent());
	if (!x->getParent())
	{
		this->anker = y;
	}
	else if (x == y->getParent()->getRight())
	{
		x->getParent()->setRight(y);
	}
	else
	{
		x->getParent()->setLeft(y);
	}
	y->setRight(x);
	x->setParent(y);
	return true;
}

Tree::Tree()
{
	anker = nullptr;
	currentNodeChronologicalID = 0;
}

Tree::~Tree()
{
	deleteAll(anker);
}

bool Tree::addNode(std::string Name, int Age, double Income, int PostCode)
{
	int newOrderID = Age + Income + PostCode;
	TreeNode* newNode = new TreeNode(newOrderID, currentNodeChronologicalID, Name, Age, Income, PostCode);
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
		if (y)
		{
			split4Node(y);
		}
	}
	newNode->setParent(y);
	if (!y)
	{
		anker = newNode;
		anker->setRed(0);
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
	if (newNode->getParent() == nullptr)
	{
		newNode->setRed(0);
		return true;
	}
	if (newNode->getParent()->getParent() == nullptr)
	{
		return true;
	}
	x = newNode;
	while (x)
	{
		if (x->getRed() && x->getParent()->getRed())
		{
			balance(x);
		}
		x = x->getParent();
	}
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
	cout << "    ID  |           Name     | Age  | Income |PostCode| OrderID" << endl;
	cout << "--------+--------------------+------+--------+--------+---------" << endl;
	printAllRekursiv(anker);
}

void Tree::printLevelOrder(void)
{
	if (!anker)
		return;
	cout << endl << "    ID  |           Name     | Age  | Income |PostCode| OrderID  | Red" << endl;
	cout << "--------+--------------------+------+--------+--------+----------+----" << endl;
	printLevelOrde(anker);
	cout << "Ausgabe in Levelorder als 234-Baum:" << endl;
	printLevelOrder123(anker);
}

void Tree::printLevelOrder(int lvl)
{
	cout << "Niv " << lvl << ": ";
	printLevelOrder123(anker, lvl);
	cout << endl;
}

void Tree::checkRBCriterion(void)
{
	cout << proofRBCriterion(anker) << endl;
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
		std::cout << "Node ID: " << ptr->getNodeChronologicalID() << " Name: " << ptr->getName() << ", Alter: " << ptr->getAge() << "Einkomen: " << ptr->getIncome() << ", PLZ: " << ptr->getPostCode() << std::endl;
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

	std::cout << setw(8) << ptr->getNodeChronologicalID() << "|" << setw(20) << ptr->getName() << "|" << setw(6) << ptr->getAge() << "|" << setw(8) << ptr->getIncome() << "|" << setw(8) << ptr->getPostCode() << "|" << setw(8) << ptr->getNodeOrderID() << std::endl;

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

	if (k != nullptr) {
		//Wurzel und startniveu pushen
		q.push(k);
		nq.push(0);

		while (!q.empty()) {
			TreeNode* curr = q.front();
			q.pop();
			nv = nq.front();
			nq.pop();
			if (prev_nv != nv)
			{
				temp_nv = nv;
				prev_nv = nv;
			}
			std::cout << setw(8) << curr->getNodeChronologicalID() << "|" << setw(20) << curr->getName() << "|" << setw(6) << curr->getAge() << "|" << setw(8) << curr->getIncome() << "|" << setw(8) << curr->getPostCode() << "|" << setw(10) << curr->getNodeOrderID() << "|" << setw(8) << curr->getRed() << " " << nv << std::endl;
			if (curr->getLeft())
			{
				q.push(curr->getLeft());
				nq.push(nv + 1);
			}

			if (curr->getRight())
			{
				q.push(curr->getRight());
				nq.push(nv + 1);
			}
		}
	}
}

void Tree::printLevelOrder123(TreeNode* k)
{
	if (!k)
	{
		return;
	}
	queue<TreeNode*> q;
	queue<int> nq;

	int prev_nv = -1;
	int niveau;
	int temp_nv;

	q.push(k);
	nq.push(0);

	while (!q.empty())
	{
		int nodeCount = q.size();

		while (nodeCount > 0)
		{
			TreeNode* curr = q.front();
			niveau = nq.front();
			nq.pop();
			if (prev_nv != niveau)
			{
				cout << "Niv " << niveau << ": ";
				temp_nv = niveau;
				prev_nv = niveau;
			}

			cout << "(";
			if (curr->getLeft() && curr->getLeft()->getRed())
			{
				cout << curr->getLeft()->getNodeOrderID() << ",";
			}
			cout << curr->getNodeOrderID();
			if (curr->getRight() && curr->getRight()->getRed())
			{
				cout << "," << curr->getRight()->getNodeOrderID();
			}
			cout << ")";

			q.pop();
			if (!curr->getRed()) {
				if (curr->getLeft() && curr->getLeft()->getLeft()) {
					q.push(curr->getLeft()->getLeft());
					nq.push(niveau + 1);
				}
				if (curr->getLeft() && curr->getLeft()->getRight()) {
					q.push(curr->getLeft()->getRight());
					nq.push(niveau + 1);
				}
				if (curr->getRight() && curr->getRight()->getLeft()) {
					q.push(curr->getRight()->getLeft());
					nq.push(niveau + 1);
				}
				if (curr->getRight() && curr->getRight()->getRight()) {
					q.push(curr->getRight()->getRight());
					nq.push(niveau + 1);
				}
			}
			else {
				if (curr->getLeft()) {
					q.push(curr->getLeft());
					nq.push(niveau + 1);
				}
				if (curr->getRight()) {
					q.push(curr->getRight());
					nq.push(niveau + 1);
				}
			}
			nodeCount--;
		}
		cout << endl;
	}
}

void Tree::printLevelOrder123(TreeNode* k, int level)
{
	if (!k)
	{
		return;
	}
	queue<TreeNode*> q;
	queue<int> nq;

	int prev_nv = -1;
	int nv;
	int temp_nv;

	q.push(k);
	nq.push(0);

	while (!q.empty())
	{
		int nodeCount = q.size();

		while (nodeCount > 0)
		{
			TreeNode* node = q.front();
			nv = nq.front();
			nq.pop();
			if (prev_nv != nv)
			{
				temp_nv = nv;
				prev_nv = nv;
			}
			if (level == nv)
			{
				cout << "(";
				if (node->getLeft() && node->getLeft()->getRed())
				{
					cout << node->getLeft()->getNodeOrderID() << ", ";
				}
				cout << node->getNodeOrderID();
				if (node->getRight() && node->getRight()->getRed())
				{
					cout << ", " << node->getRight()->getNodeOrderID();
				}
				cout << ")" << " ";
			}

			q.pop();
			if (node->getLeft())
			{
				if (node->getLeft() && !node->getLeft()->getRed())
				{
					q.push(node->getLeft());
					nq.push(nv + 1);
				}
				if (node->getLeft()->getLeft() && !node->getLeft()->getLeft()->getRed())
				{
					q.push(node->getLeft()->getLeft());
					nq.push(nv + 1);
				}
				if (node->getLeft()->getRight() && !node->getLeft()->getRight()->getRed())
				{
					q.push(node->getLeft()->getRight());
					nq.push(nv + 1);
				}
			}
			if (node->getRight())
			{
				if (node->getRight() && !node->getRight()->getRed())
				{
					q.push(node->getRight());
					nq.push(nv + 1);
				}
				if (node->getRight()->getLeft() && !node->getRight()->getLeft()->getRed())
				{
					q.push(node->getRight()->getLeft());
					nq.push(nv + 1);
				}
				if (node->getRight()->getRight() && !node->getRight()->getRight()->getRed())
				{
					q.push(node->getRight()->getRight());
					nq.push(nv + 1);
				}
			}
			nodeCount--;
		}
	}
}