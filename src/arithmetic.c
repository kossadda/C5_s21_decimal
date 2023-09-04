#include "s21_decimal.h"

// Сложение двух чисел decimal
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  bool sign1 = s21_get_sign(value_1);
  bool sign2 = s21_get_sign(value_2);
  s21_decimal temp1 = value_1;
  s21_decimal temp2 = value_2;
  if (sign1 && !sign2) {
    s21_set_sign(&value_1, 0);
    if (s21_is_less(value_2, value_1)) {
      s21_sub(value_1, value_2, result);
      s21_set_sign(result, 1);
    } else
      s21_sub(value_2, value_1, result);
  } else if (!sign1 && sign2) {
    s21_set_sign(&value_2, 0);
    if (s21_is_less(value_1, value_2)) {
      s21_sub(value_2, value_1, result);
      s21_set_sign(result, 1);
    } else
      s21_sub(value_1, value_2, result);
  } else {
    if (s21_get_scale(value_1) < s21_get_scale(value_2))
      normalization(&value_1, &value_2);
    else if (s21_get_scale(value_1) > s21_get_scale(value_2))
      normalization(&value_2, &value_1);
    post_normalization(&value_1, &value_2, temp1, temp2);
    if (!sign1 && !sign2) {
      s21_add_logic(value_1, value_2, result);
    } else if (sign1 && sign2) {
      s21_set_sign(&value_1, 0);
      s21_set_sign(&value_2, 0);
      s21_add_logic(value_1, value_2, result);
      if (s21_is_greater(*result, value_1) || s21_is_greater(*result, value_2))
        s21_set_sign(result, 1);
    }
    s21_set_scale(result, s21_get_scale(value_1));
  }
  return 0;
}

// Вычитание двух чисел decimal
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  bool sign1 = s21_get_sign(value_1);
  bool sign2 = s21_get_sign(value_2);
  s21_decimal temp1 = value_1;
  s21_decimal temp2 = value_2;
  bool div_condition = false;
  if (s21_get_scale(value_2) > s21_get_scale(value_1))
    div_condition = normalization(&value_1, &value_2);
  if (s21_get_scale(value_1) > s21_get_scale(value_2))
    div_condition = normalization(&value_2, &value_1);
  if ((sign1 && !sign2) || (!sign1 && sign2)) {
    post_normalization(&value_1, &value_2, temp1, temp2);
    s21_add_logic(value_1, value_2, result);
    if (sign1 && !sign2) s21_set_sign(result, 1);
  } else {
    s21_set_sign(&value_1, 0);
    s21_set_sign(&value_2, 0);
    if (!sign1 && !sign2) {
      if (s21_is_less(value_1, value_2)) {
        s21_sub_logic(value_2, value_1, result);
        s21_set_sign(result, 1);
      } else
        s21_sub_logic(value_1, value_2, result);
    } else if (sign1 && sign2) {
      if (s21_is_less(value_1, value_2)) {
        s21_sub_logic(value_2, value_1, result);
      } else {
        s21_sub_logic(value_1, value_2, result);
        s21_set_sign(result, 1);
      }
    }
    if (div_condition) {
      int sign = s21_get_sign(*result);
      s21_sub_logic(*result, (s21_decimal){{1, 0, 0, 0}}, result);
      s21_set_sign(result, sign);
    }
  }
  if (decimal_is_empty(*result)) {
    s21_set_sign(result, 0);
  } else {
    s21_set_scale(result, s21_get_scale(value_1));
  }
  return 0;
}

// Умножение двух чисел decimal
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  bool sign1 = s21_get_sign(value_1);
  bool sign2 = s21_get_sign(value_2);
  s21_mul_logic(value_1, value_2, result);
  if ((sign1 && !sign2) || (!sign1 && sign2)) s21_set_sign(result, 1);
  s21_set_scale(result, s21_get_scale(value_1) + s21_get_scale(value_2));
  return 0;
}

// Деление двух чисел decimal
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  bool sign1 = s21_get_sign(value_1);
  bool sign2 = s21_get_sign(value_2);
  if (s21_get_scale(value_1) < s21_get_scale(value_2))
    normalization(&value_1, &value_2);
  else if (s21_get_scale(value_1) > s21_get_scale(value_2))
    normalization(&value_2, &value_1);
  if (decimal_is_empty(value_2)) value_2 = (s21_decimal){{1, 0, 0, 0}};
  s21_div_logic(value_1, value_2, result);
  s21_set_scale(result, abs(s21_get_scale(value_1) - s21_get_scale(value_2)));
  if ((sign1 && !sign2) || (!sign1 && sign2)) s21_set_sign(result, 1);
  return 0;
}

// Остаток от деления двух чисел decimal
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  bool sign1 = s21_get_sign(value_1);
  s21_big_decimal big_res = {0};
  if (s21_get_scale(value_1) < s21_get_scale(value_2))
    normalization(&value_1, &value_2);
  else if (s21_get_scale(value_1) > s21_get_scale(value_2))
    normalization(&value_2, &value_1);
  if (decimal_is_empty(value_2)) value_2 = (s21_decimal){{1, 0, 0, 0}};
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  if (s21_is_less(value_1, value_2)) {
    *result = value_1;
  } else {
    if (s21_is_not_equal(value_1, value_2))
      *result = big_decimal_div(small_decimal_to_big(value_1),
                                small_decimal_to_big(value_2), &big_res);
    s21_set_scale(result, s21_get_scale(value_1));
  }
  s21_set_sign(result, sign1);
  return 0;
}