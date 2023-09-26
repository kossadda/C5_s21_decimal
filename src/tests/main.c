#include "../s21_decimal.h"

void dprint(s21_decimal val) {
    printf("%s(%u + %u * 2^32 + %u * 2^64)/(10^%d)\n", ((s21_get_sign(val)) ? "-" : ""), val.bits[0], val.bits[1], val.bits[2],
           s21_get_scale(val));
}

int main() {




    // -26409387.504754779197847983445 * 0.0000000000000005 = -0.0000000132046937523773895989






    // 0.0000000000000005
    // -0.0000000132046937523773895989
    s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
    s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
    s21_decimal res = {{0, 0, 0, 0}};
    printf("return val = %d\n", s21_mul(decimal1, decimal2, &res));
    dprint(res);
}