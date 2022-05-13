/*
 * ArrayPassenger.h
 *
 *  Created on: 28 abr. 2022
 *      Author: equipo
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define MAX_CHAR 51

typedef struct{
	int id;
	char name[MAX_CHAR];
	char lastName[MAX_CHAR];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}passenger;

typedef struct{
	int typePassenger;
	char descrpicion[MAX_CHAR];
}eTypePassenger;

typedef struct{
	int idFlyCode;
	char flyCode[10];
}eFlyCode;

typedef struct{
	int statusFlight;
	char descripcion[MAX_CHAR];
}eStatusFlight;

/** @brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* @param list Passenger* Pointer to array of passenger
* @param len int Array length
* @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(passenger* list,int len);



/**
 * @brief add in a existing list of passengers the values received as parameters
 * 		  in the first empty position
 *
 * @param list passenger*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param price float
 * @param typePassenger int
 * @param flycode[] char
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without
 *		   free space] - (0) if Ok
 */
int  addPassenger(passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[]);


/**
 * @brief find a Passenger by Id en returns the index position in array.
 *
 * @param list Passenger*
 * @param len int
 * @param id int
 * @return
 */
int findPassengerById(passenger* list, int len,int id);

/**
 * @brief Remove a Passenger by Id (put isEmpty Flag in 1)
 *
 * @param list Passenger*
 * @param len int
 * @param id int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 *  find a passenger] - (0) if Ok
 */
int removePassenger(passenger* list, int len, int id);


/**
 * @brief Sort the elements in the array of passengers, the argument order
 *        indicate UP or DOWN order
 *
 * @param list Passenger*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengers(passenger* list, int len, int order);

/**
 * @brief print the content of passengers array
 *
 * @param list Passenger*
 * @param length int
 * @return int
 */
int printPassenger(passenger* list, int length);

/**
 * @brief  Sort the elements in the array of passengers, the argument order
 *         indicate UP or DOWN order
 *
 * @param list Passenger*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengersByCode(passenger* list, int len, int order);


void cargaPasajeros(passenger lista[], int tam, int *id);

void mostrarTipoPasajero(eTypePassenger list[], int tam);


void mostrarCodigoVuelo(eFlyCode list[], int tam);

void listar(passenger lista[], int tam);

int alta(passenger lista[], int len, int *id);

#endif /* ARRAYPASSENGER_H_ */
