#include <bits/stdc++.h>
using namespace std;
int D[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N, L, idx, count = 0, m = 0;
  cin >> N >> L;

  while (N--) {
    cin >> idx;
    m = max(m, idx);
    D[idx] = 1;
  }

  idx = 1;
  while (idx <= m) {
    if (D[idx] == 1) {
      count++;
      idx += L;
    } else
      idx++;
  }
  cout << count;
}