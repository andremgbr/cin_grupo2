#include "../inc/mercado.h"

#define SIZE_PRODUCTS 3

int main() {
  
Product products[SIZE_PRODUCTS] = {
  {"sabão", 1, 1.3}, 
  {"banana", 5, 3.3}, 
  {"vassoura", 0, 10},
  {"", -1, -1} 
};

  int exit = 0;
  while (exit == 0) {

    exit = get_user_action(products);
  }

  return 0;
}
