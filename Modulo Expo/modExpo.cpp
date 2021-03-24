#include <iostream>
using namespace std;

int modulo(int X, int N, int K)
{
    if (N == 1)
        return X % K;
    if (N % 2 == 0)
    {
        N /= 2;
        return (modulo(X, N, K)*modulo(X, N, K))%K;
    }
    else
    {
        N -= 1;
        return (modulo(X, N, K) * (X % K))%K;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int X, N, K;
    cin >> X >> N >> K;
    cout << modulo(X, N, K) << "\n";
}