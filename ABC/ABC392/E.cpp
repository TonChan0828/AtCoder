#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, 0, m) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
  }

  vector<int> spare;
  dsu uf(n);
  rep(i, 0, m) {
    if (uf.same(a[i], b[i])) {
      spare.push_back(i);
    } else {
      uf.merge(a[i], b[i]);
    }
  }
  auto gr = uf.groups();
  set<int> le;
  for (auto v : gr) {
    le.insert(uf.leader(v[0]));
  }

  int sz = gr.size() - 1;
  cout << sz << "\n";
  int j = 1;
  rep(i, 0, sz) {
    int t = a[spare[i]];
    int lt = uf.leader(t);
    le.erase(lt);
    int rt = *le.begin();
    le.erase(rt);
    le.insert(uf.merge(lt, rt));

    printf("%d %d %d\n", spare[i] + 1, a[spare[i]] + 1, rt + 1);
  }
  return 0;
}
