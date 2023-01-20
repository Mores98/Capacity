#pragma once
#include "Material.h"
#include <string>
using std::string;

class Plastic : public Material {
private:
	string name;
	double price;
	int number;
public:
	Plastic(string _name, double _price, int _number);
};