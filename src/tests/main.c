#include "../s21_decimal.h"

#define s21_inf 0.0 / 0.0

void dprint(s21_decimal val) {printf("%u, %u, %u, %u\n", val.bits[0], val.bits[1], val.bits[2], val.bits[3]/65536);}

int main() {
    float n11 = -79225.01;
    s21_decimal n1 = {{424992, 12333, 0, e1*3 | MINUS}};
    s21_decimal n2 = {{3, 0, 132, e1*4 | MINUS}};
    s21_decimal res = {{0}};
    printf("%d\n", s21_from_float_to_decimal(n11, &res));
    dprint(res);
}

    // float n11 = -0.0000000000000000000000000000000321345400000006730099912123563543;
    // s21_decimal n1 = {{43421234, 1234, 0, e1*44 | MINUS}};
    // s21_decimal n2 = {{3, 0, 132, e1*4 | MINUS}};
    // s21_decimal res = {{0}};
    // printf("%d\n", s21_from_decimal_to_float(n1, &n11));
    // printf("%.50f\n", n11);
    // // dprint(res);