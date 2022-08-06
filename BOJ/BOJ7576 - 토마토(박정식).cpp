#define _CRT_SECURE_NO_WARNINGS
#define X first
#define Y second
#define MAX 1000+1

#include <iostream>
#include <queue>

using namespace std;

int visited[MAX][MAX];
int map[MAX][MAX];

// ��������
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

// M : ���α���, N : ���� ����
int N, M;
int result;
queue<pair<int, int>> q;

// �ʿ� ������ �丶�䰡 �ִ��� üũ
void check()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {           
            if (map[x][y] == 0)
            {
                // �������� --�� ���ֹǷ� 0���� �ʱ�ȭ�ؼ� ������ �丶�䰡 ������� -1�� ����
                result = 0;
                return;
            }
        }
    }
}

void bfs()
{    
    while (!q.empty())
    {
        // q�� ����ִ� �丶�並 ������ cur�� �Ҵ�
        pair<int, int> cur = q.front();
        q.pop();

        // �� �ʿ��� �ʹµ� ���� �ɸ� �ҿ���-1 ���� ���������Ƿ� q���� ���� �丶���� ���� ���Ͽ� �ִ밪 ���ϱ�  
        if (result < map[cur.X][cur.Y])
            result = map[cur.X][cur.Y];

        for (int dir = 0; dir < 4; dir++)
        {                  
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // �������� Ž���� ���߹��� ����ų� 
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            // �̹� �湮�� �ߴ����̰ų�, �ش������� ������ �丶�䰡 ������� �湮�� �ʿ䰡 �����Ƿ� �湮ó�� X
            if (visited[nx][ny] == 1 || map[nx][ny] != 0)
                continue;
            visited[nx][ny] = 1;
            // �湮�Ҷ����� �ͰԸ��� �丶�䰡 �����ִ°����� 1�� ������
            map[nx][ny] = map[cur.X][cur.Y] + 1;

            // �湮���������� ���� �丶�䰡 ���Ӱ� �������Ƿ� q�� �־��ֱ�
            q.push({ nx, ny });
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    scanf("%d %d", &M, &N);
    // M : ���α���, N : ���� ����
    // �� ���� �Է�
    for (int x = 0; x < N; x++) 
    {
        for (int y = 0; y < M; y++) 
        {
            scanf("%d", &map[x][y]);
            // �� ���� �Է��� �丶�䰡 ������� q�� �̸� �־�д�.
            if (map[x][y] == 1)
            {
                q.push({ x, y });
                // q�� �ִ� ������ �ݵ�� �湮�� �ҿ����̹Ƿ� �̸� �湮üũ
                visited[x][y] = 1;
            }
        }
    }

    bfs();
    check();

    result--;
    printf("%d", result);


    return 0;
}