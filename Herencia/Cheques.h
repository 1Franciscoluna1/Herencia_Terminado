
#pragma once
#include "Cuenta.h"


class Cheques :public Cuenta
{

private:
	int cantidadCheques;

public:
	Cheques();
	//	Cheques(string,int,double,int);
	void setCantidadCheques(int);
	int getCantidadCheques();
	int girarcheque(double);
	void Mostrar();
};