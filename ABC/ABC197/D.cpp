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
  double x0, y0, xn2, yn2;
  cin >> x0 >> y0 >> xn2 >> yn2;
  double r = 2 * M_PI / n;
  double xm = (x0 + xn2) / 2, ym = (y0 + yn2) / 2;
  double ansX = (x0 - xm) * cos(r) - (y0 - ym) * sin(r) + xm;
  double ansY = (x0 - xm) * sin(r) + (y0 - ym) * cos(r) + ym;
  cout << setprecision(12);
  cout << ansX << " " << ansY << endl;
  return 0;
}
