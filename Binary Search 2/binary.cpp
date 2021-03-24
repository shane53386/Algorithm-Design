#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &v, int start, int end, int key)
{
    if (start == end)
    {
        if (key < v[start])
            return (start - 1) < 0 ? -1 : v[start - 1];
        else
            return v[start];
    }
    else
    {
        int div = (end - start + 2) / 2;
        div += start;
        if (key < v[div])
            end = div - 1;
        else
            start = div;
        return binarySearch(v, start, end, key);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, c, idx;
    vector<int> v;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> c;
        v.push_back(c);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> c;
        cout << binarySearch(v, 0, v.size() - 1, c) << "\n";
    }
}
