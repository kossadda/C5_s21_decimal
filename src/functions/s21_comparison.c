#include "../s21_decimal.h"

// Оператор сравнения ==
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
    if (s21_get_scale(value_2) > s21_get_scale(value_1)) {
        normalization(&value_1, &value_2);
    } else if (s21_get_scale(value_1) > s21_get_scale(value_2)) {
        normalization(&value_2, &value_1);
    }
    int equal = 0;
    for (int i = 0; i < 4; i++) {
        if (value_1.bits[i] == value_2.bits[i]) equal++;
    }
    if (s21_get_sign(value_1) != s21_get_sign(value_2)) {
        equal = 0;
    }
    return (equal == 4) ? 1 : 0;
}

// Оператор сравнения !=
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
    return (s21_is_equal(value_1, value_2)) ^ 1;
}

// Оператор сравнения <
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
    bool sign1 = s21_get_sign(value_1);
    bool sign2 = s21_get_sign(value_2);
    if (s21_get_scale(value_2) > s21_get_scale(value_1)) {
        normalization(&value_1, &value_2);
    } else if (s21_get_scale(value_1) > s21_get_scale(value_2)) {
        normalization(&value_2, &value_1);
    }
    int max_rank1 = 0;
    int max_rank2 = 0;
    int ret_val = 0;
    int i = 95;
    for (; i >= 0; i--) {
        max_rank1 = s21_get_bit(value_1, i);
        max_rank2 = s21_get_bit(value_2, i);
        if (max_rank1 != max_rank2) {
            break;
        }
    }
    if (s21_get_bit(value_1, i) < s21_get_bit(value_2, i)) {
        ret_val = 1;
    }
    if (sign1 && !sign2) {
        ret_val = 1;
    } else if (!sign1 && sign2) {
        ret_val = 0;
    } else if (sign1 && sign2) {
        ret_val ^= 1;
    }
    if (s21_is_equal(value_1, value_2) && sign1 == sign2) {
        ret_val = 0;
    } else if (decimal_is_empty(value_1) && decimal_is_empty(value_2)) {
        ret_val = 0;
    }
    return ret_val;
}

// Оператор сравнения <=
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
    return (s21_is_equal(value_1, value_2)) ? 1 : s21_is_less(value_1, value_2);
}

// Оператор сравнения >
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
    return (s21_is_less_or_equal(value_1, value_2)) ^ 1;
}

// Оператор сравнения >=
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
    return (s21_is_less(value_1, value_2)) ^ 1;
}