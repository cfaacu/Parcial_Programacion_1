/*
 * ventas.c
 *
 *  Created on: 30 abr. 2021
 *      Author: Pato
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "utn2.h"
#include "clientes.h"
#include "ventas.h"
#define CLIENTES 100
#define VENTAS 1000
#define VACIO 0
#define LLENO 1
#define PENDIENTE 0
#define COBRADO 1

/**
 * \brief Inicializa un array de Contrataciones en VACIO(0).
 * \param array pContratacion Array de contrataciones.
 * \param Longitud tama�o del array a inicializar.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int ven_inizializarArray(Venta *arrayVentas, int longitud)
{
	int retorno = -1;
	if(arrayVentas!=NULL && longitud>0)
	{
		retorno=0;
		for(int i=0;i<longitud;i++)
		{
			arrayVentas[i].isEmpty=VACIO;
			arrayVentas[i].estado=2;
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
int ven_isEmptyArray(Venta* arrayVentas, int limite)
{
	int retorno=-1;

	if(arrayVentas!=NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(arrayVentas[i].isEmpty==VACIO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime una contratacion.
 * \param array pContratacion Array de contrataciones a imprimir.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int ven_imprimir(Venta *arrayVentas)
{
	int retorno = -1;

	if(arrayVentas!=NULL)
	{
		retorno=0;
		printf("ID Venta: %d\t",arrayVentas->idVenta);
		printf("Cantidad de barbijos: %d\tDireccion: %s\tColor: %s\tId De Cliente: %d\tEstado: %d\n",arrayVentas->cantidadBarbijos,arrayVentas->direccion,arrayVentas->color,arrayVentas->idCliente,arrayVentas->isEmpty);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}

	return retorno;
}

/**
 * \brief Imprime un array de contrataciones
 * \param array pContratacion Array de contrataciones a imprimir.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int ven_imprimirArray(Venta *arrayVentas, int longitud)
{
	int retorno = -1;
	int verifyIsEmpty=0;
	if(arrayVentas!=NULL && longitud>0)
	{
		retorno=0;
		for(int i=0;i<longitud;i++)
		{
			if(arrayVentas[i].isEmpty==LLENO)
			{
				verifyIsEmpty=verifyIsEmpty+1;
				ven_imprimir(&arrayVentas[i]);
			}
		}
	}
	if(verifyIsEmpty==0)
		printf("No hay contrataciones cargadas.\n");
	return retorno;
}

/**
 * \brief Busca un ID en un array y devuelve el indice en que se encuentra
 * \param array Array de ...
 * \param limite Limite del array de ...
 * \param valorBuscado ID a buscar
 * \return Retorna la posicion del array (EXITO) y -1 (ERROR)
 */
