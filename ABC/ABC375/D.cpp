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
  string s;
  cin >> s;

  int n = s.size();
  vector<vector<int>> mp(26);
  rep(i, 0, n) mp[s[i] - 'A'].push_back(i);

  ll ans = 0;
  for (auto v : mp) {
    if (v.size() < 2) continue;
    rep(i, 0, v.size() - 1) {
      ll l = i + 1;
      ll r = v.size() - i - 1;
      ll d = v[i + 1] - v[i] - 1;
      // printf("l:%d r:%d d:%d\n", l, r, d);
      ans += d * l * r;

      ans += l * (r - 1LL);
    }
  }

  cout << ans << endl;
  return 0;
}
