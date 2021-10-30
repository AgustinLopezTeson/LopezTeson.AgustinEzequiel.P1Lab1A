#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Fecha.h"
#include "Marca.h"
#include "TipoNote.h"
#include "Notebook.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "cliente.h"







int mostrarClientes(eCliente clientes[],int tam)
{

    int todoOk = 0;
    int flag = 1;
    if(clientes != NULL && tam > 0)
    {
        system("cls");
        printf("       *** Listado de Clientes ***      \n");
         printf("---------------------------------------------------------------\n");
        printf("   Id         Nombre    Sexo\n");
        printf("----------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(clientes[i].isEmpty == 0)
            {

               printf("%d       %s    %s",clientes[i].idCliente,clientes[i].nombre,clientes[i].sexo);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Clientes para mostrar");

        }
        todoOk=1;

    }

    return todoOk;

}

int traerCliente(eCliente clientes[], int tamCli, int idCliente , char descCliente[])
{
	int todoOk = 0;
	if(clientes!= NULL && tamCli > 0 && descCliente != NULL)
	{
		for(int i = 0; i < tamCli; i++)
		{
			if(clientes[i].idCliente == idCliente)
			{
				strcpy(descCliente, clientes[i].nombre);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}






