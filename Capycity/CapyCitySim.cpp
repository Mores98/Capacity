#include <iostream>
#include "CapyCitySim.h"
#include "Wasserkraftwerk.h"
#include "Windkraftwerk.h"
#include "Solarpanele.h"
#include "Wood.h"
#include "Metal.h"
#include "Plastic.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;

//Anlegen Material
Wood wo1("Holz", 10.5, 1);
Metal me1("Metall", 20.2, 1);
Plastic pa1("Plastik", 5.1, 1);

//Anlegen Gebäude	
Windkraftwerk wi1(100, "W",3,me1.getName(),me1.getName(),pa1.getName());
Solarpanele so1(50, "S",4,wo1.getName(), me1.getName(), me1.getName());
Wasserkraftwerk wa1(200, "H",2, wo1.getName(), pa1.getName(), pa1.getName());

CapyCitySim::CapyCitySim(int _rows,int _cols){
	setRows(_rows);
	setCols(_cols);
	buildPlan = createMaps(_rows, _cols);
}

CapyCitySim::~CapyCitySim() {
	for (int j = 0; j < rows; j++) {
		delete[] buildPlan[j];
	}
	delete[] buildPlan;
	buildPlan = NULL;
	cout << "\nKarte wurde geloescht" << endl;
}

void CapyCitySim::setRows(int _rows) {
	rows = _rows;
}

int CapyCitySim::getRows() {
	return rows;
}


void CapyCitySim::setCols(int _cols) {
		cols = _cols;
}

int CapyCitySim::getCols() {
	return cols;
}

int** CapyCitySim::createMaps(int rows,int cols){

	//Dynaisch verwaltetes Array da die groeße zur Laufzeit geaendert wird.
	int** table = new int* [rows];
	for (int i = 0; i < rows ; i++) {
		table[i] = new int[cols];
	}

	for (int i = 0; i < rows ; i++) {
		for (int j = 0; j < cols ; j++) {

				table[i][j] = 1;

		}
	}
	cout << "\nBauplan wurde erstellt\n" << endl;
	return table;
}

void CapyCitySim::showMap() {

	// int forEnum = 0;
	int myValue = 0;
	int water = 0;
	int wind = 0;
	int sun = 0;
	int waPrice = 0;
	int wiPrice = 0;
	int suPrice = 0;
	string vergleich = "";
	int holz = 0;
	int plastic = 0;
	int metall = 0;

	//Dreht die Darstellung der Map um damit sie wie ein Funktionsgraph dargestellt wird. Das heißt unten links der Koordinaten Ursprung (0|0).
	for (int i = rows -1 ; i >= 0; i--) {
		for (int j = 0; j < cols; j++) {
			/*
			forEnum = buildPlan[i][j];
			switch ((GebaeudeTypen)forEnum) {
			case Border: cout << "B "; break;
			case Empty: cout << "X "; break;
			case Wasserkraftwerk: cout << "H "; break;
			case Windkraftwerk: cout << "W "; break;
			case Solarpanele: cout << "S "; break;
			}
			*/
			myValue = buildPlan[i][j];
			if (myValue == 1) {
				cout << "X ";
			}
			else {
				cout << wi1.getLabelById(myValue) + wa1.getLabelById(myValue) + so1.getLabelById(myValue) + " ";
				switch (myValue){
				case 2: water++; break;
				case 3: wind++; break;
				case 4: sun++; break;
			}
			}
		}
		cout << endl;
	}
	cout << "\n Legende: X steht fuer Leer, H fuer Wasserkraft, W fuer Windkraft und S fuer Solarpanele\n" << endl;
	cout << "Wasserkraftwerke: " << water << " Windkraftwerke: " << wind << " Solarpanele: " << sun << " Gebaede" << endl;

	for (int i = 0; i < 3; i++) {
		waPrice = pa1.getPriceByName(wa1.getBauMateriallien(i)) + me1.getPriceByName(wa1.getBauMateriallien(i)) + wo1.getPriceByName(wa1.getBauMateriallien(i));
	}
	waPrice += wa1.getGrundpreis();
	cout << "\nWasserkraftwerk einzelpreis: " << waPrice << " fals vorhanden. Wasserkraftwerks Preis fuer alle: " << water * waPrice << endl;

	for (int i = 0; i < 3; i++) {
		wiPrice = pa1.getPriceByName(wi1.getBauMateriallien(i)) + me1.getPriceByName(wi1.getBauMateriallien(i)) + wo1.getPriceByName(wi1.getBauMateriallien(i));
	}
	wiPrice += wi1.getGrundpreis();
	cout << "\nWindkraftwerk einzelpreis: " << wiPrice << " fals vorhanden. Windkraftwerks Preis fuer alle: " << wind * wiPrice << endl;

	for (int i = 0; i < 3; i++) {
		suPrice = pa1.getPriceByName(so1.getBauMateriallien(i)) + me1.getPriceByName(so1.getBauMateriallien(i)) + wo1.getPriceByName(so1.getBauMateriallien(i));
	}
	suPrice += so1.getGrundpreis();
	cout << "\nSolarpanele einzelpreis: " << suPrice << " fals vorhanden. Solarpanele Preis fuer alle: " << sun * suPrice << endl;

	for (int i = 0; i < 3; i++) {
		vergleich = wa1.getBauMateriallien(i);
		if (vergleich == "Holz") {
			holz++;
		}
		else if (vergleich == "Plastik") {
			plastic++;
		}
		else if(vergleich == "Metall"){
			metall++;
		}
	}
	cout << "\nEin Wasserkraftwerk braucht: " << holz <<" Holz " << plastic << " Plastik " << metall << " Metall. Fuer alle Wasserkraftwerke braucht man: " << holz*water<< " Holz " << plastic*water << " Plastik " << metall*water << " Metall" << endl;

	holz = 0;
	plastic = 0;
	metall = 0;

	for (int i = 0; i < 3; i++) {
		vergleich = wi1.getBauMateriallien(i);
		if (vergleich == "Holz") {
			holz++;
		}
		else if (vergleich == "Plastik") {
			plastic++;
		}
		else if (vergleich == "Metall") {
			metall++;
		}
	}
	cout << "\nEin Windkraftwerk braucht: " << holz << " Holz " << plastic << " Plastik " << metall << " Metall. Fuer alle Windkraftwerk braucht man: " << holz * wind << " Holz " << plastic * wind << " Plastik " << metall * wind << " Metall" << endl;
	
	holz = 0;
	plastic = 0;
	metall = 0;

	for (int i = 0; i < 3; i++) {
		vergleich = so1.getBauMateriallien(i);
		if (vergleich == "Holz") {
			holz++;
		}
		else if (vergleich == "Plastik") {
			plastic++;
		}
		else if (vergleich == "Metall") {
			metall++;
		}
	}
	cout << "\nEin Solarpanel braucht: " << holz << " Holz " << plastic << " Plastik " << metall << " Metall. Fuer alle Solarpanele braucht man: " << holz * sun << " Holz " << plastic * sun << " Plastik " << metall * sun << " Metall\n" << endl;
	
	
}

