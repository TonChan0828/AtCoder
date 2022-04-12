#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
  int a, b;
  cin >> a >> b;
  // cout << a << b << endl;

  int ans = 1;
  int count = 0;
  while (ans < b)
  {
    ans += (a - 1);
    count++;
    if (ans >= b)
    {
      break;
    }
  }

  cout << count << endl;

  return 0;
}
