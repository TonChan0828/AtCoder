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
  ll w, h, n;
  cin >> w >> h >> n;
  vector<pair<ll, ll>> pq(n);
  rep(i, 0, n) {
    ll p, q;
    cin >> p >> q;
    pq[i] = {p, q};
  }

  ll A;
  cin >> A;
  vector<ll> a(A + 1);
  rep(i, 0, A) cin >> a[i];
  a[A] = w;
  ll B;
  cin >> B;
  vector<ll> b(B + 1);
  rep(i, 0, B) cin >> b[i];
  b[B] = h;

  map<pair<int, int>, ll> mp;
  rep(i, 0, n) {
    auto itra = lower_bound(a.begin(), a.end(), pq[i].first);
    auto itrb = lower_bound(b.begin(), b.end(), pq[i].second);
    // printf("%d %d %d\n", i, *itra, *itrb);
    ++mp[{*itra, *itrb}];
  }
  ll ma = 0, mi = INT_MAX;
  // cout << mp.size() << endl;
  if ((A + 1LL) * (B + 1LL) != (ll)mp.size()) mi = 0;
  for (auto [key, value] : mp) {
    ma = max(ma, value);
    mi = min(mi, value);
  }
  printf("%lld %lld\n", mi, ma);
  return 0;
}
