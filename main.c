#include "src/s21_decimal.h"

void dprint(s21_decimal val) {printf("%u, %u, %u, %u\n", val.bits[0], val.bits[1], val.bits[2], val.bits[3]);}

int main() {
    s21_decimal n1 = {{212331, 32333, 2513221, e1*6}};
    s21_decimal n2 = {{145312, 0, 0, e1*2}};
    // s21_set_sign(&n2, 1);
    s21_decimal res = {{0}};
    s21_mul(n1, n2, &res);
    dprint(res);
}