#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int v, cost = 0;
  cin >> v;
  vector<PII> adj[v];
  vector<bool> p(v);

  for (int i = 0; i < v - 1; i++) {
    for (int j = i + 1; j < v; j++) {
      int weight;
      cin >> weight;
      adj[i].push_back(make_pair(weight, j));
      adj[j].push_back(make_pair(weight, i));
    }
  }

  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    int w = q.top().first;
    int n = q.top().second;
    q.pop();
    if (p[n])
      continue;
    cost += w;
    if (!v) break;
    p[n] = true;
    v--;
    for (auto e : adj[n]) {
      if (!p[e.second])
        q.push(e);
    }
  }

  cout << cost;
}