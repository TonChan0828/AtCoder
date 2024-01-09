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
  int n, Q;
  cin >> n >> Q;
  int y = 0, x = 1;
  int cnt = 0;
  deque<pair<int, int>> dq;
  rep(i, 1, Q + 1) {
    int q;
    cin >> q;
    if (q == 1) {
      char c;
      cin >> c;
      if (c == 'R') {
        x++;
      } else if (c == 'L') {
        x--;
      } else if (c == 'U') {
        y++;
      } else {
        y--;
      }
      dq.push_front({x, y});
      // cout << "   " << x << " " << y << endl;
      cnt++;
    } else {
      int p;
      cin >> p;
      if (p > cnt) {
        printf("%d 0\n", p - cnt);
      } else {
        auto [nx, ny] = dq[p - 1];
        printf("%d %d\n", nx, ny);
      }
    }
  }
  return 0;
}
