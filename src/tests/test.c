#include <check.h>
#include "../smartcalc.h"


#define EPS 1e-7

START_TEST(calculate_01) {
  char str[] = " 2 +6 -x";
  double result_num = 9, test_num = 0, x = -1;
  stack *input = NULL;
  stack *ready = NULL;
  no_space(str);
  validator(str);
  parser(str, &input);
  rpn(&input, &ready, x);
  test_num = calculate(&ready);
  ck_assert_double_eq(test_num, result_num);
}
END_TEST

START_TEST(calculate_01_1) {
  char str[] = " ";
  double result_num = 0, test_num = 0, x = 0;
  stack *input = NULL;
  stack *ready = NULL;
  validator(str);
  parser(str, &input);
  rpn(&input, &ready, x);
  test_num = calculate(&ready);
  ck_assert_double_eq(test_num, result_num);
}
END_TEST

START_TEST(calculate_01_2) {
  char str[] = "(20000*0.01)/(1-(1+0.01)^(-12)";
  double result_num = 1776.97, test_num = 0, x = 0;
  stack *input = NULL;
  stack *ready = NULL;
  validator(str);
  parser(str, &input);
  rpn(&input, &ready, x);
  test_num = calculate(&ready);
  ck_assert_ldouble_eq_tol(test_num, result_num, 1e-2);
}
END_TEST

START_TEST(calculate_02) {
  char str[] = "-7+8";
  double result_num = 1, test_num = 0, x = 0;
  stack *input = NULL;
  stack *ready = NULL;
  validator(str);
  parser(str, &input);
  // reverse(&input);
  rpn(&input, &ready, x);
  test_num = calculate(&ready);
  ck_assert_double_eq(test_num, result_num);
}
END_TEST

START_TEST(calculate_03) {
  char str[] = "99*(-10)+21";
  double result_num = -969, test_num = 0, x = 0;
  stack *input = NULL;
  stack *ready = NULL;
  validator(str);
  parser(str, &input);
  rpn(&input, &ready, x);
  test_num = calculate(&ready);
  ck_assert_double_eq(test_num, result_num);
}
END_TEST

// START_TEST(calculate_04) {
//   char str[] = "sin(3)";
//   double result_num = 0.1411200, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_ldouble_eq_tol(test_num, result_num, 1e-8);
// }
// END_TEST

START_TEST(calculate_04) {
  char str[] = "20000*(0.1+(0.1/(1+0.1)*24-1)";
  double result_num = 0.1411200, test_num = 0, x = 0;
  stack *input = NULL;
  stack *ready = NULL;
  validator(str);
  parser(str, &input);
  rpn(&input, &ready, x);
  test_num = calculate(&ready);
  ck_assert_ldouble_eq_tol(test_num, result_num, 1e-8);
}
END_TEST

START_TEST(calculate_05) {
  char str[] = "(120000*0.15*30)/365";
  double result_num = 1479.45, test_num, x = 0;
  stack *input = NULL;
  stack *ready = NULL;
  validator(str);
  parser(str, &input);
  rpn(&input, &ready, x);
  test_num = calculate(&ready);
  ck_assert_double_eq(test_num, result_num);
}
END_TEST

// START_TEST(calculate_06) {
//   char str[] = "11.0+12.0*13.0";
//   double result_num = 167, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(calculate_07) {
//   char str[] = "1.0/2.0*(2.0-1.0)";
//   double result_num = 0.5, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(calculate_08) {
//   char str[] = "2^2";
//   double result_num = 4, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(calculate_09) {
//   char str[] = "2^3^2";
//   double result_num = 512, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(calculate_10) {
//   char str[] = "sin(1.352^9/(4+3))";
//   double result_num = 0.83348048, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_ldouble_eq_tol(test_num, result_num, 1e-8);
// }
// END_TEST

// START_TEST(calculate_10_1) {
//   char str[] = "cos(1/3)*sin(1.352^9/(4+3))";
//   double result_num = 0.78760317717, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_ldouble_eq_tol(test_num, result_num, 1e-10);
// }
// END_TEST

// START_TEST(calculate_11) {
//   char str[] = "2+9.3-8^3/(4+56.2)";
//   double result_num = 2.7950166, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_ldouble_eq_tol(test_num, result_num, 1e-7);
// }
// END_TEST

// START_TEST(calculate_11_1) {
//   char str[] = "-(2+9.3-8^3/(4+56.2))";
//   double result_num = -2.79501661, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_ldouble_eq_tol(test_num, result_num, 1e-7);
// }
// END_TEST

// START_TEST(calculate_12) {
//   char str[] = "2*x";
//   double result_num = 6, test_num, x = 3;
//   Queue outputQueue = createQueue();
//   Stack stack = createStack();
//   to_rpn(str, &outputQueue, &stack);
//   test_num = calculate(outputQueue, x);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(calculate_13) {
//   char str[] = "log(15)";
//   double result_num = 1.1760912, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_ldouble_eq_tol(test_num, result_num, 1e-7);
// }
// END_TEST

// START_TEST(calculate_15) {
//   char str[] = "cos(x)";
//   double result_num = 0.998629, test_num, x = 3;
//   Queue outputQueue = createQueue();
//   Stack stack = createStack();
//   to_rpn(str, &outputQueue, &stack);
//   test_num = calculate(outputQueue, x);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(calculate_16) {
//   char str[] = "-7-8*(99^(2^2)-log(sin(99/0.12031-(10*0.85))))";
//   double result_num = -768476815.32054478, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_ldouble_eq_tol(test_num, result_num, 1e-8);
// }
// END_TEST

