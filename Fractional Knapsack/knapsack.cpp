#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> DD;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double W, value = 0;
  int N;
  cin >> W >> N;
  DD r[N];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      (i == 1) ? cin >> r[j].second : cin >> r[j].first;
    }
  }
  sort(r, r + N, [](DD const &a, DD const &b) { return (a.first / a.second) > (b.first / b.second); });

  for (int i = 0; i < N; i++) {
    if (W > r[i].second) {
      W -= r[i].second;
      value += r[i].first;
    } else {
      value += (W / r[i].second) * r[i].first;
      break;
    }
  }
  cout << fixed << setprecision(4) << value;
}