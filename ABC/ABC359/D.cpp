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

  auto reverseCheck = [](string s) -> bool {
    string rs = s;
    reverse(begin(rs), end(rs));
    return s == rs;
  };

  map<string, mint> dp;
  dp[""] = 1;
  rep(i, 0, n) {
    map<string, mint> pre;
    swap(dp, pre);
    for (auto [t, num] : pre) {
      for (char c = 'A'; c <= 'B'; ++c) {
        if (s[i] != '?' && s[i] != c) continue;
        string tc = t + c;
        if (tc.size() == k && reverseCheck(tc)) continue;
        if (tc.size() == k) tc.erase(begin(tc));
        dp[tc] += num;
      }
    }
  }

  mint ans = 0;
  for (auto [t, num] : dp) ans += num;
  cout << ans.val() << endl;
  return 0;
}
