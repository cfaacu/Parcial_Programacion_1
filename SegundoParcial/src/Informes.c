/*
 * Informes.c
 *
 *  Created on: Jun 19, 2021
 *      Author: facu
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
#include "Maritimo.h"
#include "Aereo.h"
#include "Informes.h"

float info_CalcularBaseImponibleAereo(Articulo* pArticulo,Aereo* pAereo, PosArancelaria* pPosArancelaria)
{
	int flagError;
	float valorFob;
	float costoEnvioAereo;
	float seguro;
	float porcentajeSeguro;
	float baseImponible = -1;

	if(pArticulo != NULL && pAereo != NULL && pPosArancelaria != NULL)
	{
		porcentajeSeguro = posAr_getPorcentajeSeguro(pPosArancelaria, &flagError);
		valorFob = art_getValorFob(pArticulo, &flagError);
		costoEnvioAereo = info_CalcularCostoAereo(pArticulo, pAereo);

		seguro = (valorFob * porcentajeSeguro) / 100;

		baseImponible = valorFob + seguro + costoEnvioAereo;
	}
	return baseImponible;
}

float info_CalcularCostoAereo(Articulo* pArticulo,Aereo* pAereo)
{
	float retorno;
	int flagError;
	float volumen;
	float pesoReal;
	float constanteVolumetrico;
	float resultadoVolumEnKG;
	float resultadoFinalVolumetrico;
	float alto;
	float ancho;
	float profundidad;
	float precioKg;
	float resultadoPeso;

	if(pArticulo != NULL && pAereo != NULL)
	{
		pesoReal = art_getPeso(pArticulo, &flagError);
		precioKg = aer_getPrecio(pAereo, &flagError);
		alto = art_getAlto(pArticulo, &flagError);
		ancho = art_getAncho(pArticulo, &flagError);
		profundidad = art_getProfundidad(pArticulo, &flagError);
		constanteVolumetrico = aer_getConstVolum(pAereo, &flagError);

		resultadoPeso = pesoReal * precioKg;

		volumen = alto * ancho * profundidad;
		resultadoVolumEnKG = volumen / constanteVolumetrico;
		resultadoFinalVolumetrico = resultadoVolumEnKG * precioKg;
		if(resultadoPeso > resultadoFinalVolumetrico)
		{
			retorno = resultadoPeso;
		}
		else
		{
			retorno = resultadoFinalVolumetrico;
		}
	}
	return retorno;
}

float info_calcularCostoArgentinoAereo(Articulo* pArticulo,PosArancelaria* pPosArancelaria,Aereo* pAereo)
{
	int flagError;
	float baseImponible;
	float porcentajeImportacion;
	float porcentajeTasaEst;
	float importacion;
	float tasaEst;
	float precioFinal = -1;

	if(pArticulo != NULL && pPosArancelaria != NULL && pAereo != NULL)
	{
		porcentajeImportacion = posAr_getPorcentajeImportacion(pPosArancelaria, &flagError);
		porcentajeTasaEst = posAr_getPorcentajeTasaEst(pPosArancelaria, &flagError);
		baseImponible = info_CalcularBaseImponibleAereo(pArticulo, pAereo, pPosArancelaria);

		if(baseImponible > -1)
		{
			importacion = (baseImponible * porcentajeImportacion) / 100;
			tasaEst = (baseImponible * porcentajeTasaEst) / 100;

			precioFinal = baseImponible + importacion + tasaEst;
		}

	}
	return precioFinal;
}

/*******************************************************************************************************************************************************/

float info_listarArticulosConCostosFinales(Dictionary* pDictionaryArticulo,Dictionary* pDictionaryPosArancelaria, LinkedList* listaMaritima,LinkedList* listaAerea)
{
	float retorno = -1;
	float valorFinalAereo;
	float valorFinalMaritimo;
	int flagError;
	int size;
	int idPosArancelaria;
	char idStr[50];
	LinkedList* listaAux;
	Articulo* auxArticulo;
	PosArancelaria* posArancelariaAux;
	Maritimo* pMaritimo;
	Aereo* pAereo;

	if(pDictionaryArticulo!=NULL && pDictionaryPosArancelaria!=NULL && listaAerea!=NULL && listaMaritima!=NULL)
	{
		pMaritimo = ll_get(listaMaritima, 0);
		pAereo = ll_get(listaAerea, 0);
		listaAux = dict_getValues(pDictionaryArticulo);
		size = ll_len(listaAux);
		for(int i=0;i<size;i++)
		{
			auxArticulo = ll_get(listaAux, i);
			if(auxArticulo != NULL)
			{
				idPosArancelaria = art_getIdPosicionArancelaria(auxArticulo, &flagError);
				snprintf(idStr,sizeof(idStr),"%d",idPosArancelaria);
				posArancelariaAux = dict_get(pDictionaryPosArancelaria, idStr);
				valorFinalMaritimo = info_calcularCostoArgentinoMaritimo(auxArticulo, posArancelariaAux, pMaritimo);
				valorFinalAereo = info_calcularCostoArgentinoAereo(auxArticulo, posArancelariaAux, pAereo);
				printf(	"ID: [%d]\tNombre: [%s]\tCodigo: [%s]\tDescripcion: [%s]\tHecho en: [%s]\tFOB: [%.2f]\tPeso(KG): [%.2f]\tDimensiones(Al*An*Pr): [%.2f*%.2f*%.2f]\tValor Final Aereo: [%.2f]\tValor Final Maritimo: [%.2f]\n",
							art_getIdArticulo(auxArticulo, &flagError),art_getNombre(auxArticulo, &flagError),art_getCodigo(auxArticulo, &flagError),art_getDescripcion(auxArticulo, &flagError),art_getPaisFabricacion(auxArticulo, &flagError),art_getValorFob(auxArticulo, &flagError),
							art_getPeso(auxArticulo, &flagError),art_getAlto(auxArticulo, &flagError),art_getAncho(auxArticulo, &flagError),art_getProfundidad(auxArticulo, &flagError),valorFinalAereo,valorFinalMaritimo);
			}
		}
	}
	return retorno;
}

