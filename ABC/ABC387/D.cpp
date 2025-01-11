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

using P = pair<int, int>;

int di[2][2] = {{-1, 1}, {0, 0}};
int dj[2][2] = {{0, 0}, {-1, 1}};
const int INF = 1001001001;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int si = 0, sj = 0, gi = 0, gj = 0;
  rep(i, 0, h) rep(j, 0, w) {
    if (s[i][j] == 'S') {
      si = i, sj = j;
    } else if (s[i][j] == 'G') {
      gi = i, gj = j;
    }
  }

  vector cnt(2, vector(h, vector<int>(w, INF)));
  queue<pair<int, P>> q;
  cnt[0][si][sj] = 0, cnt[1][si][sj] = 0;
  rep(k, 0, 2) {
    rep(l, 0, 2) {
      int ni = si + di[k][l], nj = sj + dj[k][l];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1) continue;
      if (s[ni][nj] == '#') continue;
      q.push({k, {ni, nj}});
      cnt[k][ni][nj] = 1;
    }
  }
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int k = p.first;
    int i = p.second.first, j = p.second.second;
    // cout << k << " " << i << " " << j << endl;
    rep(l, 0, 2) {
      int ni = i + di[(k + 1) % 2][l], nj = j + dj[(k + 1) % 2][l];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1) continue;
      if (s[ni][nj] == '#') continue;
      if (cnt[(k + 1) % 2][ni][nj] != INF) continue;
      q.push({(k + 1) % 2, {ni, nj}});
      cnt[(k + 1) % 2][ni][nj] = cnt[k][i][j] + 1;
    }
  }

  if (cnt[0][gi][gj] != INF || cnt[1][gi][gj] != INF) {
    cout << min(cnt[0][gi][gj], cnt[1][gi][gj]) << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
