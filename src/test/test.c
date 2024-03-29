#include <check.h>

#include "../backend/s21_calculator.h"
#define TOLERANCE 1e-6

START_TEST(calc_0) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "3.14 / 7 + 8";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 8.44857143, TOLERANCE);
}
END_TEST

START_TEST(calc_pow) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "2^3^2";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 512, TOLERANCE);
}
END_TEST

START_TEST(calc_mul) {
  stack_operators stack_op;
  stack_numbers stack_num;

  double x = 0.0;

  char* expression_string = "10.505 - 0.25 * 2";
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 10.005, TOLERANCE);
}
END_TEST

START_TEST(calc_braces) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "(10.505 - 0.25) * 2.56";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 26.2528, TOLERANCE);
}
END_TEST

START_TEST(calc_cos1) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "cos(7)";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 0.75390225, TOLERANCE);
}
END_TEST

START_TEST(calc_cos2) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "cos(2.5 + 8)";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, -0.47553693, TOLERANCE);
}
END_TEST

START_TEST(calc_sin1) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "sin(2.5 + 8 * 2)";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, -0.34248062, TOLERANCE);
}
END_TEST

START_TEST(calc_ln1) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "3 + ln(7)";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 4.94591015, TOLERANCE);
}
END_TEST

START_TEST(calc_mod) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "13.4 mod 2";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 1.4, TOLERANCE);
}
END_TEST

START_TEST(calc_tan) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "tan(896) * 13.4 mod 2";
  double result = 0.0;
  double x = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 0.1043888, TOLERANCE);
}
END_TEST

START_TEST(calc_acos) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "acos(0.5) + 5";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 6.04719755, TOLERANCE);
}
END_TEST

START_TEST(calc_asin) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "asin(0.7596324569) + 1";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 1.86274778, TOLERANCE);
}
END_TEST

START_TEST(calc_atan) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "atan(0.697865) - 3";
  double result = 0.0;
  double x = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, -2.39070835, TOLERANCE);
}
END_TEST

START_TEST(calc_sqrt) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "sqrt(54654.6568)";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 233.783354412, TOLERANCE);
}
END_TEST

START_TEST(calc_log) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "log(54654.6568)";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 4.73762717153, TOLERANCE);
}
END_TEST

START_TEST(calc_1) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "506546 + sin(2+8.5 * 1) - log(54654.6568)";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 506540.382677, TOLERANCE);
}
END_TEST

START_TEST(calc_2) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "2^8.5 * 1 + sqrt(87.554+cos(1))";
  double result = 0.0;
  double x = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 371.424528471, TOLERANCE);
}
END_TEST

START_TEST(calc_unarn) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "-3-8+(-20)";
  double result = 0.0;
  double x = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, -31, TOLERANCE);
}
END_TEST

START_TEST(calc_3) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "cos(cos(cos(cos(cos(30)))))";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 0.65818476393, TOLERANCE);
}
END_TEST

START_TEST(calc_4) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "sin(1)^2+cos(1)^2";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 1, TOLERANCE);
}
END_TEST

START_TEST(calc_5) {
  stack_operators stack_op;
  stack_numbers stack_num;
  double x = 0.0;
  char* expression_string = "3^(-0.4)+1";
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 1.64439401498, TOLERANCE);
}
END_TEST

START_TEST(calc_6) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "2^(2+3*2.5+6)";
  double result = 0.0;
  double x = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 46340.9500118, TOLERANCE);
}
END_TEST

START_TEST(calc_7) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "1-(-11+8)";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 4, TOLERANCE);
}
END_TEST

START_TEST(calc_8) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "2+0-1";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 1, TOLERANCE);
}
END_TEST

START_TEST(calc_9) {
  stack_operators stack_op;
  stack_numbers stack_num;

  char* expression_string = "-sin(-1)";
  double x = 0.0;
  double result = 0.0;
  result = parsing(expression_string, &stack_num, &stack_op, x);
  ck_assert_double_eq_tol(result, 0.8414709848, TOLERANCE);
}
END_TEST

