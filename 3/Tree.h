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
    void balance(TreeNode*);
    bool split4Node(TreeNode*);
    int proofRBCriterion(TreeNode*);
    bool roatateTreeRight(TreeNode*, TreeNode*);
    bool roatateTreeLeft(TreeNode*, TreeNode*);

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    Tree();
    ~Tree();
    bool addNode(std::string, int, double, int);
   // void deleteNode(int);
    bool searchNode(std::string);
    void printAll(void);
    void printLevelOrder(void);
    void printLevelOrder(int);
    void checkRBCriterion(void);

    void deleteAll(TreeNode*);
    bool searchRekursive(TreeNode*,std::string);
    void printAllRekursiv(TreeNode*);
    void printLevelOrde(TreeNode*);
    void printLevelOrder123(TreeNode*);
    void printLevelOrder123(TreeNode*, int);


    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
