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
  ll k;
  cin >> k;
  vector<pair<ll, ll>> p;
  ll tar = k;
  for (ll i = 2; i * i <= k; ++i) {
    if (tar % i != 0) continue;
    ll cnt = 0;
    while (tar % i == 0) {
      ++cnt;
      tar /= i;
    }
    p.push_back({i, cnt});
    // cout << i << " " << cnt << endl;
  }
  if (tar != 1) p.push_back({tar, 1});

  // rep(i, 0, p.size()) { cout << p[i].first << " " << p[i].second << endl; }
  ll ans = 0;
  rep(i, 0, p.size()) {
    ll cnt = 0;
    ll d = 0;
    while (cnt < p[i].second) {
      ++d;
      ll tar = p[i].first * d;
      while (tar % p[i].first == 0) {
        ++cnt;
        tar /= p[i].first;
        // cout << tar << endl;
      }
    }
    ans = max(ans, p[i].first * d);
    // cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
