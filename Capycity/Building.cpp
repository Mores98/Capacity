#include "Building.h"
#include <vector>
#include <iostream>
#include "Material.h"
using std::string;

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

double Building::getGrundpreis() {
	return Grundpreis;
}

string Building::getLabelById(int _id) {
	if (id == _id) {
		return Label;
	}
	return "";
}