float info_calcularCostoArgentinoMaritimo(Articulo* pArticulo,PosArancelaria* pPosArancelaria,Maritimo* pMaritimo)
{
	int flagError;
	float baseImponible;
	float porcentajeImportacion;
	float porcentajeTasaEst;
	float importacion;
	float tasaEst;
	float precioFinal = -1;

	if(pArticulo != NULL && pPosArancelaria != NULL && pMaritimo != NULL)
	{
		porcentajeImportacion = posAr_getPorcentajeImportacion(pPosArancelaria, &flagError);
		porcentajeTasaEst = posAr_getPorcentajeTasaEst(pPosArancelaria, &flagError);
		baseImponible = info_CalcularBaseImponibleMaritimo(pArticulo, pMaritimo, pPosArancelaria);
		if(baseImponible > -1)
		{
			importacion = (baseImponible * porcentajeImportacion) / 100;
			tasaEst = (baseImponible * porcentajeTasaEst) / 100;
			precioFinal = baseImponible + importacion + tasaEst;
		}
	}
	return precioFinal;
}

float info_CalcularCostoMaritimo(Articulo* pArticulo,Maritimo* pMaritimo)
{
	float retorno;
	int flagError;
	float alto = art_getAlto(pArticulo, &flagError);
	float ancho = art_getAncho(pArticulo, &flagError);
	float profundidad = art_getProfundidad(pArticulo, &flagError);
	float metrosCubicos = mar_getMtsCubicos(pMaritimo, &flagError);
	float valorContenedor = mar_getPrecio(pMaritimo, &flagError);
	float totalMtsCubicos;
	float valorPorKg;
	float costoFinal;

	if(pArticulo != NULL && pMaritimo != NULL)
	{
		totalMtsCubicos=(alto*ancho*profundidad)/(100*100*100);
		valorPorKg = valorContenedor/metrosCubicos;
		costoFinal=totalMtsCubicos*valorPorKg;
		retorno = costoFinal;
	}
	return retorno;
}

float info_CalcularBaseImponibleMaritimo(Articulo* pArticulo,Maritimo* pMaritimo, PosArancelaria* pPosArancelaria)
{
	int flagError;
	float valorFob;
	float costoEnvioMaritimo;
	float seguro;
	float porcentajeSeguro;
	float baseImponible = -1;

	if(pArticulo != NULL && pMaritimo != NULL && pPosArancelaria != NULL)
	{
		porcentajeSeguro = posAr_getPorcentajeSeguro(pPosArancelaria, &flagError);
		valorFob = art_getValorFob(pArticulo, &flagError);
		costoEnvioMaritimo = info_CalcularCostoMaritimo(pArticulo, pMaritimo);
		seguro = (valorFob * porcentajeSeguro) / 100;
		baseImponible = valorFob + seguro + costoEnvioMaritimo;
	}
	return baseImponible;
}


/*int funcionCriterio(void* pArticulo)
{
	int retorno = -1;
	float valorFob;
	int flagError = -1;
	Articulo* auxArticulo;
	if(pArticulo!=NULL)
	{
		auxArticulo = (Articulo*)pArticulo;
		valorFob = art_getValorFOB(auxArticulo, &flagError);
		if(valorFob < 100)
		{
			//art_setValorFOB(pArticulo, 0);
			retorno = 0;
		}
	}
	return retorno;
}

int funcionCriterioSort(void* pArticulo,void* pArticuloDos)
{
	int retorno = -1;
	int flagError = -1;
	Articulo* auxArticuloUno;
	Articulo* auxArticuloDos;
	int valorFobUno;
	int valorFobDos;
	if(pArticulo!=NULL && pArticuloDos!=NULL)
	{
		auxArticuloUno = (Articulo*)pArticulo;
		auxArticuloDos = (Articulo*)pArticuloDos;
		valorFobUno = art_getValorFOB(auxArticuloUno, &flagError);
		valorFobDos = art_getValorFOB(auxArticuloDos, &flagError);
		if(valorFobUno > valorFobDos)
		{
			retorno = 1;
		}
	}
	return retorno;
}
*/

