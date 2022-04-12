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

	float kms = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	int opciones;

	/*float debitoAA, creditoAA, btcAA, precioUni;
	float debitoL, creditoL, btcL, precioUni;*/

	do{
		opciones = menu();
		switch(opciones){

			case 1: //Ingreso los kilómetros
				kms = ingreseKms();
				opciones = menu();
				break;

			case 2: //Ingresar Precio de Vuelos
				if(kms == 0){
					printf("ERROR NO HAY DATOS CARGADOS\n");
				}
				else{
					precioAerolineas = caseDosAA();
					precioLatam = caseDosLatam();
				}
				opciones = menu();

				break;

			case 3: //Calcular todos los costos
				validar2(precioAerolineas, precioLatam);
				printf("Calculando...\n[Presione 4, para mostrar resultados]\n");
				opciones = menu();
				break;

			case 4: //Informar Resultados
				//opciones = menu();
				break;

			case 5: //Carga forzada de datos
				printf("CARGA FORZADA");

				opciones = menu();
				break;

			case 6: //Salir del menú
				printf("MUCHAS GRACIAS");
				break;
		}
	}while(opciones != 6);

	return 0;
}






