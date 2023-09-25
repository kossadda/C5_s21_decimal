#include "../s21_decimal.h"

// ========================================================================================================
// Работа со степенями
// ========================================================================================================

// Нормализация чисел decimal
bool normalization(s21_decimal *value_1, s21_decimal *value_2) {
    bool condition = false;
    int second_condition = 0;
    int exp1 = s21_get_scale(*value_1);
    int exp2 = s21_get_scale(*value_2);
    s21_big_decimal temp = {{10, 0, 0, 0, 0, 0, 0}};
    s21_big_decimal val1_big = small_decimal_to_big(*value_1);
    s21_big_decimal val2_big = small_decimal_to_big(*value_2);
    int exp_val = exp2;
    int diff = exp2 - exp1;
    int overflow = 0;
    for (int i = 0; i < diff; i++) {
        s21_big_decimal temp_res = {0};
        big_decimal_mul(val1_big, temp, &temp_res);
        if (!big_decimal_is_empty(temp_res)) {
            i = diff;
            continue;
        }
        val1_big = temp_res;
        overflow++;
    }
    if (diff != overflow) {
        for (int i = 0; i < diff - overflow; i++) {
            condition = true;
            if (value_2->bits[1] && (val2_big.bits[1] % 10) == 0) {
                second_condition++;
            }
            big_decimal_div(val2_big, temp, &val2_big);
            exp_val = exp1 + overflow;
            if (second_condition == diff - overflow) {
                condition = false;
            }
        }
    }
    *value_1 = big_decimal_to_small(val1_big);
    *value_2 = big_decimal_to_small(val2_big);
    s21_set_scale(value_1, exp_val);
    s21_set_scale(value_2, exp_val);
    return condition;
}

// Дополнительные условия нормализации двух чисел decimal
void post_normalization(s21_decimal *value_1, s21_decimal *value_2,
                        s21_decimal temp1, s21_decimal temp2) {
    int exp1 = s21_get_scale(temp1);
    int exp2 = s21_get_scale(temp2);
    int res_exp = s21_get_scale(*value_1);
    s21_big_decimal val1_big = small_decimal_to_big(*value_1);
    s21_big_decimal val2_big = small_decimal_to_big(*value_2);
    s21_big_decimal big_res = {0};
    if (exp1 != exp2) {
        big_decimal_add(val1_big, val2_big, &big_res);
    }
    if (!big_decimal_is_empty(big_res) && res_exp) {
        while (!big_decimal_is_empty(big_res)) {
            big_decimal_div(val1_big, (s21_big_decimal){{10, 0, 0, 0, 0, 0, 0}},
                            &val1_big);
            big_decimal_div(val2_big, (s21_big_decimal){{10, 0, 0, 0, 0, 0, 0}},
                            &val2_big);
            big_decimal_add(val1_big, val2_big, &big_res);
            res_exp--;
        }
        *value_1 = big_decimal_to_small(val1_big);
        *value_2 = big_decimal_to_small(val2_big);
        s21_set_scale(value_1, res_exp);
        s21_set_scale(value_2, res_exp);
    }
    if (value_1->bits[0] == value_1->bits[1] &&
        value_1->bits[1] == value_1->bits[2] && value_1->bits[0] == UINT_MAX &&
        !s21_get_scale(*value_1)) {
        if (decimal_is_empty(*value_2)) {
            clean_decimal(value_1);
        }
    }
}

// Проверяет слишком маленькое ли число
int check_small_value(s21_decimal *value_1, s21_decimal *value_2) {
    int ret_value = 0;
    if (s21_get_scale(*value_1) > 28 && s21_get_scale(*value_2) > 28) {
        clean_decimal(value_1);
        clean_decimal(value_2);
        ret_value = 2;
    }
    return ret_value;
}

// Возвращает float в виде целого числа
unsigned int factor_exp(double number, int accuracy) {
    unsigned int length = 10;
    for (int i = 1; i < accuracy; i++) {
        length *= 10;
    }
    long double double_tmp =
        ceill((number - truncl(number)) * powl(10, accuracy) - 0.5);
    unsigned int integ =
        (unsigned int)number * length + (unsigned int)double_tmp;
    return integ;
}

// ========================================================================================================
// Вспомогательные функции
// ========================================================================================================

