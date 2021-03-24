#include <iostream>

using namespace std;
int s[10], dp[10000], ans = 0;

void solve(int n, int k) {
  if (n == 0) {
    ans++;
    return;
  }

  if (dp[n] != 0){
    ans = (ans + dp[n] % 1000003) % 1000003;
    return;
  }

  for (int i = 0; i < k; i++) {
    if (s[i] > n) {
      // cout << "b" << endl;
      break;
    }

    solve(n - s[i], k);
    // cout << "aaaa" << endl;
  }
  dp[n] = ans;
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> s[i];
  }
  solve(n, k);
  cout << ans;
}