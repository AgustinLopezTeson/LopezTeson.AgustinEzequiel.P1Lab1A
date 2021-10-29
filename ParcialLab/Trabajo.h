#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "Fecha.h"
#include "Servicio.h"

typedef struct{
    int id;
    int idNote;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int menu();
int menuDeModificaciones();
int altaTrabajo(eNotebook lista[], int tam,eServicio servicios[],int tamSer,eTrabajo trabajos[],int tamTra,int* nextId,eTipo tipoNote[], int tamTipo, eMarca marcas[] , int tamMar);
int buscarLibreTrabajo(eTrabajo trabajos[], int tam);
int validarFecha(int dia, int mes, int anio);
int inicializarTrabajos(eTrabajo trabajos[], int tam);
void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[],int tamSer);
int mostrarTrabajos(eServicio servicios[],int tamSer, eTrabajo trabajos[] , int tamTra);
