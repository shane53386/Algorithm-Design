#include <bits/stdc++.h>
using namespace std;
stack<int> s;

void tsort(int *p, vector<int> *d, int root) {
  p[root] = 1;
  for (int v : d[root]) {
    if (!p[v])
      tsort(p, d, v);
  }
  s.push(root);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, n, a;
  cin >> N;
  int p[N] = {0};
  vector<int> d[N];
  for (int i = 0; i < N; i++) {
    cin >> n;
    while (n--) {
      cin >> a;
      d[a].push_back(i);
    }
  }
  for (int i = 0; i < N; i++) {
    if (!p[i])
      tsort(p, d, i);
  }
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}