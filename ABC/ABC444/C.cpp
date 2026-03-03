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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(begin(a), end(a));

  vector<ll> ans;
  bool ok = true;
  ll tar = 0;
  if (n % 2) {
    ok = false;
  } else {
    tar = a[0] + a[n - 1];
  }
  rep(i, 0, n / 2) {
    if (tar != (a[i] + a[n - i - 1])) {
      ok = false;
      break;
    }
  }
  if (ok) ans.push_back(tar);

  tar = a[n - 1];
  while (a.size() && tar == a.back()) a.pop_back();
  int sz = a.size();
  if (sz % 2 == 0)
    ok = true;
  else
    ok = false;
  rep(i, 0, sz / 2) {
    if (tar != (a[i] + a[sz - i - 1])) {
      ok = false;
      break;
    }
  }
  if (ok) ans.push_back(tar);

  sort(begin(ans), end(ans));
  for (ll x : ans) cout << x << " ";
  cout << endl;
  return 0;
}
