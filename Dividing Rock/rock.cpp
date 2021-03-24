#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int divide(int n, int k) {
  if (n < k)
    return 0;
  if (k == 1 || n == k)
    return 1;
  if (dp[n][k] != 0)
    return dp[n][k];
  return dp[n][k] = (divide(n - 1, k - 1) + divide(n - 1, k) * k) % 1997;
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << divide(n, k);
}