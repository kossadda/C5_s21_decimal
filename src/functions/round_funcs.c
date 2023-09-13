#include "../s21_decimal.h"

// Отбрасывание дробной части числа decimal
int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_big_decimal temp = small_decimal_to_big(value);
  for (int i = 0; i < s21_get_scale(value); i++) {
    big_decimal_div(temp, (s21_big_decimal){{10, 0, 0, 0, 0, 0, 0}}, &temp);
  }
  *result = big_decimal_to_small(temp);
  s21_set_scale(result, 0);
  if (s21_get_sign(value)) {
    s21_set_sign(result, 1);
  }
  return 0;
}

// Округление числа decimal в сторону отрицательной бесконечности
int s21_floor(s21_decimal value, s21_decimal *result) {
  *result = value;
  s21_truncate(value, result);
  if (s21_get_sign(value)) {
    s21_sub(*result, (s21_decimal){{1, 0, 0, 0}}, result);
  }
  return 0;
}

// Замена знака числа decimal на противоположный
int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  if (s21_get_sign(value)) {
    s21_set_sign(result, 0);
  } else {
    s21_set_sign(result, 1);
  }
  return 0;
}

// Округление числа decimal
int s21_round(s21_decimal value, s21_decimal *result) {
  int sign = s21_get_sign(value);
  s21_big_decimal temp = small_decimal_to_big(value);
  if (s21_get_scale(value)) {
    int round_val = 0;
    for (int i = 0; i < s21_get_scale(value); i++) {
      if (i == s21_get_scale(value) - 1) {
        round_val = last_num_in_decimal(big_decimal_to_small(temp));
      }
      big_decimal_div(temp, (s21_big_decimal){{10, 0, 0, 0, 0, 0, 0}}, &temp);
    }
    value = big_decimal_to_small(temp);
    unsigned long long next_val = temp.bits[0] + 1;
    if ((round_val > 5 && round_val <= 9) ||
        (round_val == 5 && next_val % 2 == 0)) {
      if (s21_get_sign(value)) {
        s21_sub(value, (s21_decimal){{1, 0, 0, 0}}, &value);
      } else {
        s21_add(value, (s21_decimal){{1, 0, 0, 0}}, &value);
      }
    }
  }
  *result = value;
  s21_set_sign(result, sign);
  return 0;
}