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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}
const int di[] = {0, -1, 1, 0};
const int dj[] = {-1, 0, 0, 1};

using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (s[i][j] == '#') {
        rep(k, 0, 4) {
          int ni = i + di[k], nj = j + dj[k];
          if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
          if (s[ni][nj] == '#') continue;
          s[ni][nj] = 'x';
        }
      }
    }
  }

  vector table(h, vector<int>(w, -1));
  int ans = 0;
  int pos = 0;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (s[i][j] == '#') continue;
      if (table[i][j] > -1) continue;

      queue<P> q;
      q.push({i, j});
      table[i][j] = pos;
      int cnt = 0;
      while (!q.empty()) {
        auto [si, sj] = q.front();
        q.pop();
        ++cnt;
        // printf("(%d, %d) ", si, sj);
        if (s[si][sj] == 'x') continue;
        rep(k, 0, 4) {
          int ni = si + di[k], nj = sj + dj[k];
          if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
          if (s[ni][nj] == '#') continue;
          if (table[ni][nj] == pos) continue;
          q.push({ni, nj});
          table[ni][nj] = pos;
        }
      }
      // cout << endl;

      ++pos;
      ans = max(ans, cnt);
    }
  }

  cout << ans << endl;
  return 0;
}
