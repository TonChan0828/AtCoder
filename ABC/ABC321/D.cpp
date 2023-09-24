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
  ll p;
  cin >> n >> m >> p;
  vector<ll> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  sort(begin(b), end(b));
  map<ll, int> bb;
  rep(i, 0, m) {
    if (bb[b[i]] == 0) bb[b[i]] = i;
  }
  vector<ll> sumB(m);
  rep(i, 0, m) {
    if (i == 0)
      sumB[i] = b[i];
    else {
      sumB[i] = sumB[i - 1] + b[i];
    }
  }
  ll ans = 0;

  rep(i, 0, n) {
    auto itr = upper_bound(begin(b), end(b), p - a[i]);

    if (itr == b.begin()) {
      ans += (ll)m * p;
    } else if (itr == b.end()) {
      ans += a[i] * m;
      ans += sumB[m - 1];
    } else {
      ll lo = itr - b.begin();
      int pos = bb[*itr];
      ans += a[i] * lo;
      ans += sumB[pos - 1];
      ll ov = b.end() - itr;
      // cout << ans << endl;
      ans += ov * p;
    }

    // cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
