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
  vector<int> k(n);
  vector a(n, vector<int>());
  rep(i, 0, n) {
    cin >> k[i];
    rep(j, 0, k[i]) {
      int aa;
      cin >> aa;
      a[i].push_back(aa);
    }
  }

  double ans = 0;
  rep(i, 1, n) {
    rep(j, 0, i) {
      double now = 0;
      map<int, int> cnt;
      for (int na : a[j]) cnt[na]++;
      for (int na : a[i]) now += cnt[na];
      now /= k[i];
      now /= k[j];

      ans = max(ans, now);
    }
  }

  // cout << ans << endl;
  printf("%.10f\n", ans);
  return 0;
}
