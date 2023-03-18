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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  string s;
  cin >> s;
  int sz = s.size();

  ll ans = 0;
  map<char, int> mp;
  mp[s[sz - 1]]++;
  mp[s[sz - 2]]++;

  rrep(i, sz - 3, 0) {
    if (s[i] != s[i + 1]) {
      mp[s[i]]++;
      continue;
    }
    int diff = sz - (i + 2) - (mp[s[i]] - 1);
    ans += diff;
    mp.clear();
    mp[s[i]] = sz - i;
    // cout << ans << endl;
  }

  cout << ans << endl;
  return 0;
}