START_TEST(test_plus) {
  stack_numbers stack_num;
  stack_init_num(&stack_num);
  double result;

  // Test case 1: Adding two positive numbers
  stack_push_num(&stack_num, &(double){2.0});
  stack_push_num(&stack_num, &(double){3.0});
  result = plus(&stack_num, 0.0);
  ck_assert_double_eq_tol(result, 5.0, 1e-6);

  // Test case 2: Adding two negative numbers
  stack_push_num(&stack_num, &(double){-2.0});
  stack_push_num(&stack_num, &(double){-3.0});
  result = plus(&stack_num, 0.0);
  ck_assert_double_eq_tol(result, -5.0, 1e-6);

  // Test case 3: Adding a positive and a negative number
  stack_push_num(&stack_num, &(double){2.0});
  stack_push_num(&stack_num, &(double){-3.0});
  result = plus(&stack_num, 0.0);
  ck_assert_double_eq_tol(result, -1.0, 1e-6);

  // Test case 4: Adding zero to a number
  stack_push_num(&stack_num, &(double){5.0});
  stack_push_num(&stack_num, &(double){0.0});
  result = plus(&stack_num, 0.0);
  ck_assert_double_eq_tol(result, 5.0, 1e-6);
}
END_TEST

START_TEST(test_plus_positive_numbers) {
  stack_numbers stack_num;
  double result = 0.0;

  // Инициализация стека и добавление двух положительных чисел
  stack_init_num(&stack_num);
  double num1 = 5.0;
  double num2 = 7.0;
  stack_push_num(&stack_num, &num1);
  stack_push_num(&stack_num, &num2);

  // Вызов функции plus
  result = plus(&stack_num, result);

  // Проверка результата
  ck_assert_double_eq_tol(result, 12.0, TOLERANCE);
}
END_TEST

START_TEST(test_plus_mixed_sign_numbers) {
  stack_numbers stack_num;
  double result = 0.0;

  // Инициализация стека и добавление чисел разных знаков
  stack_init_num(&stack_num);
  double num1 = -3.0;
  double num2 = 5.0;
  stack_push_num(&stack_num, &num1);
  stack_push_num(&stack_num, &num2);

  // Вызов функции plus
  result = plus(&stack_num, result);

  // Проверка результата
  ck_assert_double_eq_tol(result, 2.0, TOLERANCE);
}

int main() {
  Suite* suite = suite_create("core");
  TCase* t_case = tcase_create("core");
  SRunner* sr = srunner_create(suite);

  suite_add_tcase(suite, t_case);

  tcase_add_test(t_case, calc_pow);
  tcase_add_test(t_case, calc_mul);
  tcase_add_test(t_case, calc_braces);
  tcase_add_test(t_case, calc_cos1);
  tcase_add_test(t_case, calc_cos2);
  tcase_add_test(t_case, calc_sin1);
  tcase_add_test(t_case, calc_ln1);
  tcase_add_test(t_case, calc_mod);
  tcase_add_test(t_case, calc_tan);
  tcase_add_test(t_case, calc_acos);
  tcase_add_test(t_case, calc_asin);
  tcase_add_test(t_case, calc_atan);
  tcase_add_test(t_case, calc_sqrt);
  tcase_add_test(t_case, calc_log);
  tcase_add_test(t_case, calc_0);
  tcase_add_test(t_case, calc_1);
  tcase_add_test(t_case, calc_2);
  tcase_add_test(t_case, calc_3);
  tcase_add_test(t_case, calc_unarn);
  tcase_add_test(t_case, calc_4);
  tcase_add_test(t_case, calc_5);
  tcase_add_test(t_case, calc_6);
  tcase_add_test(t_case, calc_7);
  tcase_add_test(t_case, calc_8);
  tcase_add_test(t_case, calc_9);
  tcase_add_test(t_case, test_plus);
  tcase_add_test(t_case, test_plus_mixed_sign_numbers);
  tcase_add_test(t_case, test_plus_positive_numbers);
  double result;

  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
