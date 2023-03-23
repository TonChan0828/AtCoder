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
  ll b, c;
  cin >> b >> c;
  ll ans = 0;
  bool flag = false;
  bool odd = false;
  ll ch = c / 2;
  if (c % 2 == 1) odd = true;

  if (b > 0) {
    if (b - c / 2 <= 0) {
      flag = true;
      ans += b + 1;
    } else {
      ans += ch + 1;
    }

    if (flag) {
      ans += b;
    } else {
      if (odd) {
        ans += ch + 1;
      } else {
        ans += ch;
      }
    }

    ans += ((c - 1) / 2);
    if (odd && c > 1) {
      ans += ((c - 1) / 2) - 1;
    } else {
      ans += ((c - 1) / 2);
    }
  } else if (b == 0) {
    ans += 1;
    ans += ch;
    if (odd) {
      ans += ch;
    } else {
      ans += ch - 1;
    }
  } else {
    ans += ch + 1;
    if (odd) {
      ans += ch + 1;
    } else {
      ans += ch;
    }
    // cout << ans << endl;

    if ((c - 1) / 2 + b >= 0) {
      ans += 2 * llabs(b) - 1;
    } else {
      if (odd) {
        ans += ((c - 1) / 2) * 2 - 1;
      } else {
        ans += ((c - 1) / 2) * 2;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
