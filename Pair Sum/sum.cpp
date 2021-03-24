#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, c;
  scanf("%d%d", &N, &M);
  int q[N];
  for (int i = 0; i < N; i++)
    scanf("%d", &q[i]);

  sort(q, q + N);

  while (M--) {
    scanf("%d", &c);
    bool found = false;
    for (int i = 0; i < N - 1; i++) {
      int target = c - q[i];
      int idx = lower_bound(q + i + 1, q + N, target)-q;
      if (idx < N && q[idx] == target) {
        found = true;
        break;
      }
    }
    printf("%s\n", found ? "YES" : "NO");
  }
}