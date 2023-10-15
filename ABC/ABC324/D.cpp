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
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<int> a(10, 0);
  rep(i, 0, n) a[s[i] - '0']++;
  int ans = 0;
  rep(i, 0, 1e7) {
    // rep(i, 1, 20) {
    auto b = a;

    ll x = i;
    x *= x;
    int cnt = 0;
    while (x > 0 || cnt < n) {
      ll t = x % 10LL;

      --b[t];
      x /= 10LL;
      ++cnt;
    }

    bool ok = true;
    // cout << i << endl;
    rep(j, 0, 10) {
      // cout << b[j] << " ";
      if (b[j] != 0) ok = false;
    }
    // cout << endl;
    if (ok) {
      // cout << i << endl;
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
