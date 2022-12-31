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
  double a, b;
  double sum;
  cin >> n >> a >> b;
  vector<double> s(n);
  rep(i, 0, n) {
    cin >> s[i];
    sum += s[i];
  }
  sort(s.begin(), s.end());

  double diff = s[n - 1] - s[0];
  if (diff == 0) {
    cout << -1 << endl;
    return 0;
  }
  double p = b / diff;
  double ave = sum / (double)n;
  double avep = ave * p;
  double q = a - avep;
  cout << setprecision(12);
  cout << p << " " << q << endl;

  return 0;
}
