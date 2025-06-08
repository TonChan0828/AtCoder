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
  int T;
  cin >> T;

  while (T--) {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> c(n, vector<int>(2)), rc(n, vector<int>(2));
    rep(i, 0, n) {
      if (i) {
        c[i][0] = c[i - 1][0], c[i][1] = c[i - 1][1];
      }

      if (s[i] == '1') {
        c[i][1] = min(c[i][0], c[i][1]);
        c[i][0] += 1;
      } else {
        c[i][1] += 1;
      }
    }

    rrep(i, n - 1, 0) {
      if (i != n - 1) {
        rc[i][0] = rc[i + 1][0], rc[i][1] = rc[i + 1][1];
      }

      if (s[i] == '1') {
        rc[i][1] = min(rc[i][0], rc[i][1]);
        rc[i][0] += 1;
      } else {
        rc[i][1] += 1;
      }
    }

    int ans = n;
    ans = min(ans, c[n - 1][0]);
    ans = min(ans, c[n - 1][1]);
    ans = min(ans, rc[0][0]);
    ans = min(ans, rc[0][1]);

    rep(i, 0, n - 1) {
      ans = min(ans, c[i][0] + rc[i + 1][0]);
      ans = min(ans, c[i][1] + rc[i + 1][0]);
      ans = min(ans, c[i][0] + rc[i + 1][1]);
      ans = min(ans, c[i][1] + rc[i + 1][1]);
    }

    cout << ans << "\n";
  }
  return 0;
}
