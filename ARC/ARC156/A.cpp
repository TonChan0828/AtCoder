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
  int t;
  cin >> t;
  rep(test, 0, t) {
    int n;
    string s;
    cin >> n >> s;
    int f = 0;
    vector<int> tmp;
    rep(i, 0, n) {
      if (s[i] == '1') {
        ++f;
        tmp.push_back(i);
      }
    }
    if (f % 2 == 1)
      cout << -1 << endl;
    else if (f == 2) {
      if (abs(tmp[0] - tmp[1]) < 2) {
        if (n == 3) {
          cout << -1 << endl;
        } else if (n == 4 && (tmp[0] == 1 && tmp[1] == 2)) {
          cout << 3 << endl;
        } else {
          cout << 2 << endl;
        }
      } else {
        cout << f / 2 << endl;
      }
    } else
      cout << f / 2 << endl;
  }
  return 0;
}
