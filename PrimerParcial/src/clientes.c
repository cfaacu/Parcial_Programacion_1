/*
 * clientes.c
 *
 *  Created on: 29 abr. 2021
 *      Author: Pato
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "clientes.h"
#include "utn2.h"
#define LLENO 1
#define VACIO 0
#define CLIENTES 100
#define VENTAS 1000

/**
 * \brief Imprime una contratacion.
 * \param array pContratacion Array de contrataciones a imprimir.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_imprimir(Cliente *arrayCliente)
{
	int retorno = -1;

	if(arrayCliente!=NULL)
	{
		retorno=0;
		printf("ID Contratacion: %d\n",arrayCliente->idCliente);
		printf("Nombre: %s\tApellido: %s\tCuit: %s\tImportes Pagos: %d\tImportes Pendientes: %d\n",arrayCliente->nombre,arrayCliente->apellido,arrayCliente->cuit,arrayCliente->importesPagos,arrayCliente->importesPendientes);
		printf("------------------------------------------\n");
	}

	return retorno;
}

/**
 * \brief Imprime un array de contrataciones
 * \param array pContratacion Array de contrataciones a imprimir.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_imprimirArray(Cliente *arrayCliente, int longitud)
{
	int retorno = -1;
	int verifyIsEmpty=0;
	if(arrayCliente!=NULL && longitud>0)
	{
		retorno=0;
		for(int i=0;i<longitud;i++)
		{
			if(arrayCliente[i].isEmpty==LLENO)
			{
				verifyIsEmpty=verifyIsEmpty+1;
				cli_imprimir(&arrayCliente[i]);
			}
		}
	}
	if(verifyIsEmpty==0)
		printf("No hay clientes cargados.\n");
	return retorno;
}


/**
 * \brief Busca un ID en un array y devuelve el indice en que se encuentra
 * \param array Array de ...
 * \param limite Limite del array de ...
 * \param valorBuscado ID a buscar
 * \return Retorna la posicion del array (EXITO) y -1 (ERROR)
 */
