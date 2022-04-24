#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

int main()
{
  vector<int> a(1000000);
  int s;
  cin >> a[0];

  int ans = 0;
  int i = 1;
  while (!ans)
  {
    if ((a[i - 1]) % 2 == 0)
    {
      a[i] = a[i - 1] / 2;
    }
    else
    {
      a[i] = 3 * a[i - 1] + 1;
    }

    rep(j, 0, i)
    {
      if (a[i] == a[j])
      {
        ans = i + 1;
      }
    }
    i++;
  }

  cout << ans << endl;
  return 0;
}
