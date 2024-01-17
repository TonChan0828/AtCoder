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
  ll n;
  cin >> n;
  ++n;

  ll dp[16][2][130][130];
  vector<int> digit;
  while (n) {
    digit.push_back(n % 10);
    n /= 10;
  }
  reverse(begin(digit), end(digit));
  int m = digit.size();

  ll ans = 0;
  for (int k = 1; k <= 126; ++k) {
    rep(i, 0, m + 1) rep(j, 0, 2) rep(s, 0, k + 1) rep(r, 0, k) dp[i][j][s][r] =
        0;
    dp[0][0][0][0] = 1;
    rep(i, 0, m) rep(j, 0, 2) rep(s, 0, k + 1) rep(r, 0, k) {
      rep(d, 0, 10) {
        int ni = i + 1;
        int nj = j;
        int ns = s + d;
        int nr = (r * 10 + d) % k;
        if (ns > k) continue;
        if (j == 0) {
          if (digit[i] < d) continue;
          if (digit[i] > d) nj = 1;
        }
        dp[ni][nj][ns][nr] += dp[i][j][s][r];
      }
    }
    ans += dp[m][1][k][0];
  }
  cout << ans << endl;
  return 0;
}
