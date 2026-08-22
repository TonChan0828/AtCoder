#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int Q, v;
  cin >> Q >> v;

  priority_queue<int> pq;
  rep(qi, 0, Q) {
    int q;
    cin >> q;

    if (q == 1) {
      int t, w;
      cin >> t >> w;
      pq.push(w - t);
    } else {
      int t;
      cin >> t;
      if (pq.empty()) {
        cout << "-1\n";
        continue;
      }
      int tmp = pq.top();
      pq.pop();
      cout << min(v, tmp + t) << "\n";
    }
  }
  return 0;
}
