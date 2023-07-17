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

int main() {
  int n, m, t;
  cin >> n >> t >> m;
  vector<ll> hate(n), teams;
  rep(i, 0, m) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    hate[b] |= 1LL << a;
  }

  auto dfs = [&](auto dfs, int now) -> ll {
    if (now == n) return size(teams) == t;

    ll ans{};

    for (auto &&team : teams) {
      if (!(team & hate[now])) {
        team ^= 1LL << now;
        ans += dfs(dfs, now + 1);
        team ^= 1LL << now;
      }
    }
    if (size(teams) < t) {
      teams.emplace_back(1LL << now);
      ans += dfs(dfs, now + 1);
      teams.pop_back();
    }
    return ans;
  };
  teams.reserve(t);
  cout << dfs(dfs, 0) << endl;
  return 0;
}
