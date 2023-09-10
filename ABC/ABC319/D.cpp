#include <bits/stdc++.h>

#include <atcoder/all>
#include <ranges>
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
  vector<ll> l(n);
  rep(i, 0, n) {
    cin >> l[i];
    ++l[i];
  }
  ll lower = ranges::max(l) - 1;
  ll upper = reduce(begin(l), end(l));

  while (lower + 1 < upper) {
    ll mid = (lower + upper) / 2;

    int rows = 1;
    ll len = 0;
    rep(i, 0, n) {
      len += l[i];

      if (len > mid) {
        ++rows;
        len = l[i];
      }
    }

    if (rows > m) {
      lower = mid;
    } else {
      upper = mid;
    }
  }
  cout << upper - 1 << endl;

  return 0;
}
