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

using P = pair<ll, ll>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> xa(m);
  rep(i, 0, m) cin >> xa[i].first;
  rep(i, 0, m) cin >> xa[i].second;
  sort(begin(xa), end(xa));
  xa.push_back({n + 1, 0});

  ll sum = 0;
  int px = 0;
  ll num = 1;
  for (auto [x, a] : xa) {
    ll l = x - px;
    ll carry = num - l;
    if (carry < 0) {
      cout << -1 << endl;
      return 0;
    }

    sum += x * a;

    px = x;
    num = carry + a;
  }

  ll ans = ll(n + 1) * n / 2 - sum;

  if (num != 0) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
