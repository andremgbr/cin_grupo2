#include <check.h>
#include <mercado.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

START_TEST(teste_insert_item) {
  Product cart[6] = {
    {"banana", 2, 1.1},
    {"vassoura", 3, 1},
    {"sabao", 3,1},
    {"roupa",0,3},
    {"calça",0,4},
    {"",-1,-1}
  };

  int pipe_fds[2];
  pipe(pipe_fds);
  write(pipe_fds[1], "2\n3\n0\n", 7);

  dup2(pipe_fds[0], STDIN_FILENO);
  close(pipe_fds[0]);

  insert_item(cart);

  ck_assert_int_eq(cart[1].qtd, 6);
}
END_TEST

START_TEST(teste_clean_chart) {

  Product cart[6] = {
    {"banana", 2, 1.1},
    {"vassoura", 3, 1},
    {"sabao", 3,1},
    {"roupa",0,3},
    {"calça",0,4},
    {"",-1,-1}
  };

  clean_cart(cart);

  ck_assert_int_eq(cart[0].qtd, 0);
  ck_assert_int_eq(cart[1].qtd, 0);
  ck_assert_int_eq(cart[2].qtd, 0);
}

START_TEST(teste_read_csv) 
{
  #define MAX_PRODUCTS 100
  Product products[MAX_PRODUCTS];
  const char *file_path = "test_products.csv";
  
  FILE *file = fopen(file_path, "w");
  fprintf(file, "name,qtd,value\n");
  fprintf(file, "banana,2,1.1\n");
  fprintf(file, "vassoura,3,1.0\n");
  fprintf(file, "sabao,3,1.0\n");
  fclose(file);
  
  int count = read_csv(products, file_path);
  
  ck_assert_int_eq(count, 3);
  ck_assert_str_eq(products[0].name, "banana");
  ck_assert_int_eq(products[0].qtd, 2);
  ck_assert_float_eq(products[0].value, 1.1);
  
  ck_assert_str_eq(products[1].name, "vassoura");
  ck_assert_int_eq(products[1].qtd, 3);
  ck_assert_float_eq(products[1].value, 1.0);
  
  ck_assert_str_eq(products[2].name, "sabao");
  ck_assert_int_eq(products[2].qtd, 3);
  ck_assert_float_eq(products[2].value, 1.0);
  
  remove(file_path);
}
END_TEST


Suite *suite_case1(void) {

  Suite *s = suite_create("case1");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, teste_insert_item);
  tcase_add_test(tc_core, teste_clean_chart);

  suite_add_tcase(s, tc_core);

  return s;
}

Suite *suite_case2(void) {
  Suite *s = suite_create("case2");
  TCase *tc_core = tcase_create("core");
  
  tcase_add_test(tc_core, teste_read_csv);
  suite_add_tcase(s, tc_core);
  
  return s;
}


int main(void) {
  SRunner *sr = srunner_create(suite_case1());
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  SRunner *sr2 = srunner_create(suite_case2());
  srunner_run_all(sr2, CK_VERBOSE);
  int number_failed2 = srunner_ntests_failed(sr2);
  srunner_free(sr2);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
