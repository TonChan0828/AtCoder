#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
  ll x;
  cin >> x;
  if (x < 100) {
    cout << x << endl;
    return 0;
  }

  if (x >= 10000000000) {
    ll ans = 1;
    ll tmp = x;
    while (tmp >= 10) {
      ans *= 10LL;
      ++ans;
      tmp /= 10;
    }
    rep(i, 1, 10) {
      if (ans * (ll)i >= x) {
        cout << ans * i << endl;
        return 0;
      }
    }
  }

  ll ans = LONG_LONG_MAX;
  rep(i, 1, 10) {
    rep(j, -9, 10) {
      ll tmp = i;
      ll d = i;
      rep(k, 0, 9) {
        d += j;
        if (d < 0 || d > 9) {
          break;
        }
        tmp *= 10LL;
        tmp += d;
        if (tmp >= x) {
          chmin(ans, tmp);
          break;
        }
      }
      // cout << tmp << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
