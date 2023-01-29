#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

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
  string s, t;
  cin >> s >> t;
  int ssz = s.size(), tsz = t.size();
  vector<int> cnt(tsz + 1, 0);
  rep(i, 0, tsz) {
    bool f = (t[i] == s[i] || s[i] == '?' || t[i] == '?' ? true : false);
    bool e = (t[i] == s[i + ssz - tsz] || s[i + ssz - tsz] == '?' || t[i] == '?'
                  ? true
                  : false);
    if (f && e) {
      ++cnt[0];
    } else if (f && !e) {
      ++cnt[i + 1];
    } else if (!f && e) {
      ++cnt[0];
      --cnt[i + 1];
    }
  }
  vector<int> ans(tsz + 1, 0);
  ans[0] = cnt[0];
  rep(i, 1, tsz + 1) { ans[i] = ans[i - 1] + cnt[i]; }
  rep(i, 0, tsz + 1) {
    if (ans[i] == tsz) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
