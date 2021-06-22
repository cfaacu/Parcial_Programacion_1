/*
 * Aereo.h
 *
 *  Created on: Jun 16, 2021
 *      Author: facu
 */

#ifndef AEREO_H_
#define AEREO_H_

typedef struct{
	float constVolum;
	float precio;
}Aereo;

Aereo* aer_new(void);
Aereo* aer_newParam(float constVolum, float precio, int idAereo);
Aereo* aer_newParamTxt(char* constVolum, char* precio);
int aer_delete(Aereo* this);

int aer_setConstVolum(Aereo* this, float constVolum);
float aer_getConstVolum(Aereo* this,int* flagError);

int aer_setPrecio(Aereo* this, float precio);
float aer_getPrecio(Aereo* this,int* flagError);

#endif /* AEREO_H_ */
