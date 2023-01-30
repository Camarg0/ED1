#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAXCOMANDA 10
#define MAXCLIENTES 100

struct Clientes {
    int id;
    int comanda[MAXCOMANDA];
    float preco_final;
    int chocolate;
};

struct fila {
    struct Clientes clientes[MAXCLIENTES];
    int n_clientes;
    int primeiro;
    int ultimo;
};

typedef struct fila Fila;

Fila *criarFila(bool *deuCerto){
    Fila *f;

    f = (Fila *) malloc(sizeof(Fila));
    if (f == NULL){*deuCerto = false;}
        else{
            *deuCerto = true;
            f->n_clientes = 0;
            f->primeiro = 0;
            f->ultimo = 0;}

    return f;
}

void destruirFila(Fila *f){
    if(f != NULL){free(f);}
}

bool vaziaFila(Fila *f){
    if(f->n_clientes == 0){return true;}
        else{return false;}
}

bool cheiaFila(Fila *f){
    if(f->n_clientes == MAXCLIENTES){return true;}
        else{return false;}
}

bool insereFila(Fila *f, int id_cliente){ //id definido na main.
    bool deuCerto;

    if(cheiaFila(f)){
        deuCerto = false;
    }else{
        deuCerto = true;
        f->clientes[f->ultimo].id = id_cliente;
        f->ultimo = f->ultimo + 1;
        }
    return deuCerto;
}

bool retiraFila(Fila *f){
    bool deuCerto;

    if(vaziaFila(f)){
            deuCerto = false;
    }else{
        deuCerto = true;
        f->n_clientes = f->n_clientes - 1;

        if(f->primeiro == (MAXCLIENTES - 1)){f->primeiro = 0;}
            else{f->primeiro = f->primeiro - 1;}
        }

        return deuCerto;
}

void ListarClientes(Fila *f){
    printf("\n");
    int aux = f->primeiro;
    for (int i = 0; i < f->ultimo; i++){
        printf("\nCliente numero: %d", f->clientes[aux].id);
        aux = aux + 1;        
    }
}

void inserirItem(Fila *f, int item, int i){
    f->clientes[f->primeiro].comanda[i] = item;
    return 0;
}
