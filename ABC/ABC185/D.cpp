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
  vector<int> a(m);
  rep(i, 0, m) {
    cin >> a[i];
    --a[i];
  }
  sort(a.begin(), a.end());
  vector<int> table;
  int pos = 0;
  int mini = pow(10, 9) + 10;
  rep(i, 0, m) {
    int length = a[i] - pos;
    if (length != 0) {
      table.push_back(length);
      mini = min(mini, length);
    }
    pos = a[i] + 1;
  }
  if (n - pos != 0) {
    table.push_back(n - pos);
    mini = min(mini, n - pos);
  }

  int cnt = 0;
  rep(i, 0, table.size()) {
    cnt += table[i] / mini;
    if (table[i] % mini != 0) ++cnt;
  }

  cout << cnt << endl;
  return 0;
}
