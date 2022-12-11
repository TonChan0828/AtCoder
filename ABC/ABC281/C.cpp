#include <bits/stdc++.h>
using namespace std;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n;
  ll t;
  cin >> n >> t;
  vector<ll> a(n);
  ll all = 0;
  rep(i, 0, n) {
    cin >> a[i];
    all += a[i];
  }
  ll sum = all * (t / all);
  ll cnt = 0;
  while (sum < t) {
    if (sum + a[cnt % n] > t) {
      cout << cnt % n + 1 << " " << t - sum << endl;
      return 0;
    }
    sum += a[cnt % n];
    ++cnt;
  }
  return 0;
}
