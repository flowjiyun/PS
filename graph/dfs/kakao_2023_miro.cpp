#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string command = "dlru";
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string answer = "impossible";
string curRoute = "";
bool exitDfs = false;
int gn, gm, gx, gy, gr, gc, gk;

int getDist(int curX, int curY) {
    return abs(curX - gr) + abs(curY - gc);
}
void dfs(int curX, int curY, int depth) {
    if (!exitDfs) {
        if (gk - depth - getDist(curX, curY) < 0) {
            return;
        }
        if (((gk - depth - getDist(curX, curY)) % 2) != 0) {
            return;
        }
        if (depth == gk) {
            if (curX == gr && curY == gc) {
            exitDfs = true;
            answer = curRoute;
            }
            return;
        }
        
        
        for (int dir = 0; dir < 4; ++dir) {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];
            if ((nx > 0 && nx <= gn) && (ny > 0 && ny <= gm)) {
                curRoute += command[dir];
                dfs(nx, ny, depth + 1);
                curRoute.pop_back();
            }
            
        }
    }
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    gn = n; gm = m; gx = x; gy = y; gr = r; gc = c; gk = k;
    dfs(gx, gy, 0);
    return answer;
}