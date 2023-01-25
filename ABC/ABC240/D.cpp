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

  vector<int> a(n + 1);
  int cnt = 0;
  int tar = 1, same = 0;

  rep(i, 0, n) {
    cin >> a[cnt];
    if (tar == a[cnt]) {
      ++same;
      if (tar == same) {
        cnt -= tar;
        tar = a[cnt];
        same = 0;
        while (tar == a[cnt - same]) ++same;
      }
    } else {
      tar = a[cnt], same = 1;
      if (tar == same) {
        cnt -= tar;
        tar = a[cnt];
        same = 0;
        while (tar == a[cnt - same]) ++same;
      }
    }
    ++cnt;
    // cout << a[cnt - 1] << tar << " " << same << " " << cnt << endl;
    cout << cnt << endl;
  }

  return 0;
}
