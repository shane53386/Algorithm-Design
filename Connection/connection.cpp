#include <bits/stdc++.h>
using namespace std;
int cnt;
vector<bool> p;
void dfs(vector<vector<int>> &adj, int node, int k) {
  if (k < 0)
    return;
  if (!p[node])
    cnt++;
  p[node] = true;
  for (int v : adj[node])
    dfs(adj, v, k - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, e, k, m = 0;
  cin >> n >> e >> k;

  vector<int> node;
  vector<vector<int>> adj(n);
  while (e--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  m = 0;
  for (int v = 0; v < n; v++) {
    cnt = 0;
    p = vector<bool>(n, false);
    dfs(adj, v, k);
    m = max(cnt, m);
  }
  cout << m << endl;
}