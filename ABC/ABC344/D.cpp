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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

const int INF = 100100100;

int main() {
  string t = " ", tt;
  int n;
  cin >> tt >> n;
  t += tt;
  vector s(n, vector<string>());
  vector<int> a(n);
  rep(i, 0, n) {
    cin >> a[i];
    rep(j, 0, a[i]) {
      string tmp;
      cin >> tmp;
      s[i].push_back(tmp);
    }
  }

  int tz = t.size();

  vector dp(n + 1, vector<int>(tz, INF));
  dp[0][0] = 0;

  rep(i, 0, n) {
    rrep(k, tz - 1, 0) {
      dp[i + 1][k] = dp[i][k];
      if (dp[i][k] == INF) continue;
      rep(j, 0, a[i]) {
        int sz = s[i][j].size();
        bool ok = true;
        rep(l, 0, sz) {
          if ((k + l + 1 > tz) || (s[i][j][l] != t[k + l + 1])) {
            ok = false;
            break;
          }
        }
        if (ok) {
          dp[i + 1][k + sz] = min(dp[i + 1][k + sz], dp[i][k] + 1);
        }
      }
    }
    // rep(k, 0, tz) { cout << dp[i + 1][k] << " "; }
    // cout << endl;
  }

  int ans = dp[n][tz - 1];
  if (ans == INF) ans = -1;
  cout << ans << endl;

  return 0;
}
