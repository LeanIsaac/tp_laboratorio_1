/*
 * UTN.h
 *
 *  Created on: 28 abr. 2022
 *      Author: equipo
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * @brief Funcion menu
 *
 * @param opciones ingresamos las opciones de nuentro menu
 * @return retorna un entero, de la opcion elejida
 */
int menu( char opciones[]  );


/**
 * @brief nos permite el ingreso de un entero y lo valida
 *
 * @param mensaje ingresar el mensaje a imprimir en consola
 * @param msjError ingresar el mensaje de error
 * @param maximo de un numero a ingresar
 * @param minimo numero a ingresar
 * @return devuelve un entero
 */
int get_Int(char mensaje[],char msjError[],int maximo, int minimo);


/**
 * @brief permite el ingreso de un flotante
 *
 * @param mensaje ingresar el mensaje para el ingreso del entero
 * @param msjError ingresar el mensaje de error a imprimir
 * @param Minimo de un numero para la validacion
 * @param Maximo de un numero para la validacion
 * @return retorna el flotante
 */
float get_Float(char mensaje[], char msjError[], int Minimo, int Maximo);

/**
 * @brief
 *
 * @param palabra
 * @param mensaje
 * @param tamanio
 */
void getString(char palabra[],char mensaje[],int tamanio);

/**
 * @brief
 *
 * @param mensaje
 * @return
 */
int getInt(char mensaje[]);

/**
 * @brief
 *
 * @param auxiliar
 * @return
 */
int esNumerica(char auxiliar[]);


#endif /* UTN_H_ */
