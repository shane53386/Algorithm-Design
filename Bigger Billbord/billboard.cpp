#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score(vector<int> &v, int i, int s, int *d)
{
    if (i >= s)
        return 0;
    if (d[i] >= 0)
        return d[i];
    if (i == s - 3)
        return max(max(v[i], v[i + 1]), v[i + 2]);
    else if (i == s - 2)
        return max(v[i], v[i + 1]);
    else if (i == s - 1)
        return v[i];
    else
    {
        int a = max(max(score(v, i + 3, s, d) + v[i], score(v, i + 4, s, d) + v[i + 1]), score(v, i + 5, s, d) + v[i + 2]);
        d[i] = a;
        return a;
    }
}

int main()
{
    int n, c;
    cin >> n;
    vector<int> v;
    int data[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        data[i] = -1;
        v.push_back(c);
    }
    cout << score(v, 0, v.size(), data);
}