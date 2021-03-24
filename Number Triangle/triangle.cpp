#include <iostream>
#include <vector>

using namespace std;

int table[100][100];

int triangle(vector<vector<int>> &v, int flr, int idx, int d)
{
    if (table[flr][idx] != 0)
        return table[flr][idx];
    if (flr == d)
        return v[flr][idx];
    table[flr][idx] = max(triangle(v, flr + 1, idx, d), triangle(v, flr + 1, idx + 1, d)) + v[flr][idx];
    return table[flr][idx];
}

int main()
{
    int n, c;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> c;
            v[i].push_back(c);
        }
    }
    cout << triangle(v, 0, 0, n - 1);
}