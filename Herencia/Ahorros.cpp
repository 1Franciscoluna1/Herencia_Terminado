#include "Ahorros.h"


Ahorros::Ahorros() :Cuenta()
{
	setTasaInteres(0);
	setPeriodo(0);
}

//Ahorros::Ahorros(string Titular, int Cta, double Saldo, double tasa, int Periodo) :Cuenta(Titular, Cta, Saldo)
//{
//	tasaInteres = 0;
//	periodo = 0;
//}

void Ahorros::setTasaInteres(double tasa)
{
	tasaInteres = tasa;
}

double Ahorros::getTasaInteres()
{
	return tasaInteres;
}

void Ahorros::setPeriodo(int Periodo)
{
	periodo = Periodo;
}

int Ahorros::getPeriodo()
{
	return periodo;
}

void Ahorros::calcularInteres()
{
	setSaldo(getSaldo() + (getSaldo() * (tasaInteres * periodo)));
}

void Ahorros::Mostrar()
{
	
		cout << "\n\t\t----Cuenta de Ahorros----";
		Mostrar_Cuentas();
		cout << "\tTasa de interes:\t\t\t" << getTasaInteres() << "%" << endl
			<< "\tPeriodo:\t\t\t\t" << getPeriodo() << " Meses" << endl;
	
}
