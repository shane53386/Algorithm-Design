#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, sum = 0, mini, maxi, minimum, maximum;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    sum += tmp;
    if (i == 0)
      mini = maxi = minimum = maximum = tmp;
    else {
      maxi = max(maxi + tmp, tmp);
      mini = min(mini + tmp, tmp);
    }
    maximum = max(maxi, maximum);
    minimum = min(mini, minimum);
  }

  cout << max(maximum, (sum == minimum) ? sum : sum - minimum);
}