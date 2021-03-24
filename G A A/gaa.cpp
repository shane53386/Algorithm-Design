#include <iostream>

using namespace std;

int table[1000];

int G(int k)
{
    if (k < 0)
        return 0;
    if (table[k] != 0)
        return table[k];
    table[k] = 2 * G(k - 1) + k + 3;
    return table[k];
}

char GAA(int k, int i)
{
    if (k > G(i))
        return GAA(k, i + 1);
    if (k <= G(i - 1))
        return GAA(k, i - 1);
    k -= G(i - 1);
    if (k == 1)
        return 'g';
    else if (k <= i + 3)
        return 'a';
    return GAA(k - i - 3, i - 1);
}

int main()
{
    int k;
    cin >> k;
    cout << GAA(k, 0) << endl;
}