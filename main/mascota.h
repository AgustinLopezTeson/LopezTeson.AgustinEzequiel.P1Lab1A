#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    char vacunados;
    int isEmpty;
}Mascota;

int inicializarMascotas(Mascota lista[],int tam);
int altaMascota(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol,int* pId);
int buscarLibreMascota(Mascota lista[], int tam);
int modificarMascota(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol);
void mostrarMascota(Mascota unaMascota, Tipo tipos[], Color colores[], int tamTipo,int tamCol);
int mostrarMascotas(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol);
int buscarMascotaId(Mascota lista[], int tam, int id);
int menuDeModificaciones();
int bajaMascota(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol);
int traerMascota(Mascota unaMascota[],int tamMasc,int idMascota,char descMascota[]);

#endif // MASCOTA_H_INCLUDED
