#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, c;
  cin >> n >> m;
  vector<int> num;
  for (int i = 0; i < n; i++) {
    cin >> c;
    num.push_back(c);
  }

  for (int i = 0; i < m; i++) {
    cin >> c;
    bool found = false;
    for (int j = 1; j < n - 1; j++) {
      int l = 0;
      int r = n - 1;
      while (l < j && j < r) {
        if (c == num[l] + num[j] + num[r]){
            found = true;
            break;
        }
        c > num[l] + num[j] + num[r]? l++ : r--;
      }
    }
    cout << (found ? "YES\n" : "NO\n");
  }
}