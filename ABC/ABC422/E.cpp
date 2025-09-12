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

struct V {
  ll x, y;
};

int main() {
  int n;
  cin >> n;
  vector<V> ps(n);
  rep(i, 0, n) cin >> ps[i].x >> ps[i].y;

  rep(ti, 0, 100) {
    int i = rand() % n, j = rand() % (n - 1);
    if (i <= j) j++;
    ll a = ps[j].y - ps[i].y;
    ll b = ps[i].x - ps[j].x;
    ll c = -(a * ps[i].x + b * ps[i].y);

    int cnt = 0;
    rep(k, 0, n) {
      if (a * ps[k].x + b * ps[k].y + c == 0) ++cnt;
    }

    if (cnt * 2 > n) {
      cout << "Yes\n";
      printf("%lld %lld %lld\n", a, b, c);
      return 0;
    }
  }

  cout << "No\n";
  return 0;
}
