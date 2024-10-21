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

  int l = 0, r = 1;
  int ans = 0;
  while (Q--) {
    char h;
    int t;
    cin >> h >> t;
    --t;
    // cout << h << t << endl;
    int nxt = t;
    int target = 0, other = 0;
    if (h == 'L') {
      target = l, other = r;
    } else {
      target = r, other = l;
    }

    if (target > nxt) swap(target, nxt);
    if (target < other && other < nxt) {
      ans += n + target - nxt;
    } else {
      ans += nxt - target;
    }

    if (h == 'L') {
      l = t;
    } else {
      r = t;
    }
    // printf("%d %d %d\n", ans, l, r);
  }

  cout << ans << endl;
  return 0;
}
