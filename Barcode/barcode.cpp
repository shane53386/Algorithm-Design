#include <iostream>

using namespace std;
int n, m, k, barcode[31][31][31];

int gen(int start, int same, int change) {
  if (start > n || same > m || change < 0 || n-start < change)
    return 0;
  if (start == n && !change)
    return 1;
  if (barcode[start][same][change] != 0)
    return barcode[start][same][change];
  int total = gen(start + 1, same + 1, change) + gen(start + 1, 1, change-1);
  barcode[start][same][change] = total;
  return total;
}

int main() {
  cin >> n >> m >> k;
  cout << gen(1, 1, k);
}