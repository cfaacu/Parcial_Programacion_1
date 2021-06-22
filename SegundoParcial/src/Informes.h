/*
 * Informes.h
 *
 *  Created on: Jun 19, 2021
 *      Author: facu
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Aereo.h"
#include "Maritimo.h"

float info_CalcularBaseImponibleAereo(Articulo* pArticulo,Aereo* pAereo, PosArancelaria* pPosArancelaria);
float info_CalcularCostoAereo(Articulo* pArticulo,Aereo* pAereo);
float info_CalcularBaseImponibleMaritimo(Articulo* pArticulo,Maritimo* pMaritimo, PosArancelaria* pPosArancelaria);
float info_CalcularCostoMaritimo(Articulo* pArticulo,Maritimo* pMaritimo);
float info_calcularCostoArgentinoMaritimo(Articulo* pArticulo,PosArancelaria* pPosArancelaria,Maritimo* pMaritimo);
float info_listarArticulosConCostosFinales(Dictionary* pDictionaryArticulo,Dictionary* pDictionaryPosArancelaria, LinkedList* listaMaritima,LinkedList* listaAerea);
#endif /* INFORMES_H_ */
