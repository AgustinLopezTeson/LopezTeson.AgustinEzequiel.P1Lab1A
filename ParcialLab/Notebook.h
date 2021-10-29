#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#include "TipoNote.h"
#include "Marca.h"

typedef struct{
int idNote;
int precio;
int idMarca;
int  idTipo;
char modelo[20];
int isEmpty;

}eNotebook;


#endif // NOTEBOOK_H_INCLUDED


int inicializarNotebooks(eNotebook lista[], int tam);
int buscarLibreNotebook(eNotebook lista[], int tam);
int altaNotebook(eNotebook lista[], int tam, eMarca marcas[], int tamMar,eTipo tipoNote[], int tamCol, int* nextId);
int modificarNotebook(eNotebook lista[], int tam, eTipo tipoNote[], int tamNote, eMarca marcas[], int tamMar);
int buscarNotebookId(eNotebook lista[], int tam, int id);
int bajaNotebook(eNotebook lista[], int tam,eTipo tipoNote[],int tamTipo,eMarca marcas[],int tamMarca);
void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], eTipo tipoNote[], int tamTipo,int tamMar);
int mostrarNotebooks(eNotebook lista[],int tam, eMarca marcas[], eTipo tipoNote[], int tamTipo,int tamMarca);
int ordenarNotebook(eNotebook lista[], int tam);
