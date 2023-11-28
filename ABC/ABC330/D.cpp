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
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<ll> row(n, 0), column(n, 0);
  rep(i, 0, n) {
    rep(j, 0, n) {
      if (s[i][j] == 'o') ++row[i];
    }
  }

  rep(j, 0, n) {
    rep(i, 0, n) {
      if (s[i][j] == 'o') ++column[j];
    }
  }

  ll ans = 0;
  rep(i, 0, n) {
    rep(j, 0, n) {
      if (s[i][j] == 'x') continue;
      ll r = row[i] - 1;
      ll c = column[j] - 1;
      ans += r * c;
    }
  }
  cout << ans << endl;
  return 0;
}
