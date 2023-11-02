class Solution {
public:
    string simplifyPath(string path) {
        deque<string> words;
        string curWord = "";
        string ans = "";
        for (size_t i = 0; i < path.size(); ++i) {
            if (curWord.size() == 0) {
                if (path[i] == '/') {
                    continue;
                }
                curWord += path[i];
            } else {
                if (path[i] == '/') {
                    pushWord(curWord, words);
                    curWord = "";
                } else {
                    curWord += path[i];
                }
            }
        } 
        pushWord(curWord, words);
        auto it = words.begin();
        while (it != words.end()) {
            ans +=  "/" + *it;
            ++it;
        }
        if (ans.size() == 0) {
            return "/";
        }
        return ans;
    }
    void pushWord(string& curWord, deque<string>& words) {
        if (curWord == "") {
            return;
        }
        if (curWord == ".") {
            return;
        }
        if (curWord == "..") {
            if (!words.empty()) {
                words.pop_back();
            }
            return;
        }
        words.push_back(curWord);
    }
}