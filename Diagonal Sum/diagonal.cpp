#include <bits/stdc++.h>
using namespace std;
int table[1001][1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, maximum = -999;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> table[i][j];
      if (table[i - 1][j - 1] > 0)
        table[i][j] += table[i - 1][j - 1];
      maximum = max(maximum, table[i][j]);
    }
  }
  cout << maximum << endl;
}