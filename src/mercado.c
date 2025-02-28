#include "mercado.h"
#include <stdio.h>

#define SIZE_PRODUCTS 3


int main() {
  
Product products[SIZE_PRODUCTS] = {
  {"sabão", 1, 1.3}, 
  {"banana", 5, 3.3}, 
  {"vassoura", 0, 10} 
};

  int exit = 0;
  while (exit == 0) {

    exit = get_user_action(products);
  }

  return 0;
}


int get_user_action(Product *products) {
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

void insert_item(Product *products){

}

void show_cart(Product *products){

}

void clean_cart(Product *products){
  for(int i = 0; i < SIZE_PRODUCTS; i++){
    products[0].qtd = 0;
  }
}
