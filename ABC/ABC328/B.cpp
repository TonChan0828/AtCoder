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
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, 0, n) cin >> d[i];
  int ans = 0;
  rep(i, 1, n + 1) {
    rep(j, 1, d[i - 1] + 1) {
      vector<int> num(10);
      int x = i, y = j;
      while (x > 0) {
        num[x % 10]++;
        x /= 10;
      }
      while (y > 0) {
        num[y % 10]++;
        y /= 10;
      }
      int cnt = 0;
      rep(k, 0, 10) {
        if (num[k]) cnt++;
      }
      if (cnt == 1) {
        ++ans;
        // cout << i << " " << j << endl;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