// Логика сложения двух чисел decimal
int s21_add_logic(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result) {
    clean_decimal(result);
    int sign1 = s21_get_sign(value_1);
    int sign2 = s21_get_sign(value_2);
    s21_big_decimal res_big = {0};
    big_decimal_add(small_decimal_to_big(value_1),
                    small_decimal_to_big(value_2), &res_big);
    if (big_decimal_is_empty(res_big)) *result = big_decimal_to_small(res_big);
    return (!big_decimal_is_empty(res_big))
               ? (((sign1 && sign2) || (sign1 && !sign2)) ? 2 : 1)
               : 0;
}

// Логика вычитания двух чисел decimal
void s21_sub_logic(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
    clean_decimal(result);
    s21_big_decimal res_big = {{0, 0, 0, 0}};
    big_decimal_sub(small_decimal_to_big(value_1),
                    small_decimal_to_big(value_2), &res_big);
    *result = big_decimal_to_small(res_big);
}

// Логика деления двух чисел decimal с остатком
int s21_div_logic(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result) {
    int round_val = 0;
    int scale = abs(s21_get_scale(value_1) - s21_get_scale(value_2));
    clean_decimal(result);
    s21_big_decimal val1_big = small_decimal_to_big(value_1);
    s21_big_decimal val2_big = small_decimal_to_big(value_2);
    s21_big_decimal res_big = {{0, 0, 0, 0, 0, 0, 0}};
    while (s21_big_decimal_less_or_equal(val1_big, val2_big)) {
        big_decimal_mul(val1_big, (s21_big_decimal){{10, 0, 0, 0, 0, 0, 0}},
                        &val1_big);
        scale++;
    }
    div_rest_part(val1_big, val2_big, &res_big, &scale);
    while(!big_decimal_is_empty(res_big) && scale) {
        if(!(res_big.bits[4] && res_big.bits[5] && res_big.bits[6])) {
            round_val = last_num_in_big_decimal(res_big);
        }
        big_decimal_div(res_big, (s21_big_decimal){{10, 0, 0, 0, 0, 0, 0}}, &res_big);
        scale--;
    }
    *result = big_decimal_to_small(res_big);
    bank_round(result, round_val);
    s21_set_scale(result, scale);
    return (big_decimal_is_empty(res_big)) ? 0 : 1;
}

void div_rest_part(s21_big_decimal val1_big, s21_big_decimal val2_big, s21_big_decimal *res_big, int *scale) {
    bool period = false;
    s21_big_decimal temp = {{0, 0, 0, 0}};
    s21_big_decimal mod = {{0, 0, 0, 0}};
    mod = big_decimal_div(val1_big, val2_big, res_big);
    while (!decimal_is_empty(big_decimal_to_small(mod)) &&
           !s21_big_decimal_equal(val1_big, val2_big) && !period) {
        while (s21_big_decimal_less(mod, val2_big)) {
            big_decimal_mul(mod, (s21_big_decimal){{10, 0, 0, 0, 0, 0, 0}},
                            &mod);
            big_decimal_mul(*res_big, (s21_big_decimal){{10, 0, 0, 0, 0, 0, 0}},
                            res_big);
            if (!(res_big->bits[5] && res_big->bits[6])) {
                if(!(res_big->bits[3] && res_big->bits[2])) (*scale)++;
            } else {
                big_decimal_div(*res_big,
                                (s21_big_decimal){{10, 0, 0, 0, 0, 0, 0}},
                                res_big);
                period = true;
                (*scale)--;
            }
        }
        if (!period) {
            mod = big_decimal_div(mod, val2_big, &temp);
            big_decimal_add(temp, *res_big, res_big);
        }
    }
}

// Возвращает остаток от деления decimal на 10
int last_num_in_decimal(s21_decimal value) {
    for (int i = 2; i >= 0; i--) {
        value.bits[i] %= 10;
        if (i != 2) {
            value.bits[i] += (unsigned long long)(value.bits[i + 1] * MAX) % 10;
        }
    }
    return value.bits[0] % 10;
}

int last_num_in_big_decimal(s21_big_decimal value) {
    for (int i = 3; i >= 0; i--) {
        value.bits[i] %= 10;
        if (i != 3) {
            value.bits[i] += (unsigned long long)(value.bits[i + 1] * MAX) % 10;
        }
    }
    return value.bits[0] % 10;
}

