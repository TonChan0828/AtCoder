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
  getline(cin, s);
  int n;
  cin >> n;
  vector<string> t(n);
  rep(i, 0, n) cin >> t[i];
  int sz = s.size();
  int pos = 0;
  vector<string> w;
  rep(i, 0, sz) {
    if (s[i] == ' ') {
      w.push_back(s.substr(pos, i - pos));
      pos = i + 1;
    }
  }
  w.push_back(s.substr(pos, sz - pos));

  int wz = w.size();

  // rep(i, 0, wz) {
  //   if (i) cout << " ";
  //   cout << w[i];
  // }
  // cout << endl;

  rep(i, 0, wz) {
    rep(j, 0, n) {
      if (w[i].size() != t[j].size()) continue;
      int tz = t[j].size();
      bool ok = true;
      rep(k, 0, tz) {
        if (t[j][k] == '*') continue;
        if (t[j][k] != w[i][k]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        rep(k, 0, tz) w[i][k] = '*';
      }
    }
  }

  rep(i, 0, wz) {
    if (i) cout << " ";
    cout << w[i];
  }
  cout << endl;
  return 0;
}
