/*************************************************
 * ADS Praktikum 2.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>

////////////////////////////////////
// Ihr Code hier:

//
////////////////////////////////////

TreeNode::TreeNode(int NodeOrderID, int NodeChronologicalID, std::string Name, int Age, double Income, int PostCode)
{
    this->left = nullptr;
    this->right = nullptr;
    this->NodeChronologicalID = NodeChronologicalID;
    this->NodeOrderID = NodeOrderID;
    this->Name = Name;
    this->Age = Age;
    this->income = Income;
    this->PostCode = PostCode;
}

int TreeNode::getNodeOrderID() const
{
    return NodeOrderID;
}

void TreeNode::setNodeOrderID(int NodeOrderID)
{
    this->NodeOrderID = NodeOrderID;
}

int TreeNode::getNodeChronologicalID() const
{
    return NodeChronologicalID;
}

void TreeNode::setNodeChronologicalID(int NodeChronologicalID)
{
    this->NodeChronologicalID = NodeChronologicalID;
}

std::string TreeNode::getName() const
{
    return Name;
}

void TreeNode::setName(std::string Name)
{
    this->Name = Name;
}

int TreeNode::getAge() const
{
    return Age;
}

void TreeNode::setAge(int Age)
{
    this->Age = Age;
}

double TreeNode::getIncome() const
{
    return income;
}

void TreeNode::setIncome(double income)
{
    this->income = income;
}

int TreeNode::getPostCode() const
{
    return PostCode;
}

void TreeNode::setPostCode(int PostCode)
{
    this->PostCode = PostCode;
}

TreeNode* TreeNode::getLeft() const
{
    return left;
}

void TreeNode::setLeft(TreeNode* left)
{
    this->left = left;
}

TreeNode* TreeNode::getRight() const
{
    return right;
}

void TreeNode::setRight(TreeNode* right)
{
    this->right = right;
}

void TreeNode::print()
{
}

