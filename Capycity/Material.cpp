#include "Material.h"
#include <string>
using std::string;

Material::Material(string _name, double _price, int _number) {
	name = _name;
	price = _price;
	number = _number;
}

string Material::getName() {
		return name;
	};
double Material::getPrice() {
		return price;
	};
void Material::setPrice(double _price) {
		price = _price;
	};
double Material::getPriceByName(string _name) {
	if (name == _name) {
		return price;
	}
	else return 0;
}