#include "../s21_decimal.h"

// Перевод числа из int в decimal
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  clean_decimal(dst);
  if (src < 0) s21_set_sign(dst, 1);
  else s21_set_sign(dst, 0);
  dst->bits[0] = abs(src);
  return 0;
}

// Перевод числа из decimal в int
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (s21_get_scale(src)) s21_truncate(src, &src);
  if (!(src.bits[1] || src.bits[2])) {
    *dst = src.bits[0];
    if (s21_get_sign(src)) *dst *= -1;
  }
  return (src.bits[1] || src.bits[2]) ? 1 : 0;
}

// Перевод числа из float в decimal
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  unsigned int res = 0;
  if(!(s21_isinf(src) || s21_isinf(-src) || s21_isnan(src) || src == 0)) {
    int exp_value = 0;
    int length_int_part = length_num((unsigned long long)fabs(src));
    if(length_int_part < 7) {
      exp_value = 7 - length_int_part;
      res = factor_exp((double)src, exp_value);
      for (int i = 7; i >= 0; i--) {
        if(res % 10 == 0) {
          res /= 10;
          exp_value--;
        } else i = -1;
      }
      if (res == 0) exp_value = 0;
    } else {
      int round_val = 0;
      for(int i = 0; i < length_int_part - 7; i++) {
        if(i == length_int_part - 8) round_val = ((unsigned int)src) % 10;
        src /= 10;
      }
      res = truncf(src);
      if (round_val > 5) res++;
    }
    dst->bits[0] = res;
    s21_set_scale(dst, exp_value);
  }
  return (s21_isinf(src) || s21_isinf(-src) || s21_isnan(src) || res == 0) ? 1 : 0;
}

// Перевод числа из decimal в float
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  long double res = (long double)src.bits[2] * (long double)powf(2, 64) +
                    (long double)src.bits[1] * (long double)powl(2, 32) +
                    (long double)src.bits[0];
  if (s21_get_scale(src)) {
    for (int i = 0; i < s21_get_scale(src); i++) {
      res /= 10;
    }
  }
  if (s21_get_sign(src)) res *= -1;
  *dst = (float)res;
  return 0;
}