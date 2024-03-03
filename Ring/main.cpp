/*************************************************
* ADS Praktikum 2.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;


int main()
{
	int result = Catch::Session().run();
	int get = 0;
	string descrition, data = "cos";
	// Ihr Code hier:
	Ring backUp;
	cout << "1) Backup anlegen \n2) Backup suchen \n3) Alle Backups ausgeben\n0) Quit" << endl;
	do
	{
		cout << "?>";
		cin >> get;
		switch (get)
		{
		case 1:
			cin.ignore();
			cout << "+Neuen Datensatz anlegen\nBeschreibung ? > ";
			getline(cin,descrition);
			cout << "Daten ?>";
			cin >> data;
			backUp.addNewNode(descrition,data);
			cout << "+Ihr Datensatz wurde hinzugefuegt."<<endl;
			break;
		case 2:
			cout << "+Nach welchen Daten soll gesucht werden?\n?>";
			cin >> data;
			backUp.search(data) ? cout << "Gefunden in Backup:"<<endl : cout << "not found"<<endl;
			break;
		case 3:
		
			backUp.print(get_anker(backUp)->getNext());
			break;
		}	
		

	} while (get > 0);



	//
	///////////////////////////////////////
	system("Pause");
	return 0;
}
