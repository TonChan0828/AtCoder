#include <bits/stdc++.h>
using namespace std;
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
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, 0, h) {
    rep(j, 0, w) { cin >> a[i][j]; }
  }
  vector<vector<int>> ans;
  int x, y;
  bool e = true;
  rep(i, 0, h) {
    if (i % 2 == 0) {
      rep(j, 0, w) {
        if (!e) {
          ans.push_back({y, x, i, j});
          y = i, x = j;
        }
        if (a[i][j] % 2 == 1) {
          if (!e) {
            e = true;
          } else {
            y = i, x = j;
            e = false;
          }
        }
      }
    } else {
      rrep(j, w - 1, 0) {
        if (!e) {
          ans.push_back({y, x, i, j});
          y = i, x = j;
        }
        if (a[i][j] % 2 == 1) {
          if (!e) {
            e = true;
          } else {
            y = i, x = j;
            e = false;
          }
        }
      }
    }
  }
  cout << ans.size() << endl;
  rep(i, 0, ans.size()) {
    rep(j, 0, 4) {
      if (j != 0) cout << " ";
      cout << ans[i][j] + 1;
    }
    cout << endl;
  }

  return 0;
}
