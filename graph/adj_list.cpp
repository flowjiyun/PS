#include <iostream>
#include <vector>

using namespace std;

const int v = 4;
vector<int> adj[v];

int main(void)
{
	adj[0].push_back(1);	
	adj[0].push_back(2);	
	adj[1].push_back(0);	
	adj[2].push_back(0);	
	adj[2].push_back(3);	
	adj[3].push_back(2);	

	for (int i = 0; i < v; ++i)
	{
		cout << i << ":: ";
		for (int j = 0; j < adj[i].size(); ++j)
			cout << adj[i][j];
		cout << '\n';
	}
	return (0);
}