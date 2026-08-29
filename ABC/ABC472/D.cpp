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

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};
using P = pair<int, int>;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector<int> r(h), c(w);
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '#')++ r[i], ++c[j];

  vector cnt(h, vector<int>(w, -1));
  queue<P> q;
  rep(i, 0, h) rep(j, 0, w) if (r[i] == 0 && c[j] == 0) {
    q.emplace(i, j);
    cnt[i][j] = 0;
  }

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    rep(k, 0, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      if (cnt[ni][nj] != -1) continue;
      cnt[ni][nj] = cnt[i][j] + 1;
      q.emplace(ni, nj);
    }
  }

  int ans = 0;
  rep(i, 0, h) rep(j, 0, w) if (cnt[i][j] >= 0 && cnt[i][j] <= k)++ ans;
  cout << ans << endl;
  return 0;
}
