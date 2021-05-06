/*
 * compras.h
 *
 *  Created on: 29 abr. 2021
 *      Author: Pato
 */

#ifndef VENTAS_H_
#define VENTAS_H_
#include "clientes.h"
typedef struct{
	int cantidadBarbijos;
	char direccion[64];
	char color[32];
	float precio;
	int estado;
	int isEmpty;
	int idVenta;
	int idCliente;
}Venta;
int ven_inizializarArray(Venta *arrayVentas, int longitud);
int ven_isEmptyArray(Venta* arrayVentas, int limite);
int ven_imprimir(Venta *arrayVentas);
int ven_imprimirArray(Venta *arrayVentas, int longitud);
int ven_buscarId(Venta* arrayVentas, int limite, int valorBuscado);
int ven_altaArray(Venta *arrayVentas,Cliente *arrayClientes, int longitudPantallas, int *idCliente, int *idVenta);
int cont_bajaArray(Venta *pContrataciones, int indice);
int ven_pedirDatos(Venta *arrayVentas,Cliente *arrayClientes, int indice, int *idVenta, int *idCliente);
int ven_findClient(Venta *arrayVentas,Cliente *arrayClientes, int *idVenta);
int ven_pagarImporte(Venta *arrayVentas,Cliente *arrayClientes, int *idVenta);
int ven_cancelarCompra(Venta *arrayVentas,Cliente *arrayClientes, int *idVenta);

#endif /* VENTAS_H_ */
