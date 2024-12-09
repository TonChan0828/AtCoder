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
const int INF = 1001001001;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int main() {
  int h, w, d;
  cin >> h >> w >> d;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  vector cnt(h, vector<int>(w, INF));
  priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> q;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == 'H') {
    cnt[i][j] = 0;
    q.push({0, {i, j}});
  }

  while (!q.empty()) {
    auto [num, pp] = q.top();
    q.pop();
    if (num == d) continue;

    int i = pp.first, j = pp.second;
    rep(k, 0, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1) continue;
      if (s[ni][nj] == '#') continue;
      if (cnt[ni][nj] <= num + 1) continue;
      cnt[ni][nj] = num + 1;
      q.push({num + 1, {ni, nj}});
    }
  }

  int ans = 0;
  rep(i, 0, h) rep(j, 0, w) if (cnt[i][j] < INF) ans++;
  cout << ans << endl;
  return 0;
}
