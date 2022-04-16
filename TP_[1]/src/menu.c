/*
 * menu.c
 *
 *  Created on: 6 abr. 2022
 *      Author: equipo
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int menu(){
	int opciones;

		do{
			printf("\n════>> OPCIONES <<════\n");
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
