#include <vector>
#include <unordered_map>
#include <queue>

const int MAX_USER = 500;
const int MAX_CHANNEL = 500;
const int MAX_NEWS = 30000;

class News
{
public:
  int mTime;
  int mNewsId;
  int mChannelId;
  bool mIsCancled;

  News(int newsId, int channelId, int time) : mTime(time), mNewsId(newsId), mChannelId(channelId), mIsCancled(false) {}
};

News newsPool[MAX_NEWS];
int newsPoolIndex;

std::unordered_map<int, int> userIdMap;
std::unordered_map<int, int> channelIdMap;
std::unordered_map<int, int> newsIdMap;
int userIndex;
int channelIndex;
int newsIndex;

std::vector<int> channelInfo[MAX_CHANNEL + 1];
std::vector<News *> userInfo[MAX_USER + 1];

News *newsList[MAX_NEWS + 1];

class MyComp
{
public:
  bool operator()(const News *a, const News *b)
  {
    if (a->mTime != b->mTime)
    {
      return (a->mTime > b->mTime);
    }
    return (a->mNewsId > b->mNewsId);
  }
};
std::priority_queue<News *, std::vector<News *>, MyComp> newsSendList;

void init(int N, int K)
{
  newsPoolIndex = 0;
  userIndex = 0;
  channelIndex = 0;
  newsIndex = 0;
  for (int i = 0; i < MAX_CHANNEL; ++i)
  {
    channelInfo[i].clear();
    userInfo[i].clear();
  }
  newsSendList = {};
  userIdMap.clear();
  channelIdMap.clear();
  newsIdMap.clear();
}

void sendNews(int time)
{
  while (!newsSendList.empty())
  {
    if (newsSendList.top()->mTime > time)
    {
      return;
    }
    News *curNews = newsSendList.top();
    newsSendList.pop();

    // 삭제 됬으면 안보냄
    if (curNews->mIsCancled)
    {
      continue;
    }

    // 알람 보내기
    std::vector<int> *curChannel = &channelInfo[curNews->mChannelId]; // 해당 뉴스를 구독하는 유저 리스트
    for (int i : *curChannel)
    {
      // 시간이 빠른 순으로 저장됨
      userInfo[i].push_back(curNews);
    }
  }
}

void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[])
{
  sendNews(mTime);

  if (userIdMap.count(mUID) == 0)
  {
    userIdMap[mUID] = userIndex;
    ++userIndex;
  }
  int curUserId = userIdMap[mUID];

  for (int i = 0; i < mNum; ++i)
  {
    if (channelIdMap.count(mChannelIDs[i]) == 0)
    {
      channelIdMap[mChannelIDs[i]] = channelIndex;
      ++channelIndex;
    }
    int curChannelId = channelIdMap[mChannelIDs[i]];
    channelInfo[curChannelId].push_back(curUserId);
  }
}

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID)
{
  return -1;
}

void cancelNews(int mTime, int mNewsID)
{
}

int checkUser(int mTime, int mUID, int mRetIDs[])
{
  return -1;
}