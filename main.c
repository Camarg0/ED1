#include <stdio.h>
#include <string.h>
#include "chocolates.h"
#include "fila_clientes.h"

struct itensCardapio
{
    int id;
    float preco;
    char descricao[100];
};

struct itensCardapio cardapio[5];

//O preço de cada prato cresce R$5 a cada item.
void DefinePrecosItensCardapio(){
    float aux = 5.0;
    for (int i = 0; i <= 5; i++){
        cardapio[i].preco = aux + 5.0;
        aux = cardapio[i].preco;
    }
}

void DefineDescricoesItensCardapio(){
    strcpy(cardapio[0].descricao, "Arroz e Feijao");
    strcpy(cardapio[1].descricao, "Arroz carreteiro");
    strcpy(cardapio[2].descricao, "Macarrao com Molho Vermelho");
    strcpy(cardapio[3].descricao, "Petit Gateau");
    strcpy(cardapio[4].descricao, "Sorvete de Ameixa");
    strcpy(cardapio[5].descricao, "Sanduiche de Porco");
}

//O id de cada item será definido de acordo com o seu índice no array. Exemplo: o ID do item cardapio[5] será 5.
void DefineIdsItensCardapio(){
    for (int i = 0; i <= 5 ;i++)
    {
        cardapio[i].id = i;
    }
}

int main (){
    DefinePrecosItensCardapio();
    DefineDescricoesItensCardapio();                                                                                                                                                                                                                                    
    DefineIdsItensCardapio();

    Pilha *p = criar();
    bool deuCertoInserirClienteFila;
    Fila *f = criarFila(&deuCertoInserirClienteFila);
    int x;

    while (x != 0){
        mainMenu(p, f);
        printf("\n\n1 - Home\n\n0 - Sair\n\n");
        scanf("%d", &x);
    }
} 

void mainMenu(Pilha *p, Fila *f){
    CriaTelaInicial(p, f);
}

void CriaTelaInicial(Pilha *p, Fila *f){
    int x;

    printf("\n\n\n\t\t\t\t\t\t RESTAURANTE\n\n\n\n");
    printf("1 - Incluir um cliente na fila\n\n2 - Chamar o proximo cliente para pagamento\n\n3 - Finalizar Atendimento\n\n4 - Listar Clientes da Fila\n\n5 - Listar os itens do cardapio\n\n6 - Listar os chocolates\n\n7 - Inserir os chocolates\n\n\n\n");
    
    scanf("%d", &x);

    switch (x){
        case 1: InsereCliente(f);
            break;

        case 2: ChamarProximo(p, f);
            break;

        case 3: return;

        case 4: ListarClientes(f);
            break;

        case 5: ListarItensCardapio();
            break;

        case 6: ListarChocolates(p);
            break;

        case 7: TratarChocolate(p);
            break;
    }
}

void InsereCliente(Fila *f){
    int x;
    printf("\nDigite o id do cliente a ser inserido na fila: ");
    scanf("%d", &x);
    insereFila(f, x);  
}

void ChamarProximo(Pilha *p, Fila *f){
    int x;
    int i = 0;
    float precoTotal = 0;
    printf("Insira os itens da comanda. Aperte 0 para sair:\n");
    scanf("%d",&x);

    while(x != 0){
        inserirItem(f, x, i);
        i++;
        scanf("%d",&x);
        precoTotal = precoTotal + (cardapio[i].preco);
    }

    printf("O preco total eh: %f", precoTotal);
    bool deuCertoDesempilharChocolate = desempilhar(p);
    bool deuCertoRetirarClienteFila = retiraFila(f);
}

void ListarItensCardapio(){
    for(int i = 0; i <= 5; i++){
        printf("\n%d - %s ------ R$%.2f", cardapio[i].id, cardapio[i].descricao, cardapio[i].preco);
    }
    printf("\n");
}


void TratarChocolate(Pilha *p){
    printf("\n\n 1 - Nestle\n\n 2 - Laka\n\n 3 - Chokito\n\n 4 - Garoto\n\n");
    printf("\nDigite o chocolate a ser inserido. Digite 0 para sair ");
    int x;
    scanf("%d", &x);
    if (x != 1 && x != 2 && x != 3 && x != 4){
            printf("Chocolate nao disponivel");
            return;
        } 

    while (x != 0){
        bool deuCerto = empilhar(p, x);
        printf("\nDigite o chocolate a ser inserido. Digite 0 para sair ");
        scanf("%d", &x);
        if (x != 1 && x != 2 && x != 3 && x != 4){
            printf("Chocolate nao disponivel");
            return;
        } 
    }
}
    

