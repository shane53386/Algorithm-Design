#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e, s;
    cin >> n >> e >> s;
    bool cycle = false;
    vector<pair<int, int>> adj[n];
    vector<int> node(n, 9999999);

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }

    node[s] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto x : adj[j]) {
                int point = x.first;
                int weight = x.second;
                if (node[point] <= node[j] + weight)
                    continue;
                node[point] = node[j] + weight;
            }
        }
    }

    for (int j = 0; j < n && !cycle; j++) {
        for (auto x : adj[j]) {
            int point = x.first;
            int weight = x.second;
            if (node[point] > node[j] + weight) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << -1;
    else {
        for (auto c : node)
            cout << c << " ";
    }
}