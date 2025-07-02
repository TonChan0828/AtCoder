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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> s(n);
    rep(i, 0, n) cin >> s[i];
    if (n == 2) {
      if (s[0] * 2 >= s[1]) {
        cout << "2\n";
      } else {
        cout << "-1\n";
      }
      continue;
    }
    vector<ll> t;
    rep(i, 0, n - 1) t.push_back(s[i]);
    sort(begin(t), end(t));
    int now = s[0], cnt = 2;
    while (1) {
      if (now * 2 >= s[n - 1]) {
        cout << cnt << "\n";
        break;
      }
      auto itr = upper_bound(begin(t), end(t), now * 2);
      itr--;
      if (now == *itr) {
        cout << "-1\n";
        break;
      }
      now = *itr;
      ++cnt;
    }
  }
  return 0;
}
