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

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int main() {
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  --x, --y;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int ans = 1;
  rep(k, 0, 4) {
    int ni = x + di[k], nj = y + dj[k];

    while (ni >= 0 && ni < h && nj >= 0 && nj < w) {
      if (s[ni][nj] == '#') {
        break;
      }
      ni += di[k], nj += dj[k];
    }
    // cout << ni << " " << nj << endl;
    ans += abs(ni - x) + abs(nj - y) - 1;
  }
  cout << ans << endl;
  return 0;
}
