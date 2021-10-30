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
#define TAM 10
#define TAM_SER 4
#define TAM_TRAB 10
#define TAM_CLI 10

int main()
{
    char seguir='s';
    eNotebook lista[TAM];
    eTrabajo trabajos[TAM_TRAB];
    eCliente clientes[TAM_CLI];

    int idNotebook=100;
    int idTrabajos=1;
    int idCliente = 500;



    eMarca marcas[TAM_MAR] =
    {
        { 1000, "Compaq" },
        { 1001, "Asus" },
        { 1002, "Acer" },
        { 1003, "Acer" },
        { 1004, "HP" }
    };

    eServicio servicios [TAM_SER] =
    {
        {20000, "Bateria", 2250},
        {20001, "Display", 10300},
        {20002, "Mantenimiento", 4400},
        {20003, "Fuente", 5600}
    };

    eTipo tipoNote[TAM_TIPO] =
    {
        { 5000, "Gamer" },
        { 5001, "Disenio"},
        { 5002, "Ultrabook" },
        { 5003, "Normalita" },
    };

    inicializarNotebooks(lista,TAM);
    inicializarTrabajos(trabajos,TAM_TRAB);

    hardcodearNotebook(lista,TAM,5,&idNotebook);
    hardcodearTrabajos(trabajos,TAM,5,&idTrabajos);
    hardcodearCliente(clientes,TAM,8,&idCliente);
    do
    {
        switch (menu())
        {
        case 1:
            if(!altaNotebook(lista,TAM,marcas,TAM_MAR,tipoNote,TAM_TIPO,&idNotebook))
            {
                printf("No se pudo hacer el alta ");
            }
            else
            {
                printf("Alta Exitosa");
            }
            break;
        case 2:
            if(!modificarNotebook(lista,TAM,  tipoNote, TAM_TIPO, marcas,TAM_MAR,clientes, TAM_CLI))
            {
                printf("No se pudo realizar la modificacion");
            }
            else
            {
                printf("Modificacion exitosa");
            }
            break;
        case 3:
            if( bajaNotebook(lista,TAM,tipoNote,TAM_TIPO,marcas,TAM_MAR,clientes,TAM_CLI))
            {
                printf("No se pudo realizar la baja");
            }
            else
            {
                printf("Baja exitosa");
            }
            break;
        case 4:
            mostrarNotebooks(lista,TAM,marcas,tipoNote,TAM_TIPO,TAM_MAR,clientes,TAM_CLI);
            system("pause");
            break;
        case 5:
            system("cls");
            if(!mostrarMarcas(marcas,TAM_MAR)){

                printf("No se pudo mostrar las marcas");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            if(!mostrarTipos(tipoNote,TAM_TIPO)){

                printf("No se pudo mostrar los tipos");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(!mostrarServicios(servicios,TAM_SER)){
                printf("No se pudo mostrar los servicios");

            }
            system("pause");
            break;
        case 8:
            system("cls");
            altaTrabajo(lista,TAM,servicios,TAM_SER,trabajos,TAM_TRAB,&idTrabajos,tipoNote,TAM_TIPO,marcas, TAM_MAR,clientes,TAM_CLI);
            system("pause");
            break;
        case 9:
            system("cls");
            mostrarTrabajos(servicios,TAM_SER, trabajos, TAM_TRAB);
            system("pause");
            break;
        case 10:
            system("cls");
            informes(lista,TAM,clientes,TAM_CLI,marcas,TAM_MAR, tipoNote, TAM_TIPO,trabajos,TAM_TRAB,servicios,TAM_SER);
            system("pause");
            break;
        case 11:
            seguir ='n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
