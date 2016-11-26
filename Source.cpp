#include <stdio.h>

int length_of_number(int N) {
  int k = 0;
  while (N / 10 != 0) {
    N = N / 10;
    ++k;
  }
  ++k;
  return k;
}

int Find_All_Numbers(int N) {
  int k, Ni, num;
  int i = 1, j = 0, p, flag = 0;
  int massive[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  while (i < 100) {
    Ni = N*i;
    num = Ni;
    k = length_of_number(Ni);
    while (k != 0) {
      p = Ni % 10;
      Ni = Ni / 10;
      massive[p] = 1;
      --k;
    }
    flag = 0;
    for (j = 0; j < 10; ++j) {
      if (massive[j] == 0) ++flag;
    }
    if (flag == 0) {
      flag = 1;
      break;
    }
    flag = 0;
    ++i;
  }
  if (flag == 1)
    return num;
  else
    return -1;
}

void test(int N) {
  int num;
  num = Find_All_Numbers(N);
  if (num != -1)
    printf("%i\n", num);
  else
    printf("FAIL\n");
}

int main() {
  test(1);     // 1 2 3 4 5 6 7 8 9 10
  test(1692);  // 1692 3384 5076
  test(0);     // 0 0 0 0..
  test(2);     // 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 ... 90
  test(11);    // 11 22 33 44 55 66 77 88 99 110
  test(10);    // 10 20 30 40 50 60 70 80 90
  test(1234);  // 1234 2468 3702 4936 6170 7404 8638 ... 11*1234=13574
  test(1234567890);
}
