#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, K, a, b, c;
  queue<int> stock, request;
  cin >> N >> M >> K;
  vector<pair<int, int>> event(K + 1);

  for (int i = 1; i <= K; i++) {
    cin >> a >> b >> c;
    event[a] = make_pair(b, c);
  }

  for (int i = 1; i <= K; i++) {
    if (event[i].first == 0) {
      if (!request.empty()) {
        cout << request.front() << "\n";
        request.pop();
      } else {
        cout << 0 << "\n";
        stock.push(event[i].second);
      }
    } else {
      if (!stock.empty()) {
        cout << stock.front() << "\n";
        stock.pop();
      } else {
        cout << 0 << "\n";
        request.push(event[i].second);
      }
    }
  }
}