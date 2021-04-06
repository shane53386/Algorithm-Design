#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> PPI;
#define mp(a, b, c) make_pair(make_pair(a, b), c)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c, k, ans = 0;
  cin >> r >> c >> k;
  int t[r][c];
  queue<PPI> s;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> t[i][j];
      if (t[i][j] == 1)
        s.emplace(mp(i, j, k));
    }
  }

  while (!s.empty()) {
    int row = s.front().first.first;
    int col = s.front().first.second;
    int d = s.front().second;
    s.pop();

    if (t[row][col])
      ans++;
    if (!d)
      continue;
    d--;

    if (row > 0 && !t[row - 1][col]) {
      t[row - 1][col] = 1;
      s.emplace(mp(row - 1, col, d));
    }
    if (row + 1 < r && !t[row + 1][col]) {
      t[row + 1][col] = 1;
      s.emplace(mp(row + 1, col, d));
    }
    if (col > 0 && !t[row][col - 1]) {
      t[row][col - 1] = 1;
      s.emplace(mp(row, col - 1, d));
    }
    if (col + 1 < c && !t[row][col + 1]) {
      t[row][col + 1] = 1;
      s.emplace(mp(row, col + 1, d));
    }
  }
  cout << ans;
}