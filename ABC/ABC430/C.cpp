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
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  vector<ll> sumA(n), sumB(n);
  rep(i, 0, n) {
    if (i) {
      sumA[i] = sumA[i - 1];
      sumB[i] = sumB[i - 1];
    }
    if (s[i] == 'a') {
      sumA[i]++;
    } else {
      sumB[i]++;
    }
  }

  ll ans = 0;
  rep(i, 0, n) {
    int tarA = a;
    if (i == 0) {
      tarA += 0;
    } else {
      tarA += sumA[i - 1];
    }
    auto itA = lower_bound(begin(sumA), end(sumA), tarA);
    ll distA = itA - begin(sumA);
    int tarB = b;
    if (i == 0) {
      tarB += 0;
    } else {
      tarB += sumB[i - 1];
    }
    auto itB = lower_bound(begin(sumB), end(sumB), tarB);
    ll distB = itB - begin(sumB);
    // cout << i + 1 << " distA:" << distA << " distB:" << distB << endl;
    ans += max(0LL, distB - distA);
  }
  cout << ans << endl;
  return 0;
}
