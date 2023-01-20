#include "Building.h"
#include <vector>
#include <iostream>
#include "Material.h"
#include "Wood.h"
#include "Metal.h"
#include "Plastic.h"
#include <map>
#include <vector>
using std::string;
using std::map;
using std::inserter;
using std::pair;



Building::Building(double _Grundpreis, string _Label, int _id, string ma1, string ma2, string ma3) {
	Grundpreis = _Grundpreis;
	Label = _Label;
	id = _id;
	setBauMateriallien(ma1);
	setBauMateriallien(ma2);
	setBauMateriallien(ma3);

}

void Building::setBauMateriallien(string _bauMateriallien) {
	bauMateriallien.push_back(_bauMateriallien);
}

string Building::getBauMateriallien(int _value) {
	return bauMateriallien.at(_value);
}

void Building::setBauMateriallienWood(string _bauMateriallienWood) {
	bauMateriallienWood.push_back(_bauMateriallienWood);
}

void Building::setBauMateriallienMetal(string _bauMateriallienMetal) {
	bauMateriallienMetal.push_back(_bauMateriallienMetal);
}

void Building::setBauMateriallienPlastic(string _bauMateriallienPlastic) {
	bauMateriallienPlastic.push_back(_bauMateriallienPlastic);
}


double Building::getGrundpreis() {
	return Grundpreis;
}

string Building::getLabelById(int _id) {
	if (id == _id) {
		return Label;
	}
	return "";
}

void Building::getAmoutOfMaterialNeeded(string _name) {
	/*
	map<Material, vector<string>> mapGebaeude;
	mapGebaeude.insert(pair<Material, vector<string>> (wo2, bauMateriallienWood));
	mapGebaeude.insert(pair<Material, vector<string>> (me2, bauMateriallienMetal));
	mapGebaeude.insert(pair<Material, vector<string>> (pa2, bauMateriallienPlastic));
	*/

	setBauMateriallienMetal("Metal");
	setBauMateriallienPlastic("Plastik");
	setBauMateriallienWood("Wood");

		map<Material, vector<string>> mapGebaeude;
	mapGebaeude[Wood("Holz", 10.5, 1)] = bauMateriallienWood;
	mapGebaeude[Metal("Metall", 20.2, 1)] = bauMateriallienMetal;
	mapGebaeude[Plastic("Plastik", 5.1, 1)] = bauMateriallienPlastic;
	

}