#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>


// root에 몇개 연결되어 있는지 메모
// 해당 친구 그래프의 루트 메모
using namespace std;
int t;
vector<pair<string, string>> relations;
unordered_map<string, string> relationGraph;
set<string> names;
unordered_map<string, int> relationCnt;


string findRoot(string val) {
    if (relationGraph[val] == val) {
        return val;
    }
    relationGraph[val] = findRoot(relationGraph[val]);
    return relationGraph[val];
}

void makeUnion(string a, string b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) {
        return;
    } else {
        relationCnt[a] += relationCnt[b];
        relationGraph[b] = a;
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string a, b;
            cin >> a >> b;
            relations.push_back({a, b});
            names.insert(a);
            names.insert(b);
        }
        for (auto val : names) {
            relationGraph[val] = val;
            relationCnt[val] = 1;
        }
        for (auto val : relations) {
           string a = val.first;
           string b = val.second;
           makeUnion(a, b);
           cout << relationCnt[findRoot(a)] << "\n";
        }
        relations.clear();
        relationGraph.clear();
        names.clear();
        relationCnt.clear();
    }
    return 0;
}