#include <bits/stdc++.h>

using namespace std;

#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)

const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector vis(n, vector<bool>(m));
  vector pass(n, vector<bool>(m));

  queue<pair<int, int>> q;
  q.emplace(1, 1);
  pass[1][1] = vis[1][1] = true;
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    rep(i, 0, 4) {
      int tx = x, ty = y;
      while (s[ty][tx] == '.') {
        pass[ty][tx] = true;
        // printf("%d %d\n", ty, tx);
        ty += dy[i];
        tx += dx[i];
      }
      ty -= dy[i];
      tx -= dx[i];
      if (vis[ty][tx]) continue;
      vis[ty][tx] = true;
      q.emplace(ty, tx);
    }
  }
  int cnt = 0;
  rep(i, 0, n) {
    rep(j, 0, m) {
      if (pass[i][j]) ++cnt;
    }
  }
  cout << cnt << endl;
  return 0;
}
