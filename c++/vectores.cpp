#include <iostream>

using namespace std;

int main()
{
   cout << "Hola! Aqui podras cuenta" << "\n";

int numcuenta;
cout << "Por favor ingrese la csntidad de cuentas: " << "\n";
cin >> numcuenta;
int digito=1;

int cuenta;

double saldo=0.0;
double saldototal=0.0;

do{

cout<<"Ingrese # cuenta";
cin >> cuenta;
 cout<<"Ingrese el saldo";
cin >> saldo;
if(saldo<0){
    cout << "saldo negativo" << "\n";
    digito--;
}else{
    cout << "saldo positivo" << "\n";
    digito++;
    saldototal=saldototal+saldo;
    
     if (saldo>0) {
         cout << "El # de cuenta = "<<cuenta <<"Saldo Acreedor."<< "\n";
     }else{
         cout << "El # de cuenta = "<<cuenta <<"Saldo Nulo."<< "\n";
     }
}

}while (digito<=numcuenta);

cout<< "saldo total es:"<< saldototal << endl;
    return 0;
}