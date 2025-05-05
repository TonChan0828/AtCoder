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
  cin >> n;
  vector<string> s(n), t(n);
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, n) cin >> t[i];
  int ans = 1001001;
  rep(k, 0, 4) {
    int cnt = k;
    rep(i, 0, n) rep(j, 0, n) if (s[i][j] != t[i][j])++ cnt;
    ans = min(ans, cnt);
    auto tmp = s;
    rep(i, 0, n) rep(j, 0, n) s[i][j] = tmp[n - j - 1][i];
  }

  cout << ans << endl;
  return 0;
}
