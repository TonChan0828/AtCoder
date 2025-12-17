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

const int M = 2000;
int sky[M + 1][M + 1], one[M + 1][M + 1];

struct Cloud {
  int u, d, l, r;
};
vector<Cloud> clouds;

int main() {
  int n;
  cin >> n;

  rep(i, 0, n) {
    int u, d, l, r;
    cin >> u >> d >> l >> r;
    u--, l--;
    sky[u][l]++;
    sky[u][r]--;
    sky[d][l]--;
    sky[d][r]++;
    clouds.emplace_back(u, d, l, r);
  }

  rep(i, 0, M) rep(j, 0, M) sky[i + 1][j] += sky[i][j];
  rep(i, 0, M) rep(j, 0, M) sky[i][j + 1] += sky[i][j];

  rep(i, 0, M) rep(j, 0, M) one[i + 1][j + 1] = (sky[i][j] == 1);
  rep(i, 0, M) rep(j, 0, M + 1) one[i + 1][j] += one[i][j];
  rep(i, 0, M + 1) rep(j, 0, M) one[i][j + 1] += one[i][j];

  int base = 0;
  rep(i, 0, M) rep(j, 0, M) if (sky[i][j] == 0)++ base;

  rep(i, 0, n) {
    auto [u, d, l, r] = clouds[i];
    int dif = one[d][r] - one[d][l] - one[u][r] + one[u][l];
    cout << base + dif << "\n";
  }

  return 0;
}
