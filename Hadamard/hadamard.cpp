#include <iostream>

using namespace std;
int v[1 << 18], dp[1 << 18];
void calculate(int n, int start, int end) {
  if (n == 1) {
    return;
  }
  int div = n / 2;
  calculate(n, start, div);
  for (int i = start; i < div; i++) {
    v[i] += v[div+i];
    v[div+i] += v[i]-v[div+i]
    
  }
  return;
  // dp[div] += -pos * v[div];
  // calculate(div, r2, div, c2, -pos);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> v[i];
  // cout << v[0] << " " << v[1] << endl;
  calculate(n, 0, n);

  for (int r = 0; r < n; r++) {
    cout << v[r] << " ";
  }
}

// #include <cstdio>
// void cal(int n, int a[]) {
//   if (n == 1)
//     return;
//   int m = n >> 1;
//   cal(m, a);
//   cal(m, a + m);
//   for (int i = 0; i < m; i++) {
//     a[i] += a[i + m];
//     a[i + m] = a[i] - 2 * a[i + m];
//   }
// }
// main() {
//   int n;
//   scanf("%d", &n);
//   int arr[n];
//   for (int i = 0; i < n; i++)
//     scanf("%d", arr + i);
//   cal(n, arr);
//   for (int i = 0; i < n; i++)
//     printf("%d ", arr[i]);
// }