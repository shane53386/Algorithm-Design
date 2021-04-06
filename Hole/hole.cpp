#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int sz = 1000;
    int N, a, b, ans = sz;
    cin >> N >> a >> b;
    vector<vector<int>> map(sz, vector<int>(sz, sz));
    vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    while (N--) {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = -sz;
    }
    queue<tuple<int, int, int>> q;
    map[a - 1][b - 1] = 0;
    q.push({a - 1, b - 1, 0});
    while (!q.empty()) {
        int r, c, d;
        tie(r, c, d) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int row = r + direction[i].first;
            int col = c + direction[i].second;
            if (row < 0 || row == sz || col < 0 || col == sz) {
                ans = min(ans, d);
                continue;
            }
            int tmp = map[row][col] < 0 ? d + 1 : d;
            if (map[row][col] >= 0 && tmp >= map[row][col] || map[row][col] < 0 && tmp > abs(map[row][col]))
                continue;
            q.push({row, col, tmp});
            map[row][col] = map[row][col] > 0 ? tmp : -tmp;
        }
    }
    cout << ans;
}