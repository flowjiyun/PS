#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> map;
int row, col;

void getSkillResult(vector<vector<int>>& skill) {
    for (const auto& val : skill) {
        int type = val[0];
        int r1 = val[1];
        int c1 = val[2];
        int r2 = val[3];
        int c2 = val[4];
        int degree = val[5];
        if (type == 1) {
			degree = -degree;
        }

        map[r1][c1] += degree;
        map[r1][c2 + 1] -= degree;
        map[r2 + 1][c1] -= degree;
        map[r2 + 1][c2 + 1] += degree;

    }
  
    for (int i = 0; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            map[i][j] += map[i][j - 1];
        }
    }
   
    for (int i = 0; i < col; ++i) {
        for (int j = 1; j < row; ++j) {
            map[j][i] += map[j - 1][i];
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    row = board.size();
    col = board[0].size();
    
    // init map
    map = vector(row + 1, vector(col + 1, 0));
    
    // 스킬 맵 채우기
    getSkillResult(skill);
    
   	// 답 구하기
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            board[i][j] += map[i][j];
            if (board[i][j] > 0) {
                ++answer;
            }
        }
    }
    return answer;
}