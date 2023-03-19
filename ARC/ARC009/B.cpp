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
  map<char, int> mp;
  rep(i, 0, 10) {
    char x;
    cin >> x;
    mp[x] = i;
  }

  int n;
  cin >> n;
  vector<string> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<pair<int, string>> ans;
  rep(i, 0, n) {
    int tmp = 0;
    rep(j, 0, a[i].size()) {
      tmp *= 10;
      tmp += mp[a[i][j]];
    }
    ans.push_back({tmp, a[i]});
  }
  sort(ans.begin(), ans.end());
  for (auto x : ans) {
    cout << x.second << endl;
  }
  return 0;
}
