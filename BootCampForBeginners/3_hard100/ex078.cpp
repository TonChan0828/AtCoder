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
  string s;
  int k;
  cin >> s >> k;
  map<string, int> m;
  int sz = s.size();

  rep(i, 0, sz) {
    string t;
    rep(j, 0, min(k, sz - i)) {
      t.push_back(s[i + j]);
      m[t]++;
    }
  }

  int cnt = 0;
  for (const auto &[key, value] : m) {
    ++cnt;
    if (cnt == k) {
      cout << key << endl;
      break;
    }
  }
  return 0;
}
