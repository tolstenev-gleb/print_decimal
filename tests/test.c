#include <check.h>
#include "../src/print_decimal.h"

START_TEST(test_str_to_decimal_zero) {
  // Test
  // str:              "0"
  // s21_decimal bits:  {{0, 0, 0, 0}}
  const char *str = "0";
  s21_decimal dest = {{1, 1, 1, 2147483648}};  // non-zero decimal
  s21_decimal expected = {{0, 0, 0, 0}};
  bool expect_error = false;

  bool actual_error = str_to_decimal(str, &dest);

  ck_assert_uint_eq(expect_error, actual_error);
  ck_assert_uint_eq(expected.bits[0], dest.bits[0]);
  ck_assert_uint_eq(expected.bits[1], dest.bits[1]);
  ck_assert_uint_eq(expected.bits[2], dest.bits[2]);
  ck_assert_uint_eq(expected.bits[3], dest.bits[3]);
}
END_TEST

START_TEST(test_str_to_decimal_one) {
  // Test
  // str:              "1"
  // s21_decimal bits:  {{1, 0, 0, 0}}
  const char *str = "1";
  s21_decimal dest = {{0, 0, 0, 0}};
  s21_decimal expected = {{1, 0, 0, 0}};
  bool expect_error = false;

  bool actual_error = str_to_decimal(str, &dest);

  ck_assert_uint_eq(expect_error, actual_error);
  ck_assert_uint_eq(expected.bits[0], dest.bits[0]);
  ck_assert_uint_eq(expected.bits[1], dest.bits[1]);
  ck_assert_uint_eq(expected.bits[2], dest.bits[2]);
  ck_assert_uint_eq(expected.bits[3], dest.bits[3]);
}
END_TEST

START_TEST(test_str_to_decimal_plus_one) {
  // Test
  // str:              "+1"
  // s21_decimal bits:  {{1, 0, 0, 0}}
  const char *str = "+1";
  s21_decimal dest = {{0, 0, 0, 0}};
  s21_decimal expected = {{1, 0, 0, 0}};
  bool expect_error = false;

  bool actual_error = str_to_decimal(str, &dest);

  ck_assert_uint_eq(expect_error, actual_error);
  ck_assert_uint_eq(expected.bits[0], dest.bits[0]);
  ck_assert_uint_eq(expected.bits[1], dest.bits[1]);
  ck_assert_uint_eq(expected.bits[2], dest.bits[2]);
  ck_assert_uint_eq(expected.bits[3], dest.bits[3]);
}
END_TEST

START_TEST(test_str_to_decimal_minus_one) {
  // Test
  // str:              "-1"
  // s21_decimal bits:  {{1, 0, 0, 2147483648}}
  const char *str = "-1";
  s21_decimal dest = {{0, 0, 0, 0}};
  s21_decimal expected = {{1, 0, 0, 2147483648}};
  bool expect_error = false;

  bool actual_error = str_to_decimal(str, &dest);

  ck_assert_uint_eq(expect_error, actual_error);
  ck_assert_uint_eq(expected.bits[0], dest.bits[0]);
  ck_assert_uint_eq(expected.bits[1], dest.bits[1]);
  ck_assert_uint_eq(expected.bits[2], dest.bits[2]);
  ck_assert_uint_eq(expected.bits[3], dest.bits[3]);
}
END_TEST

START_TEST(test_str_to_decimal_max_uint_overflow) {
  // Test
  // str:              "4294967296"
  // s21_decimal bits:  {{0, 1, 0, 0}}
  const char *str = "4294967296";
  s21_decimal dest = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 1, 0, 0}};
  bool expect_error = false;

  bool actual_error = str_to_decimal(str, &dest);

  ck_assert_uint_eq(expect_error, actual_error);
  ck_assert_uint_eq(expected.bits[0], dest.bits[0]);
  ck_assert_uint_eq(expected.bits[1], dest.bits[1]);
  ck_assert_uint_eq(expected.bits[2], dest.bits[2]);
  ck_assert_uint_eq(expected.bits[3], dest.bits[3]);
}
END_TEST

START_TEST(test_str_to_decimal_scale_1) {
  // Test
  // str:              "0.1"
  // s21_decimal bits:  {{1, 0, 0, 65536}}
  const char *str = "0.1";
  s21_decimal dest = {{0, 0, 0, 0}};
  s21_decimal expected = {{1, 0, 0, 65536}};
  bool expect_error = false;

  bool actual_error = str_to_decimal(str, &dest);

  ck_assert_uint_eq(expect_error, actual_error);
  ck_assert_uint_eq(expected.bits[0], dest.bits[0]);
  ck_assert_uint_eq(expected.bits[1], dest.bits[1]);
  ck_assert_uint_eq(expected.bits[2], dest.bits[2]);
  ck_assert_uint_eq(expected.bits[3], dest.bits[3]);
}
END_TEST

