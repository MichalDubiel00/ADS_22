/*************************************************
 * ADS Praktikum 2.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>

class Tree
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode* anker;
    int currentNodeChronologicalID;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    Tree();
    ~Tree();
    void addNode(std::string, int, double, int);
    bool deleteNode(int);
    bool searchNode(std::string);
    void printAll(void);
    void  levelOrder(void);
    void deleteAll(TreeNode*);
    bool searchRekursive(TreeNode*,std::string);
    void printAllRekursiv(TreeNode*);
    void printLevelOrde(TreeNode*);

    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
