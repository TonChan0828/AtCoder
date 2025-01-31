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
  int n, x;
  cin >> n >> x;
  vector<vector<pair<int, int>>> foods(3);
  rep(i, 0, n) {
    int v, a, c;
    cin >> v >> a >> c;
    --v;
    foods[v].emplace_back(a, c);
  }

  vector d(3, vector<int>(x + 1));
  rep(v, 0, 3) {
    vector<int> dp(x + 1);
    for (auto [a, c] : foods[v]) {
      rrep(i, x, c) { chmax(dp[i], dp[i - c] + a); }
    }
    d[v] = dp;
  }

  auto judge = [&](int r) {
    int tot = 0;
    rep(v, 0, 3) {
      if (d[v][x] < r) return false;
      int need = lower_bound(begin(d[v]), end(d[v]), r) - begin(d[v]);
      tot += need;
    }
    return tot <= x;
  };

  int ac = 0, wa = 1001001001;
  while (ac + 1 < wa) {
    int wj = (ac + wa) / 2;
    if (judge(wj))
      ac = wj;
    else
      wa = wj;
  }
  cout << ac << endl;
  return 0;
}
