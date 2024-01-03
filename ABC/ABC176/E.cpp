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
using P = pair<int, int>;
int main() {
  int h, w, m;
  cin >> h >> w >> m;
  vector<int> hs(h), ws(w);
  set<P> s;
  rep(i, 0, m) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    hs[r]++;
    ws[c]++;
    s.emplace(r, c);
  }

  int mh = 0, mw = 0;
  rep(i, 0, h) mh = max(mh, hs[i]);
  rep(i, 0, w) mw = max(mw, ws[i]);

  vector<int> is, js;
  rep(i, 0, h) if (mh == hs[i]) is.push_back(i);
  rep(j, 0, w) if (mw == ws[j]) js.push_back(j);

  int ans = mh + mw;
  for (int i : is) {
    for (int j : js) {
      if (s.count(P(i, j))) continue;
      cout << ans << endl;
      return 0;
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
