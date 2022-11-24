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
  int a, b;
  cin >> a >> b;
  int max = -10000;

  rrep(i, 2, 0) {
    int tar = (a / pow(10, i));
    tar %= 10;
    int tmp = (9 - tar) * pow(10, i) + a;
    chmax(max, tmp - b);
  }
  rrep(i, 2, 0) {
    int num = 0;
    if (i == 2) {
      num = 1;
    }
    int tar = (b / pow(10, i));
    tar %= 10;
    int tmp = (num - tar) * pow(10, i) + b;
    chmax(max, a - tmp);
  }

  cout << max << endl;
  return 0;
}
