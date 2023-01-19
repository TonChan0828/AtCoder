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
  vector<int> p(n);

  rep(i, 0, n) cin >> p[i];
  priority_queue<int, vector<int>, greater<int>> pq;
  rep(i, 0, k) pq.push(p[i]);
  cout << pq.top() << endl;

  rep(i, k, n) {
    if (pq.top() < p[i]) {
      pq.pop();
      pq.push(p[i]);
    }
    cout << pq.top() << endl;
  }
  return 0;
}
