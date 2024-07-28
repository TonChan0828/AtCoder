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
  int h, w;
  cin >> h >> w;
  vector c(h, vector<char>(w));
  int si, sj;
  cin >> si >> sj;
  --si, --sj;
  rep(i, 0, h) rep(j, 0, w) cin >> c[i][j];
  string X;
  cin >> X;

  for (char x : X) {
    int ni = si, nj = sj;
    if (x == 'U') {
      --ni;
    } else if (x == 'D') {
      ++ni;
    } else if (x == 'L') {
      --nj;
    } else {
      ++nj;
    }

    if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
    if (c[ni][nj] == '#') continue;
    si = ni, sj = nj;
  }

  cout << si + 1 << " " << sj + 1 << endl;
  return 0;
}
