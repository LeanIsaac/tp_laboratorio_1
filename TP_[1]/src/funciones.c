/*
 * funciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: equipo
 */
#include <stdio.h>
#include <stdlib.h>


void validar2(int a ,int b){
	if(a == 0 || b == 0){
			printf("ERROR NO HAY DATOS CARGADOS\n");
		}
}

void validar(int a){
	if(a == 0){
		printf("ERROR NO HAY DATOS CARGADOS\n");
	}
}

float ingreseKms(){
	float kms;
		printf("Ingresar kilómetros: ");
		scanf("%f", &kms);
	return kms;
}
