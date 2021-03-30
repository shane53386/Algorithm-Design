#include <iostream>
using namespace std;

int binary_search(int *data, int n, int begin, int end) {
  if (end - begin == 1)
    return data[begin] <= n ? begin : begin - 1;
  int m = (end + begin) / 2;
  if (n < data[m])
    return binary_search(data, n, begin, m);
  else
    return binary_search(data, n, m, end);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, c;
  cin >> n >> m;
  int data[n];
  for (int i = 0; i < n; i++) {
    cin >> c;
    data[i] = c;
  }
  for (int i = 0; i < m; i++) {
    cin >> c;
    cout << binary_search(data, c, 0, n) << "\n";
  }
}