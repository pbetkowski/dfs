#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, sum;
vector<vector<int>> graph;
char foo[5];


int dfs(int root, int parent)
{	
	if ((root + 1) == 4)
	{
		cout << "I have found   "<<foo[3]<<"  in " << (root + 1) << "  His parent is  " << (parent + 1) << endl;
		exit(0);
	}

	for (int child : graph[root])
	{
		if (child == parent)
		{
			continue;
		}

		dfs(child, root);
	}
	return 0;
}

int main()
{	
	cin >> n;
	sum = 5;
	graph = vector <vector<int>>(n, vector<int>());
	foo[0] = { 'A' };
	foo[1] = { 'B' };
	foo[2] = { 'C' };
	foo[3] = { 'D' };
	foo[4] = { 'E' };
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u>> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, -1);
}
