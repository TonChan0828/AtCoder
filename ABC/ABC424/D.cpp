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

void solve() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  int ans = 9;
  auto f = [&](auto f, int now) {
    if (now >= ans) return;

    rep(i, 0, h - 1) rep(j, 0, w - 1) {
      int cnt = 0;
      rep(di, 0, 2) rep(dj, 0, 2) if (s[i + di][j + dj] == '#') cnt++;

      if (cnt == 4) {
        rep(di, 0, 2) rep(dj, 0, 2) {
          s[i + di][j + dj] = ',';
          f(f, now + 1);
          s[i + di][j + dj] = '#';
        }
        return;
      }
    }

    ans = min(ans, now);
  };

  f(f, 0);
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  rep(ti, 0, t) { solve(); }
  return 0;
}
