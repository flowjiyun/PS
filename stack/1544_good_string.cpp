class Solution {
public:
    string makeGood(string s) {
        stack<char> word;
        string ans = "";
        for (size_t i = 0; i < s.size(); ++i) {
            if (word.empty()) {
                word.push(s[i]);
                continue;
            } else {
                if ((isupper(s[i]) && (tolower(s[i]) == word.top())) ||
                    (islower(s[i]) && (toupper(s[i]) == word.top()))) {
                    word.pop();
                    continue;
                } else {
                    word.push(s[i]);
                }
            }
        }
        while (!word.empty()) {
            ans = word.top() + ans;
            word.pop();
        }
        return ans; 
    }
};