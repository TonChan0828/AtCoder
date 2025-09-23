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
  int n;
  cin >> n;
  map<int, vector<int>> mp;
  rep(i, 1, n + 1) {
    int a, b;
    cin >> a >> b;
    mp[a].push_back(i);
    mp[b].push_back(i);
  }

  set<int> ans;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (ans.find(x) != ans.end()) continue;
    ans.insert(x);
    for (int y : mp[x]) {
      if (ans.find(y) != ans.end()) continue;
      q.push(y);
      // cout << " " << y << endl;
    }
  }
  // for (int x : ans) cout << x << " ";
  // cout << endl;

  cout << ans.size() - 1 << endl;
  return 0;
}
