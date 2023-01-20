#ifndef _MATERIAL_H_
#define _MATERIAL_H_
#include <iostream>
using std::string;

class Material
{
private:
	string name;
	double price;
	int  number;
public:
	Material(string _name, double _price, int _number);
	virtual string getName();
	virtual double getPrice();
	virtual void setPrice(double _price);
	virtual double getPriceByName(string _name);
};

#endif