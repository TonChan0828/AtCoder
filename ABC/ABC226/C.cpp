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
  vector<ll> t(n + 1);
  vector<vector<ll>> a(n + 1);
  rep(i, 1, n + 1) {
    cin >> t[i];
    int k;
    cin >> k;
    rep(j, 0, k) {
      ll tmp;
      cin >> tmp;
      a[i].push_back(tmp);
    }
  }
  vector<bool> checked(n + 1, false);
  auto f = [&](auto f, int tar) -> ll {
    ll sum = 0;
    for (ll x : a[tar]) {
      if (checked[x]) continue;
      checked[x] = true;
      sum += f(f, x);
    }
    // cout << sum << endl;
    return t[tar] + sum;
  };
  cout << f(f, n) << endl;

  return 0;
}
