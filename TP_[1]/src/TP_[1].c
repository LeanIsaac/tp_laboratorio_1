/*
 ================================
  Name      : TP_[1].c
  Author    : MARECOS LEANDRO
 ================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funciones.h"



int main(){
	setbuf(stdout,NULL);

	int opciones;
	float kms = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;

	float debitoAA;
	float creditoAA;
	float debitoLatam;
	float creditoLatam;
	float btcAA;
	float btcLatam;
	float PrecioUniAA;
	float precioUniLat;
	float diferenciaPrecio;

	float aerolineasArgentinas;
	float km;
	float latam;

	do{
		opciones = menu();
		switch(opciones){

			case 1: //Ingreso los kilómetros
				kms = ingreseKms();
				opciones = menu();
				break;

			case 2: //Ingresar Precio de Vuelos
				if(kms == 0){
					printf("ERROR NO HAY DATOS CARGADOS\n");
				}
				else{
					precioAerolineas = caseDosAA();
					precioLatam = caseDosLatam();
				}
				opciones = menu();
				break;

			case 3: //Calcular todos los costos

				if(precioAerolineas > 0 && precioLatam > 0){
					casoTreImprimir();
					debitoAA =  calcularCostos(precioAerolineas, -0.1);
					creditoAA = calcularCostos(precioAerolineas, 0.25);
					btcAA = bitcoin(precioAerolineas);
					PrecioUniAA  = precioUnitario(precioAerolineas, kms);

					debitoLatam = calcularCostos(precioLatam, -0.1);
					creditoLatam = calcularCostos(precioLatam, 0.25);
					btcLatam = bitcoin(precioLatam);
					precioUniLat = precioUnitario(precioLatam, kms);

					diferenciaPrecio = diferencia(precioAerolineas, precioLatam);
				}
				else{
					printf("ERROR NO HAY DATOS CARGADOS\n");
				}
				opciones = menu();
				break;

			case 4: //Informar Resultados
				if(kms > 0 && precioAerolineas > 0 && precioLatam > 0){
					printf("══> AEROLINEAS <══\n");
					printf("a) Precio con tarjeta de débito: %.2f\n",debitoAA);
					printf("b) Precio con tarjeta de crédito: %.2f\n",creditoAA);
					printf("c) Precio pagando con bitcoin : %f BTC\n",btcAA);
					printf("d) Mostrar precio unitario %f\n",PrecioUniAA);

					printf("\n══> LATAM <══\n");
					printf("a) Precio con tarjeta de débito: %.2f\n",debitoLatam);
					printf("b) Precio con tarjeta de crédito: %.2f\n",creditoLatam);
					printf("c) Precio pagando con bitcoin : %f BTC\n",btcLatam);
					printf("d) Mostrar precio unitario %f\n",precioUniLat);
					printf("\nLa diferencia de precio es: %.2f", diferenciaPrecio);
				}
				else{
					printf("ERROR NO HAY DATOS CARGADOS\n");
				}
				opciones = menu();
				break;

			case 5: //Carga forzada de datos
				km = 7090;
				aerolineasArgentinas = 162965;
				latam = 159339;

				debitoAA =  calcularCostos(aerolineasArgentinas, -0.1);
				creditoAA = calcularCostos(aerolineasArgentinas, 0.25);
				btcAA = bitcoin(aerolineasArgentinas);
				PrecioUniAA  = precioUnitario(aerolineasArgentinas, km);

				debitoLatam = calcularCostos(latam, -0.1);
				creditoLatam = calcularCostos(latam, 0.25);
				btcLatam = bitcoin(latam);
				precioUniLat = precioUnitario(latam, km);

				diferenciaPrecio = diferencia(aerolineasArgentinas, latam);
				printf("══════> CARGA FORZADA <══════\n");
				printf("Kilometros ingresados: %.2f km\n\n",km);
				printf("Precio Aerolineas: %.2f\n",aerolineasArgentinas);
				printf("a) Precio con tarjeta de débito: %.2f\n",debitoAA);
				printf("b) Precio con tarjeta de crédito: %.2f\n",creditoAA);
				printf("c) Precio pagando con bitcoin : %f BTC\n",btcAA);
				printf("d) Mostrar precio unitario %f\n\n",PrecioUniAA);

				printf("Precio Latam: %.2f\n",latam);
				printf("a) Precio con tarjeta de débito: %.2f\n",debitoLatam);
				printf("b) Precio con tarjeta de crédito: %.2f\n",creditoLatam);
				printf("c) Precio pagando con bitcoin : %f BTC\n",btcLatam);
				printf("d) Mostrar precio unitario %f\n",precioUniLat);
				printf("\nLa diferencia de precio es: %.2f", diferenciaPrecio);

				opciones = menu();
				break;

			case 6: //Salir del menú
				printf("MUCHAS GRACIAS!!");
				break;
		}
	}while(opciones != 6);

	return 0;
}

