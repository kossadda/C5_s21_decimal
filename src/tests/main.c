#include "../s21_decimal.h"

void dprint(s21_decimal val) {
    printf("%s(%u + %u * 2^32 + %u * 2^64)/(10^%d)\n",
           ((s21_get_sign(val)) ? "-" : ""), val.bits[0], val.bits[1],
           val.bits[2], s21_get_scale(val));
}

int main() {
    // 79228162514264337593543950335
    s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
    // 0.9999999999999999999999999999
    s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
    // overflow
    s21_decimal res = {{0, 0, 0, 0}};
    printf("return val = %d\n", s21_div(decimal1, decimal2, &res));
    dprint(res);
}