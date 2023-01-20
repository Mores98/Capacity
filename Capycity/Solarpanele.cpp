#include "Solarpanele.h"

Solarpanele::Solarpanele(double _Grundpreis, string _Label,int _id, string ma1, string ma2, string ma3) : Building(_Grundpreis, _Label,_id, ma1, ma2, ma3) {
	Grundpreis = _Grundpreis;
	Label = _Label;
	id = _id;
}