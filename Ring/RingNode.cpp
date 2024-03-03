/*************************************************
* ADS Praktikum 2.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"


// Ihr Code hier:


RingNode::RingNode()
{
    this->next = nullptr;
    oldAge = 0;
}

RingNode::RingNode(int oldAge, std::string description, std::string symbolicData)
{
    this->oldAge = oldAge;
    this->description = description;
    this->symbolicData = symbolicData;
}

int RingNode::getAge()
{
    return this->oldAge;
}

void RingNode::setAge(int oldAge)
{
    this->oldAge = oldAge;
}

// 
////////////////////////////////////
std::string RingNode::getDescription() const
{
    return description;
}

void RingNode::setDescription(std::string description)
{
    this->description = description;
}

std::string RingNode::getData() const
{
    return symbolicData;
}

void RingNode::setData(std::string symbolicData)
{
    this->symbolicData = symbolicData;
}

RingNode* RingNode::getNext() const
{
    return next;
}

void RingNode::setNext(RingNode* next)
{
    this->next = next;
}

