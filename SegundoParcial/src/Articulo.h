/*
 * Articulo.h
 *
 *  Created on: Jun 15, 2021
 *      Author: facu
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_

#include "Dictionary.h"

#define CODIGO_LEN 50
#define DESCRIPCION_LEN 50
#define PAIS_LEN 50
#define NOMBRE_LEN 50

typedef struct
{
	char codigo [CODIGO_LEN];
	char nombre [NOMBRE_LEN];
	char descripcion [DESCRIPCION_LEN];
	char paisDeFabricacion [PAIS_LEN];
	float valorFob;
	float peso;
	float ancho;
	float alto;
	float profundidad;
	int idPosicionArancelaria;
	int idArticulo;
}Articulo;

Articulo* art_new(void);
Articulo* art_newParametros(int idArticulo,char* codigo,char* nombre,char* descripcion,char* paisFabricacion,float valorFob,float peso, float ancho, float alto, float profundidad, int idPosicionArancelaria);
Articulo* art_newParametrosTxt(char* idArticulo,char* nombre,char* codigo,char* descripcion,char* paisDeFabricacion,char* valorFob,char* pesos, char* ancho, char* alto, char* profundidad, char* idPosicionArancelaria);

int art_delete(Articulo* this);

int art_setNombre(Articulo* this, char* nombre);
char* art_getNombre(Articulo* this,int* flagError);

int art_setCodigo(Articulo* this, char* codigo);
char* art_getCodigo(Articulo* this,int* flagError);

int art_setDescripcion(Articulo* this, char* descripcion);
char* art_getDescripcion(Articulo* this,int* flagError);

int art_setPaisFabricacion(Articulo* this, char* paisFabricacion);
char* art_getPaisFabricacion(Articulo* this,int* flagError);

int art_setValorFob(Articulo* this, float valorFob);
float art_getValorFob(Articulo* this,int* flagError);

int art_setPeso(Articulo* this, float peso);
float art_getPeso(Articulo* this,int* flagError);

int art_setAncho(Articulo* this, float ancho);
float art_getAncho(Articulo* this,int* flagError);

int art_setAlto(Articulo* this, float alto);
float art_getAlto(Articulo* this,int* flagError);

int art_setProfundidad(Articulo* this, float profundidad);
float art_getProfundidad(Articulo* this,int* flagError);

int art_setIdPosicionArancelaria(Articulo* this, int idPosicionArancelaria);
int art_getIdPosicionArancelaria(Articulo* this,int* flagError);

int art_setIdAereo(Articulo* this, int idAereo);
int art_getIdAereo(Articulo* this,int* flagError);

int art_setIdMaritimo(Articulo* this, int idMaritimo);
int art_getIdMaritimo(Articulo* this,int* flagError);

int art_setIdArticulo(Articulo* this, int idArticulo);
int art_getIdArticulo(Articulo* this,int* flagError);

int art_generarId(void);
void art_setearValorInicialDeId(Dictionary* pDictionaryArticulo);

#endif /* ARTICULO_H_ */
