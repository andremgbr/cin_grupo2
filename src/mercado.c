#include <stdio.h>
#include <mercado.h>
#include <string.h>

int get_user_action(Product products[])
{
  int input;

  print_instructions();

  scanf("%d", &input);

  printf("\n======================================================\n");

  switch (input)
  {
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
    remove_item(products); // Não passa mais o tamanho
    break;
  case 5:
    return 1;
    break;
  }
  return 0;
}

void print_instructions()
{
  printf("\n======================================================\n");
  printf("====================== MENU ==========================\n");
  printf("1-Inserir item;\n");
  printf("2-Mostrar Carrinho;\n");
  printf("3-Limpar Carrinho;\n");
  printf("4-Remover item do carrinho\n");
  printf("5-Sair\n");
  printf("\nDigite a opção desejada:\n");
}

void insert_item(Product products[])
{

  int addOther=1;


  while (addOther == 1)
  {
    int local_itemID = -1;
    int local_itemAmount = -1;

    printf("Lista de Produtos\n");
    printf("Código - Nome\n");

    int i = 0;
    while(products[i].qtd != -1)
    {
      printf("%d - %s \n",i+1,products[i].name);
      i++;
    }

    int SIZE_PRODUCTS = i;

    //recebimento e validação do ID
    int validID=0;
    while(validID==0)

    {
      printf("Digite o código do produto que deseja:\n");
      scanf("%d", &local_itemID);
      if (local_itemID <= SIZE_PRODUCTS && local_itemID > 0)
      {
        validID = 1;
      }
      else
      {
        printf("Código do produto inválido\n");
      }
    }

    // recebimento e validação da quantidade
    int validAmount = 0;
    while (validAmount == 0)
    {
      printf("Digite a quantidade do produto que deseja:\n");
      scanf("%d", &local_itemAmount);
      if (local_itemAmount >= 0)
      {
        validAmount = 1;
      }
      else
      {
        printf("Quantidade do produto inválida\n");
      }
    }

    // se ID e Quantidade forem validos escrevemos na memoria global
    if (validAmount == 1 && validID == 1)
    {
      // Inserir Rotina para escrever na memória global
      products[local_itemID - 1].qtd = products[local_itemID - 1].qtd + local_itemAmount;
      printf("%d x %s adicionadas ao carrinho\n", local_itemAmount, products[local_itemID - 1].name);
    }

    int validSelection = 0;
    while (validSelection == 0)
    {
      printf("Deseja adicionar outro item ao carrinho? (0-Nao 1-Sim)\n");
      scanf("%d", &addOther);
      if (addOther == 0 || addOther == 1)
      {
        validSelection = 1;
      }
      else
      {
        validSelection = 0;
      }
    }
  }
}

void show_cart(Product products[])
{
  int i = 0;
  float total = 0.0;
  printf("=============== CARRINHO DE COMPRAS ==================\n");
  //printf("\nCarrinho de Compras:\n");
  printf("------------------------------------------------------\n");
  printf("%-5s \t%-20s \t%-10s \t%-10s\n", "Qtd", "Product", "Value (un.)", "Total");

  while (products[i].qtd != -1)
  {
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

void clean_cart(Product products[])
{
  int i = 0;

  while (products[i].qtd != -1)
  {
    products[i].qtd = 0;
    i = i + 1;
  }
}

#define MAX_PRODUCTS 100
#define MAX_LINE 100

int read_csv(Product products[],const char *file_path) 
{
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Erro ao abrir arquivo");
        return 0;
    }

    char line[MAX_LINE];
    fgets(line, MAX_LINE, file); 

    int count = 0;
    while (fgets(line, MAX_LINE, file) && count < MAX_PRODUCTS) {
        char name[20];
        int qtd;
        float value;

        if (sscanf(line, "%19[^,],%d,%f", name, &qtd, &value) == 3) 
        {


            strcpy(products[count].name, name);
            products[count].qtd = qtd;
            products[count].value = value;
            if (strcmp(name, "-1") == 0) break;
            count++;
        }
    }

    fclose(file);

    clean_cart(products);

    return count; // Retorna número de produtos lidos
}

void remove_item(Product products[]) {
  int local_itemID = -1;
  
  printf("\n======================================================\n");
  printf("============ REMOVER ITENS DO CARRINHO ===============\n");

  printf("-----------------------------\n");
  printf("Lista de Produtos no Carrinho\n");
  printf("Cod - Nome\n");
  for (int i = 0; products[i].qtd != -1; i++) {
      if (products[i].qtd > 0) {
          printf("%d - %s\n", i + 1, products[i].name);
      }
  }
  printf("-----------------------------\n");

  // Recebimento e validação do ID
  int validID = 0;
  while (validID == 0) {
      printf("Digite o código do produto que deseja remover:\n");
      scanf("%d", &local_itemID);
      int i = 0;
      while(products[i].qtd != -1) {
        if(local_itemID == i+1) {
          validID=1;
          break;
        }
        i++;
      }

      if (validID == 0) {
          printf("Código do produto inválido ou produto não está no carrinho.\n");
      }
  }

  // Remover o produto do carrinho
  if (validID == 1) {
      products[local_itemID - 1].qtd = 0; // Zera a quantidade
      printf("%s removido do carrinho.\n", products[local_itemID - 1].name);
  }
}