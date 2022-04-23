#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

int main()
{
  string T;
  cin >> T;
  int maxCount = 0;
  rep(i, 0, 10)
  {
    if (T[i] == 'A' || T[i] == 'C' || T[i] == 'G' || T[i] == 'T')
    {
      int count = 0;
      rep(j, i, 10)
      {
        if (T[j] == 'A' || T[j] == 'C' || T[j] == 'G' || T[j] == 'T')
        {
          count++;
        }
        else
        {
          break;
        }
      }
      if (count > maxCount)
      {
        maxCount = count;
      }
    }
  }

  cout << maxCount << endl;
  return 0;
}
