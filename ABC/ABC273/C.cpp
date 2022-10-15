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
  vector<int> a(n), b;
  set<int> s;
  vector<int> cnt(n, 0);
  rep(i, 0, n) {
    cin >> a[i];
    s.insert(a[i]);
  }
  for (auto itr = s.begin(); itr != s.end(); ++itr) {
    b.push_back(*itr);
  }
  sort(b.begin(), b.end());
  rep(i, 0, n) {
    auto itr = upper_bound(b.begin(), b.end(), a[i]);
    int c = b.end() - itr;
    // cout << *itr << endl;
    cnt[c]++;
  }
  rep(i, 0, n) { cout << cnt[i] << endl; }
  return 0;
}
