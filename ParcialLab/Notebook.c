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


int inicializarNotebooks(eNotebook lista[], int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibreNotebook(eNotebook lista[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaNotebook(eNotebook lista[], int tam, eMarca marcas[], int tamMar, eTipo tipoNote[], int tamCol, int* nextId)
{
    int todoOk = 0;
    int indice;
    eNotebook auxNote;
    if (lista != NULL && tam > 0)
    {
        system("cls");
        printf("  ***Alta Auto*** \n\n");
        indice = buscarLibreNotebook(lista, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxNote.idNote=*nextId;

            printf("Ingrese Modelo: ");
            fflush(stdin);
            scanf("%s",&auxNote.modelo);

            mostrarMarcas(marcas,TAM_MAR);
            printf("Ingrese la marca: ");
            scanf("%d",&auxNote.idMarca);

            mostrarTipos(tipoNote,TAM_TIPO);
            printf("Ingrese el tipo: ");
            scanf("%d", &auxNote.idTipo);

            printf("Ingrese el precio: ");
            scanf("%d", &auxNote.precio);

            auxNote.isEmpty = 0;

            lista[indice] = auxNote;
            printf("Alta Exitosa !!! \n\n");
            system("pause");
            todoOk = 1;
        }

        (*nextId)++;
    }
    return todoOk;
}
int buscarNotebookId(eNotebook lista[], int tam, int id)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].idNote == id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}




int modificarNotebook(eNotebook lista[], int tam, eTipo tipoNote[], int tamNote, eMarca marcas[], int tamMar)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char salir;
    eNotebook auxNote;
    if (lista != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Modificar Notebook *** \n\n");

        mostrarNotebooks(lista,tam,marcas,tipoNote,tamNote,tamMar);
        printf("Ingrese id de la notebook: ");
        scanf("%d", &id);

        indice = buscarNotebookId(lista, tam, id);



        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {


            mostrarNotebook(lista[indice],marcas,tipoNote,tamNote,tamMar);


            do
            {
                switch ( menuDeModificaciones() )
                {
                case 1:

                    mostrarTipos(tipoNote,TAM_TIPO);
                    printf("Modificar Tipo: ");
                    scanf("%d",&auxNote.idTipo);
                    printf("Confirma cambio de tipo? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                       lista[indice].idTipo=auxNote.idTipo;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 2:
                    printf("Modificar precio: ");
                    scanf("%d", &auxNote.precio);
                    printf("Confirma cambio de precio? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].precio = auxNote.precio;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 3:
                    printf("Esta seguro que quiere salir? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir = toupper(salir);
                    if (salir == 'S')
                    {
                        seguir = 'n';
                    }
                    else
                    {
                        break;
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                }
                system("pause");
            }
            while(seguir == 's');

            todoOk = 1;

        }
    }
    return todoOk;
}




int bajaNotebook(eNotebook lista[], int tam,eTipo tipoNote[],int tamTipo,eMarca marcas[],int tamMarca)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    if(lista != NULL && tipoNote != NULL && marcas != NULL && tam > 0 && tamTipo > 0 && tamMarca > 0 )
    {
        system("cls");
        printf("---------------------------------------------\n");
        printf("       *** Baja Notebook ***      \n");
        printf("---------------------------------------------\n");

        mostrarNotebooks(lista,tam,marcas,tipoNote,tamTipo,tamMarca);


        printf("Ingrese el id de la notebook que quiere dar de baja: ");
        scanf("%d", &id);

        indice = buscarNotebookId(lista,tam,id);

        if(indice == -1)
        {
            printf("No existe una notebook con id: %d\n", id);
        }
        else
        {
            printf("\n\n");
            mostrarNotebook(lista[indice],marcas,tipoNote,tamTipo,tamMarca);
            printf("\n\n");
            printf("Confirma baja? (s para si): \n");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                printf("Auto dado de baja.\n");
                todoOk = 1;
            }
            else
            {
                printf("Se ha cancelado la baja \n");
            }
        }


}
return todoOk;
}

int mostrarNotebooks(eNotebook lista[],int tam, eMarca marcas[], eTipo tipoNote[], int tamTipo,int tamMarca)
{

    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && tipoNote != NULL && marcas != NULL && tam > 0 && tamTipo > 0 && tamMarca > 0 )
    {
        system("cls");
        printf("       *** Listado de Notebooks ***      \n");
         printf("---------------------------------------------------------------\n");
        printf("   Id          Marca       Modelo        Tipo       Precio\n");
        printf("----------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                ordenarNotebook(lista,tam);
                mostrarNotebook(lista[i],marcas,tipoNote,tamTipo,tamMarca);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Notebooks para mostrar, \n se debe dar de alta alguna notebook antes de poder mostrarlo.\n");

        }
        todoOk=1;

    }

    return todoOk;

}

void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], eTipo tipoNote[], int tamTipo,int tamMarca)
{


    char descTipo[21];
    char descMarca[21];

    traerTipo(tipoNote,tamTipo, unaNotebook.idTipo,descTipo);
    traerMarca(marcas,tamMarca, unaNotebook.idMarca,descMarca);


    printf("\n\n  %4d   %10s   %10s     %10s     $%5d    \n",
           unaNotebook.idNote,
           descMarca,
           unaNotebook.modelo,
           descTipo,
           unaNotebook.precio);


}

int ordenarNotebook(eNotebook lista[], int tam)
{
    int todoOk = 0;
    eNotebook auxNote;
    if(lista != NULL && tam > 0)
    {
        for(int i = 1 ; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(lista[i].idMarca > lista[j].idMarca ||
                        (lista[i].idMarca == lista[j].idMarca &&
                         lista[i].precio>lista[j].precio))
                {
                    auxNote = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxNote;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}



