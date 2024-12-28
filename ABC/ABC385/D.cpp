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
  int n, m;
  ll x, y;
  cin >> n >> m >> x >> y;
  map<ll, set<ll>> yx, xy;
  rep(i, 0, n) {
    ll xx, yy;
    cin >> xx >> yy;
    yx[yy].insert(xx);
    xy[xx].insert(yy);
  }

  int ans = 0;

  rep(i, 0, m) {
    char d;
    ll c;
    cin >> d >> c;

    if (d == 'D') {
      auto itr = xy[x].lower_bound(y - c);
      while (itr != xy[x].end() && *itr <= y) {
        // printf("  %d %d\n", x, *itr);
        yx[*itr].erase(x);
        itr = xy[x].erase(itr);
        ++ans;
      }
      y -= c;
    } else if (d == 'U') {
      auto itr = xy[x].lower_bound(y);
      while (itr != xy[x].end() && *itr <= y + c) {
        // printf("  %d %d\n", x, *itr);
        yx[*itr].erase(x);
        itr = xy[x].erase(itr);
        ++ans;
      }
      y += c;
    } else if (d == 'L') {
      auto itr = yx[y].lower_bound(x - c);
      while (itr != yx[y].end() && *itr <= x) {
        // printf("  %d %d\n", *itr, y);
        xy[*itr].erase(y);
        itr = yx[y].erase(itr);
        ++ans;
      }
      x -= c;
    } else if (d == 'R') {
      auto itr = yx[y].lower_bound(x);
      while (itr != yx[y].end() && *itr <= x + c) {
        // printf("  %d %d\n", *itr, y);
        xy[*itr].erase(y);
        itr = yx[y].erase(itr);
        ++ans;
      }
      x += c;
    }
    // printf("%lld %lld %d\n", x, y, ans);
  }

  printf("%lld %lld %d\n", x, y, ans);
  return 0;
}
