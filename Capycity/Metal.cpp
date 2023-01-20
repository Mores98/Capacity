#include "Metal.h"

Metal::Metal(string _name, double _price, int _number):Material(_name, _price, _number) {
	name = _name;
	price = _price;
	number = _number;
}