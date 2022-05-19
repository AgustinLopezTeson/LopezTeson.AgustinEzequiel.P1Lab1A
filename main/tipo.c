#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#include "tipo.h"
#include "mascota.h"

#define TAM 20
#define TAMTIPO 5
#define TAMCOL 5
#define TAMSER 3


int mostrarTipos(Tipo tipos[], int tam)
{
    int todoOk = 0;
    if (tipos != NULL && tam > 0 )
    {
        system("cls");
        printf("      *** Listado de tipos *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n",tipos[i].id,tipos[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}


int traerTipo(Tipo tipos[], int tamTipo, int idTipo, char descTipo[])
{
        int todoOk = 0;
    if(tipos != NULL && tamTipo > 0 && descTipo != NULL){

         for(int i= 0; i < tamTipo; i++){

            if( tipos[i].id == idTipo){
                strcpy( descTipo, tipos[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}
