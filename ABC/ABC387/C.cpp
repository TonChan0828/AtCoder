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

ll int_pow(ll a, ll t) {
  ll res = 1;
  rep(i, 0, t) res *= a;
  return res;
}

ll count(ll r) {
  vector<int> digit;
  while (r) {
    digit.push_back(r % 10);
    r /= 10;
  }
  reverse(begin(digit), end(digit));
  int n = digit.size();
  ll res = 0;
  rep(i, 1, n + 1) {
    if (i == n) {
      res++;
      break;
    }

    res += int_pow(digit[0], n - 1 - i) * min(digit[0], digit[i]);
    if (digit[i] >= digit[0]) break;
  }

  rep(i, 0, n) {
    int mx = (i ? 9 : digit[0] - 1);
    rep(j, 1, mx + 1) res += int_pow(j, n - 1 - i);
  }
  return res;
}

int main() {
  ll l, r;
  cin >> l >> r;

  cout << count(r) - count(l - 1) << endl;
  return 0;
}
