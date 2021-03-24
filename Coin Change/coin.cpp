#include <iostream>
using namespace std;

int coin[20], dp[10000];

int change(int value, int end) {
  if (value == 0)
    return 0;
  if (dp[value] != 0)
    return dp[value];

  int minimum = value;
  for (int i = 0; i < end; i++) {
    if (value < coin[i])
      continue;
    minimum = min(minimum, 1 + change(value - coin[i], end));
  }

  return dp[value] = minimum;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> coin[i];
  }
  cout << change(m, n);
}