START_TEST(test_str_to_decimal_scale_5) {
  // Test
  // str:              "0.12345"
  // s21_decimal bits:  {{12345, 0, 0, 327680}}
  const char *str = "0.12345";
  s21_decimal dest = {{0, 0, 0, 0}};
  s21_decimal expected = {{12345, 0, 0, 327680}};
  bool expect_error = false;

  bool actual_error = str_to_decimal(str, &dest);

  ck_assert_uint_eq(expect_error, actual_error);
  ck_assert_uint_eq(expected.bits[0], dest.bits[0]);
  ck_assert_uint_eq(expected.bits[1], dest.bits[1]);
  ck_assert_uint_eq(expected.bits[2], dest.bits[2]);
  ck_assert_uint_eq(expected.bits[3], dest.bits[3]);
}
END_TEST

START_TEST(test_str_to_decimal_scale_max) {
  // Test
  // str:              "0.0000000000000000000000000001" <- 28 signs
  // s21_decimal bits:  {{1, 0, 0, 1835008}} <- scale 28
  const char *str = "0.0000000000000000000000000001";
  s21_decimal dest = {{0, 0, 0, 0}};
  s21_decimal expected = {{1, 0, 0, 1835008}};
  bool expect_error = false;

  bool actual_error = str_to_decimal(str, &dest);

  ck_assert_uint_eq(expect_error, actual_error);
  ck_assert_uint_eq(expected.bits[0], dest.bits[0]);
  ck_assert_uint_eq(expected.bits[1], dest.bits[1]);
  ck_assert_uint_eq(expected.bits[2], dest.bits[2]);
  ck_assert_uint_eq(expected.bits[3], dest.bits[3]);
}
END_TEST

START_TEST(test_str_to_decimal_max_decimal) {
  // Test
  // str:              "79228162514264337593543950335"
  // s21_decimal value: 79228162514264337593543950335
  // s21_decimal bits:  {{4294967295, 4294967295, 4294967295, 0}}
  const char *str = "79228162514264337593543950335";
  s21_decimal dest = {{0, 0, 0, 0}};
  s21_decimal expected = {{4294967295, 4294967295, 4294967295, 0}};
  bool expect_error = false;

  bool actual_error = str_to_decimal(str, &dest);

  ck_assert_uint_eq(expect_error, actual_error);
  ck_assert_uint_eq(expected.bits[0], dest.bits[0]);
  ck_assert_uint_eq(expected.bits[1], dest.bits[1]);
  ck_assert_uint_eq(expected.bits[2], dest.bits[2]);
  ck_assert_uint_eq(expected.bits[3], dest.bits[3]);
}
END_TEST

START_TEST(test_str_to_decimal_random) {
  // Test
  // str:              "-12345678901234.5678901234"
  // s21_decimal bits:  {{1821814770, 2602504352, 6692, 2148139008}}
  const char *str = "-12345678901234.5678901234";
  s21_decimal dest = {{0, 0, 0, 0}};
  s21_decimal expected = {{1821814770, 2602504352, 6692, 2148139008}};
  bool expect_error = false;

  bool actual_error = str_to_decimal(str, &dest);

  ck_assert_uint_eq(expect_error, actual_error);
  ck_assert_uint_eq(expected.bits[0], dest.bits[0]);
  ck_assert_uint_eq(expected.bits[1], dest.bits[1]);
  ck_assert_uint_eq(expected.bits[2], dest.bits[2]);
  ck_assert_uint_eq(expected.bits[3], dest.bits[3]);
}
END_TEST

Suite* example_suite_create(void) {
  Suite* suite = suite_create("print_decimal");
  TCase* tcase_core = tcase_create("Core of print_decimal");

  tcase_add_test(tcase_core, test_str_to_decimal_zero);
  tcase_add_test(tcase_core, test_str_to_decimal_one);
  tcase_add_test(tcase_core, test_str_to_decimal_plus_one);
  tcase_add_test(tcase_core, test_str_to_decimal_minus_one);
  tcase_add_test(tcase_core, test_str_to_decimal_max_uint_overflow);
  tcase_add_test(tcase_core, test_str_to_decimal_scale_1);
  tcase_add_test(tcase_core, test_str_to_decimal_scale_5);
  tcase_add_test(tcase_core, test_str_to_decimal_scale_max);
  tcase_add_test(tcase_core, test_str_to_decimal_max_decimal);
  tcase_add_test(tcase_core, test_str_to_decimal_random);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  int result = 0, failed_count = 0;
  Suite* suite = example_suite_create();
  SRunner* suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    result = 1;
  }
  return result;
}