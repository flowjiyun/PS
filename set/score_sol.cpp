#include <algorithm>
#include <set>
#include <unordered_map>

#define MAX_SCORE 400000
#define MAX_ID 1000000001
struct Student {
  int id;
  int score;

  bool operator<(const Student &other) const {
    if (score == other.score) {
      return id < other.id;
    }
    return score < other.score;
  }
};

struct Info {
  int grade;
  int gender; // 0 : male, 1 : female
  int score;
};

std::set<Student> db[3][2];
std::unordered_map<int, Info> hashMap;

void init() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      db[i][j].clear();
    }
  }
  hashMap.clear();
  return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
  int grade = mGrade - 1;
  int gender = (mGender[0] == 'm') ? 0 : 1;

  db[grade][gender].insert({mId, mScore});
  hashMap[mId] = {grade, gender, mScore};

  return db[grade][gender].rbegin()->id;
}

int remove(int mId) {
  // 삭제할 것 없으면 0 반환
  if (hashMap.find(mId) == hashMap.end()) {
    return 0;
  }
  // 삭제
  int grade = hashMap[mId].grade;
  int gender = hashMap[mId].gender;
  int score = hashMap[mId].score;
  auto &curDB = db[grade][gender];
  hashMap.erase(mId);
  curDB.erase({mId, score});
  // 현재 디비 비었으면 0 반환
  if (curDB.empty()) {
    return 0;
  }
  return curDB.begin()->id;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7],
          int mScore) {
  Student ret{0, MAX_SCORE};
  for (int i = 0; i < mGradeCnt; ++i) {
    for (int j = 0; j < mGenderCnt; ++j) {
      int grade = mGrade[i] - 1;
      int gender = (mGender[j][0] == 'm') ? 0 : 1;
      auto &curDB = db[grade][gender];
      auto it = curDB.lower_bound({0, mScore});
      if (it != curDB.end()) {
        if (*it < ret) {
          ret = *it;
        }
      }
    }
  }
  return ret.id;
}