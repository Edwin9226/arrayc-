#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;

void imprimir_vector(int [], int);
void float_vector(int [],int);
void imprimir_vectorF(float [], int);
void negativos(int [],int);
void minimo(int [], int);
void maximo(int [], int);
void max_min_Element(int [], int);
void par_impar(int [], int );
void media(int [], int );
void intercambio(int ,int []);
void mediana(int [], int );
int main()
{


    int num;
    cout << "ingrese la cantidad de elementos que desea que tenga el vector: " << "\n";
    cin >> num;


    int vector1[num];

    cout << "ingrese los elementos del vector: " << "\n";
    int sizevec=num-1;
    int numi;
    for (int i = 0 ; i <=sizevec ; ++i)
    {

        cout << "ingrese el numero : " << "\n";
        cin >> vector1[i];
    }

    int numeroBuscado;
    int opc;
    do
    {
        cout << "" << "\n";
        cout << "***** MENU PRINCIPAL DE OPCIONES ***** " << "\n";
        cout << "1.método de Impresion: " << "\n";
        cout << "2.Metodo float: " << "\n";
        cout << "3.Negativos : " << "\n";
        cout << "4. Min y Max del vector: " << "\n";
        cout << "5. pares e Impares del vector: " << "\n";
         cout << "6. Media y Mediana del vector: " << "\n";
            cout << "7.intercambio Media del vector: " << "\n";

        int opc;
        cout << "Escoja un metodo de ordenamiento... (digite el cero para finalizar) " << "\n";
        cin >> opc;


        switch(opc)
        {
        case 1 :
            cout << "método de Impresion " << endl;
            imprimir_vector(vector1, sizevec);
            break;
        case 2 :
            cout << "Metodo float:" << endl;
            float_vector(vector1,sizevec);
            break;
        case 3 :
            cout << "Negativos :" << endl;
            negativos(vector1, sizevec);
            break;
        case 4 :
            cout << "Negativos :" << endl;
            max_min_Element(vector1, sizevec);
            break;

        case 5 :
            cout << "Pares e Impares del vector:" << endl;
            par_impar(vector1, sizevec);
            break;

        case 6 :
            cout << "Media del vector:" << endl;
            intercambio(sizevec,vector1);
            media(vector1, sizevec);
            mediana(vector1, sizevec);
            break;
        case 7 :
            cout << "intercambio del vector:" << endl;
            intercambio( sizevec, vector1);
            imprimir_vector( vector1,sizevec);
            break;

        default :
            cout << "Invalid patron" << endl;
        }

    }
    while(opc!=0);

    return 0;
}

void imprimir_vector(int a[], int n)
{

    for (int k = 0; k <= n; k++)
    {
        cout<<a[k]<<endl;
    }
}


void float_vector(int a[], int n)
{

    float vector2[n];
    for (int k = 0; k <= n; k++)
    {
        vector2[k]=(float) a[k]   ;
    }

    imprimir_vectorF(vector2, n);
}

void imprimir_vectorF(float a[], int n)
{

    for (int k = 0; k <= n; k++)
    {
        cout<<a[k]<<endl;
    }
}

void negativos(int v[], int n)
{
    int i, count = 0;

    for (i = 0; i <= n; i++)
    {
        if (v[i] < 0)
        {
            cout<<"valores negativos del vector:" + v[i] <<endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout<<"No hay valores negativos en el vector.\n"<<endl;

    }
    else
    {
        cout<<"Existen hay valores negativos en el vector.\n"<<endl;
    }
}


void max_min_Element(int a[], int n)
{

    maximo(a, n);
    minimo(a, n );
}


void maximo(int v[], int n)
{
    int max=0;

    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || max < v[i])
        {
            max = v[i];
        }


    }

    cout << "El valor maximo del vector es:" << endl;
    cout << max << endl;
}

void minimo(int v[], int n)
{


    int min=0;

    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || min > v[i])
        {
            min = v[i];
        }

    }

    cout << "El valor minimo del vector es:" << endl;
    cout << min << endl;
}


   void par_impar(int a[], int n)
    {

        int par = 0, impar = 0;
        string parRes , imparRes;
        for (int k = 0; k <= n; k++)
        {
            if (a[k] % 2 == 0)
            {
                parRes+= to_string(a[k])+",";
                //pares[par++] = a[k];
            }
            else
            {
               imparRes+= to_string(a[k])+",";
                //impares[impar++] = a[k];
            }
        }


       cout << "Los numeros pares son:" << endl;
        cout << parRes << endl;

          cout << "Los numeros impares son:" << endl;

        cout << imparRes << endl;

    }


    void media(int a[], int n)
{
    int num=n+1;

    int sumatoria=0;
    for (int k = 0; k <= n; k++)
    {
        sumatoria += a[k];

    }
    float media= (float) sumatoria/ (float) num;
     cout << "La media es:"<< endl;
    cout << media<< endl;
}

void mediana(int a[], int n){
int num=n+1;

          if (num % 2 == 0)
            {
                int mediaParDer=(num/2)+1;
                int mediaParIzq=num/2;

                int sumDerIzq= (a[mediaParDer]+a[mediaParIzq]);
                float media= (float) (sumDerIzq/2);
                cout << "La mediana es:"<< endl;
                cout << media<< endl;
                //pares
            }
            else
            {
                int mediaImpar= round(num/2);
                cout << mediaImpar<< endl;
                cout << "La mediana es:"<< endl;
                cout << a[mediaImpar]<< endl;
                //impares
            }
}


void intercambio(int n,int v[])
{
int j, aux;
int i = 0;
bool ord = false;

// Ordenaciones
while(!ord){
	// Comparaciones
	ord=true;
	for(j=0;j<n-i;j++){
		if(v[j]>v[j+1]){
			// Intercambiar los elementos
			aux=v[j];
			v[j]=v[j+1];
			v[j+1]=aux;
			ord = false;	// Indicador de vector ordenado
		}
	}
	i++;
}

}
