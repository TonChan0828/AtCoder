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
  int n;
  cin >> n;
  vector<pair<ll, ll>> sc(n);
  rep(i, 0, n) {
    ll s, c;
    cin >> s >> c;
    sc[i] = {s, c};
  }
  sort(begin(sc), end(sc));
  map<ll, ll> mp;
  rep(i, 0, n) {
    auto [s, c] = sc[i];
    while (c > 0) {
      ll spc = mp[s] + c;
      mp[s] = spc % 2;
      c = spc / 2;
      s *= 2;
    }
  }
  ll ans = 0;
  for (auto [key, value] : mp) {
    // cout << key << " " << value << endl;
    ans += value;
  }
  cout << ans << endl;
  return 0;
}
