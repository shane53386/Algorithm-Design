#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, w, k, m = 0;
  cin >> n >> w >> k;
  int BB[n][2], DP[n][2][2];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++)
      cin >> BB[j][i];

  for (int limit = 0; limit < min(k,(n+w)/(w+1)); limit++) {
    int l = limit % 2;
    for (int side = 0; side < 2; side++) {
      DP[0][l][side] = BB[0][side];
      for (int idx = 1; idx < n; idx++) {
        DP[idx][l][side] = (limit == 0) ? max(BB[idx][side], DP[idx - 1][0][side]) : max(BB[idx][side] + ((idx - w - 1 < 0) ? 0 : DP[idx - w - 1][(limit - 1) % 2][!side]), DP[idx - 1][l][side]);
      }
      m = max(m, DP[n - 1][l][side]);
    }
  }
  cout << m;
}