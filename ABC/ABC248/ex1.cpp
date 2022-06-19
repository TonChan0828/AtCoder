#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string S;
  int ans[10];
  char c[10];
  int count = 0;
  cin >> c;

  rep(i, 10)
  {
    rep(j, 10)
    {
      // cout << (int)c[i];
      if (((int)c[i] - '0') == j)
      {
        ans[count] = j;
        count++;
        break;
      }
    }
  }
  // rep(i, 10)
  // {
  //   cout << ans[i] << endl;
  // }

  rep(i, 10)
  {
    count = 0;
    // cout << i << endl;
    rep(j, 10)
    {
      if (i == ans[j])
      {
        break;
      }
      else
      {
        count++;
      }
    }
    // cout << count << endl;
    if (count >= 9)
    {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
