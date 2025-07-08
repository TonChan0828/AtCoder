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
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

using P = pair<ll, ll>;
int main() {
  int Q;
  cin >> Q;
  vector<P> num;
  int now = 0;
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      ll c, x;
      cin >> c >> x;
      num.push_back({c, x});
    } else {
      ll k;
      cin >> k;
      ll sum = 0;
      while (k > 0) {
        auto [a, b] = num[now];
        sum += b * min(k, a);
        if (k <= a) {
          num[now].first = a - k;
          k -= a;
        } else {
          now++;
          k -= a;
        }
      }
      cout << sum << "\n";
    }
  }
  return 0;
}
