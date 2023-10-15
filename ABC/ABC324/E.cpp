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
  string t;
  cin >> t;
  int tz = t.size();
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<int> fo(n), ba(n);
  rep(i, 0, n) {
    int cnt = 0;
    int sz = s[i].size();
    rep(j, 0, sz) {
      if (s[i][j] == t[cnt]) ++cnt;
    }
    fo[i] = cnt;

    cnt = 0;
    rrep(j, sz - 1, 0) {
      if (s[i][j] == t[tz - 1 - cnt]) ++cnt;
    }
    ba[i] = cnt;
  }
  sort(begin(ba), end(ba));
  ll ans = 0;
  rep(i, 0, n) {
    auto itr = lower_bound(begin(ba), end(ba), tz - fo[i]);
    int dist = ba.end() - itr;
    ans += dist;
  }
  cout << ans << endl;
  return 0;
}
