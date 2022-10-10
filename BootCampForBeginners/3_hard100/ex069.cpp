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

ll get(vector<ll> b) {
  ll sm = 0;
  rep(i, 0, b.size() - 1) { sm += llabs(b[i + 1] - b[i]); }
  return sm;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<ll> b(n);
  ll ans = -1;
  if (n % 2 == 0) {
    rep(i, 0, n / 2) b[i * 2 + 1] = a[i];
    rep(i, 0, n / 2) b[i * 2] = a[i + n / 2];
    ans = get(b);
  } else {
    rep(i, 0, n / 2) b[i * 2 + 1] = a[i];
    b[n - 1] = a[n / 2];
    rep(i, 0, n / 2) b[i * 2] = a[i + n / 2 + 1];
    chmax(ans, get(b));

    b[0] = a[n / 2];
    rep(i, 0, n / 2) b[i * 2 + 2] = a[i];
    rep(i, 0, n / 2) b[i * 2 + 1] = a[i + n / 2 + 1];
    chmax(ans, get(b));
  }
  cout << ans << endl;
  return 0;
}
