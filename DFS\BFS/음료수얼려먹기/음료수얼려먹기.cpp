#include <stdio.h>
#include <iostream>
using namespace std;

int n,m;
int graph[1000][1000];

bool dfs(int x, int y);

int main()
{
    //n 과 m을 공백을 기준으로 받아오기
    cin >> n >> m; 
    //2차열 배열의 맵 정보 받기
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            scanf("%1d",&graph[i][j]);
        }
    }
    int result = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(dfs(i,j)){
                result++;
            }
        }
    }
    cout << result << endl;
}

bool dfs(int x, int y)
{
    if(x<=-1 || y<=-1 || x>=n || y>=m ){
        return false;
    }
    if(graph[x][y] == 0){
        graph[x][y] = 1;
        //상하좌우 재귀적으로 호출
        dfs(x - 1, y);
        dfs(x, y - 1);
        dfs(x + 1, y);
        dfs(x, y + 1);
        return true;
    }
    return false;
}