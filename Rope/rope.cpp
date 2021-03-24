#include <iostream>
using namespace std;
#define min(a, b, c) min(min(a, b), c)
#define max(a, b, c) max(max(a, b), c)
int dp[4001];

int rope(int length, int a, int b, int c)
{
    if (length == 0)
        return 0;
    if (length < a)
        return -4000;
    if (dp[length] != 0)
        return dp[length];
    dp[length] = 1 + max(rope(length - a, a, b, c), rope(length - b, a, b, c), rope(length - c, a, b, c));
    return dp[length];
}

int main()
{
    int n, a, b, c, x, y, z;
    cin >> n >> a >> b >> c;
    x = min(a, b, c);
    z = max(a, b, c);
    y = a + b + c - x - z;
    cout << rope(n, x, y, z) << endl;
}