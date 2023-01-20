#pragma once
#include "Material.h"
#include <string>
using std::string;

class Metal : public Material {
private:
	string name;
	double price;
	int number;
public:
	Metal(string _name, double _price, int _number);
};