// START_TEST(calculate_16_1) {
//   char str[] = "8mod5";
//   double result_num = 3, test_num = 0;
//   stack *input = NULL;
//   stack *ready = NULL;
//   validator(str);
//   parser(str, &input);
//   rpn(&input, &ready);
//   test_num = calculate(&ready);
//   ck_assert_ldouble_eq_tol(test_num, result_num, 1e-0);
// }
// END_TEST

// START_TEST(calculate_17) {
//   char str[] = "2*(200/75)+10mod3";
//   double result_num = 6.3333334, test_num, x = 0;
//   Queue outputQueue = createQueue();
//   Stack stack = createStack();
//   to_rpn(str, &outputQueue, &stack);
//   test_num = calculate(outputQueue, x);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(calculate_18) {
//   char str[] = "sqrt25";
//   double result_num = 5, test_num, x = 0;
//   Queue outputQueue = createQueue();
//   Stack stack = createStack();
//   to_rpn(str, &outputQueue, &stack);
//   test_num = calculate(outputQueue, x);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(calculate_19) {
//   char str[] = "asin0.5";
//   double result_num = 0.5235987, test_num, x = 0;
//   Queue outputQueue = createQueue();
//   Stack stack = createStack();
//   to_rpn(str, &outputQueue, &stack);
//   test_num = calculate(outputQueue, x);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(calculate_20) {
//   char str[] = "tan1";
//   double result_num = 0.0174551, test_num, x = 0;
//   Queue outputQueue = createQueue();
//   Stack stack = createStack();
//   to_rpn(str, &outputQueue, &stack);
//   test_num = calculate(outputQueue, x);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(calculate_21) {
//   char str[] = "atan";
//   double result_num = 0.4636476, test_num, x = 0;
//   Queue outputQueue = createQueue();
//   Stack stack = createStack();
//   to_rpn(str, &outputQueue, &stack);
//   test_num = calculate(outputQueue, x);
//   ck_assert_double_eq(test_num, result_num);
// }
// END_TEST

// START_TEST(credit_01) {
//   double amount = 200000;
//   double rate = 0.12;
//   int term = 24;
//   char type = 'd';
//   double payment = 0, overpayment = 0, total_payments = 0;
//   credit_calc(amount, term, rate, type, &payment, &overpayment,
//               &total_payments);
//   ck_assert_double_eq_tol(9375.0, payment, EPS);
//   ck_assert_double_eq_tol(25000.0, overpayment, EPS);
//   ck_assert_double_eq_tol(225000.0, total_payments, EPS);
// }
// END_TEST

START_TEST(credit_02) {
  double credit_sum = 200000;
  double rate = 10;
  int mounth = 24;
  // char type = 'a';
  double payment = 0, overpayment = 0, total_payments = 0;
  credit_calc(rate, mounth, credit_sum, &payment, &total_payments, &overpayment);
  ck_assert_double_eq_tol(9228.99, payment, EPS);
    ck_assert_double_eq(21495.7, overpayment);
    ck_assert_double_eq_tol(221495.65, total_payments, EPS);
}
END_TEST

START_TEST(credit_03) {
  double credit_sum = 200000;
  double rate = 6;
  int mounth = 24;
  // char type = 'a';
  double payment = 0, overpayment = 0, total_payments = 0;
  credit_calc(rate, mounth, credit_sum, &payment, &total_payments, &overpayment);
  ck_assert_double_eq_tol(8864.12, payment, 1e-1);
  ck_assert_double_eq_tol(212738.87, total_payments, 1e-1);
  ck_assert_double_eq_tol(12738.91, overpayment, 1e-1);
}
END_TEST

Suite *count_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("count_test");
  tc_core = tcase_create("count_test");

  tcase_add_test(tc_core, calculate_01);
  tcase_add_test(tc_core, calculate_01_1);
  tcase_add_test(tc_core, calculate_01_2);
  tcase_add_test(tc_core, calculate_02);
  tcase_add_test(tc_core, calculate_03);
  tcase_add_test(tc_core, calculate_04);
  tcase_add_test(tc_core, calculate_05);
  // tcase_add_test(tc_core, calculate_06);
  // tcase_add_test(tc_core, calculate_07);
  // tcase_add_test(tc_core, calculate_08);
  // tcase_add_test(tc_core, calculate_09);
  // tcase_add_test(tc_core, calculate_10);
  // tcase_add_test(tc_core, calculate_10_1);
  // tcase_add_test(tc_core, calculate_11);
  // tcase_add_test(tc_core, calculate_11_1);
  // tcase_add_test(tc_core, calculate_12);
  // tcase_add_test(tc_core, calculate_13);
  // tcase_add_test(tc_core, calculate_15);
  // tcase_add_test(tc_core, calculate_16);
  // tcase_add_test(tc_core, calculate_16_1);
  // tcase_add_test(tc_core, calculate_17);
  // tcase_add_test(tc_core, calculate_18);
  // tcase_add_test(tc_core, calculate_19);
  // tcase_add_test(tc_core, calculate_20);
  // tcase_add_test(tc_core, calculate_21);

  suite_add_tcase(s, tc_core);

  return s;
}

Suite *credit_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("credit_test");
  tc_core = tcase_create("credit_test");

//   tcase_add_test(tc_core, credit_01);
  // tcase_add_test(tc_core, credit_02);
  // tcase_add_test(tc_core, credit_03);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = count_test();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  no_failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  s = credit_test();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  no_failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}