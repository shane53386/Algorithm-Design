#include <iostream>
#include <vector>

using namespace std;

vector<int> product(const vector<int> &a, const vector<int> &b)
{
    vector<int> result(4);
    result[0] = a[0] * b[0] + a[1] * b[2];
    result[1] = a[0] * b[1] + a[1] * b[3];
    result[2] = a[2] * b[0] + a[3] * b[2];
    result[3] = a[2] * b[1] + a[3] * b[3];
    return result;
}

vector<int> mod(const vector<int> &v, int n, int k)
{
    vector<int> r(4);
    if (n == 1)
    {
        for (int i = 0; i < v.size(); i++)
        {
            r[i] = v[i] % k;
        }
        return r;
    }
    if (n % 2 == 0)
    {
        r = mod(v, n / 2, k);
        return mod(product(r, r), 1, k);
    }
    else
    {
        r = mod(v, n / 2, k);
        return mod(product(product(r, r), mod(v, 1, k)), 1, k);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> matrix;
    for (int i = 0; i < 4; i++)
    {
        int c;
        cin >> c;
        matrix.push_back(c);
    }

    vector<int> v = mod(matrix, n, k);
    for (int i = 0; i < 4; i++)
    {
        cout << v[i] << " ";
    }
}