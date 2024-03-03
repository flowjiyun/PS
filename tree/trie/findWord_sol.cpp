#include <cstring>
#include <string>
#include <vector>

// 여러 단어를 추가 할 수 있는 trie 자료 구조 구현 해보기
// 단어끝 플래그에 단어 수를 저장
using namespace std;

class TrieNode {
public:
  TrieNode() : cnt(0) {
    for (int i = 0; i < 26; ++i) {
      nodes[i] = nullptr;
    }
  }
  TrieNode *nodes[26];
  int cnt;
};

TrieNode *root = nullptr;
bool isRemoved;
int wordCnt;

void deleteTrie(TrieNode *node) {
  if (node == nullptr)
    return;
  for (int i = 0; i < 26; ++i) {
    if (node->nodes[i] != nullptr) {
      deleteTrie(node->nodes[i]);
    }
  }
  delete node;
}

void init() {
  deleteTrie(root);
  root = new TrieNode();
}

int add(char str[]) {
  TrieNode *curNode = root;
  for (int i = 0; str[i] != 0; ++i) {
    char c = str[i];
    int idx = c - 'a';
    if (curNode->nodes[idx] == nullptr) {
      curNode->nodes[idx] = new TrieNode();
    }
    curNode = curNode->nodes[idx];
  }
  return ++curNode->cnt;
}

void updateCount(TrieNode *node, char str[], int idx) {
  if (node != nullptr) {
    char nextChar = str[idx + 1];
    switch (nextChar) {
    case 0:
      wordCnt += node->cnt;
      if (isRemoved)
        node->cnt = 0;
      break;
    case '?':
      for (int i = 0; i < 26; i++) {
        updateCount(node->nodes[i], str, idx + 1);
      }
      break;
    default:
      updateCount(node->nodes[nextChar - 'a'], str, idx + 1);
    }
  }
}

void updateCount(char str[]) {
  wordCnt = 0;
  char firstChar = str[0];
  if (firstChar == '?') {
    for (int i = 0; i < 26; i++) {
      TrieNode *startNode = root->nodes[i];
      updateCount(startNode, str, 0);
    }
  } else {
    TrieNode *startNode = root->nodes[firstChar - 'a'];
    updateCount(startNode, str, 0);
  }
}

int remove(char str[]) {
  isRemoved = true;
  updateCount(str);
  return wordCnt;
}

int search(char str[]) {
  isRemoved = false;
  updateCount(str);
  return wordCnt;
}