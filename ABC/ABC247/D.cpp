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
  int Q;
  cin >> Q;

  vector<ll> vx, vc;
  int i = 0;

  while (Q--) {
    // cout << Q << endl;
    ll q;
    cin >> q;
    if (q == 1) {
      ll x, c;
      cin >> x >> c;
      vx.push_back(x);
      vc.push_back(c);
    } else {
      ll c;
      cin >> c;
      ll cnt = 0;
      ll res = 0;
      while (cnt < c) {
        if (vc[i] <= c - cnt) {
          res += vx[i] * vc[i];
          cnt += vc[i];
          ++i;
        } else {
          res += vx[i] * (c - cnt);
          vc[i] -= (c - cnt);
          cnt = c;
        }
      }
      cout << res << endl;
    }
  }
  return 0;
}
