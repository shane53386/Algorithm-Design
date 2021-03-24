#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 100000007;

ll gen(ll num, int prev1, int prev2) {
  if (num == 1) return 1;
  num = num >> 1;
  
}

int main() {
  ll n;
  scanf("%lld", &n);
  ll result = gen(n, 0, 0);
  printf("%lld", result);
  return 0;
}