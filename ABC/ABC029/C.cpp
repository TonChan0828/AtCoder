#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}
vector<string> ans;

void dfs(int n, string s) {
  if (n == 0) {
    ans.push_back(s);
    return;
  }
  dfs(n - 1, s + 'a');
  dfs(n - 1, s + 'b');
  dfs(n - 1, s + 'c');
  return;
}
int main() {
  int n;
  cin >> n;
  dfs(n, "");
  for (string s : ans) {
    cout << s << endl;
  }
  return 0;
}
