// ELABORAR UN PROGRAMA QUE HAGA USO DE LA SENTENCIA SWITCH QUE PERMITA CONSOLIDAR LOS MÉTODOS DE ORDENAMIENTO
// DE VECTORES (Ascendente, Descendente, Selección, Burbuja, Inserción, Quick Sort, Intercambio, shell, binaria, y secuencial.)
#include <stdio.h>

int main()
{
    int n, i, opc;
    printf("Ingrese la cantidad de elementos que desea que tenga el vector: ");
    scanf("%i", &n);
    // Ingreso de los elementos del vector
    int vector[n]; // Se declara un vector de tipo entero
    printf("Ingrese los elementos del Vector: \n");
    for (i = 0; i < n; i++)
    {
        printf("Posicion %i: ", i);
        scanf("%i", &vector[i]);
    }
    do
    {
        printf("\n\n***** MENU PRINCIPAL DE OPCIONES *****");
        printf("\n1. Ordenamiento por Insercion: ");
        printf("\n2. Ordenamiento por Selección directa: ");
        printf("\n3. Ordenamiento por Burbuja: ");
        printf("\n4. Ordenamiento por Ascendente: ");
        printf("\n5. Ordenamiento por Descendente: ");
        printf("\n6. Ordenamiento por Quick Sort: ");
        printf("\n7. Ordenamiento por Intercambio: ");
        printf("\n8. Ordenamiento por Shell: ");
        printf("\n9. Busqueda Binaria: ");
        printf("\n10. Busqueda Secuencial: ");
        
        printf("\nEscoja un metodo de ordenamiento... (digite el cero para finalizar)");
        scanf("%i", &opc);
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
            printf(" El vector ordenado de manera Descendente por el metodo de Insercion es: \n");
            for (i = 0; i < n; i++)
            {
                printf("%7d %13d \n", i, vector[i]);
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
            printf(" El vector ordenado Ascendentemente por el metodo de Seleccion directa es: \n");
            for (i = 0; i < n; i++)
            {
                printf("%7d %13d \n", i, vector[i]);
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
            printf(" El vector ordenado Ascendentemente por el metodo de la Burbuja es: \n");
            for (i = 0; i < n; i++)
            {
                printf("%7d %13d \n", i, vector[i]);
            }
            break;

        case 4:
        	//metodo de ordenamiento po ascendente
        	for (i = 0; i < n - 1; i++)
        	
        	

            break;

        case 5:
        	//metodo de ordenamiento por descendente
        	for (i = 0; i < n - 1; i++)

            break;

        case 6:
        	//metodo de ordenamiento por Quick Sort
        	for (i = 0; i < n - 1; i++)

            break;

        case 7:
        	//metodo de ordenamiento por intercambio
        	for (i = 0; i < n - 1; i++)

            break;
            
        case 8:
        	//metodo de ordenamiento por Shell
        	for (i = 0; i < n - 1; i++)
        	
        	break;
        	
        case 9:
        	//metodo de Busqueda binaria
        	for (i = 0; i < n - 1; i++)
        	
        	break;
        	
        case 10:
        	//metodo de Busqueda Secuencial
        	for (i = 0; i < n - 1; i++)
        	
        	breack;
        	
        	

        default:
        printf("\nOpcion incorrecta, vuelva a intentarlo (solo se permite del 1 al 10)");
            break;
        }
    } while (opc !=0);
}

