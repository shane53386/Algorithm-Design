#include <iostream>
#include <vector>
using namespace std;

int inversion(vector<int> &v, int start)
{
    if (start == v.size() - 1)
    {
        return 0;
    }
    else
    {
        int c = 0;
        for (int i = start + 1; i < v.size(); i++)
        {
            if (v[start] > v[i])
            {
                c++;
            }
        }
        int r = inversion(v, start + 1);
        return r + c;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        v.push_back(c);
    }
    cout << inversion(v, 0);
    return 0;
}