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
  vector<int> num;
  rep(i, 1, n) {
    if (i * i > n) break;
    num.push_back(i * i);
  }
  int sz = num.size();

  unordered_map<int, int> mp;
  rep(i, 0, sz) {
    rep(j, i + 1, sz) {
      if (num[i] + num[j] > n) break;
      mp[num[i] + num[j]]++;
    }
  }
  vector<int> ans;
  for (auto [x, cnt] : mp)
    if (cnt == 1) ans.push_back(x);

  sort(begin(ans), end(ans));
  cout << ans.size() << endl;
  for (int x : ans) cout << x << " ";
  cout << endl;

  return 0;
}
