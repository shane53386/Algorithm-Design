#include <iostream>
#include <vector>
using namespace std;
int table[101][101];

int mcm(vector<int> &v, int l, int r)
{
    if (l == r)
        return 0;
    if (table[l][r] != 0)
        return table[l][r];
    int minimum = mcm(v, l, l) + mcm(v, l + 1, r) + v[l] * v[l + 1] * v[r + 1];
    for (int i = l + 1; i < r; i++)
    {
        minimum = min(mcm(v, l, i) + mcm(v, i + 1, r) + v[l] * v[i + 1] * v[r + 1], minimum);
    }
    table[l][r] = minimum;
    return minimum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        cin >> v[i];
    }
    cout << mcm(v, 0, n - 1);
}