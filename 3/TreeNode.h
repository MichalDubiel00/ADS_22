/*************************************************
 * ADS Praktikum 2.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    int NodeOrderID;
    int NodeChronologicalID;
    std::string Name;
    int Age;
    double income;
    int PostCode;
    bool red;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode(int, int, std::string, int, double, int);

    //
    ////////////////////////////////////
    int getNodeOrderID() const;
    void setNodeOrderID(int NodeOrderID);

    int getNodeChronologicalID() const;
    void setNodeChronologicalID(int NodeChronologicalID);

    std::string getName() const;
    void setName(std::string Name);

    int getAge() const;
    void setAge(int Age);

    double getIncome() const;
    void setIncome(double income);

    int getPostCode() const;
    void setPostCode(int PostCode);

    TreeNode* getLeft() const;
    void setLeft(TreeNode* left);

    TreeNode* getRight() const;
    void setRight(TreeNode* right);
    void print();

    bool getRed() const;
    void setRed(bool red);

    TreeNode* getParent() const;
    void setParent(TreeNode* parent);

};
