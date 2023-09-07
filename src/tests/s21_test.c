#include <check.h>

#include "../s21_decimal.h"

void test_add(s21_decimal m1[], s21_decimal m2[], int size_m1, int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_add(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_add(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 0);
      s21_set_sign(&m2[j], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_add(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 1);
      s21_set_sign(&m2[j], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_add(m1[i], m2[j], &res1);
    }
  }
}

void test_sub(s21_decimal m1[], s21_decimal m2[], int size_m1, int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_sub(m1[i], m2[j], &res1);
      s21_sub(m2[i], m1[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_sub(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 0);
      s21_set_sign(&m2[j], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_sub(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 1);
      s21_set_sign(&m2[j], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_sub(m1[i], m2[j], &res1);
    }
  }
}

void test_mul(s21_decimal m1[], s21_decimal m2[], int size_m1, int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_mul(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_mul(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 0);
      s21_set_sign(&m2[j], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_mul(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 1);
      s21_set_sign(&m2[j], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_mul(m1[i], m2[j], &res1);
    }
  }
}

void test_div(s21_decimal m1[], s21_decimal m2[], int size_m1, int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_div(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_div(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 0);
      s21_set_sign(&m2[j], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_div(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 1);
      s21_set_sign(&m2[j], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_div(m1[i], m2[j], &res1);
    }
  }
}

void test_mod(s21_decimal m1[], s21_decimal m2[], int size_m1, int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_mod(m1[i], m2[j], &res1);
    }
  }
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_set_sign(&m1[i], 1);
      s21_decimal res1 = {{0, 0, 0, 0}};
      s21_mod(m1[i], m2[j], &res1);
    }
  }
}

void test_equal(s21_decimal m1[], s21_decimal m2[], int size_m1, int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_is_equal(m1[i], m2[j]);
    }
  }
}

void test_not_equal(s21_decimal m1[], s21_decimal m2[], int size_m1,
                    int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_is_not_equal(m1[i], m2[j]);
    }
  }
}

void test_less(s21_decimal m1[], s21_decimal m2[], int size_m1, int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_is_less(m1[i], m2[j]);
    }
  }
}

void test_less_eq(s21_decimal m1[], s21_decimal m2[], int size_m1,
                  int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_is_less_or_equal(m1[i], m2[j]);
    }
  }
}

void test_greater(s21_decimal m1[], s21_decimal m2[], int size_m1,
                  int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_is_greater(m1[i], m2[j]);
    }
  }
}

void test_greater_eq(s21_decimal m1[], s21_decimal m2[], int size_m1,
                     int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
      s21_is_greater_or_equal(m1[i], m2[j]);
    }
  }
}

void test_truncate(s21_decimal m1[], int size_m1) {
  for (int i = 0; i < size_m1; i++) {
    s21_set_sign(&m1[i], 0);
    s21_decimal res1 = {{0, 0, 0, 0}};
    s21_truncate(m1[i], &res1);
  }
  for (int i = 0; i < size_m1; i++) {
    s21_set_sign(&m1[i], 1);
    s21_decimal res1 = {{0, 0, 0, 0}};
    s21_truncate(m1[i], &res1);
  }
}

void test_floor(s21_decimal m1[], int size_m1) {
  for (int i = 0; i < size_m1; i++) {
    s21_set_sign(&m1[i], 0);
    s21_decimal res1 = {{0, 0, 0, 0}};
    s21_floor(m1[i], &res1);
  }
  for (int i = 0; i < size_m1; i++) {
    s21_set_sign(&m1[i], 1);
    s21_decimal res1 = {{0, 0, 0, 0}};
    s21_floor(m1[i], &res1);
  }
}

void test_negate(s21_decimal m1[], int size_m1) {
  for (int i = 0; i < size_m1; i++) {
    s21_set_sign(&m1[i], 0);
    s21_decimal res1 = {{0, 0, 0, 0}};
    s21_negate(m1[i], &res1);
  }
  for (int i = 0; i < size_m1; i++) {
    s21_set_sign(&m1[i], 1);
    s21_decimal res1 = {{0, 0, 0, 0}};
    s21_negate(m1[i], &res1);
  }
}

void test_round(s21_decimal m1[], int size_m1) {
  for (int i = 0; i < size_m1; i++) {
    s21_set_sign(&m1[i], 0);
    s21_decimal res1 = {{0, 0, 0, 0}};
    s21_round(m1[i], &res1);
  }
  for (int i = 0; i < size_m1; i++) {
    s21_set_sign(&m1[i], 1);
    s21_decimal res1 = {{0, 0, 0, 0}};
    s21_round(m1[i], &res1);
  }
}

void test_int_dec(int m3[], int size_m3) {
  for (int i = 0; i < size_m3; i++) {
    s21_decimal res1 = {{0, 0, 0, 0}};
    s21_from_int_to_decimal(m3[i], &res1);
  }
}

void test_dec_int(s21_decimal m1[], int size_m1) {
  for (int i = 0; i < size_m1; i++) {
    int res1 = 0;
    s21_from_decimal_to_int(m1[i], &res1);
  }
}

void test_float_dec(float value[], int size_m5) {
  for (int i = 0; i < size_m5; i++) {
    s21_decimal res1 = {{0, 0, 0, 0}};
    s21_from_float_to_decimal(value[i], &res1);
  }
}