int ven_buscarId(Venta* arrayVentas, int limite, int valorBuscado)
{
	int retorno = -1;

	if(arrayVentas != NULL && limite > 0 && valorBuscado >= 0)
	{
		retorno = 0;
		for(int i=0;i<limite;i++)
		{
			if(arrayVentas[i].idVenta == valorBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Funcion para dar de alta un array de contrataciones.
 * \param pContrataciones array de pantallas.
 * \param pPantallas array de pantallas
 * \param longitudPantallas cantidad de pantallas
 * \param indice indice a ocupar
 * \param idContratacion id de la contratacion
 * \param idPantalla id de pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int ven_altaArray(Venta *arrayVentas,Cliente *arrayClientes, int longitudPantallas, int *idCliente, int *idVenta)
{
	int retorno = -1;
	int indice;
	if(arrayVentas!=NULL && arrayClientes!=NULL && idVenta!=NULL && arrayClientes->isEmpty==LLENO)
	{
		indice = ven_isEmptyArray(arrayVentas, VENTAS);
		if(ven_pedirDatos(arrayVentas, arrayClientes, indice, idVenta, idCliente)==0)
		{
			printf("El ID de la compra es: %d", *idVenta-1);
		}
	}

	return retorno;
}
/**
 * \brief Pide un ID para dar de baja
 * \param pContrataciones Array de contrataciones
 * \param indice Indice a dar de baja
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cont_bajaArray(Venta *pContrataciones, int indice)
{
	int retorno = -1;

	if(pContrataciones!=NULL && pContrataciones[indice].isEmpty==LLENO)
	{
		retorno = 0;
		pContrataciones[indice].isEmpty=VACIO;
	}
	return retorno;
}

int ven_pedirDatos(Venta *arrayVentas,Cliente *arrayClientes, int indice, int *idVenta, int *idCliente)
{
	int retorno = -1;
	Venta buffer_venta;
	if(arrayVentas!=NULL && arrayClientes!=NULL && indice>=0 && idCliente!=NULL)
	{
		cli_imprimirArray(arrayClientes, CLIENTES);
		if(utn_getNumero(&buffer_venta.idCliente, "Ingrese ID del cliente:\n", "[ERROR]ID Invalido.\n", 0, *idCliente-1, 3)==0
			&&utn_getNumero(&buffer_venta.cantidadBarbijos, "Ingrese Cantidad de barbijos:\n", "[ERROR]Cantidad Invalida.\n", 1, 1000, 3)==0
			&& utn_getName(buffer_venta.direccion, sizeof(buffer_venta.direccion), "Ingrese direccion:\n", "[ERROR]Direccion Invalida.\n", 3)==0
			&& utn_getName(buffer_venta.color, sizeof(buffer_venta.color), "Ingrese Color:\n", "[ERROR]Color Invalido.\n", 3)==0)
		{
			retorno = 0;
			buffer_venta.isEmpty=LLENO;
			buffer_venta.idVenta=*idVenta;
			buffer_venta.estado=PENDIENTE;
			(*idVenta)++;
			utn_hacerMinuscula(buffer_venta.color, sizeof(buffer_venta.color));
			arrayVentas[indice]=buffer_venta;
		}
	}

	return retorno;
}


int ven_pagarImporte(Venta *arrayVentas,Cliente *arrayClientes, int *idVenta)
{
	int retorno = -1;
	int auxId;
	int auxIndiceCliente;
	int auxIndiceVenta;
	float importePagado;
	int desicion;

	if(arrayVentas!=NULL && arrayClientes!=NULL)
	{
		if(utn_getNumero(&auxId, "Ingrese ID de la venta a pagar:\n", "[ERROR]ID Invalido.\n", 0, *idVenta-1, 3)==0)
		{
			auxIndiceCliente = ven_findClient(arrayVentas, arrayClientes, &auxId);
			cli_imprimir(&arrayClientes[auxIndiceCliente]);
			if(utn_getNumeroFloat(&importePagado, "Dinero a abonar:\n", "[ERROR]Importe incorrecto.\n", 1, 99999, 3)==0)
			{
				if(utn_getNumero(&desicion, "Confirmar Pago(1-Si/2-No).\n", "[ERROR]Opcion Incorrecta.\n", 1, 2, 3)==0)
				{
					if(desicion==1)
					{
						auxIndiceVenta = ven_buscarId(arrayVentas, VENTAS, auxId);
						arrayVentas[auxIndiceVenta].estado=COBRADO;
						arrayVentas[auxIndiceVenta].precio=importePagado;
					}
				}
			}
		}
	}


	return retorno;
}

int ven_findClient(Venta *arrayVentas,Cliente *arrayClientes, int *idVenta)
{
	int retorno=-1;
	int indiceVenta;
	int indiceCliente;
	if(arrayVentas!=NULL && arrayClientes!=NULL && idVenta!=NULL)
	{
		indiceVenta = ven_buscarId(arrayVentas, VENTAS, *idVenta);
		indiceCliente = cli_buscarId(arrayClientes, CLIENTES, arrayVentas[indiceVenta].idCliente);
		retorno = indiceCliente;
	}


	return retorno;
}

int ven_cancelarCompra(Venta *arrayVentas,Cliente *arrayClientes, int *idVenta)
{
	int retorno = -1;
	int auxId;
	int auxIndiceCliente;
	int auxIndiceVenta;
	int desicion;
	if(arrayVentas!=NULL && arrayClientes!=NULL)
	{
		if(utn_getNumero(&auxId, "Ingrese ID de la venta a cancelar:\n", "[ERROR]ID Invalido.\n", 0, *idVenta-1, 3)==0)
		{
			auxIndiceCliente = ven_findClient(arrayVentas, arrayClientes, &auxId);
			cli_imprimir(&arrayClientes[auxIndiceCliente]);
			if(utn_getNumero(&desicion, "Confirmar eliminacion?(1-Si/2-No).\n", "[ERROR]Opcion Incorrecta.\n", 1, 2, 3)==0)
			{
				if(desicion==1)
				{
					auxIndiceVenta = ven_buscarId(arrayVentas, VENTAS, auxId);
					if(arrayVentas[auxIndiceVenta].estado==PENDIENTE)
					{
						arrayVentas[auxIndiceVenta].isEmpty=VACIO;
						printf("Cancelacion Exitosa!\n");
					}
					else
					{
						printf("La compra ya fue abonada, no es posible eliminarla.\n");
					}
				}
			}
		}
	}

	return retorno;
}
