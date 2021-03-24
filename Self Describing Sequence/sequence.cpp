#include <iostream>
#include <vector>

using namespace std;

int sequence(int c, int n, int sum)
{
    if (n == 1 || n == 2)
        return n;
    if (c <= sum)
    {
        cout << n << "\n";
        return;
    }
    sequence(c, n + 1, sum + n + 1);
}

int main()
{
    int n, c;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        sequence(c, 1, 1);
    }
}