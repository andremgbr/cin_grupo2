#include <stdio.h>
#include <mercado.h>

int get_user_action(Product products[]) {
  int input;
  
  print_instructions();
  
  scanf("%d", &input);
  
  switch (input) {
  case 1:
    insert_item(products);
    break;
  case 2:
    show_cart(products);
    break;
  case 3:
    clean_cart(products);
    break;
  case 4:
    return 1;
    break;
  }
  return 0;
}

void print_instructions(){
  
}

void insert_item(Product products[])
{
  int addOther=1;
  int SIZE_PRODUCTS=4;

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
      products[local_itemID-1].qtd= products[local_itemID-1].qtd+local_itemAmount;
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

void show_cart(Product products[]){
  int i = 0;
  float total = 0.0;

  printf("\nCarrinho de Compras:\n");
  printf("------------------------------------------------------\n");
  printf("%-5s \t%-20s \t%-10s \t%-10s\n", "Qtd", "Product", "Value (un.)", "Total");

  while (products[i].qtd != -1) {
      printf("%-5d\t", products[i].qtd);
      printf("%-20s\t", products[i].name);
      printf("%-10.2f\t", products[i].value);
      printf("%-10.2f\t\n", products[i].value * products[i].qtd);
      
      total = total + products[i].value * products[i].qtd;
      i = i + 1;
  }
  printf("------------------------------------------------------\n");
  printf("Total: %.2f\n\n", total);
}

void clean_cart(Product products[]){
  for(int i = 0; i < 3; i++){
    products[0].qtd = 0;
  }
}
