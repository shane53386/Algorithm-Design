#include <bits/stdc++.h>
using namespace std;

void merge(int start, int end, int n, int k) {
  if (k == 1) {
    for (int i = start; i <= end; i++)
      cout << i << " ";
    return;
  }
  int div = n / 2;
  int kL = min(k - 2, 2 * n - 1);
  merge(end - div + 1, end, div, kL);
  merge(start, start + n - div - 1, n - div, k - kL);
}

int main() {
  int n, k;
  cin >> n >> k;
  int num[n];

  if (k % 2 == 0 || k > 2 * n - 1)
    cout << -1;
  else
    merge(1, n, n, k);
}