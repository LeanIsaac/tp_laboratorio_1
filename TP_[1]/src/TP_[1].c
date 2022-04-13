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

float bitcoin(float);

int main(){
	setbuf(stdout,NULL);

	float kms = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	int opciones;

	float debitoAA;
	float creditoAA;
	float debitoLatam;
	float creditoLatam;
	float btcAA;
	float btcLatam;

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
				printf("Calculando...\n");
				debitoAA =  calcularCostos(precioAerolineas, -0.1);
				creditoAA = calcularCostos(precioAerolineas, 0.25);
				btcAA = bitcoin(precioAerolineas);

				debitoLatam = calcularCostos(precioLatam, -0.1);
				creditoLatam = calcularCostos(precioLatam, 0.25);
				btcLatam = bitcoin(precioLatam);



				/*
				 * a) Tarjeta de débito (descuento 10%) x
				 * b) Tarjeta de crédito (interés 25%) x
				 * c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos) x
				 * d) Mostrar precio por km (precio unitario)
				 * e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
				 */
				opciones = menu();

				break;

			case 4: //Informar Resultados
				printf("══> AEROLINEAS <══\n");
				printf("a) Precio con tarjeta de débito: %.2f\n",debitoAA);
				printf("b) Precio con tarjeta de crédito: %.2f\n",creditoAA);
				printf("c) Precio pagando con bitcoin : %f BTC\n",btcAA);

				printf("\n══> LATAM <══\n");
				printf("a) Precio con tarjeta de débito: %.2f\n",debitoLatam);
				printf("b) Precio con tarjeta de crédito: %.2f\n",creditoLatam);
				printf("c) Precio pagando con bitcoin : %f BTC\n",btcLatam);
				opciones = menu();
				break;

			case 5: //Carga forzada de datos
				printf("CARGA FORZADA");

				opciones = menu();
				break;

			case 6: //Salir del menú
				printf("MUCHAS GRACIAS!!");
				break;
		}
	}while(opciones != 6);

	return 0;
}

float bitcoin(float costo){
	float total;
	float btc = 4606954.55;

	total = costo/btc;

	return total;
}




