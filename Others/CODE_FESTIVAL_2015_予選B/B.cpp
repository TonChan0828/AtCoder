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
  map<int, int> score;
  rep(i, 0, n) {
    int a;
    cin >> a;
    score[a]++;
  }
  int ans = -1;
  int cnt = 0;
  for (const auto &[key, value] : score) {
    if (value > n / 2) {
      ans = key;
      ++cnt;
    }
  }
  if (cnt == 1) {
    cout << ans << endl;
  } else {
    cout << '?' << endl;
  }
  return 0;
}
