#include <iostream>

using namespace std;

int score(int *data, int n, int *table)
{
    if (n <= 0)
        return data[0];
    if (table[n] != 0)
        return table[n];
    int a = max(max(score(data, n - 1, table), score(data, n - 2, table)), score(data, n - 3, table));
    table[n] = a + data[n];
    return table[n];
}

int main()
{
    int n, e;
    cin >> n;
    int data[n], table[n];
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        table[i] = 0;
        data[i] = e;
    }
    cout << score(data, n - 1, table);
}