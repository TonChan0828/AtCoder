#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
  if (a > b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); i--)
bool myCompare(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first > b.first;
  }
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return true;
  }
}

int main()
{
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p(a), q(b), r(c);
  rep(i, 0, a)
  {
    cin >> p[i];
  }
  rep(i, 0, b)
  {
    cin >> q[i];
  }
  rep(i, 0, c)
  {
    cin >> r[i];
  }
  sort(p.begin(), p.end(), greater());
  sort(q.begin(), q.end(), greater());
  sort(r.begin(), r.end(), greater());

  ll ans = 0;
  vector<ll> pq;
  rep(i, 0, x)
  {
    pq.push_back(p[i]);
    ans += p[i];
  }
  rep(i, 0, y)
  {
    pq.push_back(q[i]);
    ans += q[i];
  }
  sort(pq.begin(), pq.end());
  vector<ll> sum(c + 1);
  sum[0] = ans;
  // cout << sum[0] << endl;
  int tar = min(x + y, c);
  rep(i, 1, tar + 1)
  {
    int t = i - 1;
    sum[i] = sum[t] - pq[t] + r[t];
    ans = max(ans, sum[i]);
    // cout << sum[i] << endl;
  }

  cout << ans << endl;
  return 0;
}
