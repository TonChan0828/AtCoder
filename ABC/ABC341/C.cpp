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

const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

int main() {
  int h, w, n;
  string t;
  cin >> h >> w >> n >> t;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  auto check = [&](int y, int x) -> bool {
    if (y < 0 || x < 0 || y >= h || x >= w) return false;
    if (s[y][x] == '.') return true;
    return false;
  };

  int ans = 0;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (!check(i, j)) continue;
      bool ok = true;
      int ni = i, nj = j;
      rep(k, 0, n) {
        if (t[k] == 'L') {
          ni += di[0], nj += dj[0];
        } else if (t[k] == 'R') {
          ni += di[1], nj += dj[1];
        } else if (t[k] == 'U') {
          ni += di[2], nj += dj[2];
        } else {
          ni += di[3], nj += dj[3];
        }

        if (!check(ni, nj)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ++ans;
        // cout << i << " " << j << endl;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
