#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int countOnes(int c, int div, int digit) {
  if (c <= 11) {
    return min(13 - c, c);
  }
  int n = c / div;

  if (c % div == 0)
    return n * digit;
  int upper = (n + 1) * div - c;
  int onesUp = (n + 1) * digit;

  int lower = c - (n * div);
  int onesLow = n * digit;
  return min(onesUp + countOnes(upper, div / 10, digit - 1),
             onesLow + countOnes(lower, div / 10, digit - 1));
}

int main() {
  int c;
  cin >> c;
  int div = 1;
  int digit = 1;
  while (c >= div) {
    ++digit;
    div = div * 10 + 1;
  }
  cout << countOnes(c, div, digit) << "\n";
}