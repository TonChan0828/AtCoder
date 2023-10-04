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
  int n = 3, m = 4;
  vector p(n, vector<string>(m));
  rep(i, 0, n) {
    rep(j, 0, 4) { cin >> p[i][j]; }
  }

  vector<vector<vector<string>>> s(n);
  rep(pi, 0, n) {
    rep(ri, 0, 4) {
      for (int di = -m; di < m; di++) {
        for (int dj = -m; dj < m; dj++) {
          vector np(m, string(m, '.'));
          bool ok = true;
          rep(i, 0, m) rep(j, 0, m) {
            if (p[pi][i][j] == '.') continue;
            int ni = i + di, nj = j + dj;
            if (ni < 0 || nj < 0 || ni >= m || nj >= m) {
              ok = false;
              continue;
            }
            np[ni][nj] = '#';
          }
          if (!ok) continue;
          s[pi].push_back(np);
        }
      }

      {
        auto pre = p[pi];
        rep(i, 0, m) rep(j, 0, m) { p[pi][i][j] = pre[m - 1 - j][i]; }
      }
    }
  }

  for (auto p0 : s[0]) {
    for (auto p1 : s[1]) {
      for (auto p2 : s[2]) {
        vector cnt(m, vector<int>(m));
        auto put = [&](vector<string> p) {
          rep(i, 0, m) {
            rep(j, 0, m) {
              if (p[i][j] == '#') cnt[i][j]++;
            }
          }
        };
        put(p0);
        put(p1);
        put(p2);
        if (cnt == vector(m, vector<int>(m, 1))) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