int CapyCitySim::getBuildPlan(int x, int y) {
	if (x <= rows && y <= cols) {
		return buildPlan[x][y];
	}
	else return 0;
}

void CapyCitySim::place() {

	int x = 0;
	int y = 0;
	int laenge = 0;
	int breite = 0;
	int validatePosition = 0;
	int validateGebaeude = 0;
	int maxX = cols;
	int maxY = rows;
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
	} while (building < 1 && building>3);
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
					if (buildPlan[j][i] != 1) {
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
						buildPlan[j][i] = building;
					}
				}
			}
		}
		else {
			laenge += y;
			breite += x;

			for (int j = y; j > laenge; j--) {
				for (int i = x; i < breite; i++) {
					if (buildPlan[j][i] != 1) {
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
						buildPlan[j][i] = building;
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
					if (buildPlan[j][i] != 1) {
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
						buildPlan[j][i] = building;
					}
				}
			}

		}
		else {
			laenge += y;
			breite += x;
			for (int j = y; j > laenge; j--) {
				for (int i = x; i > breite; i--) {
					if (buildPlan[j][i] != 1) {
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
						buildPlan[j][i] = building;
					}
				}

			}
		}
	}

}

void CapyCitySim::deleteArea() {

	int x = 0;
	int y = 0;
	int laenge = 0;
	int breite = 0;
	int validatePosition = 0;
	int validateGebaeude = 0;
	int maxX = cols;
	int maxY = rows;

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
		if ((breite > 0 && x + breite <= maxX || breite < 0 && x + breite >= 0) && (laenge > 0 && y + laenge <= maxY || laenge < 0 && y + laenge >= 0) && laenge != 0 && breite != 0) {
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
					buildPlan[y][i] = 1;
				}
			}

		}
		else {
			laenge += y;
			breite += x;

			for (y; y > laenge; --y) {
				for (int i = x; i < breite; i++) {
					buildPlan[y][i] = 1;
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
					buildPlan[y][i] = 1;
				}
			}
		}
		else {
			laenge += y;
			breite += x;
			for (y; y > laenge; y--) {
				for (int i = x; i > breite; i--) {
					buildPlan[y][i] = 1;


				}

			}
		}
	}
}
