#include "../s21_decimal.h"

#define s21_inf 0.0 / 0.0

void dprint(s21_decimal val) {printf("%u, %u, %u, %u\n", val.bits[0], val.bits[1], val.bits[2], val.bits[3]/65536);}

int main() {
    // float n11 = -79225.01;
    // s21_decimal n1 = {{0, 123, 1, MINUS}};
    // s21_decimal n2 = {{6, 0, 0, e1*11}};
    // s21_decimal res = {{0}};
    // printf("%d\n", s21_div(n1, n2, &res));
    // dprint(res);
}
