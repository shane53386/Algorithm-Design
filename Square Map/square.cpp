#include <bits/stdc++.h>
using namespace std;
#define min(a, b, c) min(min(a, b), c)
int dp[1001][1001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int r, c, maximum = 0;
  cin >> r >> c;
  char e[c];

  for (int i = 1; i <= r; i++) {
    cin >> e;
    for (int j = 1; j <= c; j++) {
      dp[i][j] = (e[j - 1] == '1')
                     ? min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1
                     : 0;
      maximum = max(maximum, dp[i][j]);
    }
  }
  cout << maximum << endl;
}
