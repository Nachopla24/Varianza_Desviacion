#include <iostream>
#include <ctime>
#include <math.h>

const int tamano = 10000, MAXIMO = 10000;//el tamaño del arreglo y los valores [0 y maximo[

using namespace std;

void llenarArreglo(int []);
void verArreglo(int []);
float promedioArreglo(int []);
float varianzaArreglo(int []);

int main()
{
    cout << "Tarea 2 Computacion Paralela\n\n\n";
    int arregloRandom[tamano];
    int menu = 0;
    float promedio = 0, varianza = 0;
    while (menu != 6){
      cout << "Selecciona una opcion digitando su numero: \n";
      cout << "1. Llenar el arreglo con enteros al azar: \n";
      cout << "2. Mostrar el arreglo: \n";
      cout << "3. Calcular el promedio: \n";
      cout << "4. Calcular la varianza: \n";
      cout << "5. Calcular la desviacion estandar: \n";
      cout << "6. Para Salir: \n";
      cout << "Tu seleccion: ";
      cin >> menu;
        switch (menu){
          case 1:
              llenarArreglo(arregloRandom);
              cout << "Llenado exitoso\n\n";
              break;
          case 2:
              verArreglo(arregloRandom);
              cout << "\n\n";
              break;
          case 3:
              promedio = promedioArreglo(arregloRandom);
              cout << "El promedio de los valores del arreglo es: " << promedio << "\n\n";
              break;
          case 4:
              varianza = varianzaArreglo(arregloRandom);
              cout << "La varianza de los valores del arreglo es: " << varianza << "\n\n";
              break;
          case 5:
              cout << "La desviacion estandar de los valores del arreglo es: " << sqrt(varianza) << "\n\n";
              break;
          default:
              cout << "Au revoir...........\n";
              return 0;
        }
    }
}



void llenarArreglo(int arregloRandom[])
{
  srand( time( 0 ) );
  for ( int i = 0; i < tamano; ++i ){//LLena con numeros al azar (tamano) entre 0 y maximo
    arregloRandom[ i ] = rand() % MAXIMO;
  }
}



void verArreglo(int auxiliar[])
{
  for ( int i = 0; i < tamano; ++i ){
    cout <<"arreglo[" << i << "] = " << auxiliar[ i ] << "\n";
  }
}

float promedioArreglo(int arregloRandom[])
{
  float aux = 0;
  for ( int i = 0; i < tamano; ++i ){
    aux += arregloRandom[i];
  }
  aux = aux/tamano;
  return aux;
}

float varianzaArreglo(int arregloRandom[])
{
  float aux = 0, promedio = 0, numerador = 0;
  promedio = promedioArreglo(arregloRandom);
  for ( int i = 0; i < tamano; ++i ){
    numerador = arregloRandom[i]-promedio;
    aux += pow(numerador,2);
  }
  aux = aux/tamano;
  return aux;
}
