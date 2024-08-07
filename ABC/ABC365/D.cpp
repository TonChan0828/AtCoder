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

  map<char, int> mp;
  mp['R'] = 0;
  mp['P'] = 1;
  mp['S'] = 2;

  auto battle = [&](int a, int b) -> int { return ((b + 1) % 3 == a); };

  vector dp(n + 1, vector<int>(3, 0));
  rep(i, 0, n) {
    rep(j, 0, 3) {
      if (battle(mp[s[i]], j)) continue;
      int score = 0;
      if (i) {
        rep(k, 0, 3) {
          if (j == k) continue;
          if (battle(mp[s[i - 1]], k)) continue;
          score = max(score, dp[i][k]);
        }
      }
      dp[i + 1][j] = score + battle(j, mp[s[i]]);
    }
  }

  // rep(j, 0, 3) {
  //   rep(i, 0, n + 1) cout << dp[i][j] << " ";
  //   cout << endl;
  // }

  cout << ranges::max(dp[n]) << endl;
  return 0;
}
