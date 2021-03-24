#include <bits/stdc++.h>
using namespace std;
bool found;

void dfs(int root, int parent, vector<int> *adj, int *p) {
  if (p[root]) {
    found = true;
    return;
  }
  p[root] = 1;
  for (auto v : adj[root]) {
    if (found)
      break;
    if (v != parent)
      dfs(v, root, adj, p);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, v, e, a, b;
  cin >> N;
  while (N--) {
    cin >> v >> e;
    int p[v] = {0};
    vector<int> adj[v];
    found = false;
    while (e--) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    for (int i = 0; i < v && !found; i++) {
      if (!p[i])
        dfs(i, -1, adj, p);
    }
    cout << (found ? "YES" : "NO") << "\n";
  }
}