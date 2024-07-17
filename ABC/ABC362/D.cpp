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

using P = pair<ll, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector g(n, vector<P>());
  rep(i, 0, m) {
    int u, v;
    ll b;
    cin >> u >> v >> b;
    --u, --v;
    g[u].push_back({b, v});
    g[v].push_back({b, u});
  }

  vector<ll> ans(n, 1001001001001001);

  priority_queue<P, vector<P>, greater<P>> q;
  q.push({a[0], 0});
  while (!q.empty()) {
    auto [cost, now] = q.top();
    q.pop();
    // cout << cost << " " << now << endl;

    if (cost >= ans[now]) continue;
    ans[now] = cost;
    for (auto [b, nxt] : g[now]) {
      ll nxtCost = cost + b + a[nxt];
      if (nxtCost >= ans[nxt]) continue;
      q.push({nxtCost, nxt});
    }
  }

  rep(i, 1, n) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
