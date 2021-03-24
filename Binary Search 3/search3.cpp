#include <iostream>
using namespace std;

int binary_search(int *data, int n, int begin, int end)
{
    if (end - begin == 1)
        return data[begin] <= n ? begin : begin - 1;
    if (end - begin == 2)
    {
        if (n < data[begin])
            return begin - 1;
        return n >= data[begin + 1] ? begin + 1 : begin;
    }
    int a = (end + 2 * begin) / 3;
    int b = (begin + 2 * end) / 3;
    if (n >= data[b])
    {
        return binary_search(data, n, b, end);
    }
    else if (n < data[a])
    {
        return binary_search(data, n, begin, a);
    }

    else
    {
        return binary_search(data, n, a, b);
    }
}

int main()
{
    int n, m, c;
    cin >> n >> m;
    int data[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        data[i] = c;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c;
        cout << binary_search(data, c, 0, n) << "\n";
    }
}