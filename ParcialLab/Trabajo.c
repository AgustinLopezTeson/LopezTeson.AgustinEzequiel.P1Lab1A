#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "TipoNote.h"
#include "Notebook.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "cliente.h"
#include "Fecha.h"

#define TAM_MAR 5
#define TAM_TIPO 4
#define TAM 10
#define TAM_SER 4
#define TAM_TRAB 5


int menu()
{
    int opcion = 0;
    system("cls");
    printf("     *** Servicee de Notebooks  ***\n");
    printf("1- Alta Notebook\n");
    printf("2- Modificar Notebook\n");
    printf("3- Baja Notebook\n");
    printf("4- Listar Notebook\n");
    printf("5- Listar marcas\n");
    printf("6- Listar tipos\n");
    printf("7- Listar servicios\n");
    printf("8- Alta Trabajo\n");
    printf("9- Listar Trabajos\n");
    printf("10- Informes\n");
    printf("11- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    printf("\n");
    return opcion;
}

int informes(eNotebook lista[],int tam,eCliente clientes[], int tamCli, eMarca marcas[], int tamMar, eTipo tipoNote[], int tamTipo,eTrabajo trabajos[],int tamTra,eServicio servicios, int tamServ){


    switch(menuInformes()){

    case 1 :
    mostrarNotebookTipo(lista,tam,marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);
    break;
    case 2 :
    mostrarNoteMarca(lista,tam,marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);
    break;
    case 3:

    break;
    case 4:
    mostrarNoteMarca(lista,tam,marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);
    break;
    case 5:
    mostrarNotebookTipoMarca(lista,tam,marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);
    break;
    case 6:
    informarMarcasMasElegidas(lista,tam,marcas,tamMar);
    break;
    }


}


int menuDeModificaciones()
{
    int opcion;

    printf("\n\n        *** Modificar Notebook ***          \n");
    printf("------------------------------------------------\n");
    printf("    1- Tipo\n\n");
    printf("    2- Precio\n\n");
    printf("    3- Salir\n\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    printf("\n\n        *** Menu de Informes ***          \n");
    printf("------------------------------------------------\n");
    printf("    1- Buscar Notebook por tipo\n\n");
    printf("    2- Buscar Notebook por marca\n\n");
    printf("    3- Informar la Notebook mas barata\n\n");
    printf("    4- Mostrar las notebook por marca\n\n");
    printf("    5- Contar notebooks por tipo y marca  \n\n");
    printf("    6- Mostrar por marca mas elegida \n\n");
    printf("    7- Salir\n\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}


int validarFecha(int dia, int mes, int anio)
{
    int todoOk = 0;

    if(
        (dia > 0 && dia < 32) &&
        (mes > 0 && mes < 13) &&
        (anio > 0 && anio < 2022)
       )
    {
        todoOk = 1;
    }

    return todoOk;
}

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;
    if (trabajos != NULL && tam > 0)
    {

        for (int i = 0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}




int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (trabajos[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int altaTrabajo(eNotebook lista[], int tam,eServicio servicios[],int tamSer,eTrabajo trabajos[],int tamTra,  int* nextId,eTipo tipoNote[], int tamTipo, eMarca marcas[] , int tamMar,eCliente clientes[], int tamCli)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;
    if (lista != NULL && tam > 0)
    {
        system("cls");
        printf("  ***Alta Trabajo*** \n\n");

        indice = buscarLibreTrabajo(trabajos,tamTra);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxTrabajo.id=*nextId;
            (*nextId)++;
           mostrarNotebooks(lista,tam,marcas,tipoNote,tamTipo,tamMar,clientes,tamCli);

            printf("\n\nIngrese el ID de la Notebook a trabajar: ");
            scanf("%d", &auxTrabajo.idNote);

            while(buscarNotebookId(lista,tam,auxTrabajo.idNote)==-1){

                printf("Ingrese un ID valida para una notebook");
                scanf("%d", &auxTrabajo.idNote);
            }

                system("cls");
            mostrarServicios(servicios,tamSer);
            printf("Ingrese el servicio que desea: ");
            scanf("%d", &auxTrabajo.idServicio);

            while(auxTrabajo.idServicio<20000&&auxTrabajo.idServicio>20003)
            {
                printf("error, id no valido. Vuelva a ingresar el id del servicio que desea: ");
                scanf("%d", &auxTrabajo.idServicio);
            }

            printf(" ***Ingrese la fecha*** \n ");
            printf("  Formato (dd/mm/aaaa) \n\n");
            printf("Ingrese dia:");
            scanf("%d",&auxTrabajo.fecha.dia);
            printf("Ingrese mes:");
            scanf("%d", &auxTrabajo.fecha.mes);
            printf("Ingrese anio: ");
            scanf("%d", &auxTrabajo.fecha.anio);

            while(!validarFecha(auxTrabajo.fecha.dia,auxTrabajo.fecha.mes,auxTrabajo.fecha.anio))
            {
                printf("Error, ingrese una fecha valida (dd/mm/aaaa): ");
                fflush(stdin);
                scanf("%d/%d/%d", &auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
            }

            auxTrabajo.isEmpty = 0;

            trabajos[indice] = auxTrabajo;
            printf("Alta Exitosa !!! \n\n");
            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[],int tamSer)
{



    char descServicio[26];

    traerServicio(servicios,  tamSer, unTrabajo.idServicio , descServicio);


    printf("  %d       %5d       %-20s   %02d/%02d/%d    \n",
           unTrabajo.id,
           unTrabajo.idNote,
            descServicio,
           unTrabajo.fecha.dia,
           unTrabajo.fecha.mes,
           unTrabajo.fecha.anio);



}

int mostrarTrabajos(eServicio servicios[],int tamSer, eTrabajo trabajos[] , int tamTra)
{

    int todoOk = 0;
    int flag = 1;
    if(trabajos != NULL && servicios != NULL && tamSer > 0 && tamTra > 0  )
    {
        system("cls");
        printf("       *** Listado de trabajos ***      \n");
         printf("------------------------------------------------------\n");
        printf("   IdTra   IdNote        Servicio            Fecha\n");
        printf("-------------------------------------------------------\n");
        for(int i = 0; i < tamTra; i++)
        {
            if(trabajos[i].isEmpty==0)
            {

                mostrarTrabajo(trabajos[i], servicios, tamSer);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay trabajos para mostrar, \n se debe dar de alta algun trabajo antes de poder mostrarlo.\n");

        }
        todoOk=1;

    }

    return todoOk;

}
