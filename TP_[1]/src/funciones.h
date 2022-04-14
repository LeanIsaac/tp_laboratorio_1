/*
 * funciones.h
 *
 *  Created on: 10 abr. 2022
 *      Author: equipo
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

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


/**
 * @brief esta funcion es para converit el costo del vuelo a bitcoin
 *
 * @param se ingresa la variable (cargada)
 * @return retorna el valor en bitcoin
 */
float bitcoin(float);


/**
 * @brief esta funcion divide el precio por los kilometros ingresados, para sacar el precio unitario.
 *
 * @param precio , ingresamos el precio
 * @param kms , ingresamos los kilometros
 * @return retorna el resultado
 */
float precioUnitario ( float precio, float kms);


/**
 * @brief esta funcion es para sacar la diferencia entre dos parametros (el resto)
 *
 * @param precio1 ingreso el primer precio
 * @param precio2 ingreso el segundo precio
 * @return retorna el resultado de la operacion
 */
float diferencia (float precio1, float precio2);

/**
 * @brief imprime lo que que tipo de calculos va hacer la siguiente opcion;
 *
 */
void casoTreImprimir (void);

#endif /* FUNCIONES_H_ */

