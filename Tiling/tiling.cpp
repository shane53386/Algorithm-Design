#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix;
matrix result;

void tiling(int x, int y, int r1, int c1, int r2, int c2)
{
    if (r2 - r1 == 2)
    {
        if (x == c1 && y == r1)
        {
            result.push_back({0, c1, r1});
        }
        else if (x == c1 + 1 && y == r1)
        {
            result.push_back({1, c1, r1});
        }
        else if (x == c1 && y == r1 + 1)
        {
            result.push_back({2, c1, r1});
        }
        else if (x == c1 + 1 && y == r1 + 1)
        {
            result.push_back({3, c1, r1});
        }
        return;
    }

    int dx = (c2 + c1) / 2;
    int dy = (r2 + r1) / 2;
    if (x < dx && y < dy)
    {
        tiling(x, y, r1, c1, dy, dx);
        tiling(dx, dy - 1, r1, dx, dy, c2);
        tiling(dx - 1, dy, dy, c1, r2, dx);
        tiling(dx, dy, dy, dx, r2, c2);
        tiling(dx - 1, dy - 1, dy - 1, dx - 1, dy + 1, dx + 1);
    }
    else if (x >= dx && y < dy)
    {
        tiling(dx - 1, dy - 1, r1, c1, dy, dx);
        tiling(x, y, r1, dx, dy, c2);
        tiling(dx - 1, dy, dy, c1, r2, dx);
        tiling(dx, dy, dy, dx, r2, c2);
        tiling(dx, dy - 1, dy - 1, dx - 1, dy + 1, dx + 1);
    }
    else if (x < dx && y >= dy)
    {
        tiling(dx - 1, dy - 1, r1, c1, dy, dx);
        tiling(dx, dy - 1, r1, dx, dy, c2);
        tiling(x, y, dy, c1, r2, dx);
        tiling(dx, dy, dy, dx, r2, c2);
        tiling(dx - 1, dy, dy - 1, dx - 1, dy + 1, dx + 1);
    }
    else
    {
        tiling(dx - 1, dy - 1, r1, c1, dy, dx);
        tiling(dx, dy - 1, r1, dx, dy, c2);
        tiling(dx - 1, dy, dy, c1, r2, dx);
        tiling(x, y, dy, dx, r2, c2);
        tiling(dx, dy, dy - 1, dx - 1, dy + 1, dx + 1);
    }
}

int main()
{
    int s, x, y;
    cin >> s >> x >> y;
    matrix v(s, vector<int>(s));
    tiling(x, y, 0, 0, s, s);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < 3; j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
}