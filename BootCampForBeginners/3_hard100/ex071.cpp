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
  cin >> n;
  vector<int> a(n);
  ll ans = 0;
  rep(i, 0, n) {
    cin >> a[i];
    a[i] -= i + 1;
  }
  sort(a.begin(), a.end());
  int b;
  if (n % 2 == 1)
    b = a[n / 2];
  else
    b = (a[n / 2 - 1] + a[n / 2]) / 2;

  rep(i, 0, n) ans += abs(a[i] - b);
  cout << ans << endl;
  return 0;
}
