#include "../inc/mercado.h"

#define SIZE_PRODUCTS 100

int main() {

  Product products[SIZE_PRODUCTS];

  const char *file_path = "./files/estoque.csv";
  read_csv(products,file_path);


  int exit = 0;
  while (exit == 0) {

    exit = get_user_action(products);
  }

  // Teste chamada de função show_cart
  show_cart(products);

  return 0;
}
