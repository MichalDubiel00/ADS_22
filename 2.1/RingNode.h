/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode{
	
private:
	// Ihr Code hier:
	int oldAge;
	std::string description;
	std::string symbolicData;
	RingNode* next;


	//	
public:
	// Ihr Code hier:
	RingNode();
	RingNode(int oldAge,std::string description,std::string symbolicData);
	int getAge();
	void setAge(int);

    std::string getDescription() const;
    void setDescription(std::string description);

    std::string getData() const;
    void setData(std::string symbolicData);

    RingNode* getNext() const;
    void setNext(RingNode* next);

};
