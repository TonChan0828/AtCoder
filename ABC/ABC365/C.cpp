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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  ll all = 0;
  rep(i, 0, n) {
    cin >> a[i];
    all += a[i];
  }

  if (all <= m) {
    cout << "infinite" << endl;
    return 0;
  }

  ll l = 0, r = m;
  while (l + 1LL < r) {
    // cout << l << " " << r << endl;
    ll mid = (l + r) / 2LL;

    ll sum = 0;
    rep(i, 0, n) sum += min(a[i], mid);

    if (sum <= m) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l << endl;
  return 0;
}
