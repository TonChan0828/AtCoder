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
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> odd, even;
  rep(i, 0, n) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      even.push_back(a[i]);
    } else {
      odd.push_back(a[i]);
    }
  }

  ll ans = -1;
  sort(odd.begin(), odd.end(), greater());
  sort(even.begin(), even.end(), greater());
  if (odd.size() > 1) {
    ll tmp = odd[0] + odd[1];
    chmax(ans, tmp);
  }
  if (even.size() > 1) {
    ll tmp = even[0] + even[1];
    chmax(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
