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
				printf("Ingresar kilómetros: ");
				scanf("%f", &kms);
				opciones = menu();
				break;

			case 2: //Ingresar Precio de Vuelos
				validar(kms); 						//valida un solo parametro
				printf("Precio Aerolíneas:");
				scanf("%f", &precioAerolineas);
				printf("Precio Latam:");
				scanf("%f", &precioLatam);
				opciones = menu();

				break;

			case 3: //Calcular todos los costos
				validar2(precioAerolineas, precioLatam);
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




