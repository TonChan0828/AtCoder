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
  string s, t;
  cin >> s >> t;
  map<char, int> mp;
  int sa = 0, ta = 0;
  int sz = s.size();
  rep(i, 0, sz) {
    if (s[i] == '@')
      ++sa;
    else
      ++mp[s[i]];
  }
  rep(i, 0, sz) {
    if (t[i] == '@')
      ++ta;
    else
      --mp[t[i]];
  }

  for (auto [key, value] : mp) {
    if (value == 0) continue;

    if (key == 'a' || key == 't' || key == 'c' || key == 'o' || key == 'd' ||
        key == 'e' || key == 'r') {
      if (value < 0) {
        if (sa < 0 - value) {
          cout << "No" << endl;
          return 0;
        } else {
          sa -= 0 - value;
          mp[key] = 0;
        }
      } else {
        if (ta < value) {
          cout << "No" << endl;
          return 0;
        } else {
          ta -= value;
          mp[key] = 0;
        }
      }
    } else {
      cout << "No" << endl;
      return 0;
    }
  }

  if (sa == ta) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
