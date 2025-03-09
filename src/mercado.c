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

void insert_item(Product products[]){

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
