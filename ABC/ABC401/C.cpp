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
const ll P = 1e9;
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  ll now = 0;
  rep(i, 0, n + 1) {
    if (i < k) {
      a[i] = 1;
      now += a[i];
    } else {
      a[i] = now;
      now = (now + a[i] - a[i - k] + P) % P;
    }
    // printf("%7d %lld \n", i, now);
  }

  cout << a[n] % P << endl;
  return 0;
}
