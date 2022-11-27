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
  const int M = 1e6;
  vector<bool> isP(M + 1, true);
  vector<int> primes;
  isP[0] = isP[1] = false;
  rep(i, 2, M + 1) {
    if (!isP[i]) continue;
    primes.push_back(i);
    for (ll j = (ll)i * i; j <= M; j += i) {
      isP[j] = false;
    }
  }

  vector<int> s(M + 1);
  for (int p : primes) s[p] = 1;
  rep(i, 0, M) s[i + 1] += s[i];

  ll n;
  cin >> n;
  ll ans = 0;
  for (int q : primes) {
    int r = min<ll>(n / q / q / q, q - 1);
    ans += s[r];
  }
  cout << ans << endl;
  return 0;
}
