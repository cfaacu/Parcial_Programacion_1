/*
 * informes.c
 *
 *  Created on: 1 may. 2021
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
#include "informes.h"
#define CLIENTES 100
#define VENTAS 1000
#define LLENO 1
#define VACIO 0

int info_imprimirArrayClienteUnico(ClienteUnico *arrayCliente, int longitud)
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
				info_imprimirClienteUnico(&arrayCliente[i]);
			}
		}
	}
	if(verifyIsEmpty==0)
		printf("No hay clientes cargados.\n");
	return retorno;
}

int info_imprimirClienteUnico(ClienteUnico *arrayCliente)
{
	int retorno = -1;

	if(arrayCliente!=NULL)
	{
		retorno=0;

		printf("Cuit: %s\tID: %d\tImportesPagos: %d\n",arrayCliente->cuit,arrayCliente->idCliente,arrayCliente->importesPagos);
		printf("------------------------------------------\n");
	}

	return retorno;
}

int info_bajaCliente(Venta *arrayVentas,Cliente *arrayClientes, int *idCliente, int *idVentas)
{
	int retorno = -1;
	int auxId;

	if(arrayVentas!=NULL && arrayClientes!=NULL)
	{
		retorno = 0;
		utn_getNumero(&auxId, "Ingrese ID del cliente a dar de baja.\n", "[ERROR]ID invalido-\n", 0, *idCliente-1, 3);
		printf("Compras de cliente [%d]:\n",auxId);
		for(int j=0;j<VENTAS;j++)
		{
			if(arrayVentas[j].isEmpty==LLENO)
			{
				if(arrayVentas[j].idCliente==auxId)
				{
					if(arrayVentas[j].estado==0)
					{
						printf("Barbijos: [%d]\tDireccion: [%s]\tColor: [%s]\tEstado [Pendiente]\n",arrayVentas[j].cantidadBarbijos,arrayVentas[j].direccion,arrayVentas[j].color);
					}
					else
					{
						printf("Barbijos: [%d]\tDireccion: [%s]\tColor: [%s]\tEstado [Cobrado]\n",arrayVentas[j].cantidadBarbijos,arrayVentas[j].direccion,arrayVentas[j].color);
					}
				}
			}
		}

		if(info_baja(arrayVentas,arrayClientes,&auxId)==0)
		{
			printf("Baja Exitosa!\n");
		}

	}

	return retorno;
}

int info_baja(Venta *arrayVentas, Cliente *arrayClientes, int *id)
{
	int retorno=-1;
	int desicion;
	if(utn_getNumero(&desicion, "Al dar de baja un cliente, se eliminaran sus compras.\nDesea confirmar la baja?(1-Si/2-No)\n", "[ERROR]Opcion Invalida.\n", 1, 2, 3)==0)
	{
		retorno = 0;
		if(desicion==1)
		{
			for(int i=0;i<VENTAS;i++)
			{
				if(arrayVentas[i].isEmpty==LLENO)
				{
					if(arrayVentas[i].idCliente==*id)
					{
						arrayClientes[*id].isEmpty=VACIO;
						arrayVentas[i].isEmpty=VACIO;
					}
				}
			}
		}
	}

	return retorno;
}


int info_colorBarbijoMasVeces(Venta *arrayVentas, int *idVentas)
{
	int retorno = -1;
	VentasColor listaVentas[VENTAS];
	info_inicializarArrayVentasPorColor(listaVentas);
	if(arrayVentas!=NULL)
	{
		info_listarBarbijosPorColor(arrayVentas,listaVentas,idVentas);
		info_maximoBarbijoColor(listaVentas);
	}

	return retorno;
}

int info_listarBarbijosPorColor(Venta *arrayVentas,VentasColor *listaVentas, int *idVentas)
{
	int retorno = -1;
	int flagExisteColor;
	int indicePosicionLibre=0;

	if(arrayVentas!=NULL && listaVentas!=NULL && idVentas!=NULL)
	{
		for(int i=0;i<*idVentas;i++)
		{
			flagExisteColor=0;
			for(int j=0;j<indicePosicionLibre;j++)
			{
				if(strcmp(arrayVentas[i].color,listaVentas[j].color)==0)
				{
					flagExisteColor=1;
					listaVentas[j].cantidadColor=listaVentas[j].cantidadColor+1;
					break;
				}
			}
			if(flagExisteColor==0)
			{
				strncpy(listaVentas[indicePosicionLibre].color,arrayVentas[i].color,sizeof(listaVentas[indicePosicionLibre].color));
				listaVentas[indicePosicionLibre].isEmpty=LLENO;
				indicePosicionLibre++;
			}
		}
	}


	return retorno;
}

int info_inicializarArrayVentasPorColor(VentasColor *arrayVentasPorColor)
{
	int retorno = -1;

	if(arrayVentasPorColor!=NULL)
	{
		for(int i=0;i<VENTAS;i++)
		{
			arrayVentasPorColor[i].isEmpty=VACIO;
			arrayVentasPorColor[i].cantidadColor=1;
		}
	}

	return retorno;
}
int info_inicializarArrayClienteUnico(ClienteUnico *arrayClientesUnicos)
{
	int retorno = -1;
	if(arrayClientesUnicos!=NULL)
	{
		for(int i=0;i<VENTAS;i++)
		{
			arrayClientesUnicos[i].isEmpty=VACIO;
			arrayClientesUnicos[i].importesPagos=0;

		}
	}

	return retorno;
}

int info_imprimirArrayVentasPorColor(VentasColor *arrayVentasPorColor, int limite)
{
	int retorno = -1;
	printf("Entre 1\n");
	if(arrayVentasPorColor!=NULL && limite>0)
	{
		for(int i=0;i<limite;i++)
		{
			if(arrayVentasPorColor[i].isEmpty==LLENO)
			{
				printf("Color: %s\n",arrayVentasPorColor[i].color);
				printf("Cantidad: %d\n",arrayVentasPorColor[i].cantidadColor);
			}
		}
	}

	return retorno;
}


int info_cantidadComprasPendientes(Venta *arrayVentas)
{
	int retorno = -1;
	int acumVentasPendientes=0;
	if(arrayVentas!=NULL)
	{
		retorno=0;
		for(int i=0;i<VENTAS;i++)
		{
			if(arrayVentas[i].isEmpty==LLENO && arrayVentas[i].estado==0)
			{
				acumVentasPendientes=acumVentasPendientes+1;
			}
		}
		printf("Compras pendientes a pagar: %d\n",acumVentasPendientes);
	}

	return retorno;
}

int info_compraConPrecioPorUnidadMasBajo(Venta *arrayVentas)
{
	int retorno = -1;
	float preciosPorUnidad[VENTAS];
	info_inicializarArrayFloat(preciosPorUnidad);
	if(arrayVentas!=NULL)
	{
		for(int i=0;i<VENTAS;i++)
		{
			if(arrayVentas[i].isEmpty==LLENO && arrayVentas[i].estado==1)
			{
				preciosPorUnidad[i]=arrayVentas[i].precio/arrayVentas[i].cantidadBarbijos;
			}
		}
		info_minimoPrecioPorUnidad(preciosPorUnidad);
	}

	return retorno;
}

int info_minimoPrecioPorUnidad(float *preciosPorUnidad)
{
	int retorno = -1;
	float minimoPrecio;
	if(preciosPorUnidad!=NULL)
	{
		minimoPrecio=preciosPorUnidad[0];
		for(int i=0;i<VENTAS;i++)
		{
			if(preciosPorUnidad[i]!=0)
			{
				if(preciosPorUnidad[i]<=minimoPrecio)
				{
					minimoPrecio=preciosPorUnidad[i];
				}
			}
		}
		printf("El precio por unidad mas bajo es: %.2f\n",minimoPrecio);
	}

	return retorno;
}

int info_inicializarArrayFloat(float *arrayFloat)
{
	int retorno = -1;

	if(arrayFloat!=NULL)
	{
		retorno = 0;
		for(int i=0;i<VENTAS;i++)
		{
			arrayFloat[i]=0;
		}
	}

	return retorno;
}

int info_maximoBarbijoColor(VentasColor *listaVentas)
{
	int retorno = -1;
	int maximoColorBarbijo;
	char colorMasComprado[64];
	if(listaVentas!=NULL)
	{
		retorno = 0;
		maximoColorBarbijo=listaVentas[0].cantidadColor;
		for(int i=0;i<VENTAS;i++)
		{
			if(listaVentas[i].isEmpty==LLENO)
			{
				if(listaVentas[i].cantidadColor>=maximoColorBarbijo)
				{
					maximoColorBarbijo=listaVentas[i].cantidadColor;
					strncpy(colorMasComprado,listaVentas[i].color,sizeof(colorMasComprado));
				}
			}
		}
		printf("El color mas comprado es: %s con %d ventas\n",colorMasComprado,maximoColorBarbijo);
	}
	return retorno;
}

int info_dividirVentasPorEstado(Venta *arrayVentas, Cliente *arrayCliente)
{
	int retorno=-1;


	if(arrayCliente!=NULL && arrayVentas!=NULL)
	{
		retorno = 0;
		for(int i=0;i<CLIENTES;i++)
		{
			if(arrayCliente[i].isEmpty==LLENO)
			{
				for(int j=0;j<VENTAS;j++)
				{
					if(arrayCliente[i].idCliente==arrayVentas[j].idCliente)
					{
						if(arrayVentas[j].isEmpty==LLENO)
						{
							if(arrayVentas[j].estado==1)
							{
								arrayCliente[i].importesPagos=arrayCliente[i].importesPagos+1;
								continue;
							}
							else
							{
								arrayCliente[i].importesPendientes=arrayCliente[i].importesPendientes+1;
								continue;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

int info_maximoComprasPagadas(Cliente *arrayCliente)
{
	int retorno = -1;
	int maximoCompras;
	char nombreDelMaximo[64];
	if(arrayCliente!=NULL)
	{
		maximoCompras=arrayCliente[0].importesPagos;
		for(int i=0;i<CLIENTES;i++)
		{
			if(arrayCliente[i].importesPagos>=maximoCompras)
			{
				maximoCompras=arrayCliente[i].importesPagos;
				strncpy(nombreDelMaximo,arrayCliente[i].nombre,sizeof(nombreDelMaximo));
				continue;
			}
		}
		printf("El cliente %s tiene mas cantidad de compras pagas con: %d\n",nombreDelMaximo,maximoCompras);
	}
	return retorno;
}



int info_maximoComprasPendientes(Cliente *arrayCliente)
{
	int retorno = -1;
	int maximoCompras;
	char nombreDelMaximo[64];
	if(arrayCliente!=NULL)
	{
		maximoCompras=arrayCliente[0].importesPendientes;
		for(int i=0;i<CLIENTES;i++)
		{
			if(arrayCliente[i].importesPendientes>=maximoCompras)
			{
				maximoCompras=arrayCliente[i].importesPendientes;
				strncpy(nombreDelMaximo,arrayCliente[i].nombre,sizeof(nombreDelMaximo));
				continue;
			}
		}
		printf("El cliente %s tiene mas cantidad de compras pendientes con: %d\n",nombreDelMaximo,maximoCompras);
	}
	return retorno;
}

int info_listasComprasPagoPendiente(Venta *arrayVentas, Cliente *arrayClientes)
{

	//c) Lista de compras pendientes de pago con informaci�n de la compra y del cliente.
	int retorno=-1;
	int indice;
	for(int i=0;i<VENTAS;i++)
	{
		if(arrayVentas[i].estado==0)
		{
			ven_imprimir(&arrayVentas[i]);
			indice = cli_buscarId(arrayClientes, CLIENTES,arrayVentas[i].idCliente);
			cli_imprimir(&arrayClientes[indice]);

		}
	}

	return retorno;
}

int info_clienteConMasPagadas(Cliente *arrayClientes, Venta *arrayVentas)
{
	int retorno = -1;

	if(arrayClientes!=NULL && arrayVentas!=NULL)
	{
		info_dividirVentasPorEstado(arrayVentas, arrayClientes);
		info_maximoComprasPagadas(arrayClientes);
	}

	return retorno;


}

int info_clienteConMasPendientes(Cliente *arrayClientes, Venta *arrayVentas)
{
	int retorno = -1;

	if(arrayClientes!=NULL && arrayVentas!=NULL)
	{
		printf("Entre a la funcion\n");
		info_dividirVentasPorEstado(arrayVentas, arrayClientes);
		info_maximoComprasPendientes(arrayClientes);
	}

	return retorno;


}
