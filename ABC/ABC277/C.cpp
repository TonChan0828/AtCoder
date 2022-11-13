#include <bits/stdc++.h>
using namespace std;
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
map<int, bool> b;

int ans;

void dfs(map<int, vector<int>> m, int x) {
  for (int l : m[x]) {
    if (b[l]) continue;
    b[l] = true;
    chmax(ans, l);
    dfs(m, l);
  }
}

// int main() {
//   int n;
//   cin >> n;
//   map<int, vector<int>> m;
//   rep(i, 0, n) {
//     int a, b;
//     cin >> a >> b;
//     m[a].push_back(b);
//     m[b].push_back(a);
//   }

//   ans = 1;
//   b[1] = true;
//   dfs(m, ans);

//   cout << ans << endl;
//   return 0;
// }

int main() {
  int n;
  cin >> n;
  map<int, vector<int>> m;
  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    m[a].push_back(b);
    m[b].push_back(a);
  }
  ans = 1;
  queue<int> q;
  q.push(1);
  b[1] = true;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int l : m[x]) {
      if (b[l] == true) continue;
      chmax(ans, l);
      q.push(l);
      b[l] = true;
    }
  }
  cout << ans << endl;
  return 0;
}
