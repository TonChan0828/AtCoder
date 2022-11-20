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
  int h, m;
  cin >> h >> m;
  while (1) {
    int hd = h - h % 10 + (m - m % 10) / 10;
    int md = (h % 10) * 10 + m % 10;
    if (hd < 24 && md < 60) {
      cout << h << " " << m << endl;
      return 0;
    }
    if (m == 59) ++h;
    ++m;
    h %= 24;
    m %= 60;
  }
  return 0;
}
