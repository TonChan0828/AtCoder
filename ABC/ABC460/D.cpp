#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}
const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  rep(ti, 0, 2) {
    auto t = s;
    rep(i, 0, h) rep(j, 0, w) {
      s[i][j] = '.';
      if (t[i][j] == '.') {
        rep(v, 0, 8) {
          int ni = i + di[v], nj = j + dj[v];
          if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
          if (t[ni][nj] == '#') s[i][j] = '#';
        }
      }
    }
  }

  const int INF = 1001001001;
  queue<pair<int, int>> q;
  vector dist(h, vector<int>(w, INF));
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '#') {
    dist[i][j] = 0;
    q.emplace(i, j);
  }

  while (q.size()) {
    auto [i, j] = q.front();
    q.pop();
    rep(v, 0, 8) {
      int ni = i + di[v], nj = j + dj[v];
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
      if (dist[ni][nj] != INF) continue;
      dist[ni][nj] = dist[i][j] + 1;
      q.emplace(ni, nj);
    }
  }

  rep(i, 0, h) rep(j, 0, w) s[i][j] = "#."[dist[i][j] % 2];
  rep(i, 0, h) cout << s[i] << endl;
  return 0;
}
