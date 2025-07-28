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
  int n, k, x;
  cin >> n >> k >> x;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<string> ans;

  auto bfs = [&](auto bfs, string res, int cnt) {
    if (cnt == k) {
      // cout << res << endl;
      ans.push_back(res);
      return;
    }
    rep(i, 0, n) { bfs(bfs, res + s[i], cnt + 1); }
  };

  bfs(bfs, "", 0);
  sort(begin(ans), end(ans));
  cout << ans[x - 1] << endl;
  return 0;
}
