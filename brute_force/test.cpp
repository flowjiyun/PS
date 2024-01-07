#include <iostream>

using namespace std;
int main() {
    cout << 158 << "\n";
    for (int i = 0; i < 158; ++i) {
        cout << 50 << "\n";
        for (int j = 0; j < 50; ++j) {
            for (int k = 0; k < 3; ++k) {
                cout << 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}