#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

string reverse(string s)
{
    int l = s.length();
    for (int i = 0; i < l / 2; i++)
    {
        swap(s[i], s[l - i - 1]);
    }
    return s;
}

bool virusDetect(string s, int k, bool moreThanOne)
{
    if (k == 1)
    {
        if ((s == "01") || (moreThanOne && (s == "10")))
            return true;
        return false;
    }
    int m = pow(2,k-1);
    string first = s.substr(0, m);
    string last = s.substr(m, m);
    return (virusDetect(first, k-1, moreThanOne) || virusDetect(reverse(first), k-1, moreThanOne)) && virusDetect(last, k-1, false);
}

int main()
{
    int n, k;
    string s, b;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        s = "";
        for (int j = 0; j < pow(2, k); j++)
        {
            cin >> b;
            s += b;
        }
        if ((k > 1 && virusDetect(s, k, true)) || (k == 1 && virusDetect(s, k, false)))
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
}