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
  int n, Q;
  cin >> n >> Q;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  ll sum = 0;
  rep(i, 0, n) sum += min(a[i], b[i]);

  while (Q--) {
    char c;
    int x, v;
    cin >> c >> x >> v;
    --x;
    sum -= min(a[x], b[x]);
    if (c == 'A') {
      a[x] = v;
    } else {
      b[x] = v;
    }
    sum += min(a[x], b[x]);
    // rep(i, 0, n) cout << " " << a[i];
    // cout << endl;
    // rep(i, 0, n) cout << " " << b[i];
    // cout << endl;
    cout << sum << "\n";
  }
  return 0;
}
