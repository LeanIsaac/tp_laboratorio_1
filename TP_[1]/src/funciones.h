/*
 * funciones.h
 *
 *  Created on: 10 abr. 2022
 *      Author: equipo
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * @brief esta funcion valida un parametro, en al caso de que no tengan valor imprime un mensaje informandolo.
 *
 * @param verifica si el parametro actual tiene algun valor
 */
void validar(int);



/**
 * @brief esta funcion valida dos parametros, en al caso de que no tengan valor imprime un mensaje informandolo.
 *
 * @param valida si tiene algun valor
 * @param valida si ese parametro tiene algun valor
 */
void validar2(int ,int);



/**
 * @brief pide que igresemos los kms, y lo retorna
 *
 * @return retorna los kolometros ingresador
 */
float ingreseKms();


/**
 * @brief imprime un mensaje mediante un printf, para duspues pedir el ingreso de un dato por medio de un scanf.
 *
 * @return retorna el dicho valor ingresado.
 */
float caseDosAA();


/**
 * @brief esta funcion imprime un mensaje y pide el ingreso de un flotante.
 *
 * @return devuelva el dato flotante
 */
float caseDosLatam();


#endif /* FUNCIONES_H_ */

