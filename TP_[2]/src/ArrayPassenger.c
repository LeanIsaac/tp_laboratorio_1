/*
 * ArrayPassenger.c
 *
 *  Created on: 28 abr. 2022
 *      Author: equipo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#include "ArrayPassenger.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


eStatusFlight StatusFlight[] = {{1, "ACTIVO"},{2, "DEMORADO"}, {3, "CANSELADO"}};

eFlyCode flyCode[] = {{1, "ABC104"},{2, "ADF909"},{3, "M231"}};

eTypePassenger TypePassenger[] = {{1, "TURISTA"},{2, "EJECUTIVO"}, {3, "PRIMERA CLASE"}};

///////////////////////////////////////////////////////////////

int initPassengers(passenger* list,int len){
	int i;
	int retorno = -1;
	if(list != NULL && len > 0){
		retorno = 0;
		for( i=0; i<len; i++ ){
			list[i].isEmpty = LIBRE;
		}
	}
		return retorno;
}


///////////////////////////////////////////////////////////////

int buscarEspacioLibre(passenger* list, int len){
	int i;
	int index = -1;

	for(i=0;i<len;i++){
		if(list[i].isEmpty == LIBRE){
			index = i;
			break;
		}
	}
	return index;
}

///////////////////////////////////////////////////////////////

int addPassenger(passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[]){
	int i;
	int rto=-1;
		if(list != NULL){
			for(i=0;i<len;i++){
				if(list[i].isEmpty==LIBRE){
					list[i].id = id;
					strcpy(list[i].name,name);
					strcpy(list[i].lastName,lastName);
					list[i].price = price;
					list[i].typePassenger = typePassenger;
					strcpy(list[i].flyCode,flyCode);
					list[i].isEmpty = OCUPADO;
					rto = 0;
				}
			}
		}
	return rto;
}



//////////////////////////////////////////////////////////////////

void cargaPasajeros(passenger lista[], int tam, int *id){
	char string[51];
	char name[51];
	char lastName[51];
	float price=0;
	int typePassenger=0;
	int codigo, i, codigoAux;
	char flyCodigo[10];

	codigo = *id;

	getString(string, "\nIngrese el nombre del pasajero: ", 51);

	strcpy(name, string);

	printf("\nNombre ingresado: [ %s ]\n",name);

	getString(string, "\nIngrese el Apellido del pasajero: ", 51);

	strcpy(lastName, string);

	printf("\nApellido ingresado: [ %s ]\n",lastName);

	price = get_Float("\nIngrese el precio del vuelo: ", "Vuelava ingresar el precio: ", 0, 999999);

	printf("\nPrecio ingresado: [ %.2f $]\n",price);

	printf("\nTIPO DE PASAJERO\nID\tCLASE");
	mostrarTipoPasajero(TypePassenger, 3);

	typePassenger = get_Int("\n\nIngrese el tipo de clase: ", "Vuela a ingresar la clase de vuelo: ", 3, 1);

	printf("\nTipo de pasajero ingresado: [ %d ]\n",typePassenger);

	printf("\nCODIGOS DE VUELOS");
	mostrarCodigoVuelo(flyCode, 3);

	codigoAux = get_Int("\nIngrese el ID de su codigo de Vuelo: ", "Vuelva a intentarlo: ", 3, 1);

	for(i=0;i<3;i++){
		if(flyCode[i].idFlyCode ==  codigoAux){
			codigoAux = i;
		}
	}

	strcpy(flyCodigo, flyCode[codigoAux].flyCode);

	addPassenger(lista, tam, codigo, name, lastName, price, typePassenger, flyCodigo);

	*id = *id +1;

}

///////////////////////////////////////////////////////////////////////////////////////

void mostrarTipoPasajero(eTypePassenger list[], int tam){
	int j;
	for(j=0;j<tam;j++){
		printf("\n[ %d ] - [ %s ]",list[j].typePassenger ,list[j].descrpicion);
	}
}

///////////////////////////////////////////////////////////////////////////////////////

void mostrarCodigoVuelo(eFlyCode list[], int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("\n[ %d ] - [ %s ]",list[i].idFlyCode ,list[i].flyCode);
	}
}

///////////////////////////////////////////////////////////////////////////////////////
void listar(passenger lista[], int tam){
	int i;

	for(i=0;i<tam;i++){
		if(lista[i].isEmpty == OCUPADO){
			printf("ID: [ %d ] ", lista[i].id);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////

void modificar(passenger lista[], int tam){
	int i;
	int opcionModificar;
	int auxCodigo;

	printPassenger(lista, tam);

	auxCodigo =get_Int("Codigo a Modificar: ", "Vuelva a ingresar el codigo: ", 1000000, 1);

	for( i=0; i<tam; i++ ){
		if( auxCodigo == lista[i].id && lista[i].isEmpty == OCUPADO ){
			mostrarUnPasajero(lista[i]);
		}
	}

	do{
		opcionModificar = menu("\nMODIFICAR \n1. NOMBRE\n2. APELLIDO \n3. PRECIO\n4. TIPO PASAJERO\n5. CODIGO VUELO \n6. SALIR\n");

			switch(opcionModificar){

				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
			}

	}while(opcionModificar != 6);
}

///////////////////////////////////////////////////////////////////////////////////////
/*
int removePassenger(passenger* list, int len, int id){
	int i, auxCodigo;
	char confirmar;
	int retorno =-1;

		printPassenger(list, len);

		auxCodigo = get_Int("Codigo a dar de baja: ", "Error, Codigo a dar de baja: ", 10000, 0);

		for( i=0; i<len; i++ ){
			if( auxCodigo == list[i].id && list[i].isEmpty == OCUPADO ){
				mostrarUnPasajero(list[i]);
				retorno=0;

				printf("Dar de baja? [S|N]: ");
				setbuf(stdin,NULL);
				scanf("%c", &confirmar);

				confirmar = toupper(confirmar);
				if( confirmar == 'S'){
					list[i].isEmpty = BAJA;
					printf("\nSe han borrado los datos...\n");
				}
				else{
					printf("\nNo se han borrado los datos...\n");
				}
				break;
			}
		}

		return retorno;
}
*/
///////////////////////////////////////////////////////////////////////////////////////

//imprime pasajeros en forma encolumnada
int printPassenger(passenger* list, int length){
	int i;
	int rto=-1;

	if(list != NULL && length > 0){
		rto=0;
		for(i=0;i<length;i++){
			if(list[i].isEmpty == OCUPADO){
				printf("ID del Pasajero \t|| ID %d \n",list[i].id);
				printf("Nombre: \t\t|| %s \n",list[i].name);
				printf("Apellido: \t\t|| %s \n",list[i].lastName);
				printf("Precio del viaje: \t|| $%.2f \n",list[i].price);
				printf("Tipo de pasajero: \t|| %d \n",list[i].typePassenger);
				printf("Codigo de vuelo: \t|| %s \n\n",list[i].flyCode);
			}
		}
	}

	return rto;
}

///////////////////////////////////////////////////////////////////////////////////////

void mostrarUnPasajero(passenger lista){
	printf("ID del Pasajero \t|| ID %d \n",lista.id);
	printf("Nombre: \t\t|| %s \n",lista.name);
	printf("Apellido: \t\t|| %s \n",lista.lastName);
	printf("Precio del viaje: \t|| $%.2f \n",lista.price);
	printf("Tipo de pasajero: \t|| %d \n",lista.typePassenger);
	printf("Codigo de vuelo: \t|| %s \n\n",lista.flyCode);
}

///////////////////////////////////////////////////////////////////////////////////////
