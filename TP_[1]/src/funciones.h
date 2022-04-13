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
 * @brief esta funcion imprime un mensaje y pide el ingreso de un un dato (flotante).
 *
 * @return devuelva el dato (flotante)
 */
float caseDosLatam();

/**
 * @brief esta funcion realiza descuento y aumento
 *
 * @param costo seremplaza por el precio de la aerolineas
 * @param porcentaje ingresamos cuanto el porcentaje de descuento o aumento
 * @return devuelve el resultado de la operación
 */
float calcularCostos (float costo, float porcentaje);

#endif /* FUNCIONES_H_ */

