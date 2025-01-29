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
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<ll> xs;
  vector<ll> sums;
  ll x = 0;
  auto dfs = [&](auto dfs, int i) {
    if (i == n) {
      xs.push_back(x);
      return;
    }

    rep(j, 0, sums.size()) {
      x ^= sums[j];
      sums[j] += a[i];
      x ^= sums[j];
      dfs(dfs, i + 1);
      x ^= sums[j];
      sums[j] -= a[i];
      x ^= sums[j];
    }

    sums.push_back(a[i]);
    x ^= a[i];
    dfs(dfs, i + 1);
    sums.pop_back();
    x ^= a[i];
  };

  dfs(dfs, 0);
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  cout << xs.size() << endl;
  return 0;
}
