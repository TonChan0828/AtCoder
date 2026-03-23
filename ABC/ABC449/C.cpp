#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, l, r;
  string s;
  cin >> n >> l >> r >> s;
  map<char, vector<int>> mp;
  rep(i, 0, n) { mp[s[i]].push_back(i); }
  int diff = r - l;
  ll ans = 0;
  for (auto [_, v] : mp) {
    auto it = begin(v);
    while (it != end(v)) {
      auto itl = lower_bound(begin(v), end(v), *it + l);
      auto itr = upper_bound(begin(v), end(v), *it + r);
      ans += (ll)(itr - itl);
      ++it;
    }
  }
  cout << ans << endl;
  return 0;
}
