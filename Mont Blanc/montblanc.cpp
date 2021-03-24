#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, D, d = 1, idx = 0;
  cin >> N >> D;
  int site[N];
  for (int i = 0; i < N; i++)
    cin >> site[i];
  int height = site[N - 1];
  int K = height / D;
  idx = lower_bound(site, site + N, K) - site;
  K = site[idx];
  while (d * K < height) {
    d++;
    idx = upper_bound(site + idx, site + N, d * K) - site;
    if (site[idx] > height)
      break;
    K = max(site[idx] - site[idx - 1], K);
  }
  cout << K << " " << d;
}