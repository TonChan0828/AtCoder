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
  double a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  int cnt = 1;
  vector<int> ans;
  while (w / (double)cnt >= a) {
    if (w / (double)cnt <= b) ans.push_back(cnt);
    ++cnt;
  }
  // cout << ans.size() << endl;
  if (ans.empty()) {
    cout << "UNSATISFIABLE" << endl;
  } else {
    cout << ans.front() << " " << ans.back() << endl;
  }
  return 0;
}
