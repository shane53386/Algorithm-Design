#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    int p[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> p[i][j];
            if (i > 0 && j == 0)
                p[i][0] += p[i - 1][0];
            else if (i == 0 && j > 0)
                p[0][j] += p[0][j - 1];
            else if (i > 0 && j > 0)
                p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            else
                continue;
        }
    }

    for (int i = 0; i < k; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == 0 && c1 == 0)
            cout << p[r2][c2] << "\n";
        else if (r1 == 0)
            cout << p[r2][c2] - p[r2][c1 - 1] << "\n";
        else if (c1 == 0)
            cout << p[r2][c2] - p[r1 - 1][c2] << "\n";
        else
            cout << p[r2][c2] - p[r1 - 1][c2] - p[r2][c1 - 1] + p[r1 - 1][c1 - 1] << "\n";
    }
}