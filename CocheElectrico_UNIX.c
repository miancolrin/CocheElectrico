/*############################
#    EL VEHÍCULO ELÉCTRICO   #
#       ES EL FUTURO         #
##############################
A falta de herramientas para hacer cuentas sobre coches eléctricos he creado este pequeño programa.
Con este programa se pueden hacer cálculos básicos sobre el vehículo eléctrico, como el coste de
una recarga, el coste de recorrer 100km y el tiempo que va a tardar en cargarse por completo.
Cuaquier mejora o sugerencia acerca de este programa es bien recibida.
Usad el código para lo que queráis.
Cereado por @miancolrin
P.D.: Gracias Saúl López por inspirarme a hacer este programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){
	
	setlocale(LC_CTYPE, "Spanish"); //Mostrar caraceres españoles
	
	int bucle=1;
	char tecla;
	
	int opcion;
	float cap, intensidad, tiempo, volt, precio, coste, mediaconsumo, coste100;
	float porcentrestante, kwhrestantes, kmrestantes, kwhporkilometro, porcentconsum;
	
	do{
		
		system("clear");
		
		printf("Para calcular el tiempo que tarda en cargar el coche selecciona\n");
		printf("el tipo de corriente al que lo enchufas de la siguiente lista");
		printf("\n\n========================= MENU =========================");
		printf("\n1. Corriente Continua o Corriente Alterna Monofásica\n2. Corriente Alterna Trifásica");
		printf("\n3. Calcular el precio de una carga completa del coche");
		printf("\n4. Calcular el coste de recorrer 100km");
		printf("\n5. Calcular cuántos kilómetros restantes quedan");
		printf("\n0. SALIR\n\n");
		
		printf("Opción: ");
		scanf("%d", &opcion);
		
		switch(opcion){
				
			case 1:{
				printf("\n\nHas seleccionado Corriente Continua o Corriente Alterna Monofásica");
				
				printf("\n\nIntroduce capacidad de la batería en kWh: ");
				scanf("%f", &cap);
				
				printf("\nIntroduce voltaje de entrada en V: ");
				scanf("%f", &volt);
				
				printf("\nIntroduce intensidad de entrada en A: ");
				scanf("%f", &intensidad);
				
				
				tiempo = cap / ( (volt * intensidad) / 1000); //En monofásica P=V*A
				
				printf("\n\nRESULTADO: El coche tarda %.2f horas en cargar completamente\n\n\n", tiempo);
				
				system( "read -n 1 -s -p \"Presione una tecla para continuar...\"" );
				
				break;
			}
			case 2:{
				printf("\n\nHas seleccionado Corriente Alterna Trifásica");
				
				printf("\n\nIntrduce capacidad de la batería en kWh: ");
				scanf("%f", &cap);
				
				printf("\nIntroduce voltaje de entrada en V: ");
				scanf("%f", &volt);
				
				printf("\nIntroduce la intensidad de entrada en A: ");
				scanf("%f", &intensidad);
				
				tiempo = cap / ( (volt * intensidad * (sqrt(3))) / 1000); //En trifásica P=V*A*sqrt3
				
				printf("\n\nRESULTADO: El coche tarda %.2f horas en cargar completamente\n\n\n", tiempo);
				
				system( "read -n 1 -s -p \"Presione una tecla para continuar...\"" );
				
				break;
			}
			case 3:{
				printf("\n\nHas seleccionado calcular el coste de una carga completa");
				
				printf("\n\nIntroduce la capacidad de la batería en kWh: ");
				scanf("%f", &cap);
				
				printf("\nIntroduce el precio del kilovatio hora (kWh): ");
				scanf("%f", &precio);
				
				coste = (cap * precio);
				
				printf("\n\nRESULTADO: Una carga completa del coche tiene un coste de %.2f\n\n\n", coste);
				
				system( "read -n 1 -s -p \"Presione una tecla para continuar...\"" );
				
				break;
			}
			case 4:{
				printf("\n\nHas seleccionado calcular el coste a los 100km");
				
				printf("\n\nIntroduce la media de consumo (kWh/100km, nos lo suele proporcionar el coche): ");
				scanf("%f", &mediaconsumo);
				
				printf("\nIntroduce el precio del kilovatio hora (kWh): ");
				scanf("%f", &precio);
				
				coste100 = (mediaconsumo * precio);
				
				printf("\n\nEl coste de recorrer 100km es de %f\n\n\n", coste100);
				
				system( "read -n 1 -s -p \"Presione una tecla para continuar...\"" );
				
				break;
			}
			case 5:{
				printf("\n\nHas seleccionado la opción de ver cuántos kilometros restantes quedan");
				
				printf("\n\nIntroduce la capacidad de la batería en kWh: ");
				scanf("%f", &cap);
				
				printf("\nIntroduce la media de consumo (kWh/100km, nos lo suele proporcionar el coche): ");
				scanf("%f", &mediaconsumo);
				
				printf("\nIntroduce el porcentaje de batería restante: ");
				scanf("%f", &porcentrestante);
				
				porcentconsum = 100 - porcentrestante;
				
				kwhrestantes = (cap - ((porcentconsum * cap) / 100));
				
				kwhporkilometro = mediaconsumo / 100;
				
				kmrestantes = (kwhrestantes / kwhporkilometro);
				
				printf("\n\nSegún el consumo actual, con un %.0f porciento de batería puedes recorrer %.2f kilómetros\n\n\n", porcentrestante, kmrestantes);
				
				system( "read -n 1 -s -p \"Presione una tecla para continuar...\"" );
				
				break;
			}
				
		} //Cierra el Switch
		
	} while (opcion != 0); //Cierra el Do-While
	
	return 0;
	
} //Cierra el Main
