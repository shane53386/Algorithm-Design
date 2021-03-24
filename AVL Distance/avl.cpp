#include <iostream>
#include <vector>
using namespace std;

int table[50001][501] = {0};

int distance(vector<vector<int>> &v, int root, int d)
{
    if (table[root][d] != 0)
        return table[root][d];
    if (d == 0)
    {
        int s, a;
        s = v[root].size();
        if (s == 2)
            a = 1 + distance(v, v[root][0], 0) + distance(v, v[root][1], 0);
        else if (s == 1)
            a = 1 + distance(v, v[root][0], 0);
        else
            a = 1;
        table[root][d] = a;
        return a;
    }
    return;
}

int main()
{
    int n, k, p, c;
    cin >> n >> k;
    vector<vector<int>> edge(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> p, c;
        edge[p].push_back(c);
    }
    cout << table[500][500];
}