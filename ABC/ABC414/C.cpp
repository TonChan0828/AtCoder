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
  ll a, n;
  cin >> a >> n;

  set<ll> tar;

  auto f = [&](string s) {
    ll num = stoll(s);
    if (num > n) return;
    if (tar.count(num)) return;

    int nn = s.size();
    rep(i, 0, nn / 2) {
      if (s[i] != s[nn - 1 - i]) return;
    }

    vector<int> v;
    ll res = num;
    // cout << res << endl;
    while (num) {
      v.push_back(num % a);
      num /= a;
    }
    int sz = v.size();
    rep(i, 0, sz / 2) {
      if (v[i] != v[sz - 1 - i]) return;
    }
    // cout << "A  ";
    // rep(i, 0, sz) cout << v[i];
    // cout << endl;
    tar.insert(res);
    return;
  };

  rep(i, 1, 1e6) {
    string s = to_string(i);
    string t = s;
    reverse(begin(t), end(t));
    f(s);
    f(s + t);
    rep(j, 0, 10) { f(s + to_string(j) + t); }
  }

  ll ans = 0;
  for (ll t : tar) ans += t;

  cout << ans << endl;
  return 0;
}
