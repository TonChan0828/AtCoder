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
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  ll n;
  cin >> n;
  ll ma = 0;
  while (ma * ma <= n) ++ma;

  vector<bool> isPrime(ma + 1, true);
  isPrime[0] = false;
  isPrime[1] = false;
  for (ll i = 0; i < ma + 1; ++i) {
    if (isPrime[i]) {
      for (ll j = 2; i * j <= ma; ++j) {
        isPrime[i * j] = false;
      }
    }
  }
  vector<ll> prime, primeD;
  for (ll i = 0; i < ma + 1; ++i) {
    if (isPrime[i]) {
      prime.push_back(i);
      primeD.push_back(i * i);
    }
  }

  ll ans = 0;
  int sz = prime.size();
  rep(i, 0, sz) {
    auto ir = upper_bound(begin(primeD), end(primeD), n / primeD[i]);
    auto il = lower_bound(begin(primeD), end(primeD), primeD[i]);
    int tmp = ir - il - 1;
    // cout << *ir << " " << *il << " " << tmp << endl;
    if (tmp < 1) break;
    ans += tmp;
  }

  int now = 0;
  while (1) {
    ll res = 1;
    rep(i, 0, 8) res *= prime[now];
    if (res <= n) {
      ans++;
      now++;
    } else {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
