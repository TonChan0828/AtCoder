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

int main() {
  int n;
  cin >> n;
  set<int> s;
  const ll INF = 1001001001;
  s.insert(0);
  map<int, int> mp;
  mp[0] = INF;
  ll ans = INF;
  rep(i, 0, n) {
    int x;
    cin >> x;
    s.insert(x);
    mp[x] = INF;
    ans += INF;
    auto itr = s.find(x);
    if (itr != begin(s)) {
      --itr;
      int y = *itr;
      ans -= mp[y];
      mp[y] = min(mp[y], abs(x - y));
      ans += mp[y];
      // cout << " --itr:" << *itr << " " << mp[y] << endl;

      ans -= mp[x];
      mp[x] = min(mp[x], abs(x - y));
      ans += mp[x];
      // cout << " --itr:" << *itr << " " << mp[x] << endl;
      ++itr;
    }

    ++itr;
    if (itr != end(s)) {
      int y = *itr;
      ans -= mp[y];
      mp[y] = min(mp[y], abs(y - x));
      ans += mp[y];
      // cout << "  ++itr:" << *itr << " " << mp[y] << endl;

      ans -= mp[x];
      mp[x] = min(mp[x], abs(y - x));
      ans += mp[x];
      // cout << "  ++itr:" << *itr << " " << mp[x] << endl;
    }

    cout << ans << "\n";
  }

  return 0;
}
