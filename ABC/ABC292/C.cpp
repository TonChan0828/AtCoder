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
  ll ans = 0;
  vector<int> table(n, 0);
  rep(i, 1, n) {
    for (int j = 1; j * j <= i; ++j) {
      if (i % j == 0) {
        int k = i / j;
        if (j == k) {
          ++table[i];
        } else {
          table[i] += 2;
        }
      }
    }
    // cout << table[i] << endl;
  }

  rep(i, 1, n / 2 + 1) {
    if (i == n - i) {
      ans += table[i] * table[i];
    } else {
      ans += table[i] * table[n - i] * 2;
    }
    // cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
