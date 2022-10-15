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
  ll x, k;
  cin >> x >> k;
  ll ans = x;
  rep(i, 1, k + 1) {
    ll tmp1 = ans;
    ll tmp2 = ans;
    tmp1 /= pow(10, i);
    tmp2 /= pow(10, i);
    tmp1 += 1;
    tmp1 *= pow(10, i);
    tmp2 *= pow(10, i);
    if (llabs(ans - tmp1) <= llabs(ans - tmp2)) {
      ans = tmp1;
    } else {
      ans = tmp2;
    }
  }
  cout << ans << endl;
  return 0;
}
