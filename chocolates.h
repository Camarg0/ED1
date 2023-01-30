#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

#define MAX 10

struct pilha {
    int id[MAX];
    int topo;
};

typedef struct pilha Pilha;

Pilha* criar(){
    Pilha *p;

    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = -1;

    return p;
}

void destruir(Pilha *p){
    p->topo = -1;
}

bool vazia(Pilha p){
    if(p.topo == -1) 
        return true;
    else 
        return false;
}

bool cheia(Pilha p){
    if (p.topo == (MAX - 1))
        return true;
    else 
        return false;
}

bool empilhar(Pilha *p, int id){
    if (cheia(*p) == true)
        return false;
    
    else{
        p->topo = p->topo + 1;
        p->id[p->topo] = id;
        return true;
    }
}

bool desempilhar(Pilha *p){
    if(vazia(*p))
        return false;
    else{
        p->topo = p->topo - 1;
        return true;
    }
}

void ListarChocolates(Pilha *p){
    printf("\n");
    int aux = p->topo;
    for (int i = 0; i <= p->topo; i++){
        printf("Chocolate numero: %d\n", p->id[aux]);
        aux = aux - 1;        
    }
}

