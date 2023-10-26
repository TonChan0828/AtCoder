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
using mint = modint998244353;

struct Binomial {
  vector<mint> fac, invfac, inv;
  Binomial(int n) : fac(n + 1), invfac(n + 1), inv(n + 1) {
    fac[0] = invfac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
    invfac[n] = fac[n].inv();
    for (int i = n - 1; i >= 0; i--) {
      invfac[i] = invfac[i + 1] * (i + 1);
      inv[i + 1] = invfac[i + 1] * fac[i];
    }
  }
} C{303030};
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (auto &x : A) cin >> x;
  mint ans = 1;
  for (int i = 0; i < N; i++) {
    if (i == K) break;
    map<int, int> mp;
    int all = 0;
    for (int j = i; j < N; j += K) {
      mp[A[j]]++, all++;
    }
    ans *= C.fac[all];
    for (auto &[_, val] : mp) ans *= C.invfac[val];
  }
  cout << ans.val() << "\n";
}
