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

bool comp(int i, int j) { return i > j; }

int main() {
  int n;
  cin >> n;
  vector<int> p(n), t(n);
  rep(i, 0, n) {
    cin >> p[i];
    t[i] = i + 1;
  }

  int cnt = 0;
  do {
    if (cnt) {
      rep(i, 0, n) {
        if (i != 0) cout << " ";
        cout << p[i];
      }
      cout << endl;
      return 0;
    }
    ++cnt;
  } while (next_permutation(p.begin(), p.end(), comp));

  return 0;
}
