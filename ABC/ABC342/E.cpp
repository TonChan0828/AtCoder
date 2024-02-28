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
  int n, m;
  cin >> n >> m;
  vector<vector<tuple<int, ll, ll, ll, ll>>> sta(n);
  vector<ll> ans(n, -1);
  rep(i, 0, m) {
    ll l, d, k, c;
    int a, b;
    cin >> l >> d >> k >> c >> a >> b;
    --a, --b, --k;
    sta[b].push_back({a, l, d, k, c});
  }

  // rep(i,0,n){
  //   cout<<i<<endl;
  //   for(auto [a,l,d,k,c]:sta[i]){
  //     printf(" %d",a);
  //   }
  //   cout<<endl;
  // }

  const ll INF = __LONG_LONG_MAX__;
  priority_queue<pair<ll, int>> q;
  q.emplace(INF, n - 1);

  while (!q.empty()) {
    auto [cost, pos] = q.top();
    q.pop();

    // cout << pos << endl << " ";
    for (auto [a, l, d, k, c] : sta[pos]) {
      // cout << a << " ";
      ll time = min(k, (cost - c - l) / d);
      if (chmax(ans[a], l + d * time)) {
        q.emplace(ans[a], a);
      }
    }
    // cout << endl;
    // rep(i,0,n)cout<<ans[i]<<" ";
    // cout<<endl;
  }

  rep(i, 0, n - 1) {
    if (ans[i] == -1) {
      cout << "Unreachable";
    } else {
      cout << ans[i];
    }
    cout << "\n";
  }
  return 0;
}
