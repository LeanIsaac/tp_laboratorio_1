/*
 * funciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: equipo
 */
#include <stdio.h>
#include <stdlib.h>

/******************************************************/

float ingreseKms(){
	float kms;
		printf("Ingresar kilómetros: ");
		scanf("%f", &kms);
		while(kms < 0){
			printf("Error, Vuelva a ingresar :");
			scanf("%f", &kms);
		}
	return kms;
}

/******************************************************/

float caseDosAA(){
	float precioAerolineas;

	printf("Precio Aerolíneas:");
	scanf("%f", &precioAerolineas);
	while(precioAerolineas < 0){
				printf("Error, Vuelva a ingresar :");
				scanf("%f", &precioAerolineas);
			}

	return precioAerolineas;
}

/******************************************************/

float caseDosLatam(){

	float precioLatam;

	printf("Precio Latam:");
	scanf("%f", &precioLatam);
	while(precioLatam < 0){
					printf("Error, Vuelva a ingresar :");
					scanf("%f", &precioLatam);
				}

	return  precioLatam;
}

/******************************************************/

float calcularCostos (float costo, float porcentaje){
	float total;

	total=(costo+(costo*porcentaje)); //ej. 1200 + 1200 x -0,1 da 1080

	return total;
}

/******************************************************/

float bitcoin(float costo){
	float total;
	float btc = 4606954.55;

	total = costo/btc;

	return total;
}

/******************************************************/

float precioUnitario ( float precio, float kms){
	float total;

	total = precio/kms;

	return total;
}

/******************************************************/

float diferencia (float precio1, float precio2){
	float total;

	if(precio1 > precio2){

		total = precio1 - precio2;
	}
	else{
		if(precio2 > precio1){
			total = precio2 - precio1;
		}
		else{
			total = 0;
		}
	}

	return total;
}

/*******************************************************************************/

void casoTreImprimir (void){
	printf("Calculando...\n");
	printf("a) Tarjeta de débito (descuento 10%%)\n");
	printf("b) Tarjeta de crédito (interés 25%%)\n");
	printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("d) Mostrar precio por km (precio unitario)\n");
	printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n\n");
	printf("Presione [4] para mostrar resultados.\n");
}

/******************************************************************************/

