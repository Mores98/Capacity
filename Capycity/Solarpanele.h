#include "Building.h"
#include "Material.h"
#pragma once

class Solarpanele : public Building
{
private:
	double Grundpreis;
	string Label;
	vector <Material> bauMateriallien;
	int id;
public:
	Solarpanele(double _Grundpreis, string _Label,int _id, string ma1, string ma2, string ma3);
};
