#include "Cheques.h"
#include <iostream>
#include <string>

Cheques::Cheques() :Cuenta() {
	setCantidadCheques(0);
}


void Cheques::setCantidadCheques(int Cantidad)
{
	cantidadCheques = Cantidad;
}

int Cheques::getCantidadCheques()
{
	return cantidadCheques;
}

int Cheques::girarcheque(double monto)
{
	if (getSaldo() >= monto && cantidadCheques > 0) {
		cantidadCheques--;
		setSaldo(getSaldo() - monto);
		return 1;
	}
	else {
		return 0;
	}
}

void Cheques::Mostrar()
{	
		cout << "\n\t\t----Cuenta de Cheques----";
		Mostrar_Cuentas();
		cout << "\tCantidad de cheques disponible\t\t" << getCantidadCheques()<<endl;
	
}
