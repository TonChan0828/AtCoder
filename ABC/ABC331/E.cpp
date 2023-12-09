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
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  vector<pair<int, int>> bb;
  rep(i, 0, m) bb.push_back({b[i], i});
  sort(begin(bb), end(bb), greater());
  set<pair<int, int>> set;
  rep(i, 0, l) {
    int c, d;
    cin >> c >> d;
    --c, --d;
    set.insert({c, d});
  }

  int ans = 0;
  rep(i, 0, n) {
    rep(j, 0, m) {
      if (set.find({i, bb[j].second}) == set.end()) {
        chmax(ans, a[i] + bb[j].first);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
