#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, l = 0, count = 0;
  cin >> N;
  pair<int, int> t[N];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      (i == 0) ? cin >> t[j].second : cin >> t[j].first;
    }
  }
  sort(t, t + N);

  for (int i = 0; i < N; i++) {
    if (t[i].second >= l) {
      count++;
      l = t[i].first;
    }
  }

  cout << count;
}