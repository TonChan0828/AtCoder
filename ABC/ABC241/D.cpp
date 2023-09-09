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

int main() {
  int Q;
  cin >> Q;
  multiset<ll> ms;
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      ll x;
      cin >> x;
      ms.insert(x);
    } else if (q == 2) {
      ll x;
      int k;
      cin >> x >> k;
      auto itr = ms.upper_bound(x);
      bool ok = true;
      rep(i, 0, k) {
        if (itr == ms.begin()) {
          ok = false;
          break;
        }
        itr--;
      }
      if (ok) {
        printf("%lld\n", *itr);
      } else {
        cout << "-1\n";
      }
    } else {
      ll x;
      int k;
      cin >> x >> k;
      auto itr = ms.lower_bound(x);
      bool ok = true;
      rep(i, 0, k - 1) {
        if (itr == ms.end()) {
          ok = false;
          break;
        }
        itr++;
      }
      if (itr == ms.end()) {
        ok = false;
      }
      if (ok) {
        printf("%lld\n", *itr);
      } else {
        cout << "-1\n";
      }
    }
  }
  return 0;
}
