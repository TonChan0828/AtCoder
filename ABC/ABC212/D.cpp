#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
// first昇順 firstが同値の場合second降順
template <typename T, typename U>
bool asc_desc(pair<T, U> &left, pair<T, U> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T, typename U>
bool desc_asc(pair<T, U> &left, pair<T, U> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int Q;
  cin >> Q;

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll cnt = 0;

  while (Q--) {
    int q;
    cin >> q;

    if (q == 1) {
      ll x;
      cin >> x;
      x -= cnt;
      pq.push(x);
    } else if (q == 2) {
      ll x;
      cin >> x;
      cnt += x;
    } else {
      ll res = pq.top();
      pq.pop();
      cout << res + cnt << "\n";
    }
  }

  return 0;
}
