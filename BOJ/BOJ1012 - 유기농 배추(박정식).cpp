#define _CRT_SECURE_NO_WARNINGS
#define X first
#define Y second
#define MAX 50+1

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int visited[MAX][MAX];
int map[MAX][MAX];


// T : 테스트 케이스 갯수, M : 배추밭의 가로 길이
// N : 배추밭의 세로 길이, K : 배추 갯수
int T, M, N, K;
// wormCnt : 배추흰지렁이
int wormCnt;
// 동서남북
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };


// 테스트 케이스마다 배추밭맵, 방문처리맵 초기화
void reset()
{
    wormCnt = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            map[x][y] = 0;
            visited[x][y] = 0;
        }
    }
}

void dfs_stack(int x, int y)
{
    stack<pair<int, int>> s;
    // 출발 지점 방문처리
    visited[x][y] = 1;
    s.push({ x,y });

    while (!s.empty())
    {
        pair<int, int> cur = s.top();
        s.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            // nx = nextX, ny = nextY             
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 동서남북 탐색중 배추밭을 벗어나거나 
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            // 이미 방문을 했던곳이거나, 해당지역에 배추가 없을경우 방문할 필요가 없으므로 방문처리 X
            if (visited[nx][ny] == 1 || map[nx][ny] != 1)
                continue;
            visited[nx][ny] = 1;
            s.push({nx, ny});
        }
    }
}

void bfs_queue(int x, int y)
{
    queue<pair<int, int>> q;
    // 출발 지점 방문처리
    visited[x][y] = 1;
    q.push({x,y});
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            // nx = nextX, ny = nextY             
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 동서남북 탐색중 배추밭을 벗어나거나 
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            // 이미 방문을 했던곳이거나, 해당지역에 배추가 없을경우 방문할 필요가 없으므로 방문처리 X
            if (visited[nx][ny] == 1 || map[nx][ny] != 1)
                continue;
            visited[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;    
    
    for (int t = 0; t < T; t++)
    {        
        cin >> M >> N >> K;
        reset();
        // 배추밭 데이터 입력
        for (int k = 0; k < K; k++)
        {
            int x, y;
            cin >> x >> y;
            // 입력 데이터와 맵 좌표를 맞추기위해 y x 바꿔주기
            // ex 1 1 0
            //    0 1 0
            //    0 0 0
            // (0,0), (0,1), (1,1)
            map[y][x] = 1;
        }
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < M; y++)
            {
                if (map[x][y] == 1 && visited[x][y] == 0)
                {
                    //dfs_stack(x,y);
                    bfs_queue(x,y);
                    // 탐색이 끝날떄마다 배추흰지렁이 한마리씩 늘려주기
                    wormCnt++;
                }
            }
        }
        cout << wormCnt << endl;
    }

    return 0;
}