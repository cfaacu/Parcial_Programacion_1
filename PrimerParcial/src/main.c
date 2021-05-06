/*
 ============================================================================
 Name        : Parcial_Oficial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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

int main(void) {

	int desicionMain;
	int desicion;
	int idCliente = 0;
	int idVenta = 0;
	Cliente arrayClientes[CLIENTES];
	Venta arrayVentas[VENTAS];
	cli_inizializarArray(arrayClientes, CLIENTES);
	ven_inizializarArray(arrayVentas, VENTAS);

	strncpy(arrayClientes[0].nombre,"Patricio",sizeof(arrayClientes[0].nombre));
	strncpy(arrayClientes[0].apellido,"Orce",sizeof(arrayClientes[0].apellido));
	strncpy(arrayClientes[0].cuit,"43388641",sizeof(arrayClientes[0].cuit));
	arrayClientes[0].isEmpty=LLENO;
	arrayClientes[0].importesPagos=0;
	arrayClientes[0].importesPendientes=0;
	arrayClientes[0].idCliente=0;
	idCliente++;

	strncpy(arrayClientes[1].nombre,"Facundo",sizeof(arrayClientes[1].nombre));
	strncpy(arrayClientes[1].apellido,"Careri",sizeof(arrayClientes[1].apellido));
	strncpy(arrayClientes[1].cuit,"42252292",sizeof(arrayClientes[1].cuit));
	arrayClientes[1].isEmpty=LLENO;
	arrayClientes[1].importesPagos=0;
	arrayClientes[1].importesPendientes=0;
	arrayClientes[1].idCliente=1;
	idCliente++;

	strncpy(arrayClientes[2].nombre,"Agostina",sizeof(arrayClientes[2].nombre));
	strncpy(arrayClientes[2].apellido,"Orce",sizeof(arrayClientes[2].apellido));
	strncpy(arrayClientes[2].cuit,"39276614",sizeof(arrayClientes[2].cuit));
	arrayClientes[2].isEmpty=LLENO;
	arrayClientes[2].importesPagos=0;
	arrayClientes[2].importesPendientes=0;
	arrayClientes[2].idCliente=2;
	idCliente++;


	strncpy(arrayVentas[0].direccion,"Artigas",sizeof(arrayVentas[0].direccion));
	strncpy(arrayVentas[0].color,"Rojo",sizeof(arrayVentas[0].color));
	arrayVentas[0].cantidadBarbijos=10;
	arrayVentas[0].estado=0;
	arrayVentas[0].isEmpty=LLENO;
	arrayVentas[0].idCliente=1;
	arrayVentas[0].idVenta=0;
	idVenta++;

	strncpy(arrayVentas[1].direccion,"Estrada",sizeof(arrayVentas[1].direccion));
	strncpy(arrayVentas[1].color,"Verde",sizeof(arrayVentas[1].color));
	arrayVentas[1].cantidadBarbijos=10;
	arrayVentas[1].estado=1;
	arrayVentas[1].isEmpty=LLENO;
	arrayVentas[1].idCliente=0;
	arrayVentas[1].idVenta=1;
	idVenta++;

	strncpy(arrayVentas[2].direccion,"Ramos",sizeof(arrayVentas[2].direccion));
	strncpy(arrayVentas[2].color,"Rosa",sizeof(arrayVentas[2].color));
	arrayVentas[2].cantidadBarbijos=10;
	arrayVentas[2].estado=1;
	arrayVentas[2].isEmpty=LLENO;
	arrayVentas[2].idCliente=2;
	arrayVentas[2].idVenta=2;
	idVenta++;

	strncpy(arrayVentas[3].direccion,"Artigas",sizeof(arrayVentas[3].direccion));
	strncpy(arrayVentas[3].color,"Beige",sizeof(arrayVentas[3].color));
	arrayVentas[3].cantidadBarbijos=10;
	arrayVentas[3].estado=1;
	arrayVentas[3].isEmpty=LLENO;
	arrayVentas[3].idCliente=1;
	arrayVentas[3].idVenta=3;
	idVenta++;

	strncpy(arrayVentas[4].direccion,"Artigas",sizeof(arrayVentas[4].direccion));
	strncpy(arrayVentas[4].color,"Beige",sizeof(arrayVentas[4].color));
	arrayVentas[4].cantidadBarbijos=10;
	arrayVentas[4].estado=1;
	arrayVentas[4].isEmpty=LLENO;
	arrayVentas[4].idCliente=1;
	arrayVentas[4].idVenta=4;
	idVenta++;

	do
		{
			printf("Elija una desicion:\n");
			printf("1)Alta de Cliente.\n2)Modificar datos de Cliente.\n3)Baja de Cliente.\n4)Realizar compra.\n5)Pagar Compra.\n"
			"6)Cancelar compra.\n7)Imprimir clientes.\n8)Informar.\n9)Salir!.\n");
			utn_getNumero(&desicionMain, "-->", "[ERROR]Opcion incorrecta.\n", 1, 9, 3);

			switch (desicionMain) {
				case 1:
					cli_altaArray(arrayClientes, CLIENTES, &idCliente);
					break;
				case 2:
					cli_modificarArray(arrayClientes, &idCliente);
					break;
				case 3:
					info_bajaCliente(arrayVentas, arrayClientes, &idCliente, &idVenta);
					break;
				case 4:
					ven_altaArray(arrayVentas, arrayClientes, CLIENTES, &idCliente, &idVenta);
					break;
				case 5:
					ven_pagarImporte(arrayVentas, arrayClientes, &idVenta);
					break;
				case 6:
					ven_cancelarCompra(arrayVentas, arrayClientes, &idVenta);
					break;
				case 7:
					cli_imprimirArray(arrayClientes, CLIENTES);
					break;
				case 8:
					utn_getNumero(&desicion, "10) Color de barbijo que se compro mas veces.\n11) Cantidad de compras pendientes.\n12) Compra con precio por unidad mas bajo.\n"
							"13) Cliente con mas compras pagadas.\n14) Cliente con mas compras pendientes.\n15) Lista de compras pendientes de pago con informacion de la compra y del cliente.\n",
							"[ERROR]Opcion incorrecta.\n", 10, 15, 3);
					switch (desicion) {
						case 10:
							info_colorBarbijoMasVeces(arrayVentas,&idVenta);
							break;
						case 11:
							info_cantidadComprasPendientes(arrayVentas);
							break;
						case 12:
							info_compraConPrecioPorUnidadMasBajo(arrayVentas);
							break;
						case 13:
							info_clienteConMasPagadas(arrayClientes, arrayVentas);
							break;
						case 14:
							info_clienteConMasPendientes(arrayClientes,arrayVentas);
							break;
						case 15:
							info_listasComprasPagoPendiente(arrayVentas, arrayClientes);
							break;
					}
					break;
				case 9:
					printf("SALISTE!.\n");
					break;
			}
		}
		while(desicionMain!=9);
	return EXIT_SUCCESS;
}
