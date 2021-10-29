#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


typedef struct{
    int id;
    char descripcion[20];
    int precio;

}eServicio;


#endif // SERVICIO_H_INCLUDED

int mostrarServicios(eServicio servicios[], int tam);
int traerServicio(eServicio servicios[], int tamSer, int idServ , char descServ[]);
