#include "../s21_decimal.h"

int main() {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_sign(&val1, 1);
  s21_set_sign(&val2, 1);
  printf("%d", s21_is_less(val1, val2));
}