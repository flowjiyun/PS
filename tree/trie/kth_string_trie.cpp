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
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
      if (nodes[nodeID].child[str[i] - 'a'] == -1) {
        nodes[nodeID].child[str[i] - 'a'] = nodes.size();
        nodes.emplace_back();
      }
      nodeID = nodes[nodeID].child[str[i] - 'a'];
    }
    nodes[nodeID].isEnd = true;
  }

  bool getList(int startNode, string &str, vector<string> &list, int k) {
    TrieNode curNode = nodes[startNode];
    if (list.size() == k) {
      return true;
    }

    for (int i = 0; i < 26; ++i) {
      if (curNode.child[i] != -1) {
        str += (i + 'a');
        list.push_back(str);
        if (getList(curNode.child[i], str, list, k)) {
          return true;
        }
        str.pop_back();
      }
    }
    return false;
  }

private:
  vector<TrieNode> nodes;
};

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
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
    string str = "";
    vector<string> list;
    cout << "#" << test_case << " ";
    if (trie.getList(0, str, list, k)) {
      cout << list.back() << "\n";
    } else {
      cout << "none"
           << "\n";
    }
    // for (auto v : list) {
    //   cout << v << "\n";
    // }
  }
  return 0;
}