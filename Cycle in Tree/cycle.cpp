#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int p[100001];
bool found = false;

void dfs(int root, int parent, int distance) {
  if (p[root]) {
    found = true;
    cout << distance - p[root];
  }
  p[root] = distance;
  for (int n : adj[root]) {
    if (n != parent) {
      if (found)
        break;
      dfs(n, root, distance + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N, a, b;
  cin >> N;
  while (N--) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, -1, 1);
}