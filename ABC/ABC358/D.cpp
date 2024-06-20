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
  vector<int> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  // for (int x : a) cout << x << " ";
  // cout << endl;

  ll ans = 0;
  if (n < m) {
    ans = -1;
  } else {
    int mi = 0;
    rep(i, 0, m) {
      auto itr = lower_bound(begin(a) + mi, end(a), b[i]);
      if (itr == end(a)) {
        ans = -1;
        break;
      }
      int dist = itr - begin(a) - mi;
      if (dist < 0) {
        ans = -1;
        break;
      }
      ans += *itr;
      mi += dist + 1;
      // cout << *itr << " " << mi << endl;
    }
  }

  cout << ans << endl;
  return 0;
}
