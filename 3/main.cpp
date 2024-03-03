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
   int lvl;
   cout << "1) Datensatz einfuegen, manuell \n2) Datensatz einfuegen, CSV Datei \n3) suchen\n4) Ausgabe in Preorder \n5) Level-Order Ausgabe\n6) Ausgabe in Levelorder (mit Niveauauswahl)\n7) Beenden" << endl;
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
           cout << "+ Bitte geben Sie den zu suchenden Datensatz an\Name ?>";
           cin >> name;
           tree->searchNode(name) ? cout << "Gefunden in Tree!" << endl : cout << "Nicht gefunden!" << endl;
           break;
       case 4:
           tree->printAll();
           break;
       case 5:
           tree->printLevelOrder();
           break;
       case 6:
           cout << "geben sie gesuchtes Niveou? ";
           cin >> lvl;
           tree->printLevelOrder(lvl);
       }


   } while (get < 7);


    //
    ///////////////////////////////////////
    system("PAUSE");

    return 0;
}
