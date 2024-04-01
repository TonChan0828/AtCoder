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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

struct Data {
  ll x, y;
  int a, b;
};

int main() {
  int n = 60;
  int a, b;
  ll C;
  cin >> a >> b >> C;
  bitset<60> bs(C);
  int ab = bs.count();
  // cout << ab << endl;
  if (ab > a + b) {
    cout << -1 << endl;
    return 0;
  }
  ab = (a + b - ab) / 2;
  a -= ab, b -= ab;
  ll x = 0, y = 0;
  rep(i, 0, n) {
    if (bs[i]) {
      if (a) {
        x += 1LL << i;
        --a;
      } else if (b) {
        y += 1LL << i;
        --b;
      }
    } else {
      if (ab) {
        x += 1LL << i;
        y += 1LL << i;
        --ab;
      }
      // printf("%lld %lld\n", x, y);
    }
  }
  if (a || b || ab) {
    // printf("%d %d %d\n", a, b, ab);
    cout << -1 << endl;
    return 0;
  }

  printf("%lld %lld\n", x, y);
  return 0;
}
