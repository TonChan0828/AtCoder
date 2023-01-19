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
  int n, k;
  cin >> n >> k;
  vector<int> p(n), q(n);

  rep(i, 0, n) cin >> p[i];
  q = p;
  sort(q.begin(), q.end());
  set<int> s;
  rep(i, 0, k) s.insert(p[i]);
  int tar = *s.begin();
  int pos = 0;
  rep(i, 0, n) {
    if (tar == q[i]) {
      pos = i;
      break;
    }
  }
  cout << tar << endl;
  // cout << pos << endl;
  rep(i, k, n) {
    s.insert(p[i]);
    if (q[pos] < p[i]) {
      do {
        ++pos;
      } while (!s.count(q[pos]));
    }

    cout << q[pos] << endl;
  }
  return 0;
}
