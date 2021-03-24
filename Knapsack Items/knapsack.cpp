#include <iostream>
#include <vector>
using namespace std;

int V[501][501];
vector<int> result;

void knapsack(int a, int b, vector<pair<int, int>> &item)
{
    if (a == 0 || b == 0)
        return;
    if (b >= item[a - 1].second && a > 0)
    {
        int x = V[a - 1][b];
        int y = V[a - 1][b - item[a - 1].second] + item[a - 1].first;
        if (x < y)
        {
            result.push_back(a);
            knapsack(a - 1, b - item[a - 1].second, item);
        }
        else
            knapsack(a - 1, b, item);
    }
    else
        knapsack(a - 1, b, item);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> item(n);
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].second;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cin >> V[i][j];
        }
    }
    knapsack(n, m, item);
    int s = result.size();
    cout << s << "\n";
    for (int i = 0; i < s; i++)
    {
        cout << result[i] << " ";
    }
}