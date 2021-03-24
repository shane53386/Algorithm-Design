#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<vector<int>> d;

int solve(int node, int parent, int distance) {
  p[node] = 1;
  if (!distance && node) {
    return 1;
  }
  int c = 0;
  for (auto n : d[node]) {
    if (n != node && !p[n])
      c += solve(n, node, distance - 1);
  }
  return c;
}

int main() {
  int n, e, k;
  cin >> n >> e >> k;
  p.resize(n + 1);
  d.resize(n + 1);
  while (e--) {
    int a, b;
    cin >> a >> b;
    d[a].push_back(b);
    d[b].push_back(a);
  }
  cout << solve(0, -1, k);
}