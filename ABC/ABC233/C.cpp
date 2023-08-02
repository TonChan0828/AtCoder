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
  ll x;
  cin >> n >> x;
  vector<vector<ll>> la(n);
  rep(i, 0, n) {
    int l;
    cin >> l;
    rep(j, 0, l) {
      int a;
      cin >> a;
      la[i].push_back(a);
    }
  }

  auto dfs = [&](auto dfs, int pos, ll prod) -> ll {
    if (pos == n) return prod == 1;
    ll ans = 0;
    for (ll a : la[pos]) {
      if (prod % a == 0) {
        ans += dfs(dfs, pos + 1, prod / a);
      }
    }
    return ans;
  };
  cout << dfs(dfs, 0, x) << endl;
  return 0;
}
