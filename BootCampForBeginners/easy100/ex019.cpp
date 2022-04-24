#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

int main()
{
  int n, m, x;
  cin >> n >> m >> x;

  vector<int> a(m);
  rep(i, 0, m)
  {
    cin >> a[i];
  }

  int min = 0;
  int cost = 0;
  rep(i, x, n + 1)
  {
    rep(j, 0, m)
    {

      if ((i + 1) == a[j])
      {
        cost++;
      }
    }
  }
  min = cost;
  cost = 0;
  for (int i = x; i > 0; i--)
  {
    rep(j, 0, a.size())
    {
      if ((i) == a[j])
      {
        cost++;
      }
    }
  }

  if (min > cost)
  {
    min = cost;
  }

  cout << min << endl;
  return 0;
}
