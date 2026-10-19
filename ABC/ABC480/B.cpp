#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n), t(m);
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, m) cin >> t[i];

  vector<int> ans(n);
  rep(j, 0, m) {
    int tz = t[j].size();
    int tar = -1;
    bool ok = true;
    rep(i, 0, n) {
      int sz = s[i].size();
      if (abs(sz - tz) > 0) continue;
      int dif = 0;
      rep(k, 0, min(sz, tz)) {
        if (s[i][k] != t[j][k]) ++dif;
      }
      if (dif <= 1) {
        // cout << j << " " << i << endl;
        if (dif == 0) {
          tar = i;
          ok = true;
          break;
        }
        if (tar == -1) {
          tar = i;
        } else {
          ok = false;
        }
      }
    }

    if (ok && tar != -1) ans[tar]++;
  }

  rep(i, 0, n) { cout << ans[i] << "\n"; }
  return 0;
}
