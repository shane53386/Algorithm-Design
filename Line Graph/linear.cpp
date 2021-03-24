#include <bits/stdc++.h>
using namespace std;
int c = 0;
bool found;

void dfs(int root, int parent, int *p, vector<int> *d) {
  if (p[root] || d[root].size() > 2) {
    found = true;
    return;
  }
  p[root] = 1;
  for (int v : d[root])
    if (v != parent)
      dfs(v, root, p, d);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int v, e, a, b;
  cin >> v >> e;
  int p[v] = {0};
  vector<int> d[v];
  while (e--) {
    cin >> a >> b;
    d[a].push_back(b);
    d[b].push_back(a);
  }
  for (int i = 0; i < v; i++) {
    if (!p[i]) {
      found = false;
      dfs(i, -1, p, d);
      if (!found)
        c++;
    }
  }
  cout << c;
}