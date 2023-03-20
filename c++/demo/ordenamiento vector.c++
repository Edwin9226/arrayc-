#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

void ordenar_asc(int [], int);
void ordenar_des(int [], int);
void quicksort(int [], int , int );
void intercambio(int ,int []);
void shell(int [], int );
int binaria(int ,int ,int [] );
int buscasecuencial(int,int[],int);
int busquedaBinaria(int [], int , int );
int main()
{


int num;
cout << "ingrese la cantidad de elementos que desea que tenga el vector: " << "\n";
cin >> num;



int vector1[num];

cout << "ingrese los elementos del vector: " << "\n";
int sizevec=num;
 int numi;
 for (int i = 0 ; i <=sizevec ; ++i){

    cout << "ingrese el numero : " << "\n";
    cin >> vector1[i];
 }

int numeroBuscado;
int opc;
 do{
    cout << "" << "\n";
    cout << "***** MENU PRINCIPAL DE OPCIONES ***** " << "\n";
    cout << "1.Ordenamiento por Insercion: " << "\n";
    cout << "2.Ordenamiento por selecion directa: " << "\n";
    cout << "3.Ordenamiento por Burbuja: " << "\n";
    cout << "4.Ordenamiento por  Ascendente: " << "\n";
    cout << "5.Ordenamiento por Descendente: " << "\n";
    cout << "6.Ordenamiento por Quick Sort: " << "\n";
    cout << "7.Ordenamiento por intercambio: " << "\n";
    cout << "8.Ordenamiento por shell: " << "\n";
    cout << "9.Busqueda Binaria: " << "\n";
    cout << "10.Busqueda Secuencial: " << "\n";

    int opc;
    cout << "Escoja un metodo de ordenamiento... (digite el cero para finalizar) " << "\n";
    cin >> opc;


   switch(opc) {
      case 1 :
         cout << "método de ordenamiento por Inserción - Descendente " << endl;

         break;
      case 2 :
         cout << "Ordenamiento por selecion directa:" << endl;
         break;
      case 3 :
         cout << "Ordenamiento por Burbuja:" << endl;
         break;
      case 4 :{
         cout << "Ordenamiento por  Ascendente:" << endl;
        ordenar_asc(vector1,sizevec);
           for (int k = 0; k <= sizevec; k++)
            {
            cout<<vector1[k]<<endl;
            }
         }break;
      case 5 :
        {
            cout << "Ordenamiento por Descendente:" << endl;
            ordenar_des(vector1,sizevec);
           for (int k = 0; k <= sizevec; k++)
            {
            cout<<vector1[k]<<endl;
            }
        }
         break;
      case 6 :
          {
               cout << "Ordenamiento por Quick Sort:" << endl;
            quicksort(vector1,0,sizevec);
             for (int k = 0; k <= sizevec; k++)
            {
            cout<<vector1[k]<<endl;
            }
          }

         break;
      case 7 :
          {
        cout << "Ordenamiento por intercambio:" << endl;
         intercambio(sizevec, vector1);
          for (int k = 0; k <= sizevec; k++)
            {
            cout<<vector1[k]<<endl;
            }
          }

         break;
      case 8 :
          {
              cout << "Ordenamiento por shell:" << endl;
         shell(vector1, sizevec);
          }

         break;
      case 9 :
          {
               int elem;
             cout << "Busqueda Binaria:" ;
          cout<<"Ingrese elemento a buscar ";
        cin >> elem;
            int posbin= busquedaBinaria(vector1, sizevec, elem);
        if(posbin==-1){
             cout << "Elemento no encontrado ";}
        else{
             cout << "Elemento encontrado ";}
          }

         break;

       case 10 :
           {
                int elemn;
        cout << "Busqueda Secuencial ingrese un numero:";
        cout<<"Ingrese elemento a buscar ";
        cin >> elemn;
        if(buscasecuencial(sizevec,vector1,elemn)==1){
        cout << "Elemento encontrado ";}
        else{
        cout << "Elemento no encontrado ";}

           }
        break;


      default :
         cout << "Invalid patron" << endl;
   }

 }while(opc!=0);





    return 0;
}

void ordenar_asc(int a[], int n)
{
   int aux;
   for (int i=n; i>=0; i--)
      for (int j=0; j<=i; j++)
         if (a[j] > a[j+1])
          {
            aux = a[j];
            a[j]= a[j+1];
            a[j+1]= aux;
           }
}


void ordenar_des(int a[], int n)
{
   int aux;
   for (int i=n; i>=0; i--)
      for (int j=0; j<=i; j++)
         if (a[j] < a[j+1])
          {
            aux = a[j];
            a[j]= a[j+1];
            a[j+1]= aux;
           }
}

// Partición usando el esquema de partición de Lomuto
int partition(int a[], int start, int end)
{
    // Elija el elemento más a la derecha como un pivote de la array
    int pivot = a[end];

    // los elementos menores que el pivote serán empujados a la izquierda de `pIndex`
    // elementos más que el pivote serán empujados a la derecha de `pIndex`
    // elementos iguales pueden ir en cualquier dirección
    int pIndex = start;

    // cada vez que encontramos un elemento menor o igual que el pivote, `pIndex`
    // se incrementa, y ese elemento se colocaría antes del pivote.
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    // intercambiar `pIndex` con pivote
    swap (a[pIndex], a[end]);

    // devuelve `pIndex` (índice del elemento pivote)
    return pIndex;
}

// Rutina de clasificación rápida
void quicksort(int a[], int start, int end)
{
    // condición base
    if (start >= end) {
        return;
    }
    // reorganizar los elementos a través del pivote
    int pivot = partition(a, start, end);
    // recurre en un subarray que contiene elementos que son menores que el pivote
    quicksort(a, start, pivot - 1);
    // se repite en el subarray que contiene elementos que son más que el pivote
    quicksort(a, pivot + 1, end);
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


void shell(int array[], int size)

{

 int i, j, intervalo, temp;

 intervalo = size/2;

 while (intervalo > 0) {

 for (i=intervalo; i < size; i++) {

 j = i;

 temp = array[i];

 while ((j >= intervalo) && (array[j - intervalo] > temp)) {

 array[j] = array[j - intervalo];

 j = j - intervalo;

 }

 array[j] = temp;

 }

 intervalo /= 2;

 }

}


int buscasecuencial(int n,int a[],int ele)
{
for(int i=0;i<=n;i++)
if(ele==a[i])return 1;
return 0;
}

int busquedaBinaria(int arreglo[], int tamano, int clave)
{
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;
  while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (arreglo[Icentro] == clave)
 return Icentro;
      else
 if (clave < arreglo[Icentro])
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}
