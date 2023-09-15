#ifndef FUNC_TESTS_H_
#define FUNC_TESTS_H_

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINUS 0x80000000
#define SCALE 0x00ff0000
#define ALL 0xFFFFFFFF
#define MAX 4294967296
#define e1 65536
#define s21_isnan(X) ((X) != (X))
#define s21_isinf(X) ((X) == (1.0 / 0.0))

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[7];
} s21_big_decimal;

// Арифметические операторы

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Операторы сравнения

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

// Преобразователи

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Прочие функции

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Работа со степенями

bool normalization(s21_decimal *value_1, s21_decimal *value_2);
void post_normalization(s21_decimal *value_1, s21_decimal *value_2,
                        s21_decimal temp1, s21_decimal temp2);
int check_small_value(s21_decimal *value_1, s21_decimal *value_2);

// Вспомогательные функции

int s21_add_logic(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result);
void s21_sub_logic(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
int s21_mul_logic(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result);
int s21_div_logic(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result);
int last_num_in_decimal(s21_decimal value);
unsigned int factor_exp(double number, int accuracy);
void clean_decimal(s21_decimal *value);
int length_num(unsigned long long num);
int decimal_is_empty(s21_decimal value);

// Работа с битами

int s21_get_bit(s21_decimal dst, int index);
int s21_get_sign(s21_decimal value);
void s21_set_sign(s21_decimal *value, int sign);
void s21_set_scale(s21_decimal *value, int scale);
int s21_get_scale(s21_decimal value);

// Big decimal

int get_big_decimal_bit(s21_big_decimal dst, int index);
void set_big_decimal_bit(s21_big_decimal *value, int index, int bit);
int shift_big_decimal_left(s21_big_decimal *value, int shift);
void shift_big_decimal_right(s21_big_decimal *value, int shift);
void big_decimal_add(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result);
void big_decimal_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result);
void big_decimal_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result);
s21_big_decimal big_decimal_div(s21_big_decimal value_1,
                                s21_big_decimal value_2,
                                s21_big_decimal *result);
int big_decimal_is_empty(s21_big_decimal value);
int s21_big_decimal_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_big_decimal_less(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_big_decimal_less_or_equal(s21_big_decimal value_1,
                                  s21_big_decimal value_2);
s21_big_decimal small_decimal_to_big(s21_decimal value);
s21_decimal big_decimal_to_small(s21_big_decimal converting);
void clean_big_decimal(s21_big_decimal *value);

#endif