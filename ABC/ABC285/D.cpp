#include <bits/stdc++.h>
using namespace std;
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
  int n;
  cin >> n;
  map<string, string> mp;
  map<string, string> rmp;
  rep(i, 0, n) {
    string s, t;
    cin >> s >> t;
    mp[s] = t;
    rmp[t] = s;
  }
  map<string, int> chk;
  map<string, int> rchk;

  auto f = [&](auto f, string tmp) -> bool {
    // cout << 2 << tmp << endl;
    if (chk[tmp]) return false;
    ++chk[tmp];
    if (mp[tmp].empty()) return true;
    return f(f, mp[tmp]);
  };
  auto rf = [&](auto rf, string tmp) -> bool {
    // cout << 1 << tmp << endl;
    if (chk[rmp[tmp]] && rchk[rmp[tmp]]) return false;
    ++rchk[rmp[tmp]];
    if (rmp[tmp].empty()) return true;
    return rf(rf, rmp[tmp]);
  };

  for (auto x : mp) {
    if (chk[x.first] || rchk[x.first]) continue;
    if (!f(f, x.first) || !rf(rf, x.second)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
