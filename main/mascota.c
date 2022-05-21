#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#include "tipo.h"
#include "mascota.h"
#include "cliente.h"
#include <ctype.h>

#define TAM 20
#define TAMTIPO 5
#define TAMCOL 5
#define TAMSER 3


int inicializarMascotas(Mascota lista[],int tam)
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

int buscarLibreMascota(Mascota lista[], int tam)
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

int altaMascota(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol,int* pId,eCliente clientes[],int tamCli)
{
    int todoOk = 0;
    int indice;
    Mascota auxMascota;
    if (lista != NULL && tam > 0)
    {
        system("cls");
        printf("  ***Alta Mascota*** \n\n");
        indice = buscarLibreMascota(lista, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxMascota.id=*pId;

            printf("Ingrese el nombre de la mascota: ");
            fflush(stdin);
            gets(auxMascota.nombre);

            mostrarTipos(tipos,tamTipo);
            printf("Ingrese el tipo: ");
            scanf("%d",&auxMascota.idTipo);
            while(auxMascota.idTipo<999|| auxMascota.idTipo>1005)
            {
                printf("error. id ingresado no valido\n");
                printf("Ingrese id del tipo que desea  : ");
                scanf("%d", &auxMascota.idTipo);
            }

            mostrarColores(colores,tamCol);
            printf("Ingrese el color: ");
            scanf("%d", &auxMascota.idColor);
            while(auxMascota.idColor<4999|| auxMascota.idColor>5005)
            {
                printf("error. id ingresado no valido\n");
                printf("Ingrese id del color que desea  : ");
                scanf("%d", &auxMascota.idColor);
            }

            printf("Ingrese la edad: \n");

           scanf("%d",&auxMascota.edad);

           printf("Esta vacunado: \n");
           fflush(stdin);
           scanf("%c",&auxMascota.vacunados);

            auxMascota.isEmpty = 0;

            lista[indice] = auxMascota;
            printf("Alta Exitosa !!! \n\n");
            system("pause");
            todoOk = 1;
        }

        (*pId)++;
    }
    return todoOk;
}

int buscarMascotaId(Mascota lista[], int tam, int id)
{
  int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].id == id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarMascota(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol,eCliente clientes[],int tamCli)
{

    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char salir;
    Mascota auxMascota;
    if (lista != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Modificar Mascota *** \n\n");

       mostrarMascotas(lista,tam,tipos,tamTipo,colores,tamCol,clientes,tamCli);
        printf("Ingrese id de la mascota: ");
        scanf("%d", &id);

        indice = buscarMascotaId(lista,tam,id);



        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {


          mostrarMascota(lista[indice],tipos,colores,tamTipo,tamCol,clientes,tamCli);


            do
            {
                switch ( menuDeModificaciones() )
                {
                case 1:

                    mostrarTipos(tipos,tamTipo);
                    printf("Modificar Tipo: ");
                    scanf("%d",&auxMascota.idTipo);
                    printf("Confirma cambio de tipo? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].idTipo=auxMascota.idTipo;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 2:
                    printf("Modificar Vacunacion: ");
                    fflush(stdin);
                    scanf("%s", &auxMascota.vacunados);
                    printf("Confirma cambio de vacunacion? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].vacunados = auxMascota.vacunados;
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
int mostrarMascotas(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && tipos != NULL && colores != NULL && tam > 0 && tamTipo > 0 && tamCol > 0 )
    {
        system("cls");
        printf("       *** Listado de Mascotas ***      \n");
        printf("---------------------------------------------------------------------------------------------\n");
        printf("   Id         Nombre           Tipo       Color        edad       Vacunado         Cliente\n");
        printf("---------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {

                mostrarMascota(lista[i],tipos,colores,tamTipo,tamCol,clientes,tamCli);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Mascotas para mostrar, \n se debe dar de alta alguna mascota antes de poder mostrarlo.\n");

        }
        todoOk=1;

    }

    return todoOk;
}
int bajaMascota(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    if(lista != NULL && tipos != NULL && colores != NULL && tam > 0 && tamTipo > 0 && tamCol > 0 )
    {
        system("cls");
        printf("---------------------------------------------\n");
        printf("       *** Baja Mascota ***      \n");
        printf("---------------------------------------------\n");

        mostrarMascotas(lista,tam,tipos,tamTipo,colores,tamCol,clientes,tamCli);


        printf("Ingrese el id de la mascota que quiere dar de baja: ");
        scanf("%d", &id);

        indice = buscarMascotaId(lista,tam,id);

        if(indice == -1)
        {
            printf("No existe una mascota con id: %d\n", id);
        }
        else
        {
            printf("\n\n");
           mostrarMascota(lista[indice],tipos,colores,tamTipo,tamCol,clientes,tamCli);
            printf("\n\n");
            printf("Confirma baja? (s para si): \n");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                printf("Mascota dada de baja.\n");
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

void mostrarMascota(Mascota unaMascota, Tipo tipos[], Color colores[], int tamTipo,int tamCol,eCliente clientes[],int tamCli)
{
    char descTipo[21];
    char descColor[21];
    char descCliente[21];


    traerTipo(tipos,tamTipo,unaMascota.idTipo,descTipo);
    traerColor(colores,tamCol,unaMascota.idColor,descColor);
    traerCliente(clientes,tamCli,unaMascota.idCliente,descCliente);



    printf("%d  %10s   %10s     %10s   %10d     %10c     %s\n",unaMascota.id,unaMascota.nombre,descTipo,descColor,unaMascota.edad,unaMascota.vacunados,descCliente);

}

int menuDeModificaciones()
{
    int opcion;

    printf("\n\n        *** Modificar Mascota ***          \n");
    printf("------------------------------------------------\n");
    printf("    1- Tipo\n\n");
    printf("    2- Vacunado\n\n");
    printf("    3- Salir\n\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int traerMascota(Mascota mascotas[],int tamMasc,int idMascota,char descMascota[])
{
    int todoOk = 0;
    if(mascotas != NULL && tamMasc > 0 && descMascota != NULL){

         for(int i= 0; i < tamMasc; i++){

            if( mascotas[i].id == idMascota){
                strcpy( descMascota, mascotas[i].nombre);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}

int ordenarMascota(Mascota lista[], int tam)
{
    int todoOk = 0;
    Mascota auxMascota;
    if(lista != NULL && tam > 0)
    {
        for(int i = 1 ; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(lista[i].idTipo > lista[j].idTipo ||
                        lista[i].idTipo == lista[j].idTipo)
                {
                    auxMascota = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMascota;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}
