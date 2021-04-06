#include <bits/stdc++.h>
using namespace std;
typedef unsigned long ul;
int N;
vector<vector<int>> adj(1e5);
vector<ul> s(1e5), ans(1e5);

void dfs(int node, int parent) {
  s[node] = 1;
  ans[node] = 0;
  for (int &v : adj[node]) {
    if (v == parent)
      continue;
    dfs(v, node);
    ans[node] += s[node] * s[v];
    s[node] += s[v];
  }
  ans[node] += (N - s[node]) * s[node];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  ans.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, -1);

  for (ul &v : ans)
    cout << v << "\n";
}