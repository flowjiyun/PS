// #include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 1. 트리 구성
//  1 - 1 : 서브트리 계산을 위해 필요한 정보 : 현재 노드에서 서브트리 크기
//  1 - 2 : 공통 조상 계산을 위한 자료구조 : 현재 노드의 부모노드, 현재 노드의
//  level
// 2. 각 노드에서의 서브 트리 크기 미리 계산 하기
struct Node {
  int level = 0;
  int parent = 0;
  int subTreeSize = 0;
  vector<int> child;
};

void setLevel(Node treeInfo[], int ptr, int level) {
  treeInfo[ptr].level = level;
  for (auto c : treeInfo[ptr].child) {
    setLevel(treeInfo, c, level + 1);
  }
}

void setSubtreeSize(Node treeInfo[], int ptr) {
  treeInfo[ptr].subTreeSize = 1;
  for (auto c : treeInfo[ptr].child) {
    setSubtreeSize(treeInfo, c);
    treeInfo[ptr].subTreeSize += treeInfo[c].subTreeSize;
  }
}

int findLCA(Node treeInfo[], int t1, int t2) {
  // 노드 레벨 맞추기
  while (treeInfo[t1].level > treeInfo[t2].level) {
    t1 = treeInfo[t1].parent;
  }
  while (treeInfo[t2].level > treeInfo[t1].level) {
    t2 = treeInfo[t2].parent;
  }
  // 한칸씩 조상 노드르 올라가면서 같아지는 노드 찾기
  while (t1 != t2) {
    t1 = treeInfo[t1].parent;
    t2 = treeInfo[t2].parent;
  }
  return t1;
}

int main(int argc, char **argv) {
  int test_case;
  int T;
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
  /*
     여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
  */
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int v, e, t1, t2;
    Node treeInfo[10001];
    memset(treeInfo, 0, sizeof(treeInfo));
    cin >> v >> e >> t1 >> t2;
    for (int i = 0; i < e; ++i) {
      int parent, child;
      cin >> parent >> child;
      treeInfo[parent].child.push_back(child);
      treeInfo[child].parent = parent;
    }
    setSubtreeSize(treeInfo, 1);
    setLevel(treeInfo, 1, 0);
    cout << "#" << test_case << " ";
    int lca = findLCA(treeInfo, t1, t2);
    cout << lca << " " << treeInfo[lca].subTreeSize << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}
