#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c;
  cin >> r >> c;
  queue<pair<int, int>> q;
  vector<vector<int>> d(r, vector<int>(c, -1));
  vector<vector<bool>> p(r, vector<bool>(c, false));
  string m[r];

  for (int i = 0; i < r; i++) {
    cin >> m[i];
  }

  d[0][0]++;
  q.push({0, 0});
  p[0][0] = true;
  while (!q.empty()) {
    if (d[r - 1][c - 1] > -1)
      break;
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (x + 1 < r && !p[x + 1][y] && m[x + 1][y] == '.') {
      d[x + 1][y] = d[x][y] + 1;
      p[x + 1][y] = true;
      q.push({x + 1, y});
    }
    if (y + 1 < c && !p[x][y + 1] && m[x][y + 1] == '.') {
      d[x][y + 1] = d[x][y] + 1;
      p[x][y + 1] = true;
      q.push({x, y + 1});
    }
    if (x - 1 > 0 && !p[x - 1][y] && m[x - 1][y] == '.') {
      d[x - 1][y] = d[x][y] + 1;
      p[x - 1][y] = true;
      q.push({x - 1, y});
    }
    if (y - 1 > 0 && !p[x][y - 1] && m[x][y - 1] == '.') {
      d[x][y - 1] = d[x][y] + 1;
      p[x][y - 1] = true;
      q.push({x, y - 1});
    }
  }
  cout << d[r - 1][c - 1];
}

// #include <algorithm>
// #include <cstdio>
// using namespace std;

// const int MAXN(105);

// char a[MAXN][MAXN];

// pair<int, int> q[MAXN * MAXN];

// int d[4][2] = {1, 0, -1, 0, 0, 1, 0, -1}, path[MAXN][MAXN];

// bool visited[MAXN][MAXN];

// int main() {

//   int n, m;
//   scanf("%d%d", &n, &m);
//   for (int i = 0; i < n; i++)
//     scanf("%s", a[i]);

//   path[n - 1][m - 1] = -1;

//   int fr = 0, bk = 0;
//   path[0][0] = 0;
//   visited[0][0] = true;
//   q[bk++] = make_pair(0, 0);

//   while (fr != bk) {
//     int x = q[fr].first;
//     int y = q[fr].second;
//     fr++;
//     for (int k = 0; k < 4; k++) {
//       int tx = x + d[k][0];
//       int ty = y + d[k][1];
//       if (tx < 0 || tx >= n || ty < 0 || ty >= m)
//         continue;
//       if (a[tx][ty] == '#')
//         continue;
//       if (visited[tx][ty])
//         continue;
//       path[tx][ty] = path[x][y] + 1;
//       visited[tx][ty] = true;
//       q[bk++] = make_pair(tx, ty);
//     }
//   }

//   printf("%d", path[n - 1][m - 1]);
// }