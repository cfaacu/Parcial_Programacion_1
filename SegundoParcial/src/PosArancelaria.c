/*
 * PosArancelaria.c
 *
 *  Created on: Jun 16, 2021
 *      Author: facu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "PosArancelaria.h"

PosArancelaria* posAr_new(void)
{
	return (PosArancelaria*) malloc(sizeof(PosArancelaria));
}

PosArancelaria* posAr_newParam(char* nomenclatura,float porcentajeSeguro,float porcentajeImportacion,float porcentajeTasaEst,int tipoLicencia,int idPosicionArancelaria)
{
	PosArancelaria* auxPosAr = posAr_new();
	if(auxPosAr != NULL)
	{
		if  ( 	posAr_setNomenclatura(auxPosAr,nomenclatura) < 0 ||
				posAr_setPorcentajeSeguro(auxPosAr, porcentajeSeguro) < 0 ||
				posAr_setPorcentajeImportacion(auxPosAr, porcentajeImportacion) < 0 ||
				posAr_setPorcentajeTasaEst(auxPosAr,porcentajeTasaEst) < 0 ||
				posAr_setTipoDeLicencia(auxPosAr,tipoLicencia) < 0 ||
				posAr_setIdPosicionArancelaria(auxPosAr,idPosicionArancelaria) < 0)
		{
			posAr_delete(auxPosAr);
			auxPosAr = NULL;
		}
	}
	return auxPosAr;;
}

PosArancelaria* posAr_newParamTxt(char* nomenclatura,char* porcentajeSeguro,char* porcentajeImportacion,char* porcentajeTasaEst,char* tipoLicencia,char* idPosicionArancelaria)
{
	PosArancelaria* auxPosAr = posAr_new();
	if(auxPosAr != NULL)
	{
		if  ( 	posAr_setNomenclatura(auxPosAr,nomenclatura) < 0 ||
				posAr_setPorcentajeSeguro(auxPosAr, atof(porcentajeSeguro)) < 0 ||
				posAr_setPorcentajeImportacion(auxPosAr, atof(porcentajeImportacion)) < 0 ||
				posAr_setPorcentajeTasaEst(auxPosAr,atof(porcentajeTasaEst)) < 0 ||
				posAr_setTipoDeLicencia(auxPosAr,atoi(tipoLicencia)) < 0 ||
				posAr_setIdPosicionArancelaria(auxPosAr,atoi(idPosicionArancelaria)) < 0)
		{
			posAr_delete(auxPosAr);
			auxPosAr = NULL;
		}
	}
	return auxPosAr;;
}

int posAr_delete(PosArancelaria* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int posAr_setNomenclatura(PosArancelaria* this, char* nomenclatura)
{
	int retorno = -1;
	if(this != NULL && nomenclatura != NULL && utn_isDNI(nomenclatura)==0)
	{
		strcpy(this->nomenclatura,nomenclatura);
		retorno = 0;
	}
	return retorno;
}

char* posAr_getNomenclatura(PosArancelaria* this,int* flagError)
{
	*flagError = -1;
	char* auxNomenclatura = NULL;
	if(this != NULL && flagError != NULL )
	{
		auxNomenclatura = this->nomenclatura;
		*flagError = 0;
	}
	return auxNomenclatura;
}

int posAr_setPorcentajeSeguro(PosArancelaria* this, float porcentajeSeguro)
{
	int retorno = -1;
	if(this != NULL && isFloatValue(porcentajeSeguro)==0 )
	{
		this->porcentajeSeguro = porcentajeSeguro;
		retorno = 0;
	}
	return retorno;
}

float posAr_getPorcentajeSeguro(PosArancelaria* this,int* flagError)
{
	*flagError = -1;
	float auxPorcentajeSeguro = -1;
	if(this != NULL && flagError != NULL )
	{
		auxPorcentajeSeguro=this->porcentajeSeguro;
		*flagError = 0;
	}
	return auxPorcentajeSeguro;
}

int posAr_setPorcentajeImportacion(PosArancelaria* this, float porcentajeImportacion)
{
	int retorno = -1;
	if(this != NULL && isFloatValue(porcentajeImportacion)==0 )
	{
		this->porcentajeImportacion = porcentajeImportacion;
		retorno = 0;
	}
	return retorno;
}

float posAr_getPorcentajeImportacion(PosArancelaria* this,int* flagError)
{
	*flagError = -1;
	float auxPorcentajeImportacion = -1;
	if(this != NULL && flagError != NULL )
	{
		auxPorcentajeImportacion=this->porcentajeImportacion;
		*flagError = 0;
	}
	return auxPorcentajeImportacion;
}

int posAr_setPorcentajeTasaEst(PosArancelaria* this, float porcentajeTasaEst)
{
	int retorno = -1;
	if(this != NULL && isFloatValue(porcentajeTasaEst)==0 )
	{
		this->porcentajeTasaEst = porcentajeTasaEst;
		retorno = 0;
	}
	return retorno;
}

float posAr_getPorcentajeTasaEst(PosArancelaria* this,int* flagError)
{
	*flagError = -1;
	float auxPorcentajeTasaEst = -1;
	if(this != NULL && flagError != NULL )
	{
		auxPorcentajeTasaEst=this->porcentajeTasaEst;
		*flagError = 0;
	}
	return auxPorcentajeTasaEst;
}

int posAr_setIdPosicionArancelaria(PosArancelaria* this, int idPosicionArancelaria)
{
	int retorno = -1;
	if(this != NULL && isIntValue(idPosicionArancelaria)==0 )
	{
		this->idPosicionArancelaria = idPosicionArancelaria;
		retorno = 0;
	}
	return retorno;
}

int posAr_getIdPosicionArancelaria(PosArancelaria* this,int* flagError)
{
	*flagError = -1;
	int auxIdPosicionArancelaria = -1;
	if(this != NULL && flagError != NULL )
	{
		auxIdPosicionArancelaria=this->idPosicionArancelaria;
		*flagError = 0;
	}
	return auxIdPosicionArancelaria;
}

int posAr_setTipoDeLicencia(PosArancelaria* this, int tipoDeLicencia)
{
	int retorno = -1;
	if(this != NULL && isIntValue(tipoDeLicencia)==0 )
	{
		this->tipoDeLicencia = tipoDeLicencia;
		retorno = 0;
	}
	return retorno;
}

int posAr_getTipoDeLicencia(PosArancelaria* this,int* flagError)
{
	*flagError = -1;
	int auxTipoDeLicencia = -1;
	if(this != NULL && flagError != NULL )
	{
		auxTipoDeLicencia =this->tipoDeLicencia;
		*flagError = 0;
	}
	return auxTipoDeLicencia;
}

/********************************************************************************************************************************/

static int contador=0;

/** \brief Setea el valor inicial del id obtenido de una lista.
 * \param LinkedList* pArrayListEmployee Lista para obtener los datos.
 * \return void
 */
int posAr_setearValorInicialDeId(Dictionary* pDictionaryPosArancelaria)
{
	PosArancelaria* pPos;
	LinkedList* listaAux;
	int id;
	int idMax;
	int size;
	int flagError;

	if(pDictionaryPosArancelaria != NULL)
	{
		listaAux = dict_getValues(pDictionaryPosArancelaria);
		size = ll_len(listaAux);
		for(int i=0;i<size;i++)
		{
			pPos = ll_get(listaAux, i);
			if(pPos != NULL)
			{
				id = posAr_getIdPosicionArancelaria(pPos, &flagError);
				if(i==0)
				{
					idMax = id;
				}
				else
				{
					if(id > idMax)
					{
						idMax = id;
					}
				}
			}
			contador = idMax;
		}
	}
	return idMax;
}

/** \brief Generador de ID
 * \param Void
 * \return int devulve el ID
 */
int posAr_generarId(void)
{
	contador++;
	return contador;
}
