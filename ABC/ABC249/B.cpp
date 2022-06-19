#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

int main()
{
  string S;
  cin >> S;

  bool low = false, upper = false, same = false;
  string ans = "No";

  rep(i, 0, S.size())
  {
    if (islower(S[i]))
    {
      low = true;
    }
    else if (isupper(S[i]))
    {
      upper = true;
    }
    rep(j, i + 1, S.size())
    {
      if (S[i] == S[j])
      {
        // cout << S[i] << " " << S[j];
        same = true;
        break;
      }
    }
  }

  // cout << low << " " << upper << " " << same << endl;

  if (low && upper && !same)
  {
    ans = "Yes";
  }
  cout << ans << endl;
  return 0;
}
