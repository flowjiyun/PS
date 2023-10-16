#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

typedef struct material {
  int p;
  int f;
  int s;
  int v;
  int c;  
} material;

int n;
material target;
vector<pair<int, vector<int>>> setList;

bool isOk(material candi) {
  if (candi.p >= target.p && 
      candi.f >= target.f && 
      candi.s >= target.s && 
      candi.v >= target.v ) {
        return true;
      }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> target.p >> target.f >> target.s >> target.v;
  vector<material> materialList(n);
  for (int i = 0; i < n; ++i) {
    material mat;
    cin >> mat.p >> mat.f >> mat.s >> mat.v >> mat.c;
    materialList[i] = mat;
  }

  for (int i = 0; i < (1 << n); ++i) {
    pair<int, vector<int>> tmpSet;
    vector<int> seq;
    material candi;
    memset(&candi, 0, sizeof(candi));
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        seq.push_back(j + 1);
        candi.p += materialList[j].p;
        candi.f += materialList[j].f;
        candi.s += materialList[j].s;
        candi.v += materialList[j].v;
        candi.c += materialList[j].c;
      }
    }
    // cout << candi.p << candi.f << candi.s << candi.v << candi.c << '\n';
    if (isOk(candi)) {
      sort(seq.begin(), seq.end());
      tmpSet.first = candi.c;
      tmpSet.second = seq;
      setList.push_back(tmpSet);
    }
  }
  sort(setList.begin(), setList.end());
  if (setList.size() == 0) {
    cout << "-1";
  } else {
    cout << setList.front().first << '\n';
    for (auto v : setList.front().second) {
      cout << v << ' ';
    }
  }
  return 0;
}