#include <bits/stdc++.h>
using namespace std;
int tile[10], n, dp[10][10000];

int price(int idx, int size) {
  if (idx == n)
    return size == 0 ? 0 : -1;
  if (dp[idx][size] != 0)
    return dp[idx][size];
  int minimum = INT_MAX;
  for (int i = 0; i <= sqrt(size); i++) {
    int cost = price(idx + 1, size - pow(i, 2));
    if (cost >= 0) {
      cost += pow(tile[idx] - i, 2);
      minimum = min(minimum, cost);
    }
  }
  dp[idx][size] = (minimum == INT_MAX ? -1 : minimum);
  return dp[idx][size];
}

int main() {
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> tile[i];
  }
  cout << price(0, m);
}