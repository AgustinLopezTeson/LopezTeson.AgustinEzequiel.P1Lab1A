#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}Tipo;

int mostrarTipos(Tipo tipos[], int tam);
int traerTipo(Tipo tipos[], int tamTipo, int idTipo, char descTipo[]);
#endif // TIPO_H_INCLUDED
