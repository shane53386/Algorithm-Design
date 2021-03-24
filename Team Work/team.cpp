#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  double avg;
  cin >> N >> M;
  int subtask[M], student[N] = {0};

  for (int i = 0; i < M; i++) {
    cin >> subtask[i];
  }
  sort(subtask, subtask + M);

  for (int i = 0; i < M; i++) {
    student[i % N] += subtask[i];
    avg += student[i % N];
  }
  cout << fixed << setprecision(3) << avg / M << endl;
}