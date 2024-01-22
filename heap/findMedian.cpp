#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

// minheap과 maxheap을 통한 중앙값 구하기
// 원리 : 중앙값에 가까운 수들을 관리하는 측면
// - 동적으로 변하는 수열에서 중앙값을 구하는데 효과적 (시간 복잡도 측면다
// 1. 최초 수는 maxheap에 넣는다
// 2. 다음 넣는 수에 대해서는 maxheap의 top 값과 비교 했을 때 작거나 같으면
// maxheap 아니면 minheap 에 넣는다
// 3. 모든 수를 넣고 나서 힙 사이즈 차이가 2이상일 경우 큰 사이즈의 힙의
// top노드의 값을 반대 노드로 옮긴다.
// 4. 각 힙의 사이즈가 같으면 수열의 크기가 짝수 임으로 각 힙의 top 노드의
// 평균값이 중앙 값이고 사이즈가 다르면 사이즈가 큰 힙의 노드가 중앙값임

using namespace std;

const int MODUL = 20171109;

int getMedian(priority_queue<int, vector<int>> &maxHeap,
              priority_queue<int, vector<int>, greater<int>> &minHeap,
              vector<int> &list) {
  // 동적으로 수열 삽입
  for (const int val : list) {
    if (val > maxHeap.top()) {
      minHeap.push(val);
    } else {
      maxHeap.push(val);
    }
  }
  // 힙 크기 차이 확인 & 재조정
  while (abs(static_cast<int>((maxHeap.size() - minHeap.size()))) > 1) {
    int top;
    if (minHeap.size() > maxHeap.size()) {
      top = minHeap.top();
      minHeap.pop();
      maxHeap.push(top);
    } else {
      top = maxHeap.top();
      maxHeap.pop();
      minHeap.push(top);
    }
  }
  int curMedian;
  if (minHeap.size() > maxHeap.size()) {
    curMedian = minHeap.top() % MODUL;
  } else {
    curMedian = maxHeap.top() % MODUL;
  }
  return curMedian;
}

int main(int argc, char **argv) {
  int test_case;
  int T;
  ios::sync_with_stdio(0);
  cin.tie(0);
  /*
     아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
     앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의
     코드입니다.
     //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을
     저장한 후, freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신
     파일로부터 입력을 받아올 수 있습니다. 따라서 테스트를 수행할 때에는 아래
     주석을 지우고 이 함수를 사용하셔도 좋습니다. freopen 함수를 사용하기
     위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다. 단,
     채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리
     하셔야 합니다.
  */
  // freopen("input.txt", "r", stdin);
  cin >> T;
  /*
     여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
  */
  for (test_case = 1; test_case <= T; ++test_case) {
    int n, a;
    int sum = 0;
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    cin >> n >> a;
    maxHeap.push(a);
    for (int i = 0; i < n; ++i) {
      vector<int> list;
      int x, y;
      cin >> x >> y;
      list.push_back(x);
      list.push_back(y);
      sum += getMedian(maxHeap, minHeap, list);
      sum %= MODUL;
    }
    cout << "#" << test_case << " " << sum << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}