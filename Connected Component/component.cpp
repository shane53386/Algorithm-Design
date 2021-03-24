#include <bits/stdc++.h>
using namespace std;
int p[10001];
vector<int> d[10001];

void dfs(int root) {
  if (!p[root]) {
    p[root] = 1;
    for (int n : d[root])
      dfs(n);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int v, e, a, b, ans = 0;
  cin >> v >> e;
  while (e--) {
    cin >> a >> b;
    d[a].push_back(b);
    d[b].push_back(a);
  }
  for (int i = 1; i <= v; i++) {
    if (!p[i]) {
      dfs(i);
      ans++;
    }
  }
  cout << ans;
}