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

int main()
{
  int n;
  cin >> n;
  map<int, int> mo, me;
  rep(i, 0, n)
  {
    int v;
    cin >> v;
    if (i % 2 == 0)
    {
      me[v]++;
    }
    else
    {
      mo[v]++;
    }
  }
  vector<pair<int, int>> ve, vo;
  for (auto &value : me)
  {
    ve.push_back({value.second, value.first});
  }
  for (auto &value : mo)
  {
    vo.push_back({value.second, value.first});
  }
  sort(ve.begin(), ve.end(), greater());
  sort(vo.begin(), vo.end(), greater());

  int ans = 0;
  if (ve[0].second != vo[0].second)
  {
    ans = (n / 2 - ve[0].first) + (n / 2 - vo[0].first);
  }
  else
  {
    ans = min((n / 2 - ve[1].first) + (n / 2 - vo[0].first), (n / 2 - ve[0].first) + (n / 2 - vo[1].first));
  }

  cout << ans << endl;
  return 0;
}
