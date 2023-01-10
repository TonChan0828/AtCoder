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
  ll n;
  cin >> n;
  ll left = 1, right = 2 * pow(10, 9) + 1;
  ll mid = 0;
  while (left < right) {
    mid = (left + right) / 2;
    ll sum = (mid * (mid + 1)) / 2;
    if (sum < n + 1) {
      left = mid + 1;
    } else {
      right = mid;
    }
    // cout << mid << endl;
  }
  ll tmp = (right + left) / 2;
  if ((tmp * (tmp + 1)) / 2 > n + 1) --tmp;
  cout << min(n, n - tmp + 1) << endl;
  return 0;
}
