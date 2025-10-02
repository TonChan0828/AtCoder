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

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  const int INF = 1001001001;
  vector cost(h, vector<int>(w, INF));
  int ans = 0;
  queue<P> q;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '#') {
    q.push({i, j});
    cost[i][j] = 0;
    ans++;
  }

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    int c = cost[i][j];
    rep(k, 0, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1) continue;
      if (cost[ni][nj] != INF) continue;
      int cnt = 0;
      rep(l, 0, 4) {
        int li = ni + di[l], lj = nj + dj[l];
        if (li < 0 || li > h - 1 || lj < 0 || lj > w - 1) continue;
        if (cost[li][lj] <= c) cnt++;
      }
      if (cnt == 1) {
        s[ni][nj] = '#';
        ans++;
        q.push({ni, nj});
        cost[ni][nj] = c + 1;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
