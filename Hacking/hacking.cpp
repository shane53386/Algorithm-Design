#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    queue<pair<int, int>> q;
    vector<int> hacked(n, INT_MAX), time(n), start;
    vector<vector<int>> adj(n);
    while (k--) {
        int tmp;
        cin >> tmp;
        start.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto &c : start) {
        hacked[c] = time[c];
        q.push({c, time[c]});
    }
    while (!q.empty()) {
        int node, cost;
        tie(node, cost) = q.front();
        q.pop();
        for (auto &c : adj[node]) {
            int t = time[c];
            if (hacked[c] < cost + t)
                continue;
            hacked[c] = cost + t;
            q.push({c, hacked[c]});
        }
    }
    for (auto &c : hacked) {
        ans = max(ans, c);
    }
    cout << ans;
}