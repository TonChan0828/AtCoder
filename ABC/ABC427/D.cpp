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
  int T;
  cin >> T;

  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<vector<int>> to(n);
    rep(i, 0, m) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      to[u].push_back(v);
    }

    vector dp(2 * k + 1, vector<int>(n));
    rep(v, 0, n) { dp[2 * k][v] = (s[v] == 'A'); }

    rrep(i, 2 * k - 1, 0) {
      rep(v, 0, n) {
        dp[i][v] = 0;
        for (int u : to[v]) {
          if (!dp[i + 1][u]) dp[i][v] = 1;
        }
      }
    }
    if (dp[0][0])
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
  return 0;
}
