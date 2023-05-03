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

vector<bool> Eratosthenes(ll n) {
  vector<bool> isprime(n + 1, true);
  isprime[0] = isprime[1] = false;
  rep(i, 2, n + 1) {
    if (!isprime[i]) continue;
    for (int j = i * 2; j < n + 1; j += i) isprime[j] = false;
  }
  return isprime;
}

int main() {
  ll n;
  cin >> n;
  vector<bool> isprime = Eratosthenes(1e6);
  vector<ll> prime;
  rep(i, 0, isprime.size()) {
    if (isprime[i]) prime.push_back(i);
    // if (isprime[i]) cout << i << endl;
  }
  // cout << prime.size() << endl;
  int sz = prime.size() + 1;
  ll ans = 0;
  rep(i, 0, sz - 2) {
    ll tmpi = prime[i] * prime[i];
    if (tmpi > n) break;
    rep(j, i + 1, sz - 1) {
      ll tmpj = tmpi * prime[j];
      if (tmpj > n) break;
      rep(k, j + 1, sz) {
        ll ch = tmpj * prime[k] * prime[k];
        if (ch > n || ch <= 0) break;
        // printf("%d %d %d %lld\n", prime[i], prime[j], prime[k], ch);
        ++ans;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
