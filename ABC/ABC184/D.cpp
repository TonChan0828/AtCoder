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
  int a, b, c;
  cin >> a >> b >> c;
  vector dp(101, vector<vector<double>>(101, vector<double>(101)));
  auto f = [&](auto f, int a, int b, int c) -> double {
    if (dp[a][b][c]) return dp[a][b][c];
    if (a == 100 || b == 100 || c == 100) return 0;
    double ans = 0;
    ans += (f(f, a + 1, b, c) + 1) * a / (a + b + c);
    ans += (f(f, a, b + 1, c) + 1) * b / (a + b + c);
    ans += (f(f, a, b, c + 1) + 1) * c / (a + b + c);
    dp[a][b][c] = ans;
    return ans;
  };
  printf("%.10f\n", f(f, a, b, c));

  return 0;
}
