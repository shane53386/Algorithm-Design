#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b, c, n;
    a = 0;
    b = 1;
    cin >> n;
    if (n < 2)
        cout << n;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        cout << c;
    }
}