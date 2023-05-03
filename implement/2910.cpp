#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<int, int> appear_num;
map<int, int> appear_order;
bool cmp(int a, int b) {
  if (appear_num[a] == appear_num[b]) {
    return appear_order[a] < appear_order[b];
  }
  return (appear_num[a] > appear_num[b]);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  vector<int> seq;
  int order = 0;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    appear_num[val]++;
    if (appear_num.at(val) == 1) {
      appear_order[val] = order++;
      seq.push_back(val);
    }
  }
  sort(seq.begin(), seq.end(), cmp);
  for (int i = 0; i < seq.size(); ++i) {
    for (int j = 0; j < appear_num[seq[i]]; ++j) {
      cout << seq[i] << " ";
    }
  }

  return (0);
}