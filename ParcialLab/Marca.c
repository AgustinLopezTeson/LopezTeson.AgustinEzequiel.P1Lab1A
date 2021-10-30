#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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


int mostrarMarcas( eMarca marcas[], int tam )
{
    int todoOk = 0;
    if (marcas != NULL && tam > 0 )
    {
        system("cls");
        printf("      *** Listado de Marcas *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n",marcas[i].idMarca,marcas[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int traerMarca(eMarca marcas[], int tamMarca, int idMarca , char descMarc[])
{
	int todoOk = 0;
	if(marcas!= NULL && tamMarca > 0 && descMarc != NULL)
	{
		for(int i = 0; i < tamMarca; i++)
		{
			if(marcas[i].idMarca == idMarca)
			{
				strcpy(descMarc, marcas[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
