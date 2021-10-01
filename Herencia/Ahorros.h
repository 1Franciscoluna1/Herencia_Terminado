#pragma once
#include "Cuenta.h"

class Ahorros :public Cuenta
{

private:
	double tasaInteres = 0;
	int periodo = 0;

public:
	Ahorros();
	//	Ahorros(string Titular, int Cta, double Saldo, double tasa, int Periodo);
	void setTasaInteres(double);
	double getTasaInteres();
	void setPeriodo(int);
	int getPeriodo();
	void calcularInteres();
	void Mostrar();
};