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
using mint = modint1000000007;

const int dx[] = {0, -1, -1};
const int dy[] = {-1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  vector<vector<mint>> dp(h, vector<mint>(w, 0)), tate(h, vector<mint>(w, 0)),
      yoko(h, vector<mint>(w, 0)), naname(h, vector<mint>(w, 0));
  dp[0][0] = tate[0][0] = yoko[0][0] = naname[0][0] = 1;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (s[i][j] == '#') continue;
      if (i > 0 && j > 0) dp[i][j] += naname[i - 1][j - 1];
      if (i > 0) dp[i][j] += tate[i - 1][j];
      if (j > 0) dp[i][j] += yoko[i][j - 1];
      tate[i][j] = yoko[i][j] = naname[i][j] = dp[i][j];
      if (i > 0 && j > 0) naname[i][j] += naname[i - 1][j - 1];
      if (i > 0) tate[i][j] += tate[i - 1][j];
      if (j > 0) yoko[i][j] += yoko[i][j - 1];
    }
  }

  cout << dp[h - 1][w - 1].val() << endl;
  return 0;
}
