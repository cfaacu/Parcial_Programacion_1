/*
 * Parser.h
 *
 *  Created on: Jun 16, 2021
 *      Author: facu
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_articuloFromText(FILE* pFile , Dictionary* pDictionaryArticulo);
int parser_posArancelariaFromText(FILE* pFile , Dictionary* pDictionaryPosArancelaria);
int parser_maritimoFromText(FILE* pFile , LinkedList* listaMaritimo);
int parser_aereoFromText(FILE* pFile , LinkedList* listaAereo);

#endif /* PARSER_H_ */
