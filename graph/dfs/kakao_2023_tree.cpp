#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int getSizeOfDummy(int binarySize) {
    int n = 1;
    while (true) {
        if (pow(2, n) - 1 >= binarySize) {
            break;
        }
        ++n;
    }
    return pow(2, n) - 1 - binarySize; 
}

string getBinaryFromNumber(long long number) {
    string ans = "";
    while (number) {
        ans = to_string(number % 2) + ans;
        number /= 2;
    }
    int binarySize = ans.length();
    int dummySize = getSizeOfDummy(binarySize);
    for (int i = 0; i < dummySize; ++i) {
    	ans = "0" + ans;    
    }
    return ans;
}


bool isAllZero(string str) {
    for (auto c : str) {
		if (c != '0') {
            return false;
        }
    }
    return true;
}

bool isValidBinary(string binary) {
    if (binary.length() <= 1 || isAllZero(binary)) {
            return true;
    }
    int mid = binary.length() / 2;
    if (binary[mid] == '0') {
        return false;
    }
    string left = binary.substr(0, mid);
    string right = binary.substr(mid + 1);
	bool isLeftValid = isValidBinary(left);
    bool isRightValid = isValidBinary(right);
    if (isLeftValid && isRightValid) {
        return true;
    } else {
        return false;
    }
}




vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); ++i) {
        string curBinary = getBinaryFromNumber(numbers[i]);
        bool isValid;
        isValid = isValidBinary(curBinary);
        answer.push_back(isValid);
    }
    return answer;
}