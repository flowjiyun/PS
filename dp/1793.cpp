#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string ans[251];
int n;

void dp(int n) {
    for (int i = 3; i <= n; ++i) {
        string tmp = "";
        string n1 = ans[i - 1];
        string n2 = ans[i - 2];
        string n3 = ans[i - 2];
        int sum = 0;
        while (!n1.empty() || !n2.empty() || !n3.empty() || sum) {
            if (n1 != "") {
                sum += n1.back() - '0';
                n1.pop_back();
            }
            if (n2 != "") {
                sum += n2.back() - '0';
                n2.pop_back();
            }
            if (n3 != "") {
                sum += n3.back() - '0';
                n3.pop_back();
            }
            tmp.push_back((sum % 10) + '0');
            sum /= 10;
        }
        reverse(tmp.begin(), tmp.end());
        ans[i] = tmp;
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ans[0] = "1";
    ans[1] = "1";
    ans[2] = "3";
    while (1) {
        cin >> n;
        if (cin.eof()) {
            break;
        }
        if (ans[n] != "") {
            cout << ans[n] << '\n';
        } else {
            dp(n);
            cout << ans[n] << '\n';
        }
    }
    return 0;
}