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

using mint = modint998244353;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  const unsigned mask{(1U << k - 1) - 1};
  vector<int> ng;
  rep(i, 0, 1 << k) {
    bool ok = true;
    for (int j = 0, l = k - 1; j < l; ++j, --l) {
      if ((1 & i >> j) != (1 & i >> l)) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      ng.push_back(i);
    }
  }

  vector<mint> dp(1 << k - 1), pre(1 << k - 1);
  {
    unsigned a_mask{}, q_mask{};
    for (auto c : s | views::take(k - 1)) {
      a_mask *= 2;
      q_mask *= 2;
      a_mask += (c == 'A');
      q_mask += (c != '?');
    }
    for (unsigned i{q_mask}; i < 1U << k - 1; ++i |= q_mask) dp[i ^ a_mask] = 1;
  }

  for (auto c : s | views::drop(k - 1)) {
    swap(dp, pre);
    ranges::fill(dp, mint{});

    if (c != 'B') {
      for (auto i : ng | views::filter([](auto i) { return ~i & 1; })) {
        dp[i & mask] += pre[i / 2];
      }
    }
    if (c != 'A') {
      for (auto i : ng | views::filter([](auto i) { return i & 1; })) {
        dp[i & mask] += pre[i / 2];
      }
    }
  }

  cout << reduce(begin(dp), end(dp)).val() << endl;
  return 0;
}
