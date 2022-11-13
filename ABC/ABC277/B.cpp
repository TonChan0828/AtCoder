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
  set<string> s;
  vector<string> v(n);
  rep(i, 0, n) {
    string t;
    cin >> t;
    v[i] = t;
    s.insert(t);
  }

  rep(i, 0, n) {
    // cout << v[i][0] << endl;
    if (!(v[i][0] == 'H' || v[i][0] == 'D' || v[i][0] == 'S' ||
          v[i][0] == 'C')) {
      cout << "No" << endl;
      return 0;
    }
    if ((v[i][1] == '2' || v[i][1] == '3' || v[i][1] == '4' || v[i][1] == '5' ||
         v[i][1] == '6' || v[i][1] == '7' || v[i][1] == '8' || v[i][1] == '9' ||
         v[i][1] == 'A' || v[i][1] == 'T' || v[i][1] == 'J' || v[i][1] == 'Q' ||
         v[i][1] == 'K')) {
    } else {
      cout << "No" << endl;
      return 0;
    }
    rep(j, i + 1, n) {
      if (v[i] == v[j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  // if (s.size() != n) {
  //   cout << "No" << endl;
  //   return 0;
  // }
  // for (auto st : s) {
  //   if (!(st[0] == 'H' || st[0] == 'D' || st[0] == 'S' || st[0] == 'S')) {
  //     cout << "No" << endl;
  //     return 0;
  //   }
  //   if (!((st[1] >= '2' && st[1] <= '9') || st[1] == 'A' || st[1] == 'T' ||
  //         st[1] == 'J' || st[1] == 'Q' || st[1] == 'K')) {
  //     cout << "No" << endl;
  //     return 0;
  //   }
  // }
  cout << "Yes" << endl;
  return 0;
}
