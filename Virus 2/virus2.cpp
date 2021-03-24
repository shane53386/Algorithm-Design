#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  int p = 1 << k, one[p];
  while (n--) {
    int shift = 2;
    bool done = false;
    for (int j = 0; j < p; j++) {
      cin >> one[j];
    }
    for (int i = 0; i < k; i++, shift *= 2) {
      for (int idx = 0; idx < p; idx += shift) {
        if (abs(one[idx] - one[idx + (shift / 2)]) > 1) {
          done = true;
          break;
        }
        one[idx] += one[idx + (shift / 2)];
      }
      if (done)
        break;
    }
    cout << ((done) ? "no\n" : "yes\n");
  }
}