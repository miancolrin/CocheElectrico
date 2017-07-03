/*############################
#    EL VEHÍCULO ELÉCTRICO   #
#       ES EL FUTURO         #
##############################

A falta de herramientas para hacer cuentas sobre
vehículos eléctricos he creado este pequeño programa.

Con este programa se pueden hacer cálculos básicos
sobre el vehículo eléctrico, como el coste de una recarga,
el coste de recorrer 100km y el tiempo que va a tardar en
cargarse por completo.

Cuaquier mejora o sugerencia acerca de este programa
es bien recibida.

Usad el código para lo que queráis.

Creado por @miancolrin

Versión en C para Windows. Para la versión de Mac en Python ir a
https://github.com/miancolrin/CocheElectrico_python

Segunda versión de este programa, ha sido reescrito por completo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

void cargaEnDC();
void cargaEnTrifasica();
void costeDeCarga();
void precioDeRecorrer();

int main(){
	
	setlocale(LC_ALL, "Spanish");
	SetConsoleTitle("COCHE ELECTRICO");
	system("color 1F");
	
	char opc;
	
	do{
		
		system("cls");
		printf("========================MENÚ========================");
		printf("\n1. Tiempo de carga en corriente continua");
		printf("\n2. Tiempo de carga en corriente alterna monofásica");
		printf("\n3. Tiempo de carga en corriente alterna trifásica");
		printf("\n4. Calcular precio de una carga completa");
		printf("\n5. Calcular el coste de recorrer 100km");
		printf("\n\n0. SALIR");
		
		printf("\n\nOpción: ");
		opc = getch();
		
		switch(opc){
			
			case '1':{
				system("cls");
				cargaEnDC();
				system("pause");
				break;
			}
			case '2':{
				system("cls");
				cargaEnDC();
				system("pause");
				break;
			}
			case '3':{
				system("cls");
				cargaEnTrifasica();
				system("pause");
				break;
			}
			case '4':{
				system("cls");
				costeDeCarga();
				system("pause");
				break;
			}
			case '5':{
				system("cls");
				precioDeRecorrer();
				system("pause");
				break;
			}
			
		}
		
	}while(opc != '0');
	
}

void precioDeRecorrer(){
	
	float precio, consumo, coste;
	
	printf("Introduce el precio del kWh: ");
	scanf("%f", &precio);
	
	printf("\n\nIntroduce la media de consumo (kWh/100km): ");
	scanf("%f", &consumo);
	
	coste = (consumo * precio);
	
	printf("\n\nRESULTADO: Recorrer 100km tiene un coste de %.2f\n\n", coste);
	
}

void costeDeCarga(){
	
	float capacidad, precio, coste;
	
	printf("Introduce capacidad de la batería: ");
	scanf("%f", &capacidad);
	
	printf("\n\nIntroduce precio del kWh: ");
	scanf("%f", &precio);
	
	coste = (capacidad * precio);
	
	printf("\n\nRESULTADO: EL precio de una carga completa es de %.2f\n\n", coste);
	
}

void cargaEnTrifasica(){
	
	float capacidad, voltaje, intensidad, tiempo;
	
	printf("Introduce capacidad de la batería en kWh: ");
	scanf("%f", &capacidad);
	
	printf("\nIntroduce voltaje de entrada: ");
	scanf("%f", &voltaje);
	
	printf("\nIntroduce intensidad de entrada: ");
	scanf("%f", &intensidad);
	
	tiempo = capacidad / ((voltaje * intensidad * sqrt(3)) / 1000);
	
	printf("\n\nRESULTADO: El coche tarda en cargar %.2f horas\n\n", tiempo);
	
}

void cargaEnDC(){
	
	float capacidad, voltaje, intensidad, tiempo;
	
	printf("Introduce capacidad de la batería en kWh: ");
	scanf("%f", &capacidad);
	
	printf("\nIntroduce voltaje de entrada: ");
	scanf("%f", &voltaje);
	
	printf("\nIntroduce intensidad de entrada: ");
	scanf("%f", &intensidad);
	
	tiempo = capacidad / ((voltaje * intensidad) / 1000);
	
	printf("\n\nRESULTADO: El coche tarda en cargar %.2f horas\n\n", tiempo);
	
}
