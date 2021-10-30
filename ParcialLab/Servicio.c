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

int mostrarServicios( eServicio servicios[], int tam )
{
    int todoOk = 0;
    if (servicios != NULL && tam > 0 )
    {
        printf("      *** Listado de tipos de Servicios  *** \n\n");
        printf("  Id         Descripcion               Precio \n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %5d       %-10s              $%5d \n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int traerServicio(eServicio servicios[], int tamSer, int idServ , char descServ[])
{
	int todoOk = 0;
	if(servicios!= NULL && tamSer > 0 && descServ != NULL)
	{
		for(int i = 0; i < tamSer; i++)
		{
			if(servicios[i].id == idServ)
			{
				strcpy(descServ, servicios[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