void test_dec_float(s21_decimal m1[], int size_m1) {
  for (int i = 0; i < size_m1; i++) {
    float res1 = 0;
    s21_from_decimal_to_float(m1[i], &res1);
  }
}

START_TEST(test_all) {
  s21_decimal m1[] = {{{0, 100, 0, e1}},
                      {{523798, 0, 0, e1}},
                      {{UINT_MAX, 0, 0, e1}},
                      {{1, 0, 0, 0}},
                      {{100, 0, 0, 0}},
                      {{0, UINT_MAX, 523798, e1*2}},
                      {{0, UINT_MAX, UINT_MAX, 0}},
                      {{0, UINT_MAX, 1, 0}},
                      {{0, UINT_MAX, 100, 0}},
                      {{UINT_MAX, 523798, 0, 0}},
                      {{UINT_MAX, UINT_MAX, 0, 0}},
                      {{UINT_MAX, 1, 0, 0}},
                      {{UINT_MAX, 100, 0, 0}},
                      {{523798, 523798, 523798, 0}},
                      {{UINT_MAX, 0, 100, 0}},
                      {{1, 0, 1, 0}},
                      {{325, 9999, 0, 0}},
                      {{1, 1, 1, 0}},
                      {{UINT_MAX, UINT_MAX, UINT_MAX, 0}},
                      {{2136, 12366, 21355, 0}},
                      {{999999, 999999, 999999, 0}},
                      {{0, 0, 523798, e1 * 1}},
                      {{0, 0, UINT_MAX, e1 * 1}},
                      {{0, 0, 1, e1 * 1}},
                      {{0, 0, 100, e1 * 1}},
                      {{0, 523798, 0, e1 * 1}},
                      {{0, UINT_MAX, 0, e1 * 1}},
                      {{0, 1, 0, e1 * 1}}};
  s21_decimal m2[] = {{{1249184, 213, 1, 0}},
                      {{1453254535, 2123413241, 21367563, 0}},
                      {{99999999, 0, 432680, 0}},
                      {{5555, 9999999, 0, 0}},
                      {{1, 1, 1, 0}},
                      {{0, 1, 0, 0}},
                      {{UINT_MAX, UINT_MAX, 0, 0}},
                      {{UINT_MAX, 2, 12343214, 0}},
                      {{1234, 1234569, 0, 0}},
                      {{22222, 13, 132154, 0}},
                      {{UINT_MAX, 4312, 4291264512, 0}},
                      {{2111111, 112312366, 121355, 0}},
                      {{1, 0, 0, e1}}};
  int m3[] = {
      5123,       2135653,   -1237,      -42736,    1,          0,
      -0,         -3241767,  2635,       72136461,  -55555,     21836754,
      -INT_MAX,   INT_MAX,   1823741784, 999999999, 111111111,  55555555,
      11,         3333,      77777777,   -41348627, 132788,     -888887,
      -153254671, -63583289, 111,        92318,     5,          1111,
      13123132,   32133,     -2373176,   123,       -132358999, 92178361,
      888888888,  81237373,  1111,       18387471,
  };
  float m5[] = {
      5123.123213,   2135653.111,      -1237.321,     -42736.1,
      1.99999999,    0.12343,          -0.0000321,    -3241767,
      2635.7421362,  72136461.111,     5.00032,       218367542,
      -UINT_MAX,     UINT_MAX,         11.123,        999999999.34,
      111111111.11,  55555555.222,     113.566777,    3333.98765545677,
      77777777.3124, -41348627.3547,   132788.132798, -888887.237896,
      -153254671,    -63583289.781236, 111.1111111,   92318.666666,
      5.7777777777,  1111.12365871,
  };
  int size_m1 = sizeof(m1) / sizeof(m1[0]);
  int size_m2 = sizeof(m2) / sizeof(m2[0]);
  int size_m3 = sizeof(m3) / sizeof(m3[0]);
  int size_m5 = sizeof(m5) / sizeof(m5[0]);
  test_add(m1, m2, size_m1, size_m2);
  test_sub(m1, m2, size_m1, size_m2);
  test_sub(m2, m1, size_m2, size_m1);
  test_mul(m1, m2, size_m1, size_m2);
  test_div(m1, m2, size_m1, size_m2);
  test_mod(m1, m2, size_m1, size_m2);
  test_equal(m1, m2, size_m1, size_m2);
  test_not_equal(m1, m2, size_m1, size_m2);
  test_less(m1, m2, size_m1, size_m2);
  test_less_eq(m1, m2, size_m1, size_m2);
  test_greater(m1, m2, size_m1, size_m2);
  test_greater_eq(m1, m2, size_m1, size_m2);
  test_truncate(m1, size_m1);
  test_truncate(m2, size_m2);
  test_floor(m1, size_m1);
  test_floor(m2, size_m2);
  test_negate(m1, size_m1);
  test_negate(m2, size_m2);
  test_round(m1, size_m1);
  test_round(m2, size_m2);
  test_int_dec(m3, size_m3);
  test_dec_int(m1, size_m1);
  test_float_dec(m5, size_m5);
  test_dec_float(m1, size_m1);
  test_dec_float(m2, size_m2);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite = suite_create("s21_decimal");

  TCase *tc_test_all = tcase_create("test_all");

  tcase_add_test(tc_test_all, test_all);

  suite_add_tcase(suite, tc_test_all);

  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}