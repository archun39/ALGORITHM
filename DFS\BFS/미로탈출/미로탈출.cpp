#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int n,m;
int graph[200][200];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int bfs(int x, int y);

int main()
{
    cin >> n >> m ;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            scanf("%1d",&graph[i][j]);
        }
    }
    cout << bfs(0,0) << endl;
    return 0;
    

    
}

int bfs(int x, int y)
{
    queue<pair<int,int>> q;
    //큐의 맨 뒤에 추가
    q.push({x,y});

    while (!q.empty()){
        //선입 선출
        int x = q.front().first;
        int y = q.front().second;
        //큐의 맨 앞 원소 삭제
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx >=n || ny < 0||ny>=m) continue;
            if(graph[nx][ny] == 0) continue;
            if(graph[nx][ny] == 1) {
                graph[nx][ny] = graph[x][y] + 1;
                q.push({nx,ny});

            }
        }
    }
    return graph[n-1][m-1];
}