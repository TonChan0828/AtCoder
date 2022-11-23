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
  cout << 0 << endl;
  string start;
  cin >> start;
  if (start == "Vacant") return 0;
  int l = 0, r = n;
  rep(i, 0, 20 - 1) {
    int m = (l + r) / 2;
    cout << m << endl;
    string tmp;
    cin >> tmp;
    if (tmp == "Vacant") return 0;
    if ((m % 2 == 1 && tmp == start) || (m % 2 == 0 && tmp != start)) {
      r = m;
    } else {
      l = m;
    }
  }
  return 0;
}
