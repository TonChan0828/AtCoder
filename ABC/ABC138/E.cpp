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
  string s, t;
  cin >> s >> t;
  ll sz = s.size();
  ll tz = t.size();

  map<char, vector<int>> mp;
  rep(i, 0, sz) mp[s[i]].push_back(i);

  ll ans = 0;
  ll pos = -1;
  rep(i, 0, tz) {
    if (mp[t[i]].empty()) {
      cout << -1 << endl;
      return 0;
    }
    auto itr = upper_bound(begin(mp[t[i]]), end(mp[t[i]]), pos);
    if (itr == mp[t[i]].end()) {
      ans += sz + mp[t[i]][0] - pos;
      pos = mp[t[i]][0];
    } else {
      ans += *itr - pos;
      pos = *itr;
    }
  }
  cout << ans << endl;
  return 0;
}