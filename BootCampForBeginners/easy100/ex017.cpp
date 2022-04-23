#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

int main()
{
  int N;
  cin >> N;
  vector<double> v(N);
  rep(i, 0, N)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  double avg = 0;

  while (v.size() > 1)
  {
    avg = (double)(v[0] + v[1]) / 2;
    v.erase(v.begin(), v.begin() + 2);
    v.insert(v.begin(), avg);
    // cout << avg << endl;
    // rep(i, 0, v.size())
    // {
    //   cout << v[i] << " ";
    // }
    // cout << endl;
  }
  cout << avg << endl;
  return 0;
}
