/*************************************************
 * ADS Praktikum 2.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:



/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV" 
 
Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/
void mainscreen_addTreeCSV(Tree*& ref)
{
    char j;
    cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
            "importieren(j / n) ? >";
    cin >> j;
    if (j == 'j')
    {
        ifstream csvread;
        csvread.open("ExportZielanalyse.csv", ios::in);
        if (!csvread.is_open())
            cout << "Fehler beim Lesen!" << endl;
        else
        {
            string name, age, postcode, income;

            while (!csvread.eof())
            {
                getline(csvread, name, ';');
                getline(csvread, age, ';');
                getline(csvread, income, ';');
                getline(csvread, postcode, '\n');
                ref->addNode(name, stoi(age), stod(income), stoi(postcode));
            }
            csvread.close();
        }
        cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
    }
}
//
///////////////////////////////////////
int main()
{

   int result = Catch::Session().run();

    ///////////////////////////////////////
    // Ihr Code hier:
   Tree* tree = new Tree;
   int get = 0;
   string name;
   int id,age, plz;
   double income;
   cout << "1) Datensatz einfuegen, manuell \n2) Datensatz einfuegen, CSV Datei \n3) Datensatz loeschenn\n4) Suchen \n5) Datenstruktur anzeigen\n6) Level-Order Ausgabe\n7) Beenden" << endl;
   do
   {
       cout << "?>";
       cin >> get;
       switch (get)
       {
       case 1:
           cout << "+ Bitte geben Sie die den Datensatz ein:\n Name ?>";
           cin >>name;
           cout << "Alter ?>";
           cin >> age;
           cout << "Einkommen ?>";
           cin >> income;
           cout << "PLZ ?>";
           cin >> plz;
           tree->addNode(name,age,income,plz);
           cout << "+ Ihr Datensatz wurde eingefuegt"<<endl;
           break;
       case 2:
           mainscreen_addTreeCSV(tree);
           break;
       case 3:
           cout << "+ Bitte geben Sie den zu loeschenden Datensatz an\nOrderID ?>";
           cin >> id;
           tree->deleteNode(id);
           break;
       case 4:
           cout << "+ Bitte geben Sie den zu suchenden Datensatz an\Name ?>";
           cin >> name;
           tree->searchNode(name) ? cout << "Gefunden in Tree!" << endl : cout << "Nicht gefunden!" << endl;
           break;
       case 5:
           tree->printAll();
           break;
       case 6:
           tree->levelOrder();
           break;
       }


   } while (get < 7);


    //
    ///////////////////////////////////////
    system("PAUSE");

    return 0;
}
