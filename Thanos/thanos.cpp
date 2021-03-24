#include <algorithm>
#include <iostream>
typedef unsigned long long ull;
using namespace std;

int avengers[100000], p, k, A, B;

int count(ull start, ull end) {
  return upper_bound(avengers, avengers + k, end) -
         lower_bound(avengers, avengers + k, start + 1);
}

ull power(ull start, ull end) {
  int n = count(start, end);
  ull force = n == 0 ? A : B * n * (end - start);
  if (n == 0 || end == start + 1)
    return force;

  ull d = (end + start) / 2;
  return min(force, power(start, d) + power(d, end));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> p >> k >> A >> B;
  for (int i = 0; i < k; i++) {
    cin >> avengers[i];
  }

  sort(avengers, avengers + k);
  cout << power(0, (1 << p));
}