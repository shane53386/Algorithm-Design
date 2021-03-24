#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void print(vector<vector<int>> &v, int d)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

void matrix(vector<vector<int>> &v, int a, int b, int top, int bottom, int left, int right)
{
    if (a == 0)
    {
        v[top][left] = b;
        return;
    }
    matrix(v, a - 1, b, top, (top + bottom) / 2, left, (left + right) / 2);
    matrix(v, a - 1, b - 1, top, (top + bottom) / 2, (left + right) / 2, right);
    matrix(v, a - 1, b + 1, (top + bottom) / 2, bottom, left, (left + right) / 2);
    matrix(v, a - 1, b, (top + bottom) / 2, bottom, (left + right) / 2, right);
}

int main()
{
    int a, b;
    cin >> a >> b;
    int d = pow(2, a);
    vector<vector<int>> v(d, vector<int>(d, 0));
    matrix(v, a, b, 0, d, 0, d);
    print(v, d);
}
