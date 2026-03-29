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

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector c(h, vector<bool>(w));

  int ans = 0;
  auto dfs = [&](auto dfs, int i, int j) -> bool {
    bool ng = false;
    if (i == 0 || j == 0 || i == h - 1 || j == w - 1) ng = true;
    rep(k, 0, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      if (c[ni][nj]) continue;
      if (ni == 0 || nj == 0 || ni == h - 1 || nj == w - 1) ng = true;
      c[ni][nj] = true;
      ng |= dfs(dfs, ni, nj);
    }
    return ng;
  };

  rep(i, 0, h) rep(j, 0, w) {
    if (s[i][j] == '#') continue;
    if (c[i][j]) continue;
    // cout << i << " " << j << endl;
    c[i][j] = true;
    bool ng = dfs(dfs, i, j);
    if (!ng) ++ans;
  }

  // rep(i, 0, h) {
  //   rep(j, 0, w) { cout << c[i][j] << " "; }
  //   cout << endl;
  // }

  cout << ans << endl;
  return 0;
}
