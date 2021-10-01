
#include "Ahorros.h"
#include "Cheques.h"


int menu();
void kieto();
int Ctatype();


int menu() {
	int opc;
	cout << "\n\n\tElija el una opcion" << endl
		<< "\t1) Crear cuenta de Ahorros" << endl
		<< "\t2) Crear cuenta de Cheques" << endl
		<< "\t3) Depositar" << endl
		<< "\t4) Retirar" << endl
		<< "\t5) Girar Cheque" << endl
		<< "\t6) Calcular Intereses" << endl
		<< "\t7) Mostrar todas las Cuentas" << endl
		<< "\t0) Salir" << endl;
	cin >> opc;
	return opc;
}

 void kieto() {
	cout << "\n\n\n";
	system("pause");
	system("cls");
}

 int Ctatype()
 {
	 int opc2 = 0;
	 do
	 {
		 cout << "\n\tQue tipo de Cuenta es?" << endl
			 << "\t1) Cuenta de Ahorros" << endl
			 << "\t2) Cuenta de Cheques\n\t"; cin >> opc2;
		 if (opc2 <= 0 || opc2 >= 3)
		 {
			 cout << "\n\tOpcion no valida";
			 kieto();
		 }
	 } while (opc2 <= 0 || opc2 >= 3);
	 return opc2;
 }

