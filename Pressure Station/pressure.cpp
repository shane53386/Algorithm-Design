#include <bits/stdc++.h>
using namespace std;
int scores[10000], k, DP[10000];
int solve(int begin, int end, int range) {
  if (begin >= end)
    return 0;
  if (DP[end] > 0)
    return DP[end];
  int minimum = INT_MAX;
  for (int i = 0; i <= k + range; i++) {
    if (i > k)
      minimum = min(minimum, scores[(end - i < 0) ? 0 : end - i] + solve(begin, end - i - 1, k));
    else
      minimum = min(minimum, (end - i < 0) ? 0 : scores[end - i] + solve(begin, end - i - 1, k));
      // cout << "minimum = " << minimum << endl;
  }
  return DP[end] = minimum;
}

int main() {
  int n;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> scores[i];
  }
  cout << solve(0, n - 1, 0);
}