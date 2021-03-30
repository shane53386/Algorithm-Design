#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int N, n;
vector<bool> p(1000);
bool G[1000][1000];
vector<int> result;

void dfs1(int node) {
  p[node] = true;
  for (int i = 0; i < N; i++) {
    if (G[i][node] && !p[i]) {
      dfs1(i);
    }
  }
  s.push(node);
}

void dfs2(int node) {
  p[node] = true;
  n++;
  for (int i = 0; i < N; i++) {
    if (G[node][i] && !p[i]) {
      dfs2(i);
    }
  }
}

int main() {
  cin >> N;
  p.resize(N);
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> n;
    while (n--) {
      cin >> tmp;
      G[i][tmp] = true;
    }
  }
  for (int i = 0; i < N; i++) {
    if (!p[i])
      dfs1(i);
  }
  p = vector<bool>(N, 0);
  while (!s.empty()) {
    if (!p[s.top()]) {
      n = 0;
      dfs2(s.top());
      result.push_back(n);
    }
    s.pop();
  }
  sort(result.begin(), result.end());
  for (int i : result) {
    cout << i << "\n";
  }
}