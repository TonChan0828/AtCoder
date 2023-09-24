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
  ll k;
  cin >> k;

  queue<ll> q;
  vector<ll> ans;
  rep(i, 1, 10) { q.push(i); }
  while (!q.empty()) {
    ll x = q.front();
    // cout << x << endl;
    q.pop();
    ans.push_back(x);
    // if (x > 9876543210) break;
    int m = x % 10;
    rep(i, 0, 10) {
      if (m > i) {
        q.push(x * 10LL + (ll)i);
      }
    }
  }
  sort(begin(ans), end(ans));
  cout << ans[k - 1] << endl;
  return 0;
}
