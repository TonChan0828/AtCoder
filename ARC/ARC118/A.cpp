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
  int t, n;
  cin >> t >> n;
  t += 100;
  vector<ll> num;

  ll tar = 0;
  set<int> s;
  while (tar / 100 < t) {
    ll tmp = tar + t;
    if ((tmp / 100 - tar / 100) > 1) num.push_back(tmp / 100 - 1);
    tar = tmp;
    // cout << tar << endl;
  }
  // cout << num.size() << endl;
  // for (int x : num) cout << x << " ";
  // cout << endl;

  ll sz = num.size();

  ll ans = 0;
  n--;
  ans += t * (n / sz);
  ans += num[(n % sz)];

  cout << ans << endl;
  return 0;
}
