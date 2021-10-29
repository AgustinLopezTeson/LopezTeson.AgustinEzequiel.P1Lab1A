
#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED


typedef struct{
int idMarca;
char descripcion[20];
}eMarca;

#endif // MARCA_H_INCLUDED
int mostrarMarcas( eMarca marcas[], int tam );
int traerMarca(eMarca marcas[], int tamMar, int idMarca , char descMarca[]);
