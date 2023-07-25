#include <bits/stdc++.h>

using namespace std;

#define rep(i, x, n) for (int i = x; i < (n); ++i)

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector visited(n, vector<bool>(m));
  vector passed(n, vector<bool>(m));

  queue<pair<int, int>> q;
  q.emplace(1, 1);
  passed[1][1] = visited[1][1] = true;
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    rep(v, 0, 4) {
      int ni = i, nj = j;
      while (s[ni][nj] == '.') {
        passed[ni][nj] = true;
        ni += di[v];
        nj += dj[v];
      }
      ni -= di[v];
      nj -= dj[v];
      if (visited[ni][nj]) continue;
      visited[ni][nj] = true;
      q.emplace(ni, nj);
    }
  }

  int ans = 0;
  rep(i, 0, n) rep(j, 0, m) if (passed[i][j]) ans++;
  cout << ans << endl;
  return 0;
}
