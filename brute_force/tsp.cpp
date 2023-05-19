// Traveling Sales-man Problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist[10][10];
int visited[10];

int path(int total, vector<int> &seq, int cur_dist) {
  if (seq.size() == total) {
    return cur_dist + dist[seq[0]][seq.back()];
  }
  double ret = numeric_limits<double>::max();
  for (int next = 0; next < total; ++next) {
    if (visited[next] == 0) {
      int here;
      if (seq.empty())
        here = next;
      else
        here = seq.back();
      seq.push_back(next);
      visited[next] = 1;
      double cand = path(total, seq, cur_dist + dist[here][next]);
      ret = min(ret, cand);
      seq.pop_back();
      visited[next] = 0;
    }
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> seq;

  cout << path(n, seq, 0);

  return 0;
}

