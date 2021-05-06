/*
 * clientes.h
 *
 *  Created on: 29 abr. 2021
 *      Author: Pato
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct
{
	char nombre[50];
	char apellido[50];
	char cuit[20];
	int idCliente;
	int isEmpty;
	int importesPagos;
	int importesPendientes;
}Cliente;

int cli_imprimir(Cliente *arrayCliente);
int cli_imprimirArray(Cliente *arrayCliente, int longitud);
int cli_buscarId(Cliente* arrayCliente, int limite, int valorBuscado);
int cli_isEmptyArray(Cliente* arrayCliente, int limite);
int cli_inizializarArray(Cliente *arrayCliente, int longitud);
int cli_altaArray(Cliente *arrayClientes,int limite, int *idCliente);
int cli_bajaArray(Cliente *arrayClientes, int *id);
int cli_pedirDatos(Cliente *arrayClientes, int indice, int *idCliente);
int cli_modificar(Cliente *arrayClientes, int indice);
int cli_modificarArray(Cliente *arrayClientes, int *id);


#endif /* CLIENTES_H_ */
