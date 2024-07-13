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
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  vector g(n, vector<P>());
  ll sum = 0;
  rep(i, 0, n - 1) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
    sum += c;
  }
  sum *= 2;

  vector<ll> vis(n, -1);
  auto dfs = [&](auto dfs, int now) -> int {
    if (vis[now] > 0 && g[now].size() == 1) return now;

    int res = 0;
    ll tmp = 0;
    for (auto [nxt, cost] : g[now]) {
      if (vis[nxt] != -1) continue;
      vis[nxt] = vis[now] + cost;
      int tar = dfs(dfs, nxt);
      if (tmp < vis[tar]) {
        tmp = vis[tar];
        res = tar;
      }
    }
    return res;
  };
  vis[0] = 0;
  int x = dfs(dfs, 0);

  rep(i, 0, n) vis[i] = -1;
  vis[x] = 0;
  int y = dfs(dfs, x);

  cout << sum - vis[y] << endl;
  return 0;
}
