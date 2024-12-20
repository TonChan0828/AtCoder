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
int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

int main() {
  int h, w;
  ll x;
  cin >> h >> w >> x;
  int p, q;
  cin >> p >> q;
  --p, --q;
  vector s(h, vector<ll>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> s[i][j];

  priority_queue<pair<ll, P>, vector<pair<ll, P>>, greater<pair<ll, P>>> qu;
  rep(d, 0, 4) {
    int ni = p + di[d], nj = q + dj[d];
    if (ni < 0 || nj < 0 || ni > h - 1 || nj > w - 1) continue;
    qu.push({s[ni][nj], {ni, nj}});
  }

  vector vis(h, vector<bool>(w, false));
  vis[p][q] = true;
  ll power = s[p][q];
  while (!qu.empty()) {
    auto tmp = qu.top();
    qu.pop();
    ll sc = tmp.first;
    int i = tmp.second.first, j = tmp.second.second;
    if (vis[i][j]) continue;
    if (sc > power / x) {
      break;
    } else if (sc == power / x) {
      if (power % x == 0) break;
    }

    // cout << i << " " << j << endl;
    power += sc;
    vis[i][j] = true;
    rep(d, 0, 4) {
      int ni = i + di[d], nj = j + dj[d];
      if (ni < 0 || nj < 0 || ni > h - 1 || nj > w - 1) continue;
      if (vis[ni][nj]) continue;
      qu.push({s[ni][nj], {ni, nj}});
    }
  }

  cout << power << endl;
  return 0;
}
