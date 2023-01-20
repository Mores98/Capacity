#include "CapyCitySim.h"
#include "Windkraftwerk.h"
#include "Solarpanele.h"
#include "Wasserkraftwerk.h"
#include "Wood.h"
#include "Metal.h"
#include "Plastic.h"
#include <iostream>



using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
		
	int rows = 0;
	int cols = 0;
	string userInput = "";
	int exitVar = 0;
	int validate = 0;

	cout << "Bitte geben sie die Laenge fuer den Bauberreich ein:\t";
	cin >> rows;
	cout << "\nBitte geben sie die Breite des Bauberreichs ein:\t";
	cin >> cols;

	CapyCitySim m(rows, cols);

	do {

		validate = 0;

		do {
			cout << "Welche der folgenden Funktion wollen Sie aufrufen? \n Gebaeude setzen(S) | Berreich loeschen(L) \n Ausgabe des aktuellen Bauplans(B) | Beenden des Programmes(E) \n" << endl;
			cin >> userInput;

			if (userInput == "E" || userInput == "e" || userInput == "exit") {
				exitVar++;
				validate++;
			}
			else if (userInput == "B" || userInput == "b") {
				m.showMap();
				validate++;
			}
			else if (userInput == "S" || userInput == "s") {

				m.place();

				cout << "setzen" << endl;
				validate++;
			}
			else if (userInput == "L" || userInput == "l") {

				m.deleteArea();

				cout << "loeschen" << endl;
			}
			else {
				cout << "\nUngueltige Eingabe\n" << endl;
			}


		} while (validate==0);

	} while (exitVar == 0);

	return 0;
}