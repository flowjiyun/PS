// go to not visted node & print where i visit
#include <iostream>

using namespace std;

const int v = 4;
bool adj[v][v], vis[v];


void go(int from)
{
	vis[from] = 1;
	cout << from << '\n';
	for (int i = 0; i < v; ++i)
	{
		if (vis[i])
			continue;
		if (adj[from][i])
			go(i);
	}
	return;
}
int main(void)
{
	adj[0][1] = 1;
	adj[1][0] = 1;
	adj[1][2] = 1;
	adj[2][1] = 1;
	adj[2][3] = 1;
	adj[3][2] = 1;
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			if (adj[i][j] && vis[i] == 0)
				go(i);
		}
	}
}