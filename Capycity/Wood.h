#pragma once
#include "Material.h"
#include <string>
using std::string;

class Wood : public Material {
public:
	string name;
	double price;
	int number;
	Wood(string _name, double _price, int _number);
};