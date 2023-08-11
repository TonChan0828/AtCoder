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
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> table;
  map<ll, ll> mp;
  ll a = x;
  int pos = 0;
  rep(i, 0, 100001) {
    if (mp[a] != 0 || (a == x && i != 0)) {
      pos = mp[a];
      break;
    }
    table.push_back(a);
    mp[a] = i;
    a = (a * a) % m;
  }

  unsigned long long ans = 0;
  int sz = table.size();

  if (n <= sz) {
    rep(i, 0, n) { ans += table[i]; }
    cout << ans << endl;
    return 0;
  }

  if (n > sz) {
    rep(i, 0, pos) ans += table[i];
    ll sum = 0;
    rep(i, pos, sz) sum += table[i];
    n -= pos;
    ans += sum * (n / (sz - pos));

    rep(i, pos, pos + (n % (sz - pos))) ans += table[i];
    cout << ans << endl;
  }

  return 0;
}
