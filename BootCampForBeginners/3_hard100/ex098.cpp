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
  int h, w;
  cin >> h >> w;
  map<char, int> map;
  rep(i, 0, h) {
    rep(j, 0, w) {
      char tmp;
      cin >> tmp;
      map[tmp]++;
    }
  }

  vector<int> v(4);
  int cnt = h * w;
  int sz = map.size();
  for (auto x : map) {
    cnt -= x.second - (x.second % 4);
    map[x.first] = x.second % 4;
    v[x.second % 4]++;
  }
  bool f = false;
  if (h % 2 == 0 && w % 2 == 0) {
    if (v[0] == sz) {
      f = true;
    }
  } else {
    f = true;
    int ac = 0;
    if (h % 2) ac += w / 2;
    if (w % 2) ac += h / 2;
    if (v[1] + v[3] != ((h % 2) & (w % 2))) f = false;
    if (ac < v[2] + v[3]) f = false;
  }
  cout << (f ? "Yes" : "No") << endl;

  // int odd = 0;
  // if (h % 2 == 1 && w % 2 == 1) {
  //   odd = h + w - 1;
  // } else if (h % 2 == 1) {
  //   odd = w;
  // } else {
  //   odd = h;
  // }
  // // cout << cnt << endl;
  // // cout << odd << endl;

  // if (cnt > odd) {
  //   cout << "No" << endl;
  //   return 0;
  // }
  // for (auto x : map) {
  //   cnt -= x.second - x.second % 2;
  // }
  // if (odd % 2 == 1) {
  //   if (cnt != 1) {
  //     cout << "No" << endl;
  //     return 0;
  //   }
  // } else {
  //   if (cnt != 0) {
  //     cout << "No" << endl;
  //     return 0;
  //   }
  // }
  // cout << "Yes" << endl;
  return 0;
}
