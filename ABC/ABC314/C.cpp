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
  int n, m;
  cin >> n >> m;
  vector<deque<char>> dp(m);
  string s;
  vector<int> c(n);
  cin >> s;
  rep(i, 0, n) {
    cin >> c[i];
    --c[i];
  }

  rep(i, 0, n) dp[c[i]].push_back(s[i]);
  rep(i, 0, m) {
    dp[i].push_front(dp[i].back());
    dp[i].pop_back();
  }

  vector<int> cnt(m, 0);
  string ans = "";
  rep(i, 0, n) { ans.push_back(dp[c[i]][cnt[c[i]]++]); }
  cout << ans << endl;
  return 0;
}
