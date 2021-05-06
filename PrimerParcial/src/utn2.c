/*
 * utn2.c
 *
 *  Created on: 25 mar. 2021
 *      Author: Pato
 */


#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
static int getFloat(float* pResultado);
static int esNumericaEnteraPositiva(char* cadena);
int isTipo(char* tipo);
void utn_hacerMinuscula(char* string, int limite);
/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un m�ximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tama�o de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
static int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		__fpurge(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}
/**
 * \brief Agarra y Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer)==0)
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
/**
* \brief Verifica si la cadena ingresada es numerica, entera y positiva
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica, entera y postiva, y -1 (falso) si no lo es
*/
int esNumerica(char* cadena)
{
	int i=0;
	int retorno = -1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] == '-' || cadena[i] == '.') || (cadena[i] >= '0' || cadena[i] <= '9'))
			{
				retorno = 0;
				i++;
			}
			else
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}
/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es
*/
static int esNumericaEnteraPositiva(char* cadena)
{
	int i=0;
	int retorno = -1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] >= '0' && cadena[i] <= '9')
			{
				retorno = 0;
				i++;
			}
			else
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \param reintentos ES la cantidad de reintentos, no puede ser 0 o menor
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;
	while(reintentos>0)
	{
		__fpurge(stdin);
		reintentos--;
		printf("%s",mensaje);
		if(getInt(&bufferInt) == 0)
		{
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Agarra y Verifica si la cadena ingresada es numerica flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer)==0)
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero Float al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \param reintentos ES la cantidad de reintentos, no puede ser 0 o menor
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos)
{
	float bufferInt;
	int retorno = -1;
	while(reintentos>0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferInt) == 0)
		{
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Solicita al usuario un string
 * \param pArray Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param limite El tama�o del Array
 * \param mensaje El mensaje por consola
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getString(char* pArray,int limite,char* mensaje)
{
	int retorno = -1;
	char buffer[800];
	if(pArray != NULL && limite > 0 && mensaje != NULL)
	{
		printf("%s",mensaje);
		if(myGets(buffer,sizeof(buffer))==0)
		{
			strncpy(pArray,buffer,limite);
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Recibe un string y valida que sea un nombre
 * \param char Puntero al string
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int isName(char* nombre)
{
	int retorno = -1;
	int i=0;

	if(nombre != NULL)
	{
		while(nombre[i] != '\0')
		{
			if((nombre[i] >= 'A' && nombre[i] <= 'Z') || (nombre[i] >= 'a' && nombre[i] <= 'z'))
			{
				nombre[0]=toupper(nombre[0]);
				retorno = 0;
				i++;
			}
			else
			{
				retorno = -1;
				break;
			}

		}
	}

	return retorno;
}

/**
 * \brief Pide al usuario un string y valida si es un nombre
 * \param char Puntero al string
 * \param limite El tama�o del string
 * \param mensaje Puntero al mensaje que muestra por pantalla
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getName(char* nombre,int limite,char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar[limite];

	if(nombre != NULL && limite > 0 && mensaje != NULL)
	{
		while(reintentos>0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(myGets(bufferChar,limite)==0 && isName(bufferChar)==0)
			{
				strncpy(nombre,bufferChar,limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
		}

	}
	return retorno;
}

/**
 * \brief Pide al usuario un string y valida si es una direccion
 * \param char Puntero al string
 * \param limite El tama�o del string
 * \param mensaje Puntero al mensaje que muestra por pantalla
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getDireccion(char* direccion,int limite,char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar[limite];

	if(direccion != NULL && limite > 0 && mensaje != NULL)
	{
		while(reintentos>0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(myGets(bufferChar,limite)==0 && isDireccion(bufferChar)==0)
			{
				strncpy(direccion,bufferChar,limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
		}

	}
	return retorno;
}

/**
 * \brief Pide al usuario un caracter
 * \param char Puntero al string
 * \param pTexto pide un texto, generalmente utilizado para "Ingresar un caracter".
 * \param pTextoError, pide un mensaje de error
 * \param minimo pide el minimo para el rango
 * \param maximi pide el maximo para el rango
 * \param reintentos pide la cantidad de reintentos del usuario
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_pedirUnCaracter(char* pCaracter, char* pTexto, char* pTextoError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

		if (pCaracter !=NULL && pTexto !=NULL && pTextoError !=NULL && minimo <= maximo && reintentos >=0)
		{
			retorno = -2;

			do
			{
				printf("%s",pTexto);
				fflush(stdin);
				bufferChar = getchar();
				bufferChar = tolower(bufferChar);
				if(bufferChar >= minimo && bufferChar <= maximo)
				{
					retorno = 0;
					*pCaracter = bufferChar;
					break;
				}
				printf("%s",pTextoError);
				reintentos--;
			}while(reintentos >= 0);
		}
		return retorno;
}

int utn_getTipo(char* pTipo, int limite, char* pMensaje, char* pMensajeError,int reintentos)
{
	int retorno = -1;
	char bufferTipo[1860];

	if(pTipo != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		while(reintentos>0)
		{
			reintentos--;
			printf("%s",pMensaje);
			if(myGets(bufferTipo,limite)==0 && isTipo(bufferTipo)==0)
			{
				strncpy(pTipo,bufferTipo,limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",pMensajeError);
			}
		}
	}

	return retorno;
}

int isTipo(char* tipo)
{
	int retorno = -1;
	char bufferTipo[50];
	if(tipo != NULL)
	{
		strncpy(bufferTipo,tipo,sizeof(bufferTipo));
		utn_hacerMinuscula(bufferTipo, sizeof(bufferTipo));
		if(strcmp(bufferTipo,"perro")==0 || strcmp(bufferTipo,"gato")==0  || strcmp(bufferTipo,"raro")==0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getSexo(char* sexo,char* pMensaje, char* pMensajeError,int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(sexo != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		while(reintentos>0)
		{
			reintentos--;
			printf("%s",pMensaje);
			__fpurge(stdin);
			bufferChar = getchar();
			bufferChar = tolower(bufferChar);
			if(bufferChar == 'f' || bufferChar == 'm')
			{
				retorno = 0;
				*sexo = bufferChar;
				break;
			}
			else
			{
				printf("%s",pMensajeError);
			}
		}

	}


	return retorno;
}

void utn_hacerMinuscula(char* string, int limite)
{
	if(string!=NULL && limite>=0)
	{
		for(int i=0;i<=limite;i++)
		{
			string[i]=tolower(string[i]);
		}
	}
}

int isTamanio(char* tamanio)
{
	int retorno = -1;
	char bufferTamanio[50];
	if(tamanio != NULL)
	{
		strncpy(bufferTamanio,tamanio,sizeof(bufferTamanio));
		utn_hacerMinuscula(bufferTamanio,sizeof(bufferTamanio));
		if(strcmp(bufferTamanio,"chico")==0 || strcmp(bufferTamanio,"mediano")==0  || strcmp(bufferTamanio,"grande")==0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getTamanio(char* pTamanio, int limite, char* pMensaje, char* pMensajeError,int reintentos)
{
	int retorno = -1;
	char bufferTamanio[1860];

	if(pTamanio != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		while(reintentos>0)
		{
			reintentos--;
			printf("%s",pMensaje);
			if(myGets(bufferTamanio,limite)==0 && isTamanio(bufferTamanio)==0)
			{
				strncpy(pTamanio,bufferTamanio,limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",pMensajeError);
			}
		}

	}

	return retorno;
}

int isDescripcion(char* nombre)
{
	int retorno = -1;
	int i=0;

	if(nombre != NULL)
	{
		while(nombre[i] != '\0')
		{
			if((nombre[i] > 'A' && nombre[i] > 'Z') || (nombre[i] > 'a' && nombre[i] < 'z'))
			{
				retorno = 0;
				i++;
			}
			else
			{
				break;
			}

		}
	}

	return retorno;
}

int utn_getDescripcion(char* nombre,int limite,char* mensaje,char* mensajeError)
{
	int retorno = -1;
	char bufferChar[limite];

	if(nombre != NULL && limite > 0 && mensaje != NULL)
	{
		printf("%s",mensaje);
		if(myGets(bufferChar,limite)==0 && isName(bufferChar)==0)
		{
			strncpy(nombre,bufferChar,limite);
			retorno = 0;
		}
		else
		{
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

int utn_mayusPrimerLetra(char* string)
{
	int retorno = -1;
	if(string!=NULL)
	{
		retorno = 0;
		string[0]=toupper(string[0]);
	}
	return retorno;
}

int utn_isDNI(char *dni)
{
	int retorno =-1;

	if(dni!=NULL)
	{
		if(strlen(dni)>5 && strlen(dni)<10)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int utn_getDNI(char* pDNI, int limite, char* pMensaje, char* pMensajeError,int reintentos)
{
	int retorno = -1;
	char bufferDNI[9];
	if(pDNI != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		while(reintentos>0)
		{
			reintentos--;
			printf("%s",pMensaje);
			if(myGets(bufferDNI, limite)==0 && esNumericaEnteraPositiva(bufferDNI)==1 && utn_isDNI(bufferDNI)==0)
			{
				strncpy(pDNI,bufferDNI,limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",pMensajeError);
			}

		}
	}
	return retorno;
}

/**
 * \brief Recibe un string y valida que sea una direccion
 * \param char Puntero al string
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int isDireccion(char* direccion)
{
	int retorno = -1;
	int i=0;

	if(direccion != NULL)
	{
		while(direccion[i] != '\0')
		{
			if((direccion[i] == '@' || direccion[i] == '%'))
			{
				retorno = -1;
				break;
			}
			else
			{
				direccion[0]=toupper(direccion[0]);
				retorno = 0;
				i++;
			}

		}
	}

	return retorno;
}

int utn_isCuit(char *pCuit)
{
	int retorno = -1;
		int i=0;

		if(pCuit != NULL)
		{
			while(pCuit[i] != '\0')
			{
				if((pCuit[i] >= '0' && pCuit[i] <= '9') && (strlen(pCuit)>=6 && strlen(pCuit)<=11))
				{
					retorno = 0;
					i++;
					break;
				}
				else
				{
					retorno = -1;
					break;
				}

			}
		}

		return retorno;
}

/**
 * \brief Pide al usuario un string y valida si es un nombre
 * \param char Puntero al string
 * \param limite El tama�o del string
 * \param mensaje Puntero al mensaje que muestra por pantalla
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getCuit(char* nombre,int limite,char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar[limite];

	if(nombre != NULL && limite > 0 && mensaje != NULL)
	{
		while(reintentos>0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(myGets(bufferChar,limite)==0 && utn_isCuit(bufferChar)==0)
			{
				strncpy(nombre,bufferChar,limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
		}

	}
	return retorno;
}


int utn_isEstado(char *pEstado)
{
	int retorno = -1;
	if(pEstado!=NULL)
	{
		utn_hacerMinuscula(pEstado, sizeof(pEstado));
		if(strcmp(pEstado,"pendiente")==0 || strcmp(pEstado,"cobrada")==0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int utn_getEstado(char* pEstado,int limite, char* mensaje, char* mensajeError,int reintentos)
{
	int retorno = -1;
	char buffer_estado[limite];

	if(pEstado!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos > 0)
	{
		do
		{
			printf("%s",mensaje);
			if(myGets(buffer_estado, sizeof(buffer_estado))==0 && utn_isEstado(buffer_estado)==0)
			{
				strncpy(pEstado,buffer_estado,limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos--;
		}
		while(reintentos>0);

	}

	return retorno;
}
