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
    if(src < 0) {
      src *= -1;
      s21_set_sign(dst, 1);
    }
    int exp_value = 0;
    int length_int_part = length_num((unsigned long long)fabs(src));
    if(length_int_part < 7) {
      while (!length_num((unsigned long long)fabs(src * 10))) {
        if(s21_isinf(src)) break;
        src *= 10;
        exp_value++;
      }
      if(src != (unsigned int)src) {
        res = factor_exp((double)src, 7 - length_int_part);
        exp_value += 7 - length_int_part;
      } else res = (unsigned int)src;
    } else {
      int round_val = 0;
      for(int i = 0; i < length_int_part - 7; i++) {
        if(i == length_int_part - 8) round_val = ((unsigned int)src) % 10;
        src /= 10;
      }
      res = truncf(src);
      if (round_val > 5) res++;
    }
    if(exp_value <= 35 && !s21_isinf(src)) {
      dst->bits[0] = res;
      s21_set_scale(dst, exp_value);
    }
  }
  return (s21_isinf(src) || s21_isinf(-src) || s21_isnan(src) || (res == 0 && src)) ? 1 : 0;
}

// Перевод числа из decimal в float
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  bool small_value = false;
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
  float temp_dst = *dst;
  for(int i = 0; i < 28; i++) {
    if (!length_num(temp_dst * 10)) {
      temp_dst *= 10;
      small_value = true;
    } else small_value = false;
  }
  return (!decimal_is_empty(src) && small_value) ? 1 : 0;
}