// Проверка на пустой decimal
int decimal_is_empty(s21_decimal value) {
    return (value.bits[0] || value.bits[1] || value.bits[2]) ? 0 : 1;
}

// Очистить число decimal
void clean_decimal(s21_decimal *value) {
    for (int i = 0; i < 4; i++) value->bits[i] = 0;
}

void bank_round(s21_decimal *value, int round_val) {
    unsigned long long next_val = value->bits[0] + 1;
    if ((round_val > 5 && round_val <= 9) ||
        (round_val == 5 && next_val % 2 == 0)) {
        if (s21_get_sign(*value)) {
            s21_sub(*value, (s21_decimal){{1, 0, 0, 0}}, value);
        } else {
            s21_add(*value, (s21_decimal){{1, 0, 0, 0}}, value);
        }
    }
}
// ========================================================================================================
// Работа с битами
// ========================================================================================================

// Получить бит числа decimal
int s21_get_bit(s21_decimal dst, int index) {
    unsigned int mask = 1u << (index % 32);
    return (dst.bits[index / 32] & mask) != 0;
}

// Получить знак числа decimal
int s21_get_sign(s21_decimal value) { return value.bits[3] >> 31; }

// Установить знак числа decimal
void s21_set_sign(s21_decimal *value, int sign) {
    if (sign) {
        value->bits[3] |= MINUS;
    } else {
        value->bits[3] = (value->bits[3] << 1) >> 1;
    }
}

// Получить степень числа decimal
int s21_get_scale(s21_decimal value) { return (value.bits[3] << 1) >> 17; }

// Установить степень числа decimal
void s21_set_scale(s21_decimal *value, int scale) {
    value->bits[3] &= MINUS;
    value->bits[3] |= scale << 16;
}

// Получить число цифр в целом числе
int length_num(unsigned long long num) {
    return (num) ? log10((double)num) + 1 : 0;
}

// ========================================================================================================
// Big decimal
// ========================================================================================================

// Получить бит числа big decimal
int get_big_decimal_bit(s21_big_decimal dst, int index) {
    int mask = 1u << (index % 32);
    return (dst.bits[index / 32] & mask) != 0;
}

// Установить бит числа big decimal
void set_big_decimal_bit(s21_big_decimal *value, int index, int bit) {
    if (bit) {
        value->bits[index / 32] |= (1u << (index % 32));
    } else {
        value->bits[index / 32] &= ~(1u << (index % 32));
    }
}

// Сдвиг числа big decimal влево
int shift_big_decimal_left(s21_big_decimal *value, int shift) {
    int much_shift = 0;
    for (int i = 0; i < shift; i++) {
        s21_big_decimal temp = *value;
        for (int j = 0; j < 7; j++) {
            if (get_big_decimal_bit(*value, 223)) {
                much_shift = 1;
                continue;
            }
            value->bits[j] <<= 1u;
            if (get_big_decimal_bit(temp, 31 + 32 * (j - 1)) && j != 0) {
                set_big_decimal_bit(value, 32 * j, 1);
            }
        }
    }
    return much_shift;
}

// Сдвиг числа big decimal вправо
void shift_big_decimal_right(s21_big_decimal *value, int shift) {
    for (int i = 0; i < shift; i++) {
        s21_big_decimal temp = *value;
        for (int j = 0; j < 7; j++) {
            value->bits[j] >>= 1u;
            if (get_big_decimal_bit(temp, 32 * j) && j != 0) {
                set_big_decimal_bit(value, 31 + 32 * (j - 1), 1);
            }
        }
    }
}

// Проверка на пустой big decimal
int big_decimal_is_empty(s21_big_decimal value) {
    return (value.bits[3] + value.bits[4] + value.bits[5] + value.bits[6]) ? 0
                                                                           : 1;
}

// Очистить число big decimal
void clean_big_decimal(s21_big_decimal *value) {
    for (int i = 0; i < 7; i++) {
        value->bits[i] = 0;
    }
}

