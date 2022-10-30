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
map<ll, ll> memo;
ll f(ll n) {
  // cout << n;
  if (n == 0) return memo[0] = 1;
  ll sum = 0;
  if (memo[n / 2] != 0) {
    sum += memo[n / 2];
  } else {
    sum += f(n / 2);
  }
  if (memo[n / 3] != 0) {
    sum += memo[n / 3];
  } else {
    sum += f(n / 3);
  }
  // cout << sum << endl;
  return memo[n] = sum;
}

int main() {
  ll n;
  cin >> n;

  cout << f(n) << endl;
  return 0;
}
