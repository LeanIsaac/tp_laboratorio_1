/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Marecos Leandro
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#include "ArrayPassenger.h"

#define CANT 3

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int id=100;

	passenger passenger[CANT];

	initPassengers(passenger, CANT);

	do{
		opcion = menu("\nAEROLINEAS ARGENTINAS\n1. ALTA\n2. MODIFICAR \n3. BAJA\n4. INFORMAR\n5. CARGA FORZADA\n8. SALIR\n ");
		switch(opcion){
			//ALTA
			case 1:
				cargaPasajeros(passenger, CANT, &id);
				//alta(passenger, CANT, &id);
				//id++;
				break;
			//MODIFICAR
			case 2:

				break;
			//BAJA
			case 3:

				break;
			//INFORMAR
			case 4:
				listar(passenger, CANT);
				break;
			//HARCODEO
			case 5:

				break;
		}

	}while(opcion != 8);


	return 0;
}
