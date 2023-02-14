#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 500 + 1
using namespace std;

int n, m;
int map[MAX][MAX];
int DP[MAX][MAX];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void input(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            DP[i][j] = -1;
        }
    }
}
void printDP(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int DFS(int x, int y){
    if(x == n-1 && y == m-1) return 1;
    if(DP[x][y] != -1) return DP[x][y];

    DP[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;

        if(map[nx][ny] < map[x][y]){
            DP[x][y] += DFS(nx,ny);
            //printDP();
            
        }
    }
    return DP[x][y];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    cout << DFS(0,0);
}