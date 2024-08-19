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
  int n, k;
  cin >> n >> k;
  vector<int> r(n);
  rep(i, 0, n) cin >> r[i];

  vector<vector<int>> ans;
  auto dfs = [&](auto dfs, int pos, int sum, vector<int> x) -> void {
    if (pos == n) {
      if (sum % k == 0) {
        ans.push_back(x);
      }
      return;
    }

    rep(i, 1, r[pos] + 1) {
      x[pos] = i;
      dfs(dfs, pos + 1, sum + i, x);
    }
  };
  vector<int> tmp(n);
  dfs(dfs, 0, 0, tmp);

  sort(begin(ans), end(ans));
  for (auto x : ans) {
    rep(i, 0, n) cout << x[i] << " ";
    cout << endl;
  }
  return 0;
}
