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

int main() {
  vector<int> prime;
  vector<bool> num(1e6 + 1, true);
  num[0] = num[1] = false;
  rep(i, 0, 1e6 + 1) {
    if (!num[i]) continue;
    for (int j = i + i; j < 1e6 + 1; j += i) num[j] = false;
  }
  rep(i, 0, 1e6 + 1) if (num[i]) prime.push_back(i);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    set<int> s;
    for (int p : prime) {
      if (n % p == 0) {
        s.insert(p);
        while (n % p == 0) n /= p;
      }
      if (n < 2) break;
    }
    if (n > 2) s.insert(n);
    printf("%s\n", ((s.size() > 1) ? "Yes" : "No"));
  }
  return 0;
}
