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

bool f(int x, vector<int> a) {
  unordered_set<int> s;
  s.insert(0);
  for (int na : a) {
    unordered_set<int> p;
    swap(p, s);
    for (int nx : p) {
      s.insert(nx - na);
      s.insert(nx + na);
    }
  }
  return s.count(x);
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n), xa(n), ya(n);
  rep(i, 0, n) cin >> a[i];
  x -= a[0];
  rep(i, 1, n) {
    if (i % 2) {
      ya.push_back(a[i]);
    } else {
      xa.push_back(a[i]);
    }
  }

  if (f(x, xa) && f(y, ya))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
