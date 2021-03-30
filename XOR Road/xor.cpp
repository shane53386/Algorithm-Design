#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull, int> PUI;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, use = 1;
  ull sum = 0;
  cin >> n;
  vector<int> code(n);
  vector<bool> p(n);
  for (int i = 0; i < n; i++) {
    cin >> code[i];
  }

  priority_queue<PUI> q;
  q.push({0, 0});
  while (!q.empty()) {
    ull cost = q.top().first;
    int node = q.top().second;
    q.pop();
    if (p[node])
      continue;
    sum += cost;
    if (use == n)
      break;
    p[node] = true;
    use++;
    for (int i = 0; i < n; i++) {
      if (p[i])
        continue;
      q.push({code[i] ^ code[node], i});
    }
  }
  cout << sum << endl;
}