#include <iostream>
#include <list>
#include <vector>
// #include <cstdio>

using namespace std;

void Insert(list<int> &passwordLists, int x, int y)
{
  list<int>::iterator curIter = passwordLists.begin();
  curIter = std::next(curIter, x);
  passwordLists.insert(curIter, y);
}

void Change(list<int> &passwordLists, int x, int y)
{
  list<int>::iterator curIter = passwordLists.begin();
  curIter = std::next(curIter, x);
  *curIter = y;
}

void Delete(list<int> &passwordLists, int x)
{
  list<int>::iterator curIter = passwordLists.begin();
  curIter = std::next(curIter, x);
  passwordLists.erase(curIter);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int test_case;
  int T;

  cin >> T;

  // freopen("input.txt", "r", stdin);
  for (test_case = 1; test_case <= T; ++test_case)
  {
    int N, M, L;
    cin >> N >> M >> L;
    list<int> passwordList;
    for (int i = 0; i < N; ++i)
    {
      int val;
      cin >> val;
      passwordList.push_back(val);
    }
    for (int i = 0; i < M; ++i)
    {
      char command;
      cin >> command;
      switch (command)
      {
      case 'I':
      {
        int x, y;
        cin >> x >> y;
        Insert(passwordList, x, y);
        break;
      }
      case 'D':
      {
        int x;
        cin >> x;
        Delete(passwordList, x);
        break;
      }
      case 'C':
      {
        int x, y;
        cin >> x >> y;
        Change(passwordList, x, y);
        break;
      }
      }
    }
    cout << "#" << test_case << " ";
    if (L > passwordList.size() - 1)
    {
      cout << "-1";
    }
    else
    {
      list<int>::iterator iter = passwordList.begin();
      iter = std::next(iter, L);
      cout << *iter;
    }
    cout << "\n";
  }
  return 0;
}