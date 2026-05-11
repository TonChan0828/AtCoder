#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<vector<int>> a(n);
  rep(i, 0, n) {
    int l;
    cin >> l;
    a[i].resize(l);
    rep(j, 0, l) cin >> a[i][j];
  }
  vector<int> c(n);
  rep(i, 0, n) cin >> c[i];

  ll cnt = 0;
  rep(i, 0, n) {
    ll l = a[i].size();
    if (cnt + (ll)c[i] * l < k) {
      cnt += c[i] * l;
      continue;
    }
    k -= cnt;
    k--;
    // cout << i << " " << k % l << endl;
    cout << a[i][k % l] << endl;
    break;
  }
  return 0;
}
