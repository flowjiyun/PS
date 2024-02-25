#include <cstring>
#include <algorithm>

const int MAXCOL = 4000010;
long long blockCnt;
int lastColIndex;

int block[MAXCOL];
int minHeight[MAXCOL];
int maxHeight[MAXCOL];

struct Result
{
  int top;
  int count;
};

void init(int C)
{
  blockCnt = 0;
  lastColIndex = C - 1;
  memset(block, 0, sizeof(block));
  memset(minHeight, 0, sizeof(minHeight));
  memset(maxHeight, 0, sizeof(maxHeight));
}

void updateMap(int queryStart, int queryEnd, int nodeIndex, int nodeStart, int nodeEnd, int delta)
{
  if (queryEnd < nodeStart || nodeEnd < queryStart)
  {
    return;
  }
  if (queryStart <= nodeStart && nodeEnd <= queryEnd)
  {
    block[nodeIndex] += delta;
    minHeight[nodeIndex] += delta;
    maxHeight[nodeIndex] += delta;
    return;
  }
  int mid = nodeStart + (nodeEnd - nodeStart) / 2;
  updateMap(queryStart, queryEnd, nodeIndex * 2, nodeStart, mid, delta);
  updateMap(queryStart, queryEnd, nodeIndex * 2 + 1, mid + 1, nodeEnd, delta);
  // 좌우 노드를 비교하여 현재 노드의 최대 최소 갱신
  minHeight[nodeIndex] = std::min(minHeight[nodeIndex * 2], minHeight[nodeIndex * 2 + 1]) + block[nodeIndex];
  maxHeight[nodeIndex] = std::max(maxHeight[nodeIndex * 2], maxHeight[nodeIndex * 2 + 1]) + block[nodeIndex];
  return;
}
Result dropBlocks(int mCol, int mHeight, int mLength)
{
  Result ret;
  ret.top = 0;
  ret.count = 0;
  // 총 블럭 갯수 업데이트
  blockCnt += mHeight * mLength;

  // 배열의 구간 업데이트
  updateMap(mCol, mCol + mLength - 1, 1, 0, lastColIndex, mHeight);
  int minVal = minHeight[1];
  int maxVal = maxHeight[1];
  ret.top = maxVal - minVal;
  ret.count = (blockCnt - ((long long)minVal * (long long)(lastColIndex + 1))) % 1000000;

  return ret;
}
