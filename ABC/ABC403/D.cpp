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
const int ma = 1e6 + 1;
int solve(vector<int> a) {
  int n = a.size();
  vector dp(n + 1, vector<int>(2));
  rep(i, 0, n) {
    dp[i + 1][1] = max(dp[i][0], dp[i][1]);
    dp[i + 1][0] = dp[i][1] + a[i];
  }
  int mx = max(dp[n][0], dp[n][1]);
  int sum = reduce(begin(a), end(a));
  return sum - mx;
}
int main() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n), cnt(ma, 0);
  rep(i, 0, n) cin >> a[i], cnt[a[i]]++;

  int ans = 0;
  if (d == 0) {
    rep(i, 0, ma) {
      if (cnt[i] > 1) ans += cnt[i] - 1;
    }
    cout << ans << endl;
    return 0;
  }

  rep(i, 0, d) {
    vector<int> aa;
    int now = i;
    while (now < ma) {
      aa.push_back(cnt[now]);
      now += d;
    }
    ans += solve(aa);
  }

  cout << ans << endl;
  return 0;
}