int cli_buscarId(Cliente* arrayCliente, int limite, int valorBuscado)
{
	int retorno = -1;

	if(arrayCliente != NULL && limite > 0 && valorBuscado >= 0)
	{
		retorno = 0;
		for(int i=0;i<limite;i++)
		{
			if(arrayCliente[i].idCliente == valorBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Busca una posicion vacia del array.
 * \param array pContratacion Array de contrataciones.
 * \param Limite tama�o del array a recorrer.
 * \return Retorna la posicion vacia (EXITO) y -1 (ERROR)
 */
int cli_isEmptyArray(Cliente* arrayCliente, int limite)
{
	int retorno=-1;

	if(arrayCliente!=NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(arrayCliente[i].isEmpty==VACIO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Inicializa un array de Contrataciones en VACIO(0).
 * \param array pContratacion Array de contrataciones.
 * \param Longitud tama�o del array a inicializar.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_inizializarArray(Cliente *arrayCliente, int longitud)
{
	int retorno = -1;
	if(arrayCliente!=NULL && longitud>0)
	{
		retorno=0;
		for(int i=0;i<longitud;i++)
		{
			arrayCliente[i].isEmpty=VACIO;
			arrayCliente[i].importesPagos=0;
			arrayCliente[i].importesPendientes=0;
		}
	}
	return retorno;
}
/**
 * \brief Funcion para dar de alta un array de pantallas.
 * \param pPantallas array de pantallas.
 * \param indice indice a ocupar
 * \param idPantalla id de pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_altaArray(Cliente *arrayClientes,int limite, int *idCliente)
{
	int retorno = -1;
	int indice;

	if(arrayClientes!=NULL && idCliente!=NULL && limite > 0)
	{
		indice = cli_isEmptyArray(arrayClientes, limite);
		if(indice>=0)
		{
			if(cli_pedirDatos(arrayClientes, indice, idCliente)==0)
			{
				retorno = 0;
				printf("ID Unico: [%d]\n",*idCliente-1);
			}
		}
	}
	return retorno;
}
/**
 * \brief Pide un ID para dar de baja
 * \param pPantallas Array de pantallas
 * \param indice Indice a dar de baja
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_bajaArray(Cliente *arrayClientes, int *id)
{
	int retorno = -1;
	int indice;
	if(arrayClientes!=NULL && arrayClientes->isEmpty==LLENO)
	{
		retorno = 0;
		utn_getNumero(&indice, "Ingrese ID a dar de baja.\n", "Error Bro.\n", 0, *id-1, 3);
		arrayClientes[indice].isEmpty=VACIO;
	}
	return retorno;
}
/**
 * \brief Modifica una contratacion
 * \param arrayPantallas Array de pantallas
 * \param auxIndice indice a modificar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_modificarArray(Cliente *arrayClientes, int *id)
{
	int retorno = -1;
	int auxId;
	int auxIndice;
	if(arrayClientes!=NULL && id!=NULL &&arrayClientes->isEmpty==LLENO)
	{
		cli_imprimirArray(arrayClientes, CLIENTES);
		if(utn_getNumero(&auxId, "Ingrese ID a modificar.\n", "[ERROR]ID Invalido", 0, *id-1, 3)==0)
		{
			auxIndice = cli_buscarId(arrayClientes, CLIENTES, auxId);
			if(auxIndice>=0)
			{
				retorno = cli_modificar(arrayClientes, auxIndice);
			}
		}
	}
	return retorno;
}

int cli_pedirDatos(Cliente *arrayClientes, int indice, int *idCliente)
{
	int retorno = -1;
	Cliente buffer_cliente;
	if(arrayClientes!= NULL && indice >= 0 && idCliente!=NULL)
	{
		if(utn_getName(buffer_cliente.nombre, sizeof(buffer_cliente.nombre), "Ingrese Nombre:\n", "[ERROR]Nombre Invalido.\n", 3)==0
		&& utn_getName(buffer_cliente.apellido, sizeof(buffer_cliente.apellido), "Ingrese Apellido:\n", "[ERROR]Apellido Invalido.\n", 3)==0
		&& utn_getCuit(buffer_cliente.cuit, sizeof(buffer_cliente.cuit), "Ingrese CUIT.\n", "[ERROR]CUIT Invalido", 3)==0)
		{
			retorno = 0;
			buffer_cliente.isEmpty=LLENO;
			buffer_cliente.idCliente=*idCliente;
			buffer_cliente.importesPagos=0;
			buffer_cliente.importesPendientes=0;
			(*idCliente)++;
			arrayClientes[indice]=buffer_cliente;
		}
	}
	return retorno;
}

int cli_modificar(Cliente *arrayClientes, int indice)
{
	int retorno = -1;
	int desicion;
	Cliente bufferClientes;
	if(arrayClientes!=NULL && indice>=0)
	{
		if(utn_getNumero(&desicion, "Que desea modificar?\n1)Nombre.\n2)Apellido.\n3)Cuit.\n", "[ERROR]Opcion Invalida.\n", 1, 4, 3)==0)
		{
			bufferClientes = arrayClientes[indice];
			retorno = 0;
			switch (desicion) {
				case 1:
					printf("Nuevo Nombre:\n");
					if(utn_getName(bufferClientes.nombre, sizeof(bufferClientes.nombre), "-->", "[Error]Nombre invalido.\n", 3)==0)
					{
						arrayClientes[indice]=bufferClientes;
						printf("Nombre cambiado con exito!.\n");
					}
					break;
				case 2:
					printf("Nuevo Apellido:\n");
					if(utn_getName(bufferClientes.apellido, sizeof(bufferClientes.apellido), "-->", "[Error]Apellido invalido.\n", 3)==0)
					{
						arrayClientes[indice]=bufferClientes;
						printf("Apellido cambiado con exito!.\n");
					}
					break;
				case 3:
					printf("Nuevo Cuit:\n");
					if(utn_getName(bufferClientes.cuit,sizeof(bufferClientes.cuit), "-->", "[Error]Cuit invalido.\n", 3)==0)
					{
						arrayClientes[indice]=bufferClientes;
						printf("Cuit cambiado con exito!.\n");
					}
					break;
				default:
					break;
			}
		}
	}
	return retorno;
}