// Перевод числа decimal в big decimal
s21_big_decimal small_decimal_to_big(s21_decimal value) {
    s21_big_decimal result = {{0, 0, 0, 0, 0, 0, 0}};
    for (int i = 0; i < 3; i++) {
        result.bits[i] = value.bits[i];
    }
    return result;
}

// Перевод числа big decimal в decimal
s21_decimal big_decimal_to_small(s21_big_decimal converting) {
    s21_decimal decimal = {{0, 0, 0, 0}};
    for (int i = 0; i < 3; i++) {
        decimal.bits[i] = converting.bits[i];
    }
    return decimal;
}

// Сложение двух чисел big decimal
void big_decimal_add(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result) {
    clean_big_decimal(result);
    int overflow = 0;
    int bit_sum = 0;
    for (int i = 0; i < 224; i++) {
        bit_sum = get_big_decimal_bit(value_1, i) +
                  get_big_decimal_bit(value_2, i) + overflow;
        overflow = bit_sum / 2;
        set_big_decimal_bit(result, i, bit_sum % 2);
    }
}

// Вычитание двух чисел big decimal
void big_decimal_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result) {
    clean_big_decimal(result);
    int rent = 0;
    int bit_sub = 0;
    for (int i = 0; i < 224; i++) {
        bit_sub = get_big_decimal_bit(value_1, i) -
                  get_big_decimal_bit(value_2, i) - rent;
        rent = bit_sub < 0;
        bit_sub = abs(bit_sub);
        set_big_decimal_bit(result, i, bit_sub % 2);
    }
}

// Умножение двух чисел big decimal
void big_decimal_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result) {
    clean_big_decimal(result);
    int error = 0;
    int count = 0;
    for (int i = 0; i < 224 && !error; i++) {
        if (get_big_decimal_bit(value_2, i)) {
            error = shift_big_decimal_left(&value_1, i - count);
            big_decimal_add(value_1, *result, result);
            count = i;
        }
    }
}

// Деление двух чисел big decimal нацело (функция возвращает остаток)
s21_big_decimal big_decimal_div(s21_big_decimal value_1,
                                s21_big_decimal value_2,
                                s21_big_decimal *result) {
    clean_big_decimal(result);
    if (s21_big_decimal_equal(value_1, value_2)) {
        result->bits[0] = 1;
    } else if (s21_big_decimal_less(value_2, value_1)) {
        s21_big_decimal temp = {{0, 0, 0, 0, 0, 0, 0}};
        int index = -1;
        while (s21_big_decimal_less_or_equal(temp, value_1)) {
            temp = value_2;
            index = -1;
            for (; s21_big_decimal_less_or_equal(temp, value_1); index++) {
                shift_big_decimal_left(&temp, 1);
            }
            shift_big_decimal_right(&temp, 1);
            big_decimal_sub(value_1, temp, &value_1);
            clean_big_decimal(&temp);
            set_big_decimal_bit(&temp, index, 1);
            big_decimal_add(temp, *result, result);
            temp = value_2;
        }
    }
    return value_1;
}

// Оператор сравнения чисел big decimal ==
int s21_big_decimal_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
    int equal = 0;
    for (int i = 0; i < 7; i++) {
        if (value_1.bits[i] == value_2.bits[i]) {
            equal++;
        }
    }
    return (equal == 7) ? 1 : 0;
}

// Оператор сравнения чисел big decimal <
int s21_big_decimal_less(s21_big_decimal value_1, s21_big_decimal value_2) {
    int max_rank1 = 0;
    int max_rank2 = 0;
    int ret_val = 0;
    int i = 223;
    for (; i >= 0; i--) {
        max_rank1 = get_big_decimal_bit(value_1, i);
        max_rank2 = get_big_decimal_bit(value_2, i);
        if (max_rank1 != max_rank2) {
            break;
        }
    }
    if (get_big_decimal_bit(value_1, i) < get_big_decimal_bit(value_2, i)) {
        ret_val = 1;
    }
    if (s21_big_decimal_equal(value_1, value_2)) {
        ret_val = 0;
    }
    return ret_val;
}

// Оператор сравнения чисел big decimal <=
int s21_big_decimal_less_or_equal(s21_big_decimal value_1,
                                  s21_big_decimal value_2) {
    return (s21_big_decimal_equal(value_1, value_2))
               ? 1
               : s21_big_decimal_less(value_1, value_2);
}