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
  vector<vector<int>> table(37);
  vector<int> c(n);
  rep(i, 0, n) {
    cin >> c[i];
    rep(j, 0, c[i]) {
      int a;
      cin >> a;
      table[a].push_back(i);
    }
  }
  int x;
  cin >> x;
  vector<pair<int, int>> vp;
  for (int y : table[x]) {
    vp.push_back({c[y], y + 1});
  }
  sort(vp.begin(), vp.end());
  int res = 0;

  for (auto [cnt, p] : vp) {
    if (cnt == vp[0].first) {
      ++res;
    }
  }
  cout << res << endl;
  for (auto [cnt, p] : vp) {
    if (cnt == vp[0].first) {
      printf("%d ", p);
        }
  }
  cout << endl;
  return 0;
}
