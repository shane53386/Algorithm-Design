#include <bits/stdc++.h>

using namespace std;
int f, m, dp[200001], n, k, start, w;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    cin >> f;
    dp[i] = (f + dp[i - 1] - m);
  }

  for (int i = 0; i < k; i++) {
    cin >> start >> w;
    cout << lower_bound(dp + start, dp + n, w + dp[start - 1]) - dp << "\n";
  }
}