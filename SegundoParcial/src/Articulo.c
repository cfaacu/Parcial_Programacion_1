/*
 * Articulo.c
 *
 *  Created on: Jun 15, 2021
 *      Author: facu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Dictionary.h"
#include "utn.h"
#include "Articulo.h"

Articulo* art_new(void)
{
	return (Articulo*) malloc(sizeof(Articulo));
}

Articulo* art_newParametros(int idArticulo,char* codigo,char* nombre,char* descripcion,char* paisFabricacion,float valorFob,float peso, float ancho, float alto, float profundidad, int idPosicionArancelaria)
{
	Articulo* auxArticulo = art_new();
	if(auxArticulo != NULL)
	{
		if  ( 	art_setIdArticulo(auxArticulo, idArticulo) < 0 ||
				art_setCodigo(auxArticulo,codigo) < 0 ||
				art_setNombre(auxArticulo, nombre) < 0 ||
				art_setDescripcion(auxArticulo, descripcion) < 0 ||
				art_setPaisFabricacion(auxArticulo, paisFabricacion) < 0 ||
				art_setValorFob(auxArticulo, valorFob) < 0 ||
				art_setPeso(auxArticulo, peso) < 0 ||
				art_setAncho(auxArticulo, ancho) < 0 ||
				art_setAlto(auxArticulo, alto) < 0 ||
				art_setProfundidad(auxArticulo, profundidad) < 0 ||
				art_setIdPosicionArancelaria(auxArticulo, idPosicionArancelaria) < 0)
		{
			art_delete(auxArticulo);
			auxArticulo = NULL;
		}
	}
	return auxArticulo;;
}

Articulo* art_newParametrosTxt(char* idArticulo,char* nombre,char* codigo,char* descripcion,char* paisDeFabricacion,char* valorFob,char* pesos, char* ancho, char* alto, char* profundidad, char* idPosicionArancelaria)
{
	Articulo* auxArticulo = art_new();
	if(auxArticulo != NULL)
	{
		if  (	art_setIdArticulo(auxArticulo, atoi(idArticulo)) < 0 ||
				art_setNombre(auxArticulo, nombre) < 0 ||
				art_setCodigo(auxArticulo, codigo) < 0 ||
				art_setDescripcion(auxArticulo, descripcion) < 0 ||
				art_setPaisFabricacion(auxArticulo, paisDeFabricacion) < 0 ||
				art_setValorFob(auxArticulo, atof(valorFob)) < 0 ||
				art_setPeso(auxArticulo, atof(pesos)) < 0 ||
				art_setAncho(auxArticulo, atof(ancho)) < 0 ||
				art_setAlto(auxArticulo, atof(alto)) < 0 ||
				art_setProfundidad(auxArticulo, atof(profundidad)) < 0 ||
				art_setIdPosicionArancelaria(auxArticulo, atoi(idPosicionArancelaria)) < 0)
		{
			art_delete(auxArticulo);
			auxArticulo = NULL;
		}
	}
	return auxArticulo;
}

int art_delete(Articulo* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int art_setNombre(Articulo* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && isName(nombre)==0 )
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

char* art_getNombre(Articulo* this,int* flagError)
{
	*flagError = -1;
	char* auxNombre = NULL;
	if(this != NULL && flagError != NULL )
	{
		auxNombre = this->nombre;
		*flagError = 0;
	}
	return auxNombre;
}

int art_setCodigo(Articulo* this, char* codigo)
{
	int retorno = -1;
	if(this != NULL && codigo != NULL && utn_isDNI(codigo)==0 )
	{
		strcpy(this->codigo,codigo);
		retorno = 0;
	}
	return retorno;
}

char* art_getCodigo(Articulo* this,int* flagError)
{
	*flagError = -1;
	char* auxCodigo= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxCodigo = this->codigo;
		*flagError = 0;
	}
	return auxCodigo;
}

int art_setDescripcion(Articulo* this, char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL && utn_isDNI(descripcion)==0 )
	{
		strcpy(this->descripcion,descripcion);
		retorno = 0;
	}
	return retorno;
}

char* art_getDescripcion(Articulo* this,int* flagError)
{
	*flagError = -1;
	char* auxDescripcion = NULL;
	if(this != NULL && flagError != NULL )
	{
		auxDescripcion = this->descripcion;
		*flagError = 0;
	}
	return auxDescripcion;
}

int art_setPaisFabricacion(Articulo* this, char* paisFabricacion)
{
	int retorno = -1;
	if(this != NULL && paisFabricacion != NULL && isName(paisFabricacion)==0 )
	{
		strcpy(this->paisDeFabricacion,paisFabricacion);
		retorno = 0;
	}
	return retorno;
}

char* art_getPaisFabricacion(Articulo* this,int* flagError)
{
	*flagError = -1;
	char* auxPaisFabricacion= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxPaisFabricacion = this->paisDeFabricacion;
		*flagError = 0;
	}
	return auxPaisFabricacion;
}

int art_setValorFob(Articulo* this, float valorFob)
{
	int retorno = -1;
	if(this != NULL && isFloatValue(valorFob)==0 )
	{
		this->valorFob = valorFob;
		retorno = 0;
	}
	return retorno;
}

float art_getValorFob(Articulo* this,int* flagError)
{
	*flagError = -1;
	float auxValorFob = -1;
	if(this != NULL && flagError != NULL )
	{
		auxValorFob=this->valorFob;
		*flagError = 0;
	}
	return auxValorFob;
}

int art_setPeso(Articulo* this, float peso)
{
	int retorno = -1;
	if(this != NULL && isFloatValue(peso)==0 )
	{
		this->peso = peso;
		retorno = 0;
	}
	return retorno;
}

float art_getPeso(Articulo* this,int* flagError)
{
	*flagError = -1;
	float auxPeso = -1;
	if(this != NULL && flagError != NULL )
	{
		auxPeso=this->peso;
		*flagError = 0;
	}
	return auxPeso;
}

int art_setAncho(Articulo* this, float ancho)
{
	int retorno = -1;
	if(this != NULL && isFloatValue(ancho)==0)
	{
		this->ancho = ancho;
		retorno = 0;
	}
	return retorno;
}

float art_getAncho(Articulo* this,int* flagError)
{
	*flagError = -1;
	float auxAncho = -1;
	if(this != NULL && flagError != NULL )
	{
		auxAncho=this->ancho;
		*flagError = 0;
	}
	return auxAncho;
}

int art_setAlto(Articulo* this, float alto)
{
	int retorno = -1;
	if(this != NULL && isFloatValue(alto)==0)
	{
		this->alto = alto;
		retorno = 0;
	}
	return retorno;
}

float art_getAlto(Articulo* this,int* flagError)
{
	*flagError = -1;
	float auxAlto = -1;
	if(this != NULL && flagError != NULL )
	{
		auxAlto=this->alto;
		*flagError = 0;
	}
	return auxAlto;
}

int art_setProfundidad(Articulo* this, float profundidad)
{
	int retorno = -1;
	if(this != NULL && isFloatValue(profundidad)==0)
	{
		this->profundidad = profundidad;
		retorno = 0;
	}
	return retorno;
}

float art_getProfundidad(Articulo* this,int* flagError)
{
	*flagError = -1;
	float auxProfundidad = -1;
	if(this != NULL && flagError != NULL )
	{
		auxProfundidad=this->profundidad;
		*flagError = 0;
	}
	return auxProfundidad;
}

int art_setIdPosicionArancelaria(Articulo* this, int idPosicionArancelaria)
{
	int retorno = -1;
	if(this != NULL && isIntValue(idPosicionArancelaria)==0)
	{
		this->idPosicionArancelaria = idPosicionArancelaria;
		retorno = 0;
	}
	return retorno;
}

int art_getIdPosicionArancelaria(Articulo* this,int* flagError)
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

int art_setIdArticulo(Articulo* this, int idArticulo)
{
	int retorno = -1;
	if(this != NULL && isIntValue(idArticulo)==0)
	{
		this->idArticulo = idArticulo;
		retorno = 0;
	}
	return retorno;
}

int art_getIdArticulo(Articulo* this,int* flagError)
{
	*flagError = -1;
	int auxIdArticulo = -1;
	if(this != NULL && flagError != NULL )
	{
		auxIdArticulo=this->idArticulo;
		*flagError = 0;
	}
	return auxIdArticulo;
}
/********************************************************************************************************************************/

static int contador=0;

/** \brief Setea el valor inicial del id obtenido de una lista.
 * \param LinkedList* pArrayListEmployee Lista para obtener los datos.
 * \return void
 */
void art_setearValorInicialDeId(Dictionary* pDictionaryArticulo)
{
	Articulo* pArt;
	LinkedList* listaAux;
	int id;
	int idMax;
	int size;
	int flagError;

	if(pDictionaryArticulo != NULL)
	{
		listaAux = dict_getValues(pDictionaryArticulo);
		size = ll_len(listaAux);
		for(int i=0;i<size;i++)
		{
			pArt = ll_get(listaAux, i);
			if(pArt != NULL)
			{
				id = art_getIdArticulo(pArt, &flagError);
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
}

/** \brief Generador de ID
 * \param Void
 * \return int devulve el ID
 */
int art_generarId(void)
{
	contador++;
	return contador;
}
