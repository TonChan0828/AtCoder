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
  int h, w, d;
  cin >> h >> w >> d;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  int ans = 0;
  rep(i1, 0, h) {
    rep(j1, 0, w) {
      if (s[i1][j1] == '#') continue;
      rep(i2, 0, h) {
        rep(j2, 0, w) {
          if (s[i2][j2] == '#') continue;

          vector<string> tmp = s;
          int cnt = 0;
          rep(k, 0, h) {
            rep(l, 0, w) {
              if (tmp[k][l] != '.') continue;
              int d1 = abs(k - i1) + abs(l - j1);
              int d2 = abs(k - i2) + abs(l - j2);
              if (d1 <= d || d2 <= d) {
                cnt++;
                tmp[k][l] = '@';
              }
            }
          }
          ans = max(ans, cnt);
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
