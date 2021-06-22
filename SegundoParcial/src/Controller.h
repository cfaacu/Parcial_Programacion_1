/*
 * Controller.h
 *
 *  Created on: Jun 16, 2021
 *      Author: facu
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadArticuloFromText(char* path , Dictionary* pDictionaryArticulo);
int controller_addArticulo(Dictionary* pDictionaryArticulo, Dictionary* pDictionaryPosArancelaria,int idPosArancelariaMax);
int controller_editArticulo(Dictionary* pDictionaryArticulo, Dictionary* pDictionaryPosArancelaria, int idPosArancelariaMax);
int controller_removeArticulo(Dictionary* pDictionaryArticulo);
int controller_ListarArticulo(Dictionary* pDictionaryArticulo);
int controller_ListarArticulosLinkedList(LinkedList* pLista);
int controller_saveArticuloAsText(char* path , Dictionary* pDictionaryArticulo);

/*********************************************************************************************************************************/

int controller_loadPosArancelariaFromText(char* path , Dictionary* pDictionary);
int controller_addPosArancelaria(Dictionary* pDictionaryPosArancelaria);
int controller_editPosArancelaria(Dictionary* pDictionaryPosArancelaria);
int controller_removePosArancelaria(Dictionary* pDictionaryPosArancelaria, Dictionary* pDictionaryArticulo);
int controller_savePosArancelariaAsText(char* path , Dictionary* diccionarioPosArancelaria);
int controller_ListarPosArancelaria(Dictionary* pDictionaryPosArancelaria);

/**********************************************************************************************************************************/

int controller_loadMaritimoFromText(char* path , LinkedList* pListaMaritimo);
int controller_editMaritimo(LinkedList* pListaMaritimo);
int controller_saveMaritimoAsText(char* path , LinkedList* listaMaritimo);
int controller_ListarMaritimo(LinkedList* pListaMaritimo);

/**********************************************************************************************************************************/

int controller_loadAereoFromText(char* path , LinkedList* pListaAereo);
int controller_editAereo(LinkedList* pListaAereo);
int controller_saveAereoAsText(char* path , LinkedList* listaAereo);
int controller_ListarAereo(LinkedList* listaAereo);

#endif /* CONTROLLER_H_ */
