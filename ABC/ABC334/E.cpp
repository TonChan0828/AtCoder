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

using mint = modint998244353;
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  vector group(h, vector<int>(w, 0));
  int cnt = 0;
  int red = 0;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (s[i][j] == '.') {
        ++red;
        continue;
      }
      if (group[i][j]) continue;

      ++cnt;
      queue<pair<int, int>> q;
      q.push({i, j});
      group[i][j] = cnt;
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        rep(k, 0, 4) {
          int ny = y + dy[k], nx = x + dx[k];
          if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
          if (s[ny][nx] == '.') continue;
          if (group[ny][nx]) continue;
          group[ny][nx] = cnt;
          q.push({ny, nx});
        }
      }
    }
  }

  mint res = 0;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (s[i][j] == '#') continue;
      set<int> s;
      rep(k, 0, 4) {
        int ny = i + dy[k], nx = j + dx[k];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        if (group[ny][nx]) s.insert(group[ny][nx]);
      }
      res += cnt + 1 - (int)s.size();
    }
  }
  res /= red;
  cout << res.val() << endl;
  return 0;
}
