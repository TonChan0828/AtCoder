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
  ll h, w, m;
  cin >> h >> w >> m;

  vector<ll> t(m), a(m), x(m);
  rep(i, 0, m) { cin >> t[i] >> a[i] >> x[i]; }

  ll toth = 0, totw = 0;
  map<ll, ll> mp;
  set<ll> ah, wh;
  mp[0] = h * w;

  rrep(i, m - 1, 0) {
    if (t[i] == 1) {
      if (ah.contains(a[i])) continue;
      ah.insert(a[i]);
      mp[x[i]] += w - totw;
      toth++;
      mp[0] -= w - totw;
    } else {
      if (wh.contains(a[i])) continue;
      wh.insert(a[i]);
      mp[x[i]] += h - toth;
      totw++;
      mp[0] -= h - toth;
    }
  }
  int cnt = 0;
  for (auto [_, val] : mp)
    if (val != 0) ++cnt;

  cout << cnt << endl;
  for (auto [key, val] : mp) {
    if (val != 0) printf("%lld %lld\n", key, val);
  }
  return 0;
}
