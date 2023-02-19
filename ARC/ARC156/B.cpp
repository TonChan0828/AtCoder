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
const ll mod = 998244353;
ll Lmax = 400000;  // Lの最大値
vector<ll> kaijo(Lmax + 1), kaijorev(Lmax + 1);

ll ruijo(ll a, ll b) {
  ll res = 1;
  for (a %= mod; b; a = a * a % mod, b >>= 1)
    if (b & 1) res = res * a % mod;
  return res;
}

void Cnum_init() {
  kaijo[0] = 1;
  kaijo[1] = 1;
  for (ll i = 2; i <= Lmax; i++) {
    kaijo[i] = (kaijo[i - 1] * i) % mod;
  }

  kaijorev[Lmax] = ruijo(kaijo[Lmax], mod - 2);
  for (ll i = Lmax - 1; i >= 0; i--) {
    kaijorev[i] = (kaijorev[i + 1] * (i + 1)) % mod;
  }
}
ll Cnum(ll L, ll R) {
  ll ret = (kaijo[L] * kaijorev[R]) % mod;
  ret *= kaijorev[L - R];
  ret %= mod;

  return ret;
}

int main() {
  ll N, K;
  cin >> N >> K;

  vector<bool> num(400001, false);
  for (ll i = 0; i < N; i++) {
    ll a;
    cin >> a;
    num[a] = true;
  }

  Cnum_init();

  ll ans = 0, rem = K;
  for (ll i = 0; i <= 400000; i++) {
    if (num[i]) {
      ans += Cnum(rem - 1 + i, i);
    } else {
      rem--;
      ans += Cnum(rem + i, i);
    }
    ans %= mod;

    if (rem == 0) break;
  }

  cout << ans << endl;
}