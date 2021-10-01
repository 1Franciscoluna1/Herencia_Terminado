#include "Cuenta.h"
#include <iostream>
#include <string>

Cuenta::Cuenta()
{
	setTitular("");
	setNumero(0);
	setSaldo(0);
}

//Cuenta::Cuenta(string Titular, int Cuenta, double Saldo)
//{
//	setTitular(" ");
//	numero = 0;
//	saldo = 0;
//}

void Cuenta::depositar(double valor)
{
	saldo += valor;
}

int Cuenta::retirar(double valor)
{
	if (saldo >= valor)
	{
		saldo -= valor;
		return 1;
	}
	else
		return 0;
}

void Cuenta::setTitular(string Titular)
{
	titular = Titular;
}

string Cuenta::getTitular()
{
	return titular;
}

void Cuenta::setSaldo(double Saldo)
{
	saldo = Saldo;
}

double Cuenta::getSaldo()
{
	return saldo;
}

void Cuenta::setNumero(int cta)
{
	numero = cta;
}

int Cuenta::getNumero()
{
	return numero;
}

int Cuenta::searchCta(int Cta, int Cant, Cuenta cta[])
{
	int encontrado = -1;

	for (int i = 0; i <= Cant; i++)
	{
		if (Cta == cta[i].getNumero())
		{
			encontrado = i;
			break;
		}
	}
	return encontrado;
}

void Cuenta::Revisar_Transaccion(int resultado, int Cta, Cuenta cta[])
{
	if (resultado == 1)
	{
		cout << "\n\tTransaccion Exitosa" << endl;
	}
	else if (resultado == 0) {
		cout << "\n\n\tSaldo Insuficiente" << endl
			<< "\tUsted solo cuenta con $" << cta[Cta].getSaldo() << " Pesos\n\n\n";
		system("pause");
		system("cls");
	}
}

void Cuenta::Mostrar_Cuentas()
{
	cout << "\n\n\tTitular:\t\t\t\t" << getTitular() << endl
	<< "\tNumero de cuenta:\t\t\t" << getNumero() << endl
	<< "\tSaldo:\t\t\t\t\t$" << getSaldo() << endl;
	
}