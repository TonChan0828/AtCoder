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
  int sum = 0;
  rep(i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % n != 0) {
    cout << -1 << endl;
    return 0;
  }
  double ave = sum / n;
  int ans = 0;
  int pos = -1;
  double tar = 0;
  rep(i, 0, n) {
    tar += a[i];
    if (tar / (double)(i - pos) == ave) {
      ans += i - pos - 1;
      pos = i;
      tar = 0;
    }
    // cout << ans << endl;
  }
  cout << ans << endl;

  return 0;
}
