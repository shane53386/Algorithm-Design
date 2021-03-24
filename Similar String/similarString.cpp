#include <iostream>
#include <math.h>

using namespace std;

string reverse(string s)
{
    int l = s.length();
    for (int i = 0; i < l/2; i++)
    {
        swap(s[i], s[l - i - 1]);
    }
    return s;
}

bool check(string s1, string s2)
{
    int m = s1.length();
    if (m == 2)
    {
        if (s1 == s2 || reverse(s1) == s2)
            return true;
        return false;
    }
    m /= 2;
    string front1 = s1.substr(0, m);
    string back1 = s1.substr(m, m);
    string front2 = s2.substr(0, m);
    string back2 = s2.substr(m, m);
    return (check(front1, front2) && check(back1, back2)) || (check(front1, back2) && check(front2, back1));
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (check(s1, s2))
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}