#include "../s21_decimal.h"

void dprint(s21_decimal val) {printf("%u, %u, %u, %u\n", val.bits[0], val.bits[1], val.bits[2], val.bits[3]);}

int main() {
    float tmp2 = MINUS;
    s21_decimal n1 = {{42949, 0, 1222111, 0}};
    s21_decimal n2 = {{1, 0, 0, e1*7}};
    s21_decimal res = {{0}};
    printf("%d\n", s21_mod(n1, n2, &res));
    dprint(res);
}