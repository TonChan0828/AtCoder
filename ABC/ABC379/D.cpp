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
  int Q;
  cin >> Q;

  ll d = 0;
  multiset<ll> s;
  rep(i, 0, Q) {
    int q;
    cin >> q;
    if (q == 1) {
      s.insert(d);
    } else if (q == 2) {
      ll t;
      cin >> t;
      d -= t;
    } else {
      ll h;
      cin >> h;
      auto itr = s.lower_bound(d + h);
      ll res = distance(itr, end(s));
      cout << res << "\n";
      vector<ll> tmp;
      while (itr != end(s)) {
        tmp.push_back(*itr);
        ++itr;
      }
      for (ll x : tmp) s.erase(x);
    }
  }
  return 0;
}
