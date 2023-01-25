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

  vector<pair<int, int>> d;
  d.emplace_back(-1, 0);
  int ans = 0;
  rep(i, 0, n) {
    int a;
    cin >> a;
    ++ans;
    if (d.back().first == a) {
      d.back().second++;
    } else {
      d.emplace_back(a, 1);
    }
    if (d.back().first == d.back().second) {
      ans -= d.back().second;
      d.pop_back();
    }
    cout << ans << endl;
  }

  return 0;
}
