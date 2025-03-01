#include <check.h>
#include <mercado.h>
#include <stdlib.h>
#include <unistd.h>

START_TEST(teste_insert_item) {
  Product cart[2] = {{"banana", 2, 1.1}, {"vassoura", 3, 1}};

  int pipe_fds[2];
  pipe(pipe_fds);
  write(pipe_fds[1], "2\n3\n", 5);

  dup2(pipe_fds[0], STDIN_FILENO);
  close(pipe_fds[0]);

  insert_item(cart);

  ck_assert_int_eq(cart[1].qtd, 6);
}
END_TEST

START_TEST(teste_clean_chart) {

  Product cart[2] = {{"banana", 2, 1.1}, {"vassoura", 3, 1}};

  clean_cart(cart);

  ck_assert_int_eq(cart[0].qtd, 0);
  ck_assert_int_eq(cart[1].qtd, 0);
}

Suite *suite_case1(void) {

  Suite *s = suite_create("case1");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, teste_insert_item);
  tcase_add_test(tc_core, teste_clean_chart);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  SRunner *sr = srunner_create(suite_case1());
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
