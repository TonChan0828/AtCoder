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
  ll n;
  int m;
  cin >> n >> m;
  vector<ll> a(m), b(m);
  rep(i, 0, m) cin >> a[i] >> b[i];
  map<ll, ll> mp;
  rep(i, 0, m) {
    if (a[i] > n) continue;
    ll d = a[i] - b[i];
    // printf("  d:%lld a:%lld\n", d, a[i]);
    if (mp[d] == 0) mp[d] = a[i];
    mp[d] = min(mp[d], a[i]);
  }

  ll now = n;
  ll ans = 0;
  for (auto [d, t] : mp) {
    if (now < t) continue;
    ll cnt = (now - t) / d + 1;
    ans += cnt;
    now -= cnt * d;
    // printf("  d:%lld t:%lld now:%lld cnt:%lld ans:%lld\n", d, t, now, cnt,
    // ans);
  }
  cout << ans << endl;
  return 0;
}
