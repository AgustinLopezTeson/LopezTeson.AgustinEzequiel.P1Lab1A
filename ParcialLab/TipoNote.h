#ifndef TIPONOTE_H_INCLUDED
#define TIPONOTE_H_INCLUDED


typedef struct{
    int idModelo;
    char nombreNote[20];
}eTipo;

#endif // TIPONOTE_H_INCLUDED

int validarTipo( int id, eTipo tipoNote[], int tamCol );
int traerTipo(eTipo tipoNote[],int tamTipo, int idTipo ,char descTipo[]);

