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
/*
int alta(passenger lista[], int len, int *id){
	int indice;
	int retorno = -1;

	if(lista != NULL && len > 0){
		indice = buscarEspacioLibre(lista, len);
		if(indice != -1){
			lista[indice] = cargaPasajeros(lista, len, &id);
			lista[indice].id = id;
			retorno = 0;
		}
	}
	return retorno;
}*/

void cargaPasajeros(passenger lista[], int tam, int *id){
	char string[51];
	char name[51];
	char lastName[51];
	float price=0;
	int typePassenger=0;
	int codigo, i, codigoAux;
	char flyCodigo[10];

	codigo = *id;

	getString(string, "\nIngrese el nombre del pasajero --> ", 51);
	strcpy(name, string);
	printf("\nEl Nombre ingresado es: [ %s ]\n",name);
	getString(string, "\nIngrese el Apellido del pasajero --> ", 51);
	strcpy(lastName, string);
	printf("\nEl Apellido ingresado es: [ %s ]\n",lastName);
	price = get_Float("\nIngrese el precio del vuelo --> ", "Vuelava ingresar el precio: ", 0, 999999);
	printf("\nEl Precio ingresado es: [ %.2f $]\n",price);
	printf("\nTIPO DE PASAJERO\nID\tCLASE");
	mostrarTipoPasajero(TypePassenger, 3);
	typePassenger = get_Int("\n\nIngrese el tipo de clase --> ", "Vuela a ingresar la clase de vuelo: ", 3, 1);
	printf("\nEl Tipo de Pasajero ingresado es: [ %d ]\n",typePassenger);
	printf("\nCODIGOS DE VUELOS");
	mostrarCodigoVuelo(flyCode, 3);
	codigoAux = get_Int("\nIngrese el ID de su codigo de Vuelo --> ", "Vuelva a intentarlo: ", 3, 1);

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



///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
void mostrarTipoPasajero(eTypePassenger list[], int tam){
	int j;
	for(j=0;j<tam;j++){
		printf("\n[ %d ] - [ %s ]",list[j].typePassenger ,list[j].descrpicion);
	}
}
///////////////////////////////////////////////////////////////////////////////////////
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
	char nombre[51];
	char apellido[51];
	int codigoAux;
	//char flyCodigo[10];


	printPassenger(lista, tam);

	auxCodigo =get_Int("\nCodigo a Modificar: ", "Vuelva a ingresar el codigo: ", 1000000, 1);

	for( i=0; i<tam; i++ ){
		if( auxCodigo == lista[i].id && lista[i].isEmpty == OCUPADO ){
			mostrarUnPasajero(lista[i]);
		}
	}

	do{
		opcionModificar = menu("\n\nMODIFICAR \n1. NOMBRE\n2. APELLIDO \n3. PRECIO\n4. TIPO PASAJERO\n5. CODIGO VUELO \n6. SALIR\n");

			switch(opcionModificar){

				case 1:
					getString(nombre, "\n\nIngrese Nombre a modificar: ", 51);
					strcpy(lista[i].name, nombre);
					break;
				case 2:
					getString(apellido, "\n\nIngrese Apellido a modificar: ", 51);
					strcpy(lista[i].name, apellido);
					break;
				case 3:
					lista[i].price = get_Float("\n\nIngrese precio a Modificar: ", "Error, ingrese precio; ", 0, 9999999);
					break;
				case 4:
					mostrarTipoPasajero(TypePassenger, 3);
					lista[i].typePassenger = getInt("\n\nIngrese Tipo de Pasajero a Modificar: ");
					break;
				case 5:
					mostrarCodigoVuelo(flyCode, 3);
					codigoAux = getInt("\n\nIngrese el Id del codo de vuelo a modificar: ");
					for(i=0;i<3;i++){
							if(flyCode[i].idFlyCode ==  codigoAux){
								codigoAux = i;
							}
						}
						strcpy(lista[i].flyCode, flyCode[codigoAux].flyCode);
					break;
				case 6:
					printf("\n\nSaliendo...\n\n");
					break;
			}

	}while(opcionModificar != 6);
}

///////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////

//imprime pasajeros en forma encolumnada
int printPassenger(passenger* list, int length){
	int i;
	int rto=-1;

	if(list != NULL && length > 0){
		rto=0;
		for(i=0;i<length;i++){
			if(list[i].isEmpty == OCUPADO){
				printf("\nID DEL PASAJERO\t\t|| ID %d \n",list[i].id);
				printf("NOMBRE:\t\t\t|| %s \n",list[i].name);
				printf("APELLIDO:\t\t|| %s \n",list[i].lastName);
				printf("PRECIO DEL VUELO:\t|| %.2f$ \n",list[i].price);
				printf("TIPO DE PASAJERO:\t|| %d \n",list[i].typePassenger);
				printf("CODIGO DEL VUELO:\t|| %s \n\n",list[i].flyCode);
			}
		}
	}

	return rto;
}

///////////////////////////////////////////////////////////////////////////////////////

void mostrarUnPasajero(passenger lista){
	printf("ID DEL PASAJERO\t|| ID %d \n",lista.id);
	printf("NOMBRE:\t\t|| %s \n",lista.name);
	printf("APELLIDO:\t\t|| %s \n",lista.lastName);
	printf("PRECIO DEL VUELO:\t|| %.2f$ \n",lista.price);
	printf("TIPO DE PASAJERO:\t|| %d \n",lista.typePassenger);
	printf("CODIGO DEL VUELO:\t|| %s \n\n",lista.flyCode);
}

///////////////////////////////////////////////////////////////////////////////////////
