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

int menu(){

	int opciones;

		do{
			printf("\tOpciones \n");
			printf("\n");
			printf("1. Ingresar Kilómetros\n");
			printf("2. Ingresar Precios de Vuelos\n");
			printf("3. Calcular Costos\n");
			printf("4. Informar Resultados\n");
			printf("5. Carga Forzada de Datos\n");
			printf("6. Salir\n");

			printf("Ingrese una opción: ");
			scanf("%d", &opciones);
			printf("\n");

			if(opciones >6 || opciones <1){
				printf("Error, Vuelva a ingresar otra opción");
			}

		}while(opciones>6 || opciones<1);

	return opciones;
}


