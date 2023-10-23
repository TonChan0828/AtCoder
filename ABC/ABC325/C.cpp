#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector<pair<int, int>> vp;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '#') vp.push_back({i, j});

  vector<vector<bool>> vis(h, vector<bool>(w, false));
  int ans = 0;
  for (auto [i, j] : vp) {
    if (vis[i][j]) continue;
    ++ans;
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();
      rep(k, 0, 8) {
        int ny = y + dy[k], nx = x + dx[k];
        if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
        if (vis[ny][nx]) continue;
        if (s[ny][nx] != '#') continue;
        q.push({ny, nx});
        vis[ny][nx] = true;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
