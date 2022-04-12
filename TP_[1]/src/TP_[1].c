/*
 ================================
  Name      : TP_[1].c
  Author    : MARECOS LEANDRO
 ================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funciones.h"



int main(){
	setbuf(stdout,NULL);

	float kms;
	float precioAerolineas;
	float precioLatam;
	int opciones;

	do{
		opciones = menu();
		switch(opciones){

			case 1: //Ingreso los kilómetros
				kms = ingreseKms();
				opciones = menu();
				break;

			case 2: //Ingresar Precio de Vuelos
				validar(kms); 		//valida un solo parametro
				/*
				printf("Precio Aerolíneas:");
				scanf("%f", &precioAerolineas);
				printf("Precio Latam:");
				scanf("%f", &precioLatam);
				*/

				opciones = menu();

				break;

			case 3: //Calcular todos los costos
				validar2(precioAerolineas, precioLatam);

				printf("a) Tarjeta de debito (descuento 10%) \n");
				printf("b) Tarjeta de credito (interes 25%) \n");
				printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
				printf("d) Mostrar precio por km (precio unitario)\n");
				printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
				opciones = menu();
				break;

			case 4: //Informar Resultados
				//opciones = menu();
				break;

			case 5: //Carga forzada de datos
				printf("5");
			//	opciones = menu();
				break;

			case 6: //Salir del menú
				printf("!!ADIOS¡¡");
				break;
		}
	}while(opciones != 6);

	return 0;
}




