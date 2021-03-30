#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, e, k, c = 0;
  cin >> n >> e >> k;
  vector<bool> p(n + 1);
  vector<vector<int>> d(n + 1);
  queue<pair<int, int>> q;
  q.push({0, k});

  while (e--) {
    int a, b;
    cin >> a >> b;
    d[a].push_back(b);
    d[b].push_back(a);
  }
  while (!q.empty()) {
    int node = q.front().first;
    int distance = q.front().second;
    q.pop();
    if (distance == 0) {
      c++;
      continue;
    }
    p[node] = true;
    distance--;
    for (auto &n : d[node]) {
      if (!p[n]) {
        p[n] = true;
        q.push({n, distance});
      }
    }
  }
  cout << c;
}