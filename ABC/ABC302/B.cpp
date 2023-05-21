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

int h, w;
vector<string> s(101);
string tar = "snuke";
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool dfs(int x, int y, int cnt, int type) {
  if (cnt == 5) return true;
  if (x < 0 || x >= w || y < 0 || y >= h) return false;
  if (s[y][x] != tar[cnt]) return false;
  bool res = dfs(x + dx[type], y + dy[type], cnt + 1, type);
  return res;
}

int main() {
  cin >> h >> w;
  rep(i, 0, h) cin >> s[i];

  rep(i, 0, h) {
    rep(j, 0, w) {
      rep(k, 0, 8) {
        if (dfs(j, i, 0, k)) {
          rep(l, 0, 5) {
            cout << i + 1 << " " << j + 1 << endl;
            j += dx[k];
            i += dy[k];
          }
          return 0;
        }
      }
    }
  }
  return 0;
}
