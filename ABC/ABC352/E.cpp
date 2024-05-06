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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  map<ll, vector<vector<ll>>> mp;
  rep(_, 0, m) {
    ll k, c;
    cin >> k >> c;
    vector<ll> v;
    rep(j, 0, k) {
      int a;
      cin >> a;
      --a;
      v.push_back(a);
    }
    mp[c].push_back(v);
  }

  dsu uf(n);
  ll ans = 0;
  for (auto [cost, vv] : mp) {
    for (auto v : vv) {
      int p = v[0];
      for (int ver : v) {
        if (!uf.same(p, ver)) {
          ans += cost;
          uf.merge(p, ver);
        }
      }
    }
  }

  if (uf.size(0) != n) ans = -1;
  cout << ans << endl;
  return 0;
}
