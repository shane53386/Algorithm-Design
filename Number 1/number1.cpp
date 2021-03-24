#include <iostream>

using namespace std;
typedef long long ll;

ll count(ll n) {
  if (n == 1)
    return 1;
  return 2 * count(n / 2) + 1;
}

int countOnes(ll n, ll l, ll r, ll all) {
  if (l < 1 || r < 1)
    return 0;
  if (all == 1)
    return n;
  ll mid = (all + 1) / 2;

  return countOnes(n / 2, (l < mid ? l : 0), min(r, mid - 1), all / 2) +
         countOnes(n % 2, (l <= mid ? 1 : 0), (r >= mid ? 1 : 0), 1) +
         countOnes(n / 2, (l <= mid ? 1 : l - mid), r - mid, all / 2);
}

int main() {
  ll n, l, r;
  cin >> n >> l >> r;
  ll all = count(n);
  cout << countOnes(n, l, r, all);
}