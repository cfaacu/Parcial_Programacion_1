/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : Facu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "LinkedList.h"
#include "Dictionary.h"
#include "Parser.h"
#include "Articulo.h"
#include "PosArancelaria.h"
#include "Controller.h"
#include "Informes.h"


int main(void) {

	int opcion;
	int idPosArancelariaMax;
	Dictionary* pDictionaryArticulo = dict_new(0);
	Dictionary* pDictionaryPosArancelaria = dict_new(0);
	LinkedList* pListaMaritimo = ll_newLinkedList();
	LinkedList* pListaAereo = ll_newLinkedList();

	controller_loadArticuloFromText("Archivo.csv", pDictionaryArticulo);
	controller_loadPosArancelariaFromText("ArchivoPosArancelaria.csv", pDictionaryPosArancelaria);
	controller_loadMaritimoFromText("Maritimo.csv", pListaMaritimo);
	controller_loadAereoFromText("Aereo.csv", pListaAereo);
	art_setearValorInicialDeId(pDictionaryArticulo);
	idPosArancelariaMax = posAr_setearValorInicialDeId(pDictionaryPosArancelaria);

	do
	{
		printf("\nIngrese una opcion:\n");
		utn_getNumero(&opcion,  "1)Calcular precio final\n"
								"2)Agregar articulos.\n"
								"3)Modificar articulos.\n"
								"4)Eliminar articulos.\n"
								"5)Listar articulos.\n"
								"6)Agregar posicion arancelaria.\n"
								"7)Modificar posicion arancelaria.\n"
								"8)Eliminar posicion arancelaria.\n"
								"9)Listar posicion arancelaria.\n"
								"10)Modificar transporte por barco.\n"
								"11)Modificar transporte por avion.\n"
								"12)Listar Maritimo.\n"
								"13)Listar Aereo.\n"
								"14)Salir\n", "Opcion incorrecta.\n", 1, 14, 3);
		switch (opcion)
		{
			case 1:
				info_listarArticulosConCostosFinales(pDictionaryArticulo, pDictionaryPosArancelaria, pListaMaritimo, pListaAereo);
				break;
			case 2:
				controller_addArticulo(pDictionaryArticulo, pDictionaryPosArancelaria, idPosArancelariaMax);
				controller_saveArticuloAsText("Archivo.csv", pDictionaryArticulo);
				break;
			case 3:
				controller_editArticulo(pDictionaryArticulo, pDictionaryPosArancelaria, idPosArancelariaMax);
				controller_saveArticuloAsText("Archivo.csv", pDictionaryArticulo);
				break;
			case 4:
				controller_removeArticulo(pDictionaryArticulo);
				controller_saveArticuloAsText("Archivo.csv", pDictionaryArticulo);
				break;
			case 5:
				controller_ListarArticulo(pDictionaryArticulo);
				break;
			case 6:
				controller_addPosArancelaria(pDictionaryPosArancelaria);
				controller_savePosArancelariaAsText("ArchivoPosArancelaria.csv", pDictionaryPosArancelaria);
				break;
			case 7:
				controller_editPosArancelaria(pDictionaryPosArancelaria);
				controller_savePosArancelariaAsText("ArchivoPosArancelaria.csv", pDictionaryPosArancelaria);
				break;
			case 8:
				controller_removePosArancelaria(pDictionaryPosArancelaria,pDictionaryArticulo);
				controller_savePosArancelariaAsText("ArchivoPosArancelaria.csv", pDictionaryPosArancelaria);
				break;
			case 9:
				controller_ListarPosArancelaria(pDictionaryPosArancelaria);
				break;
			case 10:
				controller_editMaritimo(pListaMaritimo);
				controller_saveMaritimoAsText("Maritimo.csv",pListaMaritimo);
				break;
			case 11:
				controller_editAereo(pListaAereo);
				controller_saveAereoAsText("Aereo.csv", pListaAereo);
				break;
			case 12:
				controller_ListarMaritimo(pListaMaritimo);
				break;
			case 13:
				controller_ListarAereo(pListaAereo);
				break;
			case 14:
				printf("Saliste exitosamente.\n");
				dict_deleteDictionary(pDictionaryArticulo);
				dict_deleteDictionary(pDictionaryPosArancelaria);
				ll_deleteLinkedList(pListaMaritimo);
				ll_deleteLinkedList(pListaAereo);
				break;
		}
	}
	while(opcion!=12);

	return EXIT_SUCCESS;
}
