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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<ll> pos;
  int now = 0;
  int ud = (a[1] - a[0] > 0) ? 0 : 1;
  pos.push_back(0);
  rep(i, 1, n) {
    int now = (a[i + 1] - a[i] > 0) ? 0 : 1;
    if (now != ud) {
      pos.push_back(i);
      ud = now;
    }
  }
  pos.push_back(n - 1);

  ll ans = 0;
  int sz = pos.size();
  rep(i, 0, sz - 3) {
    if (a[pos[i + 1]] - a[pos[i]] < 0) continue;
    ans += (pos[i + 1] - pos[i]) * (pos[i + 3] - pos[i + 2]);
  }
  cout << ans << endl;
  return 0;
}
