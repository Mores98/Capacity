#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int** createMaps(int, int);
void deleteFullMaps(int**);
void showMap(int**);
void place(int**);
void deleteArea(int**);
int getSizeOfMapY(int**);
int getSizeOfMapX(int**);


enum GebaeudeTypen{Border,Empty,Wasserkraftwerk,Windkraftwerk,Solarpanele};

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

	int** table = createMaps(rows, cols);

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
				showMap(table);
				validate++;
			}
			else if (userInput == "S" || userInput == "s") {

				place(table);

				cout << "setzen" << endl;
				validate++;
			}
			else if (userInput == "L" || userInput == "l") {

				deleteArea(table);

				cout << "loeschen" << endl;
			}
			else {
				cout << "\nUngueltige Eingabe\n" << endl;
			}


		} while (validate==0);

	} while (exitVar == 0);

	deleteFullMaps(table);

	return 0;
}

int** createMaps(int rows, int cols) {

	//Dynaisch verwaltetes Array da die groeße zur Laufzeit geaendert wird.
	int** table = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++) {
		table[i] = new int[cols + 1];
	}


	for (int i = 0; i < rows + 1; i++) {
		for (int j = 0; j < cols + 1; j++) {

			//0 Deffiniert den Rand der Karte. Damit unabhaengig von den Variablen rows und cols gearbeitet werden kann.
			if (i == rows) {
				table[i][j] = 0;
			}
			//1 Ist ein Leeres Feld.
			else {
				table[i][j] = 1;
			}
			//0 Deffiniert den Rand der Karte.
			if (j == cols) {
				table[i][j] = 0;
			}

		}
	}
	cout << "\nBauplan wurde erstellt\n" << endl;
	return table;
}

void deleteFullMaps(int** table) {

	//Ermittelt wie lang der Bauplan ist.
	int i = 0;
	do {

		i++;
		
	} while (table[i][0] != 0);

	//erhöht beim letzten durchlauf nicht um 1 sondern springt vorher raus.
	i++;

	//gibt den Speicher frei und setzt den Pointer auf NULL um Fehler zu vermeiden
	for (int j = 0; j < i; j++) {
		delete[] table[j];
	}
	delete[] table;
	table = NULL;
	cout << "\nKarte wurde geloescht" << endl;
}

void showMap(int** table) {
	
	int i = 0;
	int j = 0;
	int safeBreite = 0;
	int safeLaenge = 0;
	int forEnum = 0;

	do {

		do {

			/*Zeigt das ganze vor der Spiegelung an der x - Achse an.
			forEnum = table[i][j];
			switch ((GebaeudeTypen)forEnum) {
			case Border: cout << "B "; break;
			case Empty: cout << "X "; break;
			case Wasserkraftwerk: cout << "H "; break;
			case Windkraftwerk: cout << "W "; break;
			case Solarpanele: cout << "S "; break;
			}*/
	
			j++;

		} while (table[i][j] != 0);

		i++;
		safeBreite = j;
		j = 0;

	} while (table[i][j] != 0);
	
	//Da der Counter um die Grenze zu erreichen um 1 erhöht wurde.
	safeLaenge = i-1;
	cout << endl;

	//Dreht die Darstellung der Map um damit sie wie ein Funktionsgraph dargestellt wird. Das heißt unten links der Koordinaten Ursprung (0|0).
	for (i = safeLaenge; i > -1; i--) {
		for (j = 0; j < safeBreite; j++) {
			forEnum = table[i][j];
			switch ((GebaeudeTypen)forEnum) {
			case Border: cout << "B "; break;
			case Empty: cout << "X "; break;
			case Wasserkraftwerk: cout << "H "; break;
			case Windkraftwerk: cout << "W "; break;
			case Solarpanele: cout << "S "; break;
			}
		}
		cout << endl;
	}
	cout << endl;
}

