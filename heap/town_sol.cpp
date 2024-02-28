#include <algorithm>
#include <queue>
// bottom up seg tree 작성 연습
// - base를 활용한 tree 생성 & 업데이트 시작 위치 찾기
// - 완전 이진 트리의 성질의 이용
// 이분탐색을 통한 최적값 문제 해결
// - 인구 나누기 문제 : 최대가 최소가 되도록
// 우선 순위 큐를 활용한 우선순위 유기

int base;
int *population;
int edge[10000];
int segTree[1 << 15];

struct EdgeInfo {
  int index;
  int weight;
};

void updateTree(int index, int val) {
  index += base;
  segTree[index] = val;
  // 부모 노드로 계혹 이동하면서 bottom - up으로 업데이
  while (index >>= 1) {
    segTree[index] = segTree[index * 2] + segTree[index * 2 + 1];
  }
}

int querySum(int qs, int qe) {
  int ret = 0;
  for (qs += base, qe += base; qs <= qe; qs >>= 1, qe >>= 1) {
    if (qs % 2 == 1) {
      ret += segTree[qs];
      ++qs;
    }
    if (qe % 2 == 0) {
      ret += segTree[qe];
      --qe;
    }
  }
  return ret;
}

class MyComp {
public:
  bool operator()(const EdgeInfo &a, const EdgeInfo &b) {
    if (a.weight != b.weight) {
      return a.weight < b.weight;
    }
    return a.index > b.index;
  }
};

std::priority_queue<EdgeInfo, std::vector<EdgeInfo>, MyComp> pq;

void init(int N, int mPopulation[]) {
  population = mPopulation;
  pq = {};
  base = 1;
  while (base < N - 1) {
    base *= 2;
  }
  for (int i = 0; i < N - 1; ++i) {
    edge[i] = 1;
    int curWeight = (population[i] + population[i + 1]) / edge[i];
    pq.push({i, curWeight});
    // 리프노드 업데이트
    segTree[base + i] = curWeight;
  }
  // bottom - up segTree 생성
  for (int i = base - 1; i > 0; --i) {
    segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
  }
  return;
}

int expand(int M) {
  int newWeight;
  while (M--) {
    auto [index, weight] = pq.top();
    pq.pop();
    ++edge[index];
    newWeight = (population[index] + population[index + 1]) / edge[index];
    pq.push({index, newWeight});
    // 새로운 가중치로 업데이트
    updateTree(index, newWeight);
  }
  return newWeight;
}

int calculate(int mFrom, int mTo) {
  if (mFrom > mTo) {
    std::swap(mFrom, mTo);
  }
  return querySum(mFrom, mTo - 1);
}

int divide(int mFrom, int mTo, int K) {
  int left = 1;
  int right = (int)1e7;
  while (left < right) {
    int mid = (left + right) / 2;
    int group = 0;
    for (int i = mFrom; i <= mTo && group <= K; ++group) {
      int sum = 0;
      int j = i;
      while (j <= mTo && sum + population[j] <= mid) {
        sum += population[j];
        ++j;
      }
      i = j;
    }
    if (group <= K) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return right;
}