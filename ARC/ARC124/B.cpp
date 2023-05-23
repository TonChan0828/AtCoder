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
  vector<ll> a(n);
  unordered_map<ll, int> b;
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) {
    ll t;
    cin >> t;
    ++b[t];
  }
  vector<ll> ans;

  for (auto [key, value] : b) {
    bool ok = true;
    ll tar = a[0] ^ key;
    auto tmp = b;
    --tmp[key];
    rep(i, 1, n) {
      if (tmp[tar ^ a[i]] > 0) {
        --tmp[tar ^ a[i]];
      } else {
        ok = false;
      }
    }
    if (ok) ans.push_back(tar);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (ll x : ans) cout << x << endl;
  return 0;
}
