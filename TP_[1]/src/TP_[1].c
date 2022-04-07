/*
 ============================================================================
 Name        : TP_[1].c
 Author      : MARECOS LEANDRO
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"

//prototipo
int menu();


int main(){
	setbuf(stdout,NULL);

	float kms;
	int opciones;

	opciones = menu();

	switch(opciones){

		case 1: //Ingreso los kilómetros
			printf("Ingresar los kilómetros de vuelo: ");
			scanf("%f", &kms);
			opciones = menu();

			break;


		case 2: //Ingresar Precio de Vuelos
			printf("Ingresar Precio de Vuelos:");
			break;


		case 3: //Calcular todos los costos
			printf("3");
			break;


		case 4: //Informar Resultados
			printf("4");
			break;


		case 5: //Carga forzada de datos
			printf("5");
			break;


		case 6: //Salir del menú
			printf("6");
			break;
	}

	return 0;
}




