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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  vector<int> cnt(h, 0);
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (s[i][j] == '#') ++cnt[i];
    }
  }
  // rep(i, 0, h) cout << cnt[i] << endl;
  int tar = -1;
  rep(i, 0, h) {
    if (cnt[i] && tar == -1) {
      tar = i;
      continue;
    }
    if (cnt[tar] == cnt[i]) continue;
    if (cnt[tar] < cnt[i]) {
      break;
    }
    if (cnt[tar] > cnt[i] && cnt[i] > 0) {
      tar = i;
      break;
    }
  }

  int d = -1, e = 1;
  if (tar == 0) d = 1;
  if (tar == h - 1) e = -1;

  // cout << tar << " " << d << endl;
  rep(i, 0, w) {
    if (s[tar][i] == '.') {
      if (s[tar + d][i] == '#' || s[tar + e][i] == '#') {
        printf("%d %d\n", tar + 1, i + 1);
        return 0;
      }
    }
  }
  return 0;
}
