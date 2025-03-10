#include "mercado.h"
#include <stdio.h>

#define SIZE_PRODUCTS 3

Product products[SIZE_PRODUCTS] = {
  {"sabão", 1, 1.3}, 
  {"banana", 5, 3.3}, 
  {"vassoura", 0, 10} 
};

int main() {
  
  int exit = 0;
  while (exit == 0) {

    exit = get_user_action();
  }

  return 0;
}


int get_user_action() {
  int input;
  
  print_instructions();
  
  scanf("%d", &input);
  
  switch (input) {
  case 1:
    insert_item();
    break;
  case 2:
    show_cart();
    break;
  case 3:
    clean_cart();
    break;
  case 4:
    return 1;
    break;
  }
  return 0;
}

void print_instructions(){
  
}

void insert_item()
{
  int addOther=1;
  while(addOther==1)
  {
    int local_itemID=-1;
    int local_itemAmount=-1;

    printf("Lista de Produtos\n");
    printf("Código - Nome\n");
    for(int i=0;i<SIZE_PRODUCTS;i++)
    {
      printf("%d - %s \n",i+1,products[i].name);
    }

    //recebimento e validação do ID
    int validID=0;
    while(validID==0)
    {
      printf("Digite o código do produto que deseja:\n");
      scanf("%d",&local_itemID);
      if(local_itemID<=SIZE_PRODUCTS && local_itemID>0)
      {
        validID=1;
      }
      else
      { 
        printf("Código do produto inválido\n");
      }
    }
    
    //recebimento e validação da quantidade
    int validAmount=0;
    while(validAmount==0)
    {
      printf("Digite a quantidade do produto que deseja:\n");
      scanf("%d",&local_itemAmount);
      if(local_itemAmount>=0)
      {
        validAmount=1;
      }
      else
      { 
        printf("Quantidade do produto inválida\n");
      }
    }

    //se ID e Quantidade forem validos escrevemos na memoria global
    if(validAmount==1 && validID==1)
    {
      //Inserir Rotina para escrever na memória global 

      printf("%d x %s adicionadas ao carrinho\n",local_itemAmount ,products[local_itemID-1].name);

    }

    int validSelection=0;
    while(validSelection==0)
    {
      printf("Deseja adicionar outro item ao carrinho? (0-Nao 1-Sim)\n");
      scanf("%d",&addOther);
      if(addOther==0 || addOther==1)
      {
        validSelection=1;
      }
      else 
      {
        validSelection=0;
      }
    }
  }
}

void show_cart(){

}

void clean_cart(){
  for(int i = 0; i < SIZE_PRODUCTS; i++){
    products[0].qtd = 0;
  }
}
