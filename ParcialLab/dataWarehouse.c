#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dataWarehouse.h"
#include "Notebook.h"
#include "Trabajo.h"
#include "cliente.h"


char modelos[10][21]= {
            {"Thinker"},
            {"MacBook"},
            {"Empire"},
            {"Hp250"},
            {"Zenfone"},
            {"g240"},
            {"Altitud"}

                                };

char nombres [10][21] = {
            {"Juan"},
            {"Luis"},
            {"Tamara"},
            {"Maria"},
            {"Cristian"},
            {"Marisa"},
            {"Roberto"}

                                };

int idCliente[10]={500,501,502,503,504,505,506,507,508};

char sexos [10]={'m','m','f','f','m','f','m'};

int idTipos[8] = {5001, 5002, 5000, 5001, 5001, 5003, 5004};

int idMarcas[8] = {1001, 1002, 1002, 1001, 1001, 1003, 1001};

int precios [10]= {1500,30000,20000,17500,14750,32501,18000};

int dias[10]={5,12,17,12,10,2,1,3,7,9};
int meses[10]={1,8,7,10,3,1,8,7,10,3};
int anios[10]={2021,2020,2021,2020,2020,2021,2020,2021,2020,2020};
int idServicios[10]={20000,20001,20003,20002,20000,20000,20001,20001,20002,20004};
int idNotes[10]= {101,102,103,104,105,106,107,108,109};

int hardcodearNotebook(eNotebook lista[], int tam, int cant, int* pId)
{
    int contador = -1;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for(int i = 0; i < cant; i++)
        {
            lista[i].idNote = *pId;
            (*pId)++;
            strcpy(lista[i].modelo ,modelos[i]) ;
            lista[i].idTipo= idTipos[i];
            lista[i].idMarca=idMarcas[i];
            lista[i].precio=precios[i];
            lista[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}

int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pId)
{
    int contador = -1;
    if(trabajos != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for(int i = 0; i < cant; i++)
        {
            trabajos[i].id = *pId;
            (*pId)++;
            trabajos[i].idNote = idNotes[i];
            trabajos[i].idServicio=idServicios[i];
            trabajos[i].fecha.dia= dias[i];
            trabajos[i].fecha.mes = meses[i];
            trabajos[i].fecha.anio= anios[i];
            trabajos[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}

int hardcodearCliente(eCliente clientes[], int tam, int cant, int* pId)
{
    int contador = -1;
    if(clientes != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for(int i = 0; i < cant; i++)
        {
            clientes[i].idCliente = *pId;
            strcpy(clientes[i].nombre,nombres[i]) ;
            clientes[i].sexo= sexos[i];
            clientes[i].isEmpty = 0;
            (*pId)++;
            contador++;
        }
    }
    return contador;
}

