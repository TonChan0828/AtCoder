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
  vector<int> p(n);
  rep(i, 0, n) cin >> p[i];

  using P = pair<int, int>;
  vector<P> vp(n);
  rep(i, 0, n) vp[i] = {p[i], i};
  sort(begin(vp), end(vp), greater());
  int r = 1, now = vp[0].first;
  vector<int> ans(n);
  rep(i, 0, n) {
    auto [score, pos] = vp[i];
    if (score != now) {
      r = i + 1;
      now = score;
    }
    ans[pos] = r;
  }

  rep(i, 0, n) cout << ans[i] << "\n";
  return 0;
}
