#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> TI;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    pair<int, int> direction[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int cost[r][c];
    pair<int, bool> map[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            map[i][j].first = INT_MAX;
            map[i][j].second = false;

            cin >> cost[i][j];
        }
    }
    
    map[0][0].first = 0;
    priority_queue<TI, vector<TI>, greater<TI>> pq;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        int x, y, z;
        tie(x, y, z) = pq.top();
        pq.pop();

        if (map[y][z].second)
            continue;
        map[y][z].second = true;

        for (int i = 0; i < 4; i++) {
            int row = y + direction[i].first;
            int col = z + direction[i].second;
            if (map[row][col].first <= x + cost[row][col] || row < 0 || col < 0 || row >= r || col >= c)
                continue;
            map[row][col].first = x + cost[row][col];
            pq.push({map[row][col].first, row, col});
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << map[i][j].first << " ";
        }
        cout << "\n";
    }
}