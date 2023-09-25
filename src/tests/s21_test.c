#include <check.h>

#include "../s21_decimal.h"

#define s21_inf 1.0 / 0.0
#define s21_nan 0.0 / 0.0

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
      s21_decimal res1 = {{0, 0, 0, 1}};
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
}

void test_mod(s21_decimal m1[], s21_decimal m2[], int size_m1, int size_m2) {
  for (int i = 0; i < size_m1; i++) {
    for (int j = 0; j < size_m2; j++) {
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
  float res1 = 0;
  for (int i = 0; i < size_m1; i++) {
    s21_from_decimal_to_float(m1[i], &res1);
  }
  s21_from_decimal_to_float((s21_decimal){{1, 0, 0, e1 * 33}}, &res1);
}

START_TEST(test_all) {
  s21_decimal m1[] = {{{0, 100, 0, e1}},
                      {{523798, 0, 0, e1}},
                      {{UINT_MAX, 0, 0, e1}},
                      {{1, 0, 0, 0}},
                      {{100, 0, 0, 0}},
                      {{0, UINT_MAX, 523798, e1 * 2}},
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
  s21_decimal m4[] = {{{0, 100, 0, e1}},
                      {{UINT_MAX, 0, 0, e1 * 15}},
                      {{0, UINT_MAX, 523798, e1 * 2 | MINUS}},
                      {{0, UINT_MAX, 100, e1 * 5}},
                      {{UINT_MAX, 1, 0, e1 * 10}},
                      {{UINT_MAX, UINT_MAX, UINT_MAX, MINUS}},
                      {{0, 0, UINT_MAX, e1 * 16}},
                      {{0, 0, 100, MINUS}}};
  s21_decimal m6[] = {{{1249184, 213, 1, e1 * 5}},
                      {{1453254535, 2123413241, 21367563, e1 * 17}},
                      {{5555, 9999999, 0, e1 * 6 | MINUS}},
                      {{1, 0, 0, e1 * 15 | MINUS}},
                      {{UINT_MAX, UINT_MAX, UINT_MAX, MINUS}},
                      {{UINT_MAX, 2, 12343214, 0}},
                      {{22222, 13, 132154, e1 * 4 | MINUS}},
                      {{0, 0, 0, 0}},
                      {{1, 0, 0, e1 * 15}},
                      {{2111111, 112312366, 121355, e1 * 15}}};
  int m3[] = {
      5123,       2135653,   -1237,      -42736,    1,          0,
      -0,         -3241767,  2635,       72136461,  -55555,     21836754,
      -INT_MAX,   INT_MAX,   1823741784, 999999999, 111111111,  55555555,
      11,         3333,      77777777,   -41348627, 132788,     -888887,
      -153254671, -63583289, 111,        92318,     5,          1111,
      13123132,   32133,     -2373176,   123,       -132358999, 92178361,
      888888888,  81237373,  18387471,   s21_inf,   -s21_inf,   s21_nan,
  };
  float m5[] = {
      5123.123213,   2135653.111,
      -1237.321,     -42736.1,
      1.99999999,    0.12343,
      -0.0000321,    79228162514264337593543950335.0,
      2635.7421362,  72136461.111,
      5.00032,       218367542,
      -UINT_MAX,     UINT_MAX,
      11.123,        999999999.34,
      111111111.11,  55555555.222,
      113.566777,    3333.98765545677,
      77777777.3124, -41348627.3547,
      132788.132798, -888887.237896,
      -153254671,    -63583289.781236,
      111.1111111,   92318.666666,
      5.7777777777,  s21_inf,
      -s21_inf,      s21_nan,
  };
  int size_m1 = sizeof(m1) / sizeof(m1[0]);
  int size_m2 = sizeof(m2) / sizeof(m2[0]);
  int size_m3 = sizeof(m3) / sizeof(m3[0]);
  int size_m4 = sizeof(m4) / sizeof(m4[0]);
  int size_m5 = sizeof(m5) / sizeof(m5[0]);
  int size_m6 = sizeof(m6) / sizeof(m6[0]);
  test_add(m1, m2, size_m1, size_m2);
  test_sub(m1, m2, size_m1, size_m2);
  test_sub(m2, m1, size_m2, size_m1);
  test_mul(m1, m2, size_m1, size_m2);
  test_div(m4, m6, size_m4, size_m6);
  test_mod(m4, m6, size_m4, size_m6);
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

START_TEST(add_0) {
  s21_decimal val1 = {{152, 0, 0, MINUS}};
  s21_decimal val2 = {{24, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_1) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_2) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, MINUS}};
  s21_decimal val2 = {{1, 0, 0, MINUS}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(sub_0) {
  s21_decimal val1 = {{152, 0, 0, 0}};
  s21_decimal val2 = {{24, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_1) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{1, 0, 0, MINUS}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_2) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, MINUS}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(mul_0) {
  s21_decimal val1 = {{152, 0, 0, 0}};
  s21_decimal val2 = {{24, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_1) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{2, 0, 0, MINUS}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(div_0) {
  s21_decimal val1 = {{152, 0, 0, 0}};
  s21_decimal val2 = {{24, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_1) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{6, 0, 0, e1}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_2) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{6, 0, 0, e1 | MINUS}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_3) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(mod_0) {
  s21_decimal val1 = {{152, 0, 0, 0}};
  s21_decimal val2 = {{24, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mod(val1, val2, &res));
}
END_TEST

START_TEST(mod_1) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_mod(val1, val2, &res));
}
END_TEST

START_TEST(equal_0) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(equal_1) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, 0, 0}};
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_0) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(not_equal_1) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, 0, 0}};
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(less_0) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(less_1) {
  s21_decimal val1 = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(less_or_equal_0) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(less_or_equal_1) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(greater_0) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_1) {
  s21_decimal val1 = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(greater_or_equal_0) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(greater_or_equal_1) {
  s21_decimal val1 = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(int_to_dec_0) {
  int val1 = 123651;
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_from_int_to_decimal(val1, &res));
}
END_TEST

START_TEST(dec_to_int_0) {
  s21_decimal val1 = {{123556, 0, 0, 0}};
  int res = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(val1, &res));
}
END_TEST

START_TEST(dec_to_int_1) {
  s21_decimal val1 = {{123556, 0, 0, 0}};
  ck_assert_int_eq(1, s21_from_decimal_to_int(val1, NULL));
}
END_TEST

START_TEST(float_to_dec_0) {
  float val1 = 123651.129375;
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_from_float_to_decimal(val1, &res));
}
END_TEST

START_TEST(dec_to_float_0) {
  s21_decimal val1 = {{123552346, 0, 0, e1 * 6}};
  float res = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(val1, &res));
}
END_TEST

START_TEST(dec_to_float_1) {
  s21_decimal val1 = {{123556, 0, 0, 0}};
  ck_assert_int_eq(1, s21_from_decimal_to_float(val1, NULL));
}
END_TEST

START_TEST(truncate_0) {
  s21_decimal val1 = {{123556, 11320, 1, e1 * 10}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_truncate(val1, &res));
}
END_TEST

START_TEST(floor_0) {
  s21_decimal val1 = {{123556, 11320, 1, e1 * 10}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_floor(val1, &res));
}
END_TEST

START_TEST(negate_0) {
  s21_decimal val1 = {{123556, 11320, 1, e1 * 10}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_negate(val1, &res));
}
END_TEST

START_TEST(negate_1) {
  s21_decimal val1 = {{123556, 11320, 1, e1 * 10 | MINUS}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_negate(val1, &res));
}
END_TEST

START_TEST(round_0) {
  s21_decimal val1 = {{123556, 11320, 1, e1 * 10}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_round(val1, &res));
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite = suite_create("s21_decimal");

  TCase *tc_test_add = tcase_create("test_add");
  tcase_add_test(tc_test_add, add_0);
  tcase_add_test(tc_test_add, add_1);
  tcase_add_test(tc_test_add, add_2);
  suite_add_tcase(suite, tc_test_add);

  TCase *tc_test_sub = tcase_create("test_sub");
  tcase_add_test(tc_test_sub, sub_0);
  tcase_add_test(tc_test_sub, sub_1);
  tcase_add_test(tc_test_sub, sub_2);
  suite_add_tcase(suite, tc_test_sub);

  TCase *tc_test_mul = tcase_create("test_mul");
  tcase_add_test(tc_test_mul, mul_0);
  tcase_add_test(tc_test_mul, mul_1);
  tcase_add_test(tc_test_mul, mul_2);
  suite_add_tcase(suite, tc_test_mul);

  TCase *tc_test_div = tcase_create("test_div");
  tcase_add_test(tc_test_div, div_0);
  tcase_add_test(tc_test_div, div_1);
  tcase_add_test(tc_test_div, div_2);
  tcase_add_test(tc_test_div, div_3);
  suite_add_tcase(suite, tc_test_div);

  TCase *tc_test_mod = tcase_create("test_mod");
  tcase_add_test(tc_test_mod, mod_0);
  tcase_add_test(tc_test_mod, mod_1);
  suite_add_tcase(suite, tc_test_mod);

  TCase *tc_test_equal = tcase_create("test_equal");
  tcase_add_test(tc_test_equal, equal_0);
  tcase_add_test(tc_test_equal, equal_1);
  suite_add_tcase(suite, tc_test_equal);

  TCase *tc_test_not_equal = tcase_create("test_not_equal");
  tcase_add_test(tc_test_not_equal, not_equal_0);
  tcase_add_test(tc_test_not_equal, not_equal_1);
  suite_add_tcase(suite, tc_test_not_equal);

  TCase *tc_test_less = tcase_create("test_less");
  tcase_add_test(tc_test_less, less_0);
  tcase_add_test(tc_test_less, less_1);
  suite_add_tcase(suite, tc_test_less);

  TCase *tc_test_less_or_equal = tcase_create("test_less_or_equal");
  tcase_add_test(tc_test_less_or_equal, less_or_equal_0);
  tcase_add_test(tc_test_less_or_equal, less_or_equal_1);
  suite_add_tcase(suite, tc_test_less_or_equal);

  TCase *tc_test_greater = tcase_create("test_greater");
  tcase_add_test(tc_test_greater, greater_0);
  tcase_add_test(tc_test_greater, greater_1);
  suite_add_tcase(suite, tc_test_greater);

  TCase *tc_test_greater_or_equal = tcase_create("test_greater_or_equal");
  tcase_add_test(tc_test_greater_or_equal, greater_or_equal_0);
  tcase_add_test(tc_test_greater_or_equal, greater_or_equal_1);
  suite_add_tcase(suite, tc_test_greater_or_equal);

  TCase *tc_test_int_to_dec = tcase_create("test_int_to_dec");
  tcase_add_test(tc_test_int_to_dec, int_to_dec_0);
  suite_add_tcase(suite, tc_test_int_to_dec);

  TCase *tc_test_dec_to_int = tcase_create("test_dec_to_int");
  tcase_add_test(tc_test_dec_to_int, dec_to_int_0);
  tcase_add_test(tc_test_dec_to_int, dec_to_int_1);
  suite_add_tcase(suite, tc_test_dec_to_int);

  TCase *tc_test_float_to_dec = tcase_create("test_float_to_dec");
  tcase_add_test(tc_test_float_to_dec, float_to_dec_0);
  suite_add_tcase(suite, tc_test_float_to_dec);

  TCase *tc_test_dec_to_float = tcase_create("test_dec_to_float");
  tcase_add_test(tc_test_dec_to_float, dec_to_float_0);
  tcase_add_test(tc_test_dec_to_float, dec_to_float_1);
  suite_add_tcase(suite, tc_test_dec_to_float);

  TCase *tc_test_truncate = tcase_create("test_truncate");
  tcase_add_test(tc_test_truncate, truncate_0);
  suite_add_tcase(suite, tc_test_truncate);

  TCase *tc_test_floor = tcase_create("test_floor");
  tcase_add_test(tc_test_floor, floor_0);
  suite_add_tcase(suite, tc_test_floor);

  TCase *tc_test_negate = tcase_create("test_negate");
  tcase_add_test(tc_test_negate, negate_0);
  tcase_add_test(tc_test_negate, negate_1);
  suite_add_tcase(suite, tc_test_negate);

  TCase *tc_test_round = tcase_create("test_round");
  tcase_add_test(tc_test_round, round_0);
  suite_add_tcase(suite, tc_test_round);

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