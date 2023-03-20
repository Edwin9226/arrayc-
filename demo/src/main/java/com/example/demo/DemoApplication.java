package com.example.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

@SpringBootApplication
public class DemoApplication {

	public static void main(String[] args) {
		SpringApplication.run(DemoApplication.class, args
		);

		Scanner entrada = new Scanner (System.in);


		int n, i, opc;
		System.out.println("ingrese la cantidad de elementos que desea que tenga el vector: ");
		n=entrada.nextInt();

		//ingreso de los elementos del vector
		int vector[]= new int [n];  //se declara un vector en java

		System.out.println("ingrese los elementos del vector:");
		for (i = 0; i < n; i++)
		{
			System.out.print("posicion"+ i + ":");
			vector [i] = entrada.nextInt();
		}

		do
		{
			System.out.println("");
			System.out.println("***** MENU PRINCIPAL DE OPCIONES *****");
			System.out.println("1.Ordenamiento por Insercion: ");
			System.out.println("2.Ordenamiento por selecion directa: ");
			System.out.println("3.Ordenamiento por Burbuja: ");
			System.out.println("4.Ordenamiento por  Ascendente: ");
			System.out.println("5.Ordenamiento por Descendente: ");
			System.out.println("6.Ordenamiento por Quick Sort: ");
			System.out.println("7.Ordenamiento por intercambio: ");
			System.out.println("8.Ordenamiento por shell: ");
			System.out.println("9.Busqueda Binaria: ");
			System.out.println("10.Busqueda Secuencial: ");

			System.out.print("Escoja un metodo de ordenamiento... (digite el cero para finalizar)");
			opc = entrada.nextInt();

			switch (opc)
			{
				case 1:
					// método de ordenamiento por Inserción - Descendente
					for (i = 0; i < n; i++)
					{
						int nuevo = vector[i];
						int pos = 0;
						while ((pos < i) && (vector[pos] > nuevo))
						{
							pos++;
						}
						for (int j = i - 1; j >= pos; j--) // int j
						{
							vector[j + 1] = vector[j];
						}
						vector[pos] = nuevo;
					}
					System.out.println("El vector ordenado de manera Descendente por el metodo de Insercion es:");

					for (i = 0; i < n; i++)
					{
						System.out.print(vector[i] + "");

					}
					break;

				case 2:
					// Método de ordenamiento por Selección directa
					for (i = 0; i < n; i++)
					{
						int imin = i;
						for (int j = i + 1; j < n; j++)
						{
							if (vector[j] < vector[imin])
							{
								imin = j;
							}
						}
						int aux = vector[i];
						vector[i] = vector[imin];
						vector[imin] = aux;
					}
					// Imprimir los lementos del vector ingresado
					System.out.println("El vector ordenado Ascendentemente por el metodo de Seleccion directa es: ");

					for (i = 0; i < n; i++)
					{
						System.out.print(vector[i] + "");
					}
					break;

				case 3:
					// Método de ordenamiento por Burbuja
					for (i = 0; i < n - 1; i++)
					{
						for (int j = i + 1; j < n; j++)
						{
							if (vector[i] > vector[j])
							{
								int aux = vector[i];
								vector[i] = vector[j];
								vector[j] = aux;
							}
						}
					}
					// Imprimir los elmentos del vector ingresado
					System.out.println("El vector ordenado Ascendentemente por el metodo de la Burbuja es: ");

					for (i = 0; i < n; i++)
					{
						System.out.print(vector[i] + "");
					}
					break;

				case 4:
					//metodo de ordenamiento po ascendente
					ordSelAsc(vector);
					for (int num : vector) {
						System.out.println(num);
					}
						break;

				case 5:
					//metodo de ordenamiento por descendente
					ordSelDesc(vector);
					for (int num : vector) {
						System.out.println(num);
					}
						break;

				case 6:
					//metodo de ordenamiento por Quick Sort
					quicksort(vector,0, vector.length-1);
					for (int num : vector) {
						System.out.println(num);
					}
						break;

				case 7:
					//metodo de ordenamiento por intercambio
					intercambio(vector);
					for (int num : vector) {
						System.out.println(num);
					}
						break;

				case 8:
					//metodo de ordenamiento por Shell
					shell(vector);
					for (int num : vector) {
						System.out.println(num);
					}

						break;
				case 9:
					//metodo de busqueda binaria
					System.out.println("ingrese el numero a buscar en el vector: ");
					int  c=entrada.nextInt();
					int resultado= busquedaBinaria(vector,c);
					if (resultado == -1) {
						System.out.println("El elemento no esta presente");
					}else{
						System.out.println("Elemento encontrado en: " + "indice" + resultado);
			            }
					break;
				case 10:
					//metodo de busqueda secuencial
					System.out.println("ingrese el numero a buscar en el vector: ");
					int  bd=entrada.nextInt();
					Integer index= busquedaSecuencial(vector, bd);
					if (index != null) {
						System.out.println("Elemento encontrado en la posición " + index);
					} else {
						System.out.println("Elemento no encontrado");
					}
					break;



				default:
					System.out.println("Opcion incorrecta, vuelva a intentarlo (solo se permite del 1 al 10)");

					break;
			}
		} while (opc !=0);

	}

	static void ordSelAsc(int[] arreglo) {
		//iteramos sobre los elementos del arreglo
		for (int i = 0 ; i < arreglo.length - 1 ; i++) {
			int min = i;

			//buscamos el menor número
			for (int j = i + 1 ; j < arreglo.length ; j++) {
				if (arreglo[j] < arreglo[min]) {
					min = j;    //encontramos el menor número
				}
			}

			if (i != min) {
				//permutamos los valores
				int aux = arreglo[i];
				arreglo[i] = arreglo[min];
				arreglo[min] = aux;
			}
		}
	}

	static void ordSelDesc(int[] arreglo) {
		//iteramos sobre los elementos del arreglo
		for (int i = 0 ; i < arreglo.length - 1 ; i++) {
			int max = i;

			//buscamos el mayor número
			for (int j = i + 1 ; j < arreglo.length ; j++) {
				if (arreglo[j] > arreglo[max]) {
					max = j;    //encontramos el mayor número
				}
			}

			if (i != max) {
				//permutamos los valores
				int aux = arreglo[i];
				arreglo[i] = arreglo[max];
				arreglo[max] = aux;
			}
		}
	}

	public static void quicksort(int A[], int izq, int der) {

		int pivote=A[izq]; // tomamos primer elemento como pivote
		int i=izq;         // i realiza la búsqueda de izquierda a derecha
		int j=der;         // j realiza la búsqueda de derecha a izquierda
		int aux;

		while(i < j){                          // mientras no se crucen las búsquedas
			while(A[i] <= pivote && i < j) i++; // busca elemento mayor que pivote
			while(A[j] > pivote) j--;           // busca elemento menor que pivote
			if (i < j) {                        // si no se han cruzado
				aux= A[i];                      // los intercambia
				A[i]=A[j];
				A[j]=aux;
			}
		}

		A[izq]=A[j];      // se coloca el pivote en su lugar de forma que tendremos
		A[j]=pivote;      // los menores a su izquierda y los mayores a su derecha

		if(izq < j-1)
			quicksort(A,izq,j-1);          // ordenamos subarray izquierdo
		if(j+1 < der)
			quicksort(A,j+1,der);          // ordenamos subarray derecho

	}


	public static void shell(int A[]) {

		int salto, aux, i;
		boolean cambios;

		for (salto = A.length / 2; salto != 0; salto /= 2) {
			cambios = true;
			while (cambios) {   // Mientras se intercambie algún elemento
				cambios = false;
				for (i = salto; i < A.length; i++)   // se da una pasada
				{
					if (A[i - salto] > A[i]) {       // y si están desordenados
						aux = A[i];                  // se reordenan
						A[i] = A[i - salto];
						A[i - salto] = aux;
						cambios = true;              // y se marca como cambio.
					}
				}
			}
		}
	}

	public static void intercambio ( int [ ] num )
	{
		int i, j, temp;  //asegúrese de que la variable temporal sea del mismo "tipo" que la matriz
		for ( i = 0; i < num.length - 1; i ++ )
		{
			for ( j = i + 1; j < num.length; j ++ )
			{
				if( num[ i ] < num[ j ] )         //clasificación en orden descendente
				{
					temp = num[ i ];   //intercambio
					num[ i ] = num[ j ];
					num[ j ] = temp;
				}
			}
		}
	}

	public static int busquedaBinaria(int elementos[], int x)
	{
		int l = 0, r = elementos.length - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;

			if (elementos[m] == x)
				return m;

			if (elementos[m] < x)
				l = m + 1;

			else
				r = m - 1;
		}
		return -1;
	}

	public static Integer busquedaSecuencial(int[] data, int valor) {
		Integer pos = null;
		for (int i = 0; i < data.length; i++) {
			if (valor == data[i]) {
				pos = i;
				break;
			}
		}
		return pos;
	}



}
