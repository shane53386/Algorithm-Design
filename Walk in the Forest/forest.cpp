#include <iostream>
#include <vector>
#define max(a, b, c) max(max(a, b), c);
using namespace std;
typedef vector<vector<pair<int, bool>>> vp;

int forest(vp &f, int n, int m)
{
    if (n == 0 && m == 0)
        return f[0][0].first;
    else if (n < 0 || m < 0)
        return -100000;
    if (f[n][m].second)
        return f[n][m].first;

    int score = max(forest(f, n - 1, m - 1) + f[n][m].first, forest(f, n - 1, m), forest(f, n, m - 1));
    f[n][m].first += score;
    f[n][m].second = 1;
    return f[n][m].first;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vp f(n, vector<pair<int, bool>>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> f[i][j].first;
            f[i][j].second = 0;
        }
    }
    cout << forest(f, n - 1, m - 1);
}