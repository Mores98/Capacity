#ifndef _BUILDING_H_
#define _BUILDING_H_
#pragma once
#include <iostream>
#include <vector>
#include <map>

using std::string;
using std::vector;

class Building
{
private:
	double Grundpreis;
	string Label;
	vector <string> bauMateriallien;
	int id;
	vector <string> bauMateriallienWood;
	vector <string> bauMateriallienMetal;
	vector <string> bauMateriallienPlastic;

public:
	Building(double _Grundpreis, string _Label,int _id, string ma1, string ma2, string ma3);
	virtual void setBauMateriallien(string _bauMateriallien);
	virtual string getBauMateriallien(int _value);
	virtual double getGrundpreis();
	virtual string getLabelById(int _id);
	virtual void getAmoutOfMaterialNeeded(string _name);
	virtual void setBauMateriallienWood(string _bauMateriallienWood);
	virtual void setBauMateriallienPlastic(string _bauMateriallienPlastic);
	virtual void setBauMateriallienMetal(string _bauMateriallienMetal);
};
#endif