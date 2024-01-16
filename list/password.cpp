#include <iostream>
#include <list>
#include <vector>
// #include <cstdio>

using namespace std;

int N, M;

void Insert(list<int> &passwordLists, int x, int y, vector<int> &tmps)
{
  list<int>::iterator curIter = passwordLists.begin();
  for (int i = 0; i < x; ++i)
  {
    curIter++;
  }
  for (int i = 0; i < y; ++i)
  {
    passwordLists.insert(curIter, tmps[i]);
  }
}

void Append(list<int> &passwordLists, int y, vector<int> &tmps)
{
  for (int i = 0; i < y; ++i)
  {
    passwordLists.push_back(tmps[i]);
  }
}

void Delete(list<int> &passwordLists, int x, int y)
{
  list<int>::iterator curIter = passwordLists.begin();
  // 삭제하려는 위치가 리스트 범위를 벗어난 경우
  if (x >= passwordLists.size())
  {
    return;
  }
  if (x + y >= passwordLists.size())
  {
    y = passwordLists.size() - x;
  }
  for (int i = 0; i < x; ++i)
  {
    if (curIter != passwordLists.end())
    {
      curIter++;
    }
  }
  for (int i = 0; i < y; ++i)
  {
    curIter = passwordLists.erase(curIter);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int test_case;
  int T = 10;

  // freopen("input.txt", "r", stdin);
  for (test_case = 1; test_case <= T; ++test_case)
  {
    cin >> N;
    list<int> passwordList;
    for (int i = 0; i < N; ++i)
    {
      int val;
      cin >> val;
      passwordList.push_back(val);
    }
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
      char command;
      cin >> command;
      switch (command)
      {
      case 'I':
      {
        int x, y;
        vector<int> tmps;
        cin >> x >> y;
        for (int j = 0; j < y; ++j)
        {
          int s;
          cin >> s;
          tmps.push_back(s);
        }
        Insert(passwordList, x, y, tmps);
        break;
      }
      case 'D':
      {
        int x, y;
        cin >> x >> y;
        Delete(passwordList, x, y);
        break;
      }
      case 'A':
      {
        int y;
        vector<int> tmps;
        cin >> y;
        for (int j = 0; j < y; ++j)
        {
          int s;
          cin >> s;
          tmps.push_back(s);
        }
        Append(passwordList, y, tmps);
        break;
      }
      }
    }
    list<int>::iterator iter = passwordList.begin();
    cout << "#" << test_case << " ";
    for (int i = 0; i < 10; ++i)
    {
      cout << *iter << " ";
      iter++;
    }
    cout << "\n";
  }
  return 0;
}