#include <iostream>
#include <vector>
#define endl  '\n'
#define MAX 16 + 1
using namespace std;

struct pipe{
    int x;
    int y;
    int state;
};

int answer = 0;
int n;
int map[MAX][MAX];

//가로 = a, 세로 = b, 대각선 = c
int dx[3] = {0,1,1};
int dy[3] = {1,0,1};

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
}

bool checkWall(int nx, int ny, int i){
    if(i == 2){ //대각
        if(map[nx][ny] == 0 && map[nx-1][ny] == 0 && map[nx][ny-1] == 0) return true;
        return false;
    }
    else{
        if(map[nx][ny] == 0) return true;
    }
    return false;
}

void dfs(pipe p){
    if(p.x == n && p.y == n){
        answer++;
        return;
    }

    for(int i = 0; i < 3; i++){
        if((p.state == 0 && i == 1) || (p.state == 1 && i == 0)) continue;

        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        
        if(nx <= n && ny <= n){
            if(checkWall(nx,ny,i)){
                pipe tmp;
                tmp.x = nx;
                tmp.y = ny;
                tmp.state = i;
                //cout << nx << " : " << ny << " : " << i << endl;
                dfs(tmp);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    pipe p;
    p.x = 1;
    p.y = 2;
    p.state = 0;
    dfs(p);

    cout << answer << endl;
    return 0;
}