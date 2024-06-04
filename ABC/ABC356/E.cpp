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
  const int m = 1e6 + 10;
  int n;
  cin >> n;
  vector<int> c(m);
  rep(i, 0, n) {
    int a;
    cin >> a;
    c[a]++;
  }

  vector<int> s(m);
  rep(i, 0, m - 1) { s[i + 1] = s[i] + c[i]; }

  auto sum = [&](int l, int r) {
    r = min(m - 1, r);
    return s[r] - s[l];
  };

  ll ans = 0;
  rep(y, 1, m - 4) {
    ll now = 0;
    for (int x = 1; x * y < m - 4; x++) {
      int l = y * x, r = y * (x + 1);
      now += (ll)sum(l, r) * x;
    }
    now -= c[y];
    ans += now * c[y];
    ans += c[y] * ll(c[y] - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
