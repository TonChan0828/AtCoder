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
  cin >> n >> m;
  fenwick_tree<ll> d(n + 1);
  auto add = [&](int l, int r, ll x) {
    d.add(l, x);
    d.add(r, -x);
  };

  rep(i, 0, n) {
    int a;
    cin >> a;
    add(i, i + 1, a);
  }

  rep(i, 0, m) {
    int b;
    cin >> b;
    ll x = d.sum(0, b + 1);
    add(b, b + 1, -x);

    ll c = x / n;
    x %= n;
    add(0, n, c);
    b++;
    if (b + x < n) {
      add(b, b + x, 1);
    } else {
      add(b, n, 1);
      add(0, b + x - n, 1);
    }
  }

  rep(i, 0, n) {
    ll ans = d.sum(0, i + 1);
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}
