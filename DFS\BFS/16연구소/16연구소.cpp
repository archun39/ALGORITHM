#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int map[8][8];
int tmp[8][8];
//상 하 좌 우
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int result = 0;
int wall = 0;

void virus(int x,int y);
int score();
void dfs(int score);

int main(){
    cin >> n >> m ;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
    dfs(result);
    cout <<result<<endl;

}

void virus(int x, int y){
    for(int i = 0; i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 00 && nx < n && ny < m){
            if(tmp[nx][ny] == 0 )
            {
                tmp[nx][ny] = 2;
                virus(nx,ny);
            }
        }
    }
}

int score(){
    int score =0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(tmp[i][j] == 0) {
                score += 1;
            }
        }
    }
    result = max(score,result);

    return result;
}

void dfs(int wall){
    
    if(wall == 3){
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                tmp[i][j] = map[i][j];
            }
        }
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(tmp[i][j] == 2){
                    virus(i,j);
                }
            }
        }
        score();
    }
    else {
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(map[i][j] == 0){
                    map[i][j] = 1;
                    wall++;
                    dfs(wall);
                    map[i][j] = 0;
                    wall --;
                }
            }
        }
    }
    
}