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
bool desc_asc(pair<int, string> &left, pair<int, string> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

using P = pair<int, string>;

int main() {
  vector<int> score(5);
  rep(i, 0, 5) cin >> score[i];
  string problem = "ABCDE";

  vector<P> ans;
  rep(i, 1, 1 << 5) {
    int res = 0;
    string s;
    rep(j, 0, 5) {
      if (i & (1 << j)) {
        res += score[j];
        s += problem[j];
      }
    }
    ans.push_back({res, s});
  }

  sort(begin(ans), end(ans), desc_asc);
  for (auto p : ans) cout << p.second << "\n";
  return 0;
}
