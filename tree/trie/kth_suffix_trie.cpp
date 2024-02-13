#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
public:
  struct TrieNode {
    int child[26];
    bool isEnd;
    TrieNode() {
      memset(child, -1, sizeof(child));
      isEnd = false;
    }
  };
  Trie() : nodes(1) {}

  void insert(const char *str) {
    int nodeID = 0;
    size_t len = strlen(str);
    for (int i = 0; i < (int)len; ++i) {
      if (nodes[nodeID].child[str[i] - 'a'] == -1) {
        nodes[nodeID].child[str[i] - 'a'] = nodes.size();
        nodes.emplace_back();
      }
      nodeID = nodes[nodeID].child[str[i] - 'a'];
    }
    nodes[nodeID].isEnd = true;
  }

  string find(int startNode, string &str, int &loopCnt) {
    TrieNode curNode = nodes[startNode];
    if (curNode.isEnd) {
      --loopCnt;
      if (loopCnt == 0) {
        return str;
      }
    }
    for (int i = 0; i < 26; ++i) {
      if (curNode.child[i] != -1) {
        str += i + 'a';
        string ret = find(curNode.child[i], str, loopCnt);
        if (loopCnt == 0) {
          return ret;
        }
        str.pop_back();
      }
    }
    return "";
  }

private:
  vector<TrieNode> nodes;
};

int main(int argc, char **argv) {
  int test_case;
  int T;
  // freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int k;
    string val;
    cin >> k;
    cin >> val;
    Trie trie = Trie();
    for (int i = 0; i < val.size(); ++i) {
      trie.insert(val.c_str() + i);
    }
    string ret = "";
    cout << "#" << test_case << " " << trie.find(0, ret, k) << "\n";
  }
  return 0;
}