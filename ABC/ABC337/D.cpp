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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector row(h, vector<int>(w, 0)), rowO(h, vector<int>(w, 0)),
      col(h, vector<int>(w, 0)), colO(h, vector<int>(w, 0));
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (s[i][j] == 'x') continue;

      if (j != 0) {
        row[i][j] = row[i][j - 1];
        rowO[i][j] = rowO[i][j - 1];
      }
      if (s[i][j] == 'o') rowO[i][j]++;
      row[i][j]++;
    }
  }

  rep(j, 0, w) {
    rep(i, 0, h) {
      if (s[i][j] == 'x') continue;

      if (i != 0) {
        col[i][j] = col[i - 1][j];
        colO[i][j] = colO[i - 1][j];
      }
      if (s[i][j] == 'o') colO[i][j]++;
      col[i][j]++;
    }
  }

  const int INF = 100100100;
  int ans = INF;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (s[i][j] == 'x') continue;
      if (row[i][j] >= k) {
        int cntR = row[i][j];
        if (j + 1 > k) cntR -= row[i][j - k];
        if (cntR >= k) {
          cntR -= rowO[i][j];
          if (j + 1 > k) cntR += rowO[i][j - k];
          chmin(ans, cntR);
        }
      }

      if (col[i][j] >= k) {
        int cntC = col[i][j];
        if (i + 1 > k) cntC -= col[i - k][j];
        if (cntC >= k) {
          cntC -= colO[i][j];
          if (i + 1 > k) cntC += colO[i - k][j];
          chmin(ans, cntC);
        }
      }
    }
  }

  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}
