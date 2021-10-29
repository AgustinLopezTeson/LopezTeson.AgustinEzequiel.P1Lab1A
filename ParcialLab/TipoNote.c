#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Fecha.h"
#include "Marca.h"
#include "TipoNote.h"
#include "Notebook.h"
#include "Servicio.h"
#include "Trabajo.h"

#define TAM_MAR 5
#define TAM_TIPO 4
#define TAM 100
#define TAM_SER 4


int mostrarTipos( eTipo tipoNote[], int tam )
{
    int todoOk = 0;
    if (tipoNote != NULL && tam > 0 )
    {
        system("cls");
        printf("      *** Listado de tipos *** \n\n");
        printf("  Id         Descripcion\n\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n",tipoNote[i].idModelo,tipoNote[i].nombreNote);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int validarTipo( int id, eTipo tipoNote[], int tamTipo )
{
    int esValido = 0;
    if ( tipoNote != NULL && tamTipo > 0)
    {
        for (int i = 0; i < tamTipo; i++)
        {
            if (id == tipoNote[i].idModelo)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}


int traerTipo(eTipo tipoNote[], int tam, int idTipo, char descTipo[])
{
	int todoOk = 0;
	if(tipoNote != NULL && tam > 0 && descTipo != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(tipoNote[i].idModelo == idTipo)
			{
				strcpy(descTipo, tipoNote[i].nombreNote);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