int main() {
	int opc,opc2, Entero=0,ContAhor=0,ContCheq=0,a,b;
	double Double=0;
	string texto, ptm;

	Ahorros CuentaAhorros[5];
	Cheques CuentaCheques[5];

	do
	{
		opc = menu();
		cin.ignore();
		switch (opc)
		{

		case 1:
			system("cls");
			cout << "\n\t\t----Creando Cuenta de Ahorros----" << endl
				 << "\tIngrese el Nombre del Titular:\t\t"; getline(cin, texto);
			CuentaAhorros[ContAhor].setTitular(texto);
			cout << "\tIngrese el Numero de Cuenta\t\t"; cin >> Entero;
			CuentaAhorros[ContAhor].setNumero(Entero);
			cout << "\tIngrese el Saldo\t\t\t$"; cin >> Double;
			CuentaAhorros[ContAhor].setSaldo(Double);
			cout << "\tIngrese la Tasa de Interes\t\t"; cin >> Double;
			CuentaAhorros[ContAhor].setTasaInteres(Double);
			cout << "\tIngrese el Periodo de Ahorro\t\t"; cin >> Entero;
			CuentaAhorros[ContAhor].setPeriodo(Entero);
			kieto();
			ContAhor++;
			break;

		case 2:
			system("cls");
			cout<<"\n\t\t----Creando Cuenta de Cheques----"<<endl
				 << "\tIngrese el Nombre del Titular:\t\t"; getline(cin, texto);
			CuentaCheques[ContCheq].setTitular(texto);
			cout << "\tIngrese el Numero de Cuenta\t\t"; cin >> Entero;
			CuentaCheques[ContCheq].setNumero(Entero);
			cout << "\tIngrese el Saldo\t\t\t$"; cin >> Double;
			CuentaCheques[ContCheq].setSaldo(Double);
			cout << "\tIngrese la Cantidad de Cheques\t\t"; cin >> Entero;
			CuentaCheques[ContCheq].setCantidadCheques(Entero);
			kieto();
			ContCheq++;
			break;

		case 3:
			system("cls");
			cout << "\t\t-----Deposito de Efectivo-----" << endl;
			opc2 = Ctatype();
			cout << "\t\t-----Deposito de Efectivo-----" << endl;
			cin.ignore();

			if (opc2==1)
			{
				cout << "\n\tIngrese el Numero de Cuenta de Ahorros:\t\t"; cin >> Entero;
				a = CuentaAhorros->searchCta(Entero, ContAhor, CuentaAhorros);
				if (a == -1) {
					cout << "\n\tCuenta no encontrada";
					kieto();
					break;
				}
				cout << "\tIngrese el monto del Deposito\t\t\t$"; cin >> Double;
				CuentaAhorros[a].depositar(Double);
				cout << "\tSu nuevo saldo es :\t\t\t\t$" << CuentaAhorros[a].getSaldo();
			}
			else if (opc2==2)
			{
				cout << "\n\tIngrese el Numero de Cuenta de Cheques:\t\t"; cin >> Entero;
				a = CuentaCheques->searchCta(Entero, ContCheq, CuentaCheques);
				if (a == -1) {
					cout << "\n\tCuenta no encontrada";
					kieto();
					break;
				}
				cout << "\tIngrese el monto del Deposito\t\t\t$"; cin >> Double;
				CuentaCheques[a].depositar(Double);
				cout << "\tSu nuevo saldo es :\t\t\t\t$" << CuentaCheques[a].getSaldo();
			}
			else
			{
				cout << "\n\tOpcion no valida";
			}
			kieto();
			break;

		case 4:
			system("cls");
			cout << "\t\t-----Retiro de Efectivo-----" << endl;

			opc2 = Ctatype();
			cout << "\t\t-----Retiro de Efectivo-----" << endl;
			cin.ignore();

			if (opc2 == 1)
			{
				cout << "\n\tIngrese el Numero de Cuenta de Ahorros:\t\t"; cin >> Entero;
				a = CuentaAhorros->searchCta(Entero, ContAhor, CuentaAhorros);
				if (a == -1) {
					cout << "\n\tCuenta no encontrada";
					kieto();
					break;
				}
				cout << "\tIngrese el monto del Retiro\t\t\t$"; cin >> Double;
				b = CuentaAhorros[a].retirar(Double);

				CuentaAhorros[a].Revisar_Transaccion(b, a, CuentaAhorros);
				if (b == 0)
					break;
				cout << "\tSu nuevo saldo es :\t\t\t\t$" << CuentaAhorros[a].getSaldo()<<" Pesos";

			}
			else if (opc2 == 2)
			{
				cout << "\n\tIngrese el Numero de Cuenta de Cheques:\t\t"; cin >> Entero;
				a = CuentaCheques->searchCta(Entero, ContCheq, CuentaCheques);
				if (a == -1) {
					cout << "\n\tCuenta no encontrada";
					kieto();
					break;
				}
				cout << "\tIngrese el monto del Retiro\t\t\t$"; cin >> Double;
				b = CuentaCheques[a].retirar(Double);

				CuentaCheques[a].Revisar_Transaccion(b, a, CuentaCheques);
				if (b == 0)
					break;

				cout << "\tSu nuevo saldo es :\t\t\t\t$" << CuentaCheques[a].getSaldo()<<" Pesos";
			}
			kieto();
			break;

		case 5:
			system("cls");
			cout << "\t\t-----Girar Cheque-----" << endl

				 << "\n\tIngrese el Numero de Cuenta:\t\t"; cin >> Entero;
			a = CuentaCheques->searchCta(Entero, ContAhor, CuentaCheques);
			if (a == -1) {
				cout << "\n\tCuenta no encontrada";
				kieto();
				break;
			}

			if (CuentaCheques[a].getCantidadCheques() <= 0) {
				cout << "\n\tNo cuentas con mas Cheques"; kieto(); break;
			}

			cout << "\tIngrese el Valor del Cheque\t\t$"; cin >> Double;
			b = CuentaCheques[a].girarcheque(Double);

			CuentaCheques[a].Revisar_Transaccion(b, a, CuentaCheques);


			cout << "\tSu nuevo saldo es :\t\t\t$" << CuentaCheques[a].getSaldo() << " Pesos";
			kieto();
			break;

		case 6:
			system("cls");
			cout << "\t\t-----Abono de Intereses-----" << endl

				<< "\n\tIngrese el Numero de Cuenta:\t\t"; cin >> Entero;
			a = CuentaAhorros->searchCta(Entero, ContAhor, CuentaAhorros);
			if (a == -1) {
				cout << "\n\tCuenta no encontrada";
				kieto();
				break;
			}
			cout << "Saldo previo :\t$" << CuentaAhorros[a].getSaldo() << endl;
			CuentaAhorros[a].calcularInteres();
			cout << "Saldo Actual :\t$" << CuentaAhorros[a].getSaldo() << endl;
			kieto();
			break;

		case 7:
			system("cls");
			if (ContAhor > 0) {
				for (int i = 0; i < ContAhor; i++)
				{
				CuentaAhorros[i].Mostrar();
				}
			}

			if (ContCheq > 0) {
				for (int i = 0; i < ContCheq; i++)
				{
					CuentaCheques[i].Mostrar();
				}
			}
			kieto();
			break;

		default:
			if (opc != 0) {
				system("cls");
				cout << "\n\n\tOpcion no valida" << endl;
				kieto();
			}
			break;
		}

	} while (opc!=0);
}
