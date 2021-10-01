
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Cuenta
{

private:
	string titular;
	int numero;
	double saldo;

public:
	Cuenta();
	//	Cuenta(string Titular, int Cuenta, double Saldo);
	void depositar(double);
	int retirar(double);
	void setTitular(string);
	string getTitular();
	void setSaldo(double);
	double getSaldo();
	void setNumero(int);
	int getNumero();
	int searchCta(int, int, Cuenta cta[]);
	void Revisar_Transaccion(int, int, Cuenta cta[]);
	void Mostrar_Cuentas();
};