#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#include "tipo.h"
#include "mascota.h"
#include "data.h"
typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    Fecha fecha;
    int isEmpty;
}Trabajo;

int menu();
int altaTrabajo(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[], int tamCol,Trabajo trabajos[],int tamTra,Servicio servicios[],int tamSer,int* idTrabajos);
int buscarLibreTrabajo(Trabajo trabajos[], int tam);
int inicializarTrabajos(Trabajo trabajos[], int tam);
int validarFecha(int dia, int mes, int anio);
void mostrarTrabajo(Trabajo unTrabajo,Servicio servicios[],int tamSer,Mascota mascotas[],int tamMasc);
int mostrarTrabajos(Trabajo trabajos[],int tam,Servicio servicios[],int tamSer,Mascota mascotas[],int tamMasc);
int buscarTrabajoId(Trabajo trabajos[], int tam, int id);

#endif // TRABAJO_H_INCLUDED
