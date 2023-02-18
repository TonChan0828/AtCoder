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

bool check(vector<ll> sc, vector<ll> tc) {
  ll tmps = 0, tmpt = 0;
  rep(i, 1, 10) {
    ll tmp = 1;
    rep(j, 0, sc[i]) { tmp *= 10; }
    tmps += i * tmp;
  }
  rep(i, 1, 10) {
    ll tmp = 1;
    rep(j, 0, tc[i]) { tmp *= 10; }
    tmpt += i * tmp;
  }
  if (tmps > tmpt) {
    return true;
  } else {
    return false;
  }
}

int main() {
  ll k;
  string s, t;
  cin >> k >> s >> t;
  vector<ll> card(10, k), sc(10, 0), tc(10, 0);
  card[0] = 0;
  rep(i, 0, 4) {
    --card[s[i] - '0'];
    ++sc[s[i] - '0'];
    --card[t[i] - '0'];
    ++tc[t[i] - '0'];
  }

  double r = 0;
  rep(i, 1, 10) r += card[i];
  r *= (r - 1);

  double target = 0;
  rep(i, 1, 10) {
    if (card[i] <= 0) continue;
    ++sc[i];
    rep(j, 1, 10) {
      if (i == j) {
        if (card[j] - 1 <= 0) continue;
      } else {
        if (card[j] <= 0) continue;
      }
      ++tc[j];
      if (check(sc, tc)) {
        if (i == j) {
          target += card[i] * (card[j] - 1);
        } else {
          target += card[i] * card[j];
        }
      }
      --tc[j];
    }
    --sc[i];
  }
  cout << setprecision(12);
  cout << target / r << endl;
  return 0;
}
