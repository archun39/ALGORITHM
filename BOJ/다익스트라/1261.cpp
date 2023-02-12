#include <iostream>
#include <vector>
#include <queue>
#define MAX 100+1
#define INF 10e8
using namespace std;

int n,m;
int map[MAX][MAX];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
bool visited[MAX][MAX];
int check[MAX][MAX];

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            check[i][j] = INF;
        }
    }
    check[0][0] = 0;
}

void input(){
    cin >> m >> n;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            scanf("%1d", &map[r][c]);
        }
    }
}
void printcheck(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(check[i][j] == INF) cout << "*" << " ";
            else cout << check[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



void bfs(){

    queue<pair<int,int>> q;

    q.push({0,0});
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        //printcheck();
        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            int tmp = check[r][c];
            
            
            if(nr < n && nr >= 0 && nc < m && nc >= 0){

                if(map[nr][nc] == 1){
                    if(check[nr][nc] > check[r][c]+1){
                        check[nr][nc] = check[r][c] + 1;
                        q.push({nr,nc});
                    }
                }
                else{
                    if(check[nr][nc] > check[r][c]){
                        check[nr][nc] = check[r][c];
                        q.push({nr,nc});
                    }
                }
            }
        }

    }
}
int main(){
    
    input();
    init();
    bfs();

    cout << check[n-1][m-1];
}   