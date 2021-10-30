#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
int idCliente;
char nombre[21];
char sexo;
int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

int mostrarClientes(eCliente clientes[],int tam);
int traerCliente(eCliente clientes[], int tamCli, int idCliente , char descCliente[]);
