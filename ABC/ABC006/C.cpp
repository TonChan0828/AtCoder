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
  int n, m;
  cin >> n >> m;

  int on = 0;
  if (m % 2 == 1) on = 1;
  int b = 0;
  m -= on * 3;
  while (b <= m) {
    int tmp = (b / 4) + ((m - b) / 2);
    if (tmp + on == n) {
      printf("%d %d %d\n", (m - b) / 2, on, b / 4);
      return 0;
    }
    b += 4;
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}
