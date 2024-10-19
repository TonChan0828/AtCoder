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
  cin >> n >> s;
  vector<ll> v;
  int cnt = 0;
  char c = 'C';
  rep(i, 0, n) {
    if (c != s[i]) {
      ++cnt;
    } else {
      if (cnt >= 3) {
        v.push_back((cnt + 1) / 2);
      }
      cnt = 1;
    }
    c = s[i];
  }
  if (cnt >= 3) v.push_back((cnt + 1) / 2);

  const ll r = 1e9 + 7;
  ll ans = 1;
  for (ll x : v) {
    ans *= x;
    ans %= r;
  }

  cout << ans << endl;
  return 0;
}
