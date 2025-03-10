#ifndef H_MERCADO
#define H_MERCADO

typedef struct{
  char name[20];
  int qtd;
  float value;
} Product;

void print_instructions();
int get_user_action(Product products[]);
void insert_item(Product products[]);
void show_cart(Product products[]);
void clean_cart(Product products[]);

#endif
