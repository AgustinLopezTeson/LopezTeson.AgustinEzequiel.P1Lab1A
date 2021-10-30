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

int altaNotebook(eNotebook lista[], int tam, eMarca marcas[], int tamMar, eTipo tipoNote[], int tamTipo, int* nextId)
{
    int todoOk = 0;
    int indice;
    eNotebook auxNote;
    if (lista != NULL && tam > 0)
    {
        system("cls");
        printf("  ***Alta Notebook*** \n\n");
        indice = buscarLibreNotebook(lista, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxNote.idNote=*nextId;


            int mostrarClientes(clientes,TAM_CLI);

            printf("Eliga el ID cliente (Desde el 500):");
            scanf("%d", &auxNote.idCliente);
            while(auxNote.idCliente<500)
            {
                printf("error. id ingresado no valido\n");
                printf("Ingrese id del tipo que desea  : ");
                scanf("%d", &auxNote.idCliente);
            }
            printf("Ingrese Modelo: ");
            fflush(stdin);
            scanf("%s",&auxNote.modelo);

            mostrarMarcas(marcas,TAM_MAR);
            printf("Ingrese la marca: ");
            scanf("%d",&auxNote.idMarca);
            while(auxNote.idMarca<999|| auxNote.idMarca>1005)
            {
                printf("error. id ingresado no valido\n");
                printf("Ingrese id del tipo que desea  : ");
                scanf("%d", &auxNote.idMarca);
            }

            mostrarTipos(tipoNote,TAM_TIPO);
            printf("Ingrese el tipo: ");
            scanf("%d", &auxNote.idTipo);
            while(auxNote.idTipo<4999|| auxNote.idTipo>5005)
            {
                printf("error. id ingresado no valido\n");
                printf("Ingrese id del tipo que desea  : ");
                scanf("%d", &auxNote.idTipo);
            }
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




int modificarNotebook(eNotebook lista[], int tam, eTipo tipoNote[], int tamNote, eMarca marcas[], int tamMar,eCliente clientes[], int tamCli)
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

        mostrarNotebooks(lista,tam,marcas,tipoNote,tamNote,tamMar,clientes,tamCli);
        printf("Ingrese id de la notebook: ");
        scanf("%d", &id);

        indice = buscarNotebookId(lista, tam, id);



        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {


            mostrarNotebook(lista[indice],marcas,tipoNote,tamNote,tamMar,clientes,tamCli);


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




int bajaNotebook(eNotebook lista[], int tam,eTipo tipoNote[],int tamTipo,eMarca marcas[],int tamMarca,eCliente clientes[],int tamCli)
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

        mostrarNotebooks(lista,tam,marcas,tipoNote,tamTipo,tamMarca,clientes,tamCli);


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
            mostrarNotebook(lista[indice],marcas,tipoNote,tamTipo,tamMarca,clientes,tamCli);
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

int mostrarNotebooks(eNotebook lista[],int tam, eMarca marcas[], eTipo tipoNote[], int tamTipo,int tamMarca,eCliente clientes[], int tamCli)
{

    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && tipoNote != NULL && marcas != NULL && tam > 0 && tamTipo > 0 && tamMarca > 0 )
    {
        system("cls");
        printf("       *** Listado de Notebooks ***      \n");
        printf("------------------------------------------------------------------------------\n");
        printf("   Id         Cliente           Marca       Modelo        Tipo       Precio\n");
        printf("-------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                ordenarNotebook(lista,tam);
                mostrarNotebook(lista[i],marcas,tipoNote,tamTipo,tamMarca,clientes,tamCli);
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

void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], eTipo tipoNote[], int tamTipo,int tamMarca, eCliente clientes[], int tamCli)
{


    char descTipo[21];
    char descMarca[21];
    char descCliente[21];

    traerTipo(tipoNote,tamTipo, unaNotebook.idTipo,descTipo);
    traerMarca(marcas,tamMarca, unaNotebook.idMarca,descMarca);
    traerCliente(clientes,tamCli,unaNotebook.idCliente,descCliente);

    printf("\n\n  %4d   %10s   %10s     %10s     %10s     $%5d \n",

           unaNotebook.idNote,
           descCliente,
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


int mostrarNotebookTipo(eNotebook lista[],int tam,eMarca marcas[], eTipo tipoNote[], int tamTipo,int tamMar, eCliente clientes[], int tamCli)
{
    int todoOk=0;
    int flag=1;

    if(lista != NULL && tipoNote != NULL && marcas != NULL && tam > 0 && tamTipo > 0 && tamMar > 0 )
    {
        int idTipo;
        char descTipo[20];



        mostrarTipos(tipoNote,tamTipo);
        printf("\n\n");
        printf("Ingrese el id del tipo que desea  : ");
        scanf("%d", &idTipo);
        while(idTipo<5000||idTipo>5004)
        {
            printf("error. id ingresado no valido\n");
            printf("Ingrese id del tipo que desea  : ");
            scanf("%d", &idTipo);
        }

        printf("\n\n");

        traerTipo(tipoNote,tamTipo,idTipo,descTipo);

        printf("       *** Listado de Notebooks de tipo  %s***      \n",descTipo);
        printf("------------------------------------------------------------------------------\n");
        printf("   Id         Cliente           Marca       Modelo        Tipo       Precio\n");
        printf("-------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idTipo==idTipo)
            {
                mostrarNotebook(lista[i],marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay notebooks para mostrar de ese tipo.\n");

        }
        todoOk=1;
    }

    return todoOk;


}

int mostrarNoteMarca(eNotebook lista[],int tam,eMarca marcas[], eTipo tipoNote[], int tamTipo,int tamMar,eCliente clientes[],int tamCli)
{
    int todoOk=0;
    int flag=1;

    if(lista != NULL && tipoNote != NULL && marcas != NULL && tam > 0 && tamTipo > 0 && tamMar > 0 )
    {
        int idMarca;
        char descMarca[20];



        mostrarMarcas(marcas,tamMar);
        printf("Ingrese el id de la marca: ");
        fflush(stdin);
        scanf("%d", &idMarca);

        while(idMarca<1000||idMarca>1004)
        {
            printf("error. Ingrese una marca que este en la lista.\n");
            printf("Vuelva a ingresar el id de marca a buscar: ");
            fflush(stdin);
            scanf("%d", &idMarca);
        }

       traerMarca(marcas,tamMar,idMarca,descMarca);

        printf("\n\n");



        printf("       *** Listado de Notebooks de marca %s***      \n",descMarca);
        printf("------------------------------------------------------------------------------\n");
        printf("   Id         Cliente           Marca       Modelo        Tipo       Precio\n");
        printf("-------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idMarca==idMarca)
            {
                mostrarNotebook(lista[i],marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay notebooks para mostrar de esa marca.\n");

        }
        todoOk=1;
    }

    return todoOk;


}
int mostrarNotebookMarca(eNotebook lista[],int tam,eMarca marcas[], eTipo tipoNote[], int tamTipo,int tamMar,eCliente clientes[],int tamCli)
{
    int todoOk=0;

        int flagCompaq=1;
        int flagAcer=1;
        int flagAsus=1;
        int flagHP= 1;

    if(lista !=NULL&&marcas!=NULL&&tipoNote!=NULL&&tam>0&&tamTipo>0&&tamMar>0)
    {
        printf("\n\n");
        printf("       *** Listado de Notebook de marca Compaq***      \n");
       printf("------------------------------------------------------------------------------\n");
        printf("   Id         Cliente           Marca       Modelo        Tipo       Precio\n");
        printf("-------------------------------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idMarca==1000)
            {
                printf("\n");
                mostrarNotebook(lista[i],marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);
                flagCompaq = 0;

            }
        }

        if(flagCompaq)
        {
            printf("\n\n");
            printf("No hay notebooks Compaq\n\n");
        }

        printf("\n\n");

        printf("       *** Listado de notebook Asus***      \n");
       printf("------------------------------------------------------------------------------\n");
        printf("   Id         Cliente           Marca       Modelo        Tipo       Precio\n");
        printf("-------------------------------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idMarca==1001)
            {
                printf("\n");
                mostrarNotebook(lista[i],marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);
                flagAsus = 0;

            }
        }



        if(flagAsus)
        {
            printf("\n\n");
            printf("No hay notebooks Asus\n\n");
        }

         printf("\n\n");

        printf("       *** Listado de notebook Acer***      \n");
       printf("------------------------------------------------------------------------------\n");
        printf("   Id         Cliente           Marca       Modelo        Tipo       Precio\n");
        printf("-------------------------------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idMarca==1002||lista[i].idMarca==1003)
            {
                printf("\n");
                mostrarNotebook(lista[i],marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);
                flagAcer = 0;

            }
        }



        if(flagAcer)
        {
            printf("\n\n");
            printf("No hay notebooks Acer\n\n");
        }
         printf("\n\n");

        printf("       *** Listado de notebook Hp***      \n");
       printf("------------------------------------------------------------------------------\n");
        printf("   Id         Cliente           Marca       Modelo        Tipo       Precio\n");
        printf("-------------------------------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idMarca==1004)
            {
                printf("\n");
                mostrarNotebook(lista[i],marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);
                flagAsus = 0;

            }
        }



        if(flagHP)
        {
            printf("\n\n");
            printf("No hay notebooks HP\n\n");
        }
        todoOk=1;
    }

    return todoOk;



}

int mostrarNotebookTipoMarca(eNotebook lista[],int tam,eMarca marcas[], eTipo tipoNote[], int tamTipo,int tamMar,eCliente clientes[],int tamCli)
{
    int todoOk=0;
    int flag=1;

    if(lista != NULL && tipoNote != NULL && marcas != NULL && tam > 0 && tamTipo > 0 && tamMar > 0 )
    {
        int idMarca;
        char descMarca[20];
        int idTipo;
        char descTipo[20];
        int contador=0;



        mostrarMarcas(marcas,tamMar);
        printf("Ingrese el id de la marca a buscar: ");
        fflush(stdin);
        scanf("%d", &idMarca);

        while(idMarca<1000||idMarca>1004)
        {
            printf("Invalido. Ingrese una marca que este en la lista.\n");
            printf("Reingresar el id de marca a buscar: ");
            fflush(stdin);
            scanf("%d", &idMarca);
        }

        traerMarca(marcas,tamMar,idMarca,descMarca);

        printf("\n\n");
        mostrarTipos(tipoNote,tam);
        printf("\n\n");
        printf("Ingrese id del tipo que desea buscar : ");
        scanf("%d", &idTipo);
        while(idTipo<5000||idTipo>5004)
        {
            printf("Invalido. id ingresado no valido\n");
            printf("Ingrese id del tipo que desea buscar : ");
            scanf("%d", &idTipo);
        }
        traerTipo(tipoNote,tamTipo,idTipo,descTipo);
        printf("\n\n");


        system("cls");
        printf("       *** Cantidad de Notes de marca %s y de tipo %s***      \n",descMarca,descTipo);
        printf("---------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idMarca==idMarca&&lista[i].idTipo==idTipo)
            {
                contador++;
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay notebooks de esa marca y tipo.\n\n\n");

        }
        else
        {
            printf("Hay un total de %d notebooks de marca %s y detipo %s\n\n",contador,descMarca,descTipo);

        }
        todoOk=1;
    }

    return todoOk;


}

int informarMarcasMasElegidas(eNotebook lista[],int tam,eMarca marcas[],int tamMar)
{


    int todoOk= 0;
    int contadores[5]= {0};
    int mayorCantidadMarca;

    if(lista != NULL  && marcas != NULL && tam > 0  && tamMar > 0)
    {

        printf("  *** Informe marca mas elegida ***\n");
        printf("-----------------------------------------\n");


        for(int i=0; i<tamMar; i++)
        {


            for(int j=0; j<tam; j++)
            {
                if(lista[j].idMarca==marcas[i].idMarca&&lista[j].isEmpty==0)
                {
                    contadores[i]++;
                }


            }


        }

        for(int i=0; i<tamMar; i++)
        {
            if(i==0||contadores[i]>mayorCantidadMarca)
            {
                mayorCantidadMarca=contadores[i];
            }


        }

        for(int i=0; i<tamMar; i++)
        {
            if(contadores[i]==mayorCantidadMarca)
            {
                printf("%s\n",marcas[i].descripcion);
            }


        }


        todoOk=1;


    }


    return todoOk;

}
