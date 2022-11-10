#include <bits/stdc++.h>
using namespace std;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<pair<ll, ll>>> t(n + 1);
  rep(i, 0, n - 1) {
    ll a, b, c;
    cin >> a >> b >> c;
    t[a].push_back({b, c});
    t[b].push_back({a, c});
  }
  ll q, k;
  cin >> q >> k;
  vector<ll> ans(n + 1, -1);
  ans[k] = 0;
  queue<ll> qu;
  qu.push(k);
  while (!qu.empty()) {
    ll pa = qu.front();
    qu.pop();
    for (auto x : t[pa]) {
      if (ans[x.first] != -1) continue;
      ans[x.first] = ans[pa] + x.second;
      qu.push(x.first);
    }
  }
  // rep(i, 1, n + 1) cout << ans[i] << endl;

  rep(i, 0, q) {
    ll x, y;
    cin >> x >> y;
    cout << (ans[x] + ans[y]) << endl;
  }

  return 0;
}
