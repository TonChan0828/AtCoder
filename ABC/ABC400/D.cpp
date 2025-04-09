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

const int INF = 1001001001;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

using P = pair<int, int>;
using PP = pair<int, P>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  --a, --b, --c, --d;

  vector cnt(h, vector<int>(w, INF));

  priority_queue<PP, vector<PP>, greater<PP>> q;

  q.push({0, {a, b}});
  while (!q.empty()) {
    auto tmp = q.top();
    auto [c, ij] = tmp;
    auto [i, j] = ij;
    q.pop();

    if (c >= cnt[i][j]) continue;
    // cout << c << " " << i << " " << j << endl;
    cnt[i][j] = c;
    rep(d, 0, 4) {
      int ni = i + di[d], nj = j + dj[d];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (cnt[ni][nj] <= c) continue;

      if (s[ni][nj] == '.') {
        q.push({c, {ni, nj}});
      } else {
        int ki = i, kj = j;
        rep(k, 0, 2) {
          ki += di[d];
          kj += dj[d];
          if (ki < 0 || kj < 0 || ki >= h || kj >= w) continue;
          if (cnt[ki][kj] <= c + 1) continue;
          q.push({c + 1, {ki, kj}});
        }
      }
    }
  }

  cout << cnt[c][d] << endl;
  return 0;
}
