#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int f, w, n, c, idx = 1, count = 0;
  cin >> f >> w >> n;
  w = 2 * w + 1;
  bool T[n + 1] = {false};
  for (int i = 1; i <= f; i++) {
    cin >> c;
    T[c] = true;
  }

  while (idx <= n) {
    if (T[idx]) {
      count++;
      idx += w;
    } else
      idx++;
  }

  cout << count << "\n";
}