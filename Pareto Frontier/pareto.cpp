#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, y, result = 1;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    y = v[n - 1].second;
    for (int i = n - 2; i >= 0; i--)
    {
        if (y < v[i].second)
        {
            y = v[i].second;
            result += 1;
        }
    }
    cout << result;
}