#include <bits/stdc++.h>
using namespace std;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  rep(i, 0, n) cin >> t[i];
  const int inf = 10101010;
  bitset<100001> dp;
  dp[0] = 1;
  int sum = 0;
  rep(i, 0, n) {
    sum += t[i];
    dp |= dp << t[i];
  }
  int ans = inf;
  rep(i, 0, sum + 1) {
    if (dp[i]) {
      chmin(ans, max(i, sum - i));
    }
  }
  cout << ans << endl;
  return 0;
}
