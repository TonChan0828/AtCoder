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

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> p(n);
  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    p[i] = {a, b};
  }
  map<ll, ll> m;

  rep(i, 0, n) {
    ++m[p[i].first];
    --m[p[i].first + p[i].second];
  }

  vector<ll> len(n + 1, 0);
  ll cnt = 0;
  ll day = 0;
  for (const auto &x : m) {
    int diff = x.first - day;
    len[cnt] += diff;

    day = x.first;
    cnt += x.second;
  }
  len[cnt] += 1;

  rep(i, 1, n + 1) {
    if (i != 1) cout << " ";
    cout << len[i];
  }
  cout << endl;
  return 0;
}
