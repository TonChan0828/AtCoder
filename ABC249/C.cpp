#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

// int main()
// {
//   int N, K;
//   cin >> N >> K;
//   string S[N];
//   rep(i, 0, N)
//   {
//     cin >> S[i];
//   }
//   int matchCount = 0, count = 0;
//   string v;
//   int maxlen = 0;

//   rep(i, 0, N)
//   {
//     rep(j, 0, S[i].size())
//     {
//       count = 1;
//       rep(k, i + 1, N)
//       {
//         if (*find(S[k].begin(), S[k].end(), S[i][j]))
//         {
//           // cout << S[i][j] << endl;
//           count++;
//         }

//         if (count == K && !(*find(v.begin(), v.end(), S[i][j])))
//         {
//           v += S[i][j];
//           // cout << v << endl;
//           matchCount++;

//           break;
//         }
//       }
//       if (count == K && !(*find(v.begin(), v.end(), S[i][j])))
//       {
//         v += S[i][j];
//         // cout << v << endl;
//         matchCount++;
//       }
//     }
//   }

//   cout << matchCount << endl;
//   return 0;
// }

int main()
{
  int n, k;
  cin >> n >> k;
  string s[n];
  rep(i, 0, n)
  {
    cin >> s[i];
  }

  int ans = 0;
  rep(i, 0, 1 << n)
  {
    // vector<int> sum(26);
    int sum[26] = {};
    rep(j, 0, n)
    {
      if (i >> j & 1)
      {
        rep(x, 0, s[j].size())
        {
          sum[s[j][x] - 'a']++;
        }
      }
    }
    int now = 0;
    rep(j, 0, 26)
    {
      if (sum[j] == k)
      {
        now++;
      }
      if (now > ans)
      {
        ans = now;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
