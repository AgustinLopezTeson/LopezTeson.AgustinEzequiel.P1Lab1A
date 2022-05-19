#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}Servicio;


int mostrarServicios(Servicio servicios[], int tam);
int traerServicio(Servicio servicios[],int tamSer,int idServicio,char descServicio[]);

#endif // SERVICIO_H_INCLUDED
