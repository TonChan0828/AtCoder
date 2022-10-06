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
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); i--)
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

vector<ll> patty(51), tot(51);
ll f(ll level, ll x) {
  if (level == 0) {
    return 1;
  }
  if (x < 1) {
    return 0;
  }
  x--;
  if (x < tot[level - 1]) return f(level - 1, x);
  x -= tot[level - 1];
  if (x < 1) return patty[level - 1] + 1;
  x--;
  if (x < tot[level - 1]) return patty[level - 1] + 1 + f(level - 1, x);
  x -= tot[level - 1];
  return patty[level - 1] * 2 + 1;
}

int main() {
  ll n, x;
  cin >> n >> x;
  x--;
  tot[0] = 1;
  rep(i, 1, n + 1) { tot[i] = tot[i - 1] * 2 + 3; }
  patty[0] = 1;
  rep(i, 1, n + 1) { patty[i] = patty[i - 1] * 2 + 1; }
  cout << f(n, x) << endl;
  return 0;
}
