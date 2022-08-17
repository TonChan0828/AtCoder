#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int A[3][3];
  rep(i, 3)
  {
    rep(j, 3)
    {
      cin >> A[i][j];
    }
  }
  int N;
  cin >> N;
  int B[10];
  rep(i, N)
  {
    cin >> B[i];
  }

  int ans[3][3] = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0}};
  rep(i, N)
  {
    rep(j, 3)
    {
      rep(k, 3)
      {
        if (A[j][k] == B[i])
        {
          ans[j][k] = 1;
        }
      }
    }
  }

  // rep(j, 3)
  // {
  //   rep(k, 3)
  //   {
  //     cout << ans[j][k] << " ";
  //   }
  //   cout << endl;
  // }

  int count = 0;
  rep(i, 3)
  {
    if (ans[i][0] == 1 && ans[i][1] == 1 && ans[i][2] == 1)
    {
      count++;
    }
    else if (ans[0][i] == 1 && ans[1][i] == 1 && ans[2][i] == 1)
    {
      count++;
    }
  }
  if ((ans[0][0] == 1 && ans[1][1] == 1 && ans[2][2] == 1) || (ans[0][2] == 1 && ans[1][1] == 1 && ans[2][0] == 1))
  {
    count++;
  }

  if (count)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