void place(int** table) {

	int x = 0;
	int y = 0;
	int laenge = 0;
	int breite = 0;
	int validatePosition = 0;
	int validateGebaeude = 0;
	int maxX = getSizeOfMapX(table);
	int maxY = getSizeOfMapY(table);
	int stagedBreite = 0;
	int stagedLaenge = 0;
	int collision = 0;
	string userInput = "";
	int building = 0;

	do {
		cout << "Gibt die x und y Koordinate der Position von der das Gebaude errichtet werden soll an" << endl;
		cout << "X:\t";
		cin >> x;
		cout << "Y:\t";
		cin >> y;

		if (x <= maxX && x > 0 && y <= maxY && y > 0) {
			validatePosition++;
		}

		x--;
		y--;

	} while (validatePosition == 0);

	do {
		cout << "Gibt die Dimensionen des Berreches in x und y richtung an in der das Gebaeude geplant werden soll" << endl;
		cout << "X:\t";
		cin >> breite;
		cout << "Y:\t";
		cin >> laenge;

		// x + breite liegen im Berreich der Karte und y + laenge liegen im Berreich der Karte + außerdem Koennen laenge und Breite nicht den Wert 0 haben
		if ((breite > 0 && x + breite <= maxX || breite < 0 && x + breite >= 0) && (laenge > 0 && y + laenge <= maxY || laenge < 0 && y + laenge >= 0) && laenge != 0 && breite != 0) {
			validateGebaeude++;
		}
	} while (validateGebaeude == 0);

	do {
		building = 0;
		cout << "Welches Gebaeude soll plaziert werden? Wasserkraftwerk(1), Windkraftwerk(2), Solarpanele(3)" << endl;
		cin >> building;
	} while(building<1 && building>3);
	building++;

	stagedBreite = breite;
	stagedLaenge = laenge;
	// gehen wir nach Rechts?
	if (x + breite > x) {
		//gehen wir nach Oben?
		if (y + laenge > y) {
			laenge += y;
			breite += x;

			//Schleife Laeuft ueber den Berreich des Gebaedes und erhoeht counter bei Kollision. Bei allen 4 Schleifen in place angepasst auf den Berreich.
			for (int j = y; j < laenge; j++) {
				for (int i = x; i < breite; i++) {
					if (table[j][i] != 1) {
						collision++;
					}
				}
			}
			//Abfrage bei Kollision. 
			if (collision != 0) {
				cout << "Gebaeude im Weg soll es ersetzt werden? (J/N)" << endl;
				cin >> userInput;
				if (userInput == "J" || userInput == "j") {
					collision = 0;
				}
			}
			//Setzte wieder auf State vor Kollisions Test.
			if (collision == 0) {
				laenge = y + stagedLaenge;
				breite = x + stagedBreite;

				for (int j = y; j < laenge; j++) {
					for (int i = x; i < breite; i++) {
						table[j][i] = building;
					}
				}
			}
		}
		else {
			laenge += y;
			breite += x;

			for (int j = y; j > laenge; j--) {
				for (int i = x; i < breite; i++) {
					if (table[j][i] != 1) {
						collision++;
					}
				}
			}
			if (collision != 0) {
				cout << "Gebaeude im Weg soll es ersetzt werden? (J/N)" << endl;
				cin >> userInput;
				if (userInput == "J" || userInput == "j") {
					collision = 0;
				}
			}
			if (collision == 0) {
				laenge = y + stagedLaenge;
				breite = x + stagedBreite;

				for (int j = y; j > laenge; j--) {
					for (int i = x; i < breite; i++) {
						table[j][i] = building;
					}
				}
			}
		}
	}
	else {
		if (y + laenge > y) {
			laenge += y;
			breite += x;
			for (int j = y; j < laenge; j++) {
				for (int i = x; i > breite; i--) {
					if (table[j][i] != 1) {
						collision++;
					}
				}
			}
			if (collision != 0) {
				cout << "Gebaeude im Weg soll es ersetzt werden? (J/N)" << endl;
				cin >> userInput;
				if (userInput == "J" || userInput == "j") {
					collision = 0;
				}
			}
			if (collision == 0) {
				laenge = y + stagedLaenge;
				breite = x + stagedBreite;
				for (int j = y; j < laenge; j++) {
					for (int i = x; i > breite; i--) {
						table[j][i] = building;
					}
				}
			}

		}
		else {
			laenge += y;
			breite += x;
			for (int j = y; j > laenge; j--) {
				for (int i = x; i > breite; i--) {
					if (table[j][i] != 1) {
						collision++;
					}
				}

			}
			if (collision != 0) {
				cout << "Gebaeude im Weg soll es ersetzt werden? (J/N)" << endl;
				cin >> userInput;
				if (userInput == "J" || userInput == "j") {
					collision = 0;
				}
			}
			if (collision == 0) {
				laenge = y + stagedLaenge;
				breite = x + stagedBreite;
				for (int j = y; j > laenge; j--) {
					for (int i = x; i > breite; i--) {
						table[j][i] = building;
					}
				}

			}
		}
	}

}

void deleteArea(int** table) {

	int x = 0;
	int y = 0;
	int laenge = 0;
	int breite = 0;
	int validatePosition = 0;
	int validateGebaeude = 0;
	int maxX = getSizeOfMapX(table);
	int maxY = getSizeOfMapY(table);

	do {
		cout << "Gibt die x und y Koordinate der Position von der geloescht werden soll an" << endl;
		cout << "X:\t";
		cin >> x;
		cout << "Y:\t";
		cin >> y;

		if (x <= maxX && x > 0 && y <= maxY && y > 0) {
			validatePosition++;
		}

		x--;
		y--;

	} while (validatePosition == 0);

	do {
		cout << "Gibt die Dimensionen des Berreches in x und y richtung an der geloescht werden soll" << endl;
		cout << "X:\t";
		cin >> breite;
		cout << "Y:\t";
		cin >> laenge;

// x + breite liegen im Berreich der Karte und y + laenge liegen im Berreich der Karte + außerdem Koennen laenge und Breite nicht den Wert 0 haben
		if ((breite> 0 && x+breite<=maxX || breite<0 && x+breite>=0) && (laenge> 0 && y+laenge<=maxY || laenge<0 &&  y+laenge>=0) && laenge != 0 && breite != 0) {
			validateGebaeude++;
		}
	} while (validateGebaeude == 0);
		

// gehen wir nach Rechts?
		if (x + breite > x) {
			//gehen wir nach Oben?
			if (y + laenge > y) {
				laenge += y;
				breite += x;

				for (y; y < laenge; y++) {
					for (int i = x; i < breite; i++) {
						table[y][i] = 1;
					}
				}

			}
			else {
				laenge += y;
				breite += x;

				for (y; y > laenge; --y) {
					for (int i = x; i < breite; i++) {
						table[y][i] = 1;
					}
				}


			}
		}
		else {
			//gehen wir nach Oben?
			if (y + laenge > y) {
				laenge += y;
				breite += x;
				for (y; y < laenge; y++) {
					for (int i = x; i > breite; i--) {
						table[y][i] = 1;
					}
				}
			}
			else {
				laenge += y;
				breite += x;
				for (y; y > laenge; y--) {
					for (int i = x; i > breite; i--) {
						table[y][i] = 1;


					}

				}
			}
		}
}

int getSizeOfMapX(int** table) {

	int i = 0;
	do {

		i++;

	} while (table[i][0] != 0);
	
	return i;
}

int getSizeOfMapY(int** table) {

	int i = 0;
	do {

		i++;

	} while (table[0][i] != 0);

	return i;
}