/*
 * Maritimo.h
 *
 *  Created on: Jun 16, 2021
 *      Author: facu
 */

#ifndef MARITIMO_H_
#define MARITIMO_H_

typedef struct{
	float mtsCubicos;
	float precio;
}Maritimo;

Maritimo* mar_new(void);
Maritimo* mar_newParam(float mtsCubicos, float precio, int idMaritimo);
Maritimo* mar_newParamTxt(char* mtsCubicos, char* precio);
int mar_delete(Maritimo* this);

int mar_setMtsCubicos(Maritimo* this, float mtsCubicos);
float mar_getMtsCubicos(Maritimo* this,int* flagError);

int mar_setPrecio(Maritimo* this, float precio);
float mar_getPrecio(Maritimo* this,int* flagError);

#endif /* MARITIMO_H_ */
