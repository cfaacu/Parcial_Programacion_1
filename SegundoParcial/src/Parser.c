/*
 * Parser.c
 *
 *  Created on: Jun 16, 2021
 *      Author: facu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Articulo.h"
#include "utn.h"
#include "LinkedList.h"
#include "Dictionary.h"
#include "PosArancelaria.h"
#include "Maritimo.h"
#include "Aereo.h"

int parser_articuloFromText(FILE* pFile , Dictionary* pDictionaryArticulo)
{
	int retorno = -1;
	char codigoAux[CODIGO_LEN];
	char nombreAux[NOMBRE_LEN];
	char descripcionAux[DESCRIPCION_LEN];
	char paisDeFabricacionAux[PAIS_LEN];
	char valorFob[50];
	char pesosEnKg[50];
	char alto[50];
	char ancho[50];
	char profundidad[50];
	char posArancel[50];
	char idArticulo[50];
	Articulo* auxArticulo;
	int flagFirst = 0;
	int conteo=0;

	if(pFile != NULL && pDictionaryArticulo != NULL)
	{
		do
		{
			{
				if(	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArticulo,nombreAux,codigoAux,descripcionAux,paisDeFabricacionAux,
					valorFob,pesosEnKg,alto,ancho,profundidad,posArancel)==11)
				{
					if(flagFirst == 1)
					{
						auxArticulo = art_newParametrosTxt(idArticulo,nombreAux, codigoAux, descripcionAux, paisDeFabricacionAux,
								valorFob, pesosEnKg, ancho, alto, profundidad, posArancel);
						if(auxArticulo != NULL)
						{
							dict_insert(pDictionaryArticulo, idArticulo, auxArticulo);
							conteo++;
						}
					}
					flagFirst = 1;
				}
			}

		}while(!feof(pFile));
		printf("Se cargaron %d articulos.\n",conteo);
		retorno = 0;
	}
    return retorno;
}

int parser_posArancelariaFromText(FILE* pFile , Dictionary* pDictionaryPosArancelaria)
{
	int retorno = -1;
	char nomenclatura[50];
	char porcentajeSeguro[50];
	char porcentajeImportacion[50];
	char porcentajeTasaEst[50];
	char tipoLicencia[50];
	char idPosicionArancelaria[50];
	PosArancelaria* auxPosAr;
	int flagFirst = 0;
	int conteo=0;

	if(pFile != NULL && pDictionaryPosArancelaria != NULL)
	{
		do
		{
			{
				if(	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idPosicionArancelaria,nomenclatura,porcentajeSeguro,porcentajeImportacion,
						porcentajeTasaEst,tipoLicencia)==6)
				{
					if(flagFirst == 1)
					{
						auxPosAr = posAr_newParamTxt(nomenclatura,porcentajeSeguro, porcentajeImportacion, porcentajeTasaEst, tipoLicencia,idPosicionArancelaria);
						if(auxPosAr != NULL)
						{
							dict_insert(pDictionaryPosArancelaria, idPosicionArancelaria, auxPosAr);
							conteo++;
						}
					}
					flagFirst = 1;
				}
			}

		}while(!feof(pFile));
		printf("Se cargaron %d posiciones arancelarias.\n",conteo);
		retorno = 0;
	}
    return retorno;
}

int parser_maritimoFromText(FILE* pFile , LinkedList* listaMaritimo)
{
	int retorno = -1;
	char metrosCubicos[50];
	char valorContenedor[50];
	Maritimo* auxMaritimo;
	int flagFirst = 0;
	int conteo=0;

	if(pFile != NULL && listaMaritimo != NULL)
	{
		do
		{
			if(	fscanf(pFile,"%[^,],%[^\n]\n",metrosCubicos,valorContenedor)==2)
			{
				if(flagFirst == 1)
				{
					auxMaritimo = mar_newParamTxt(metrosCubicos,valorContenedor);
					if(auxMaritimo != NULL)
					{
						ll_add(listaMaritimo, auxMaritimo);
						conteo++;
					}
				}
				flagFirst = 1;
			}
		}while(!feof(pFile));
		printf("Se cargaron %d maritimos.\n",conteo);
		retorno = 0;
	}
    return retorno;
}

int parser_aereoFromText(FILE* pFile , LinkedList* listaAereo)
{
	int retorno = -1;
	char constVolumetrica[50];
	char valorPorKg[50];
	Aereo* auxAereo;
	int flagFirst = 0;
	int conteo=0;

	if(pFile != NULL && listaAereo != NULL)
	{
		do
		{
			{
				if(	fscanf(pFile,"%[^,],%[^\n]\n",constVolumetrica,valorPorKg)==2)
				{
					if(flagFirst == 1)
					{
						auxAereo = aer_newParamTxt(constVolumetrica,valorPorKg);
						if(auxAereo != NULL)
						{
							ll_add(listaAereo, auxAereo);
							conteo++;
						}
					}
					flagFirst = 1;
				}
			}

		}while(!feof(pFile));
		printf("Se cargaron %d aereos.\n",conteo);
		retorno = 0;
	}
    return retorno;
}
