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

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int x, k;
    cin >> x >> k;
    --x;
    ll ans = 0;
    vector<bool> vis(n, false);
    queue<pair<int, int>> q;
    q.push({x, 0});
    vis[x] = true;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int now = t.first;
      int cnt = t.second;
      // cout << now << " " << cnt << endl;
      ans += now + 1;
      if (cnt >= k) continue;
      for (int nxt : g[now]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        q.push({nxt, cnt + 1});
      }
    }
    cout << ans << endl;
  }
  return 0;
}
