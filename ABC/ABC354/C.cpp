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
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<P> ac(n);
  map<P, int> mp;
  rep(i, 0, n) {
    int a, c;
    cin >> a >> c;
    ac[i] = {a, c};
    mp[ac[i]] = i + 1;
  }
  sort(begin(ac), end(ac), greater());
  int now = 0;
  set<int> ans;
  ans.insert(mp[ac[now]]);
  rep(i, 1, n) {
    if (ac[now].second < ac[i].second) {
      continue;
    } else {
      now = i;
      ans.insert(mp[ac[now]]);
    }
  }

  cout << ans.size() << endl;
  for (int x : ans) {
    printf("%d ", x);
  }
  cout << endl;
  return 0;
}
