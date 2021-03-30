#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int v, e, a, b;
  cin >> v >> e;
  vector<vector<int>> d(v + 1);

  while (e--) {
    cin >> a >> b;
    d[a].push_back(b);
  }

  for (int i = 0; i < 5; i++) {
    bool fail = false, p[v + 1] = {false};
    for (int j = 0; j < v; j++) {
      cin >> a;
      p[a] = true;
      for (auto n : d[a]) {
        if (p[n]) {
          fail = true;
          break;
        }
      }
    }
    cout << (fail ? "FAIL\n" : "SUCCESS\n");
  }
}