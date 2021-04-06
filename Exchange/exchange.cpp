#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int K, N;
  cin >> K;
  while (K--) {
    cin >> N;
    float t[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> t[i][j];
      }
    }
    bool infinity = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N && !infinity; j++) {
        for (int k = 0; k < N && !infinity; k++) {
          t[j][k] = max(t[j][k], t[j][i] * t[i][k]);
          if (j == k && t[j][k] > 1)
            infinity = true;
        }
      }
    }
    cout << (infinity ? "YES\n" : "NO\n");
  }
}