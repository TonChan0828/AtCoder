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
int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};
using P = pair<int, int>;
using PP = pair<int, tuple<int, int, int>>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h) cin >> a[i];
  int si, sj, gi, gj;
  rep(i, 0, h) rep(j, 0, w) {
    if (a[i][j] == 'S') si = i, sj = j;
    if (a[i][j] == 'G') gi = i, gj = j;
  }
  const int INF = 1001001;
  vector vis(2, vector(h, vector<int>(w, INF)));

  priority_queue<PP, vector<PP>, greater<PP>> q;
  q.emplace(0, make_tuple(0, si, sj));
  while (!q.empty()) {
    auto [cost, pos] = q.top();
    q.pop();
    auto [s, i, j] = pos;
    if (cost >= vis[s][i][j]) continue;
    vis[s][i][j] = cost;
    if (i == gi && j == gj) continue;

    rep(k, 0, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1) continue;
      if (a[ni][nj] == '#') continue;
      if (s == 0 && a[ni][nj] == 'x') continue;
      if (s == 1 && a[ni][nj] == 'o') continue;
      int ns = s;
      if (a[ni][nj] == '?') ns = (ns + 1) % 2;
      if (cost + 1 >= vis[ns][ni][nj]) continue;
      q.emplace(cost + 1, make_tuple(ns, ni, nj));
    }
  }

  int ans = min(vis[0][gi][gj], vis[1][gi][gj]);
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
