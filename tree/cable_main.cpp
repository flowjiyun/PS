#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT (100)
#define CMD_CONNECT (200)
#define CMD_MEASURE (300)
#define CMD_TEST (400)

extern void init(int mDevice);
extern void connect(int mOldDevice, int mNewDevice, int mLatency);
extern int measure(int mDevice1, int mDevice2);
extern int test(int mDevice);

static bool run()
{
  int Q;
  int mDevice, mOldDevice, mNewDevice, mDevice1, mDevice2;
  int mLatency;

  int ret = -1, ans;

  scanf("%d", &Q);

  bool okay = false;

  for (int q = 0; q < Q; ++q)
  {
    int cmd;
    scanf("%d", &cmd);
    switch (cmd)
    {
    case CMD_INIT:
      scanf("%d", &mDevice);
      init(mDevice);
      okay = true;
      break;
    case CMD_CONNECT:
      scanf("%d %d %d", &mOldDevice, &mNewDevice, &mLatency);
      connect(mOldDevice, mNewDevice, mLatency);
      break;
    case CMD_MEASURE:
      scanf("%d %d", &mDevice1, &mDevice2);
      ret = measure(mDevice1, mDevice2);
      scanf("%d", &ans);
      if (ret != ans)
        okay = false;
      break;
    case CMD_TEST:
      scanf("%d", &mDevice);
      ret = test(mDevice);
      scanf("%d", &ans);
      if (ret != ans)
        okay = false;
      break;
    default:
      okay = false;
      break;
    }
  }

  return okay;
}

int main()
{
  setbuf(stdout, NULL);
  if (!freopen("sample.txt", "r", stdin))
  {
    return 1;
  }

  int TC, MARK;

  scanf("%d %d", &TC, &MARK);
  for (int tc = 1; tc <= TC; ++tc)
  {
    int score = run() ? MARK : 0;
    printf("#%d %d\n", tc, score);
  }

  return 0;
}