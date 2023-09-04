#include "s21_decimal.h"

// Перевод числа из int в decimal
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  clean_decimal(dst);
  if (src < 0) s21_set_sign(dst, 1);
  dst->bits[0] = abs(src);
  return 0;
}

// Перевод числа из decimal в int
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (s21_get_scale(src)) s21_truncate(src, &src);
  *dst = src.bits[0];
  if (s21_get_sign(src)) *dst *= -1;
  if (src.bits[1] || src.bits[2]) *dst = 0;
  return 0;
}

// Перевод числа из float в decimal
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  char num_massive[100];
  int length_int_part = length_num((unsigned long long)fabs(src));
  snprintf(num_massive, sizeof(num_massive), "%.27f", fabs(src));
  int nums[100] = {0};
  int count_nums = 0;
  int num_massive_length = strlen(num_massive);
  for (int i = 0; i < num_massive_length; i++) {
    if (num_massive[i] >= '0' && num_massive[i] <= '9') {
      nums[count_nums++] = num_massive[i] - '0';
    }
  }
  if (src != truncf(src)) {
    for (int i = count_nums; i >= 0; i--) {
      if (nums[i] == 0)
        count_nums--;
      else if (nums[i] != 0 && nums[i + 1] == 0) {
        count_nums++;
        break;
      } else
        break;
    }
  } else {
    count_nums = length_int_part;
  }
  for (int i = count_nums; i >= 0; i--) {
    s21_decimal dec_num = {{nums[i], 0, 0, 0}};
    for (int j = 0; j < count_nums - i; j++) {
      s21_mul(dec_num, (s21_decimal){{10, 0, 0, 0}}, &dec_num);
    }
    s21_add(dec_num, *dst, dst);
  }
  if (length_int_part) length_int_part--;
  s21_set_scale(dst, abs(count_nums - length_int_part));
  if (src < 0) s21_set_sign(dst, 1);
  return 0;
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