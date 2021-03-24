#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSum(vector<int> &s, int start, int end)
{
    if (start == 0)
        return s[end];
    return s[end] - s[start - 1];
}

int mss(vector<int> &v, int start, int end, vector<int> &s)
{
    if (start == end)
        return v[start];
    int div = (start + end + 1) / 2;
    int s1 = mss(v, start, div - 1, s);
    int s2 = mss(v, div, end, s);

    int maxVertical = getSum(s, div - 1, div - 1);
    for (int i = start; i < div - 1; i++)
    {
        maxVertical = max(maxVertical, getSum(s, i, div - 1));
    }

    int maxHorizontal = getSum(s, div, div);
    for (int j = div + 1; j <= end; j++)
    {
        maxHorizontal = max(maxHorizontal, getSum(s, div, j));
    }
    return max({s1, s2, maxVertical + maxHorizontal});
}

int main()
{
    int N, c;
    vector<int> v, s;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> c;
        v.push_back(c);
        if (i == 0)
            s.push_back(c);
        else
            s.push_back(c + s[i - 1]);
    }
    cout << mss(v, 0, N - 1, s) << "\n";
}