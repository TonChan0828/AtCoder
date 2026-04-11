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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i], b[i]--;
  int m;
  cin >> m;
  vector<string> s(m);
  rep(i, 0, m) cin >> s[i];

  map<pair<int, int>, set<char>> mp;
  rep(i, 0, m) {
    int sz = s[i].size();
    rep(j, 0, sz) { mp[{sz, j}].insert(s[i][j]); }
  }

  rep(i, 0, m) {
    if ((int)s[i].size() != n) {
      cout << "No\n";
      continue;
    }

    bool ok = true;
    rep(j, 0, n) {
      bool hit = false;
      for (char c : mp[{a[j], b[j]}]) {
        if (c == s[i][j]) {
          hit = true;
          break;
        }
      }
      if (!hit) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
