#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#define MAX 1001
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

using namespace std;

int graph[MAX][MAX];
int visited[MAX];
int N, M, V;

// visited 초기화

void reset()
{
	for (int i = 1; i <= N; i++) 
	{
		visited[i] = 0;
	}
}

void bfs(int v)
{
	queue<int> q;

	cout << v << " ";
	q.push(v);
	visited[v] = 1;
	while (!q.empty())
	{
		int vertex = q.front();
		q.pop();
		for (int w = 1; w <= N; w++)
		{
			if (graph[vertex][w] == 1 && visited[w] == 0)
			{
				q.push(w);
				visited[w] = 1;
				cout << w << " ";
			}
		}
	} 
	cout << endl;
}

void dfs(int v) 
{
	stack<int> s;	
	int cur = v;
	s.push(cur);
	visited[cur] = 1;
	cout << cur << " ";
	while (!s.empty())
	{
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 0 && graph[cur][i] == 1)
			{
				s.push(i);
				visited[i] = 1;
				cur = s.top();
				i = 1;
				cout << cur << " ";
			}
		}

		if (visited[cur] == 1)
		{
			s.pop();
			if (!s.empty())
				cur = s.top();
		}		
	}
	cout << endl;
}



int main()
{
	cin >> N >> M >> V;

	// 그래프 구성
	for (int i = 0; i < M; i++)
	{
		int vertex, edge;
		cin >> vertex >> edge;
		// 양방향 간선
		graph[vertex][edge] = 1;
		graph[edge][vertex] = 1;
	}

	dfs(V);
	reset();
	bfs(V);

	return 0;
}