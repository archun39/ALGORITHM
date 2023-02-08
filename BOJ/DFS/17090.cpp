#include <iostream>
#include <vector>

#define endl '\n'
#define MAX 500 + 1
using namespace std;

char map[MAX][MAX];
bool DP[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

pair<int,int> act(char c){
    if(c == 'U') return {-1,0};
    else if(c == 'D') return {1,0};
    else if(c == 'L') return {0,-1};
    else if(c == 'R') return {0,1};

    return {0,0};
}


bool DFS(int x, int y){
    if(DP[x][y]) return true;
    if(visited[x][y]) return DP[x][y];
    visited[x][y] = true;
    pair<int,int> dPos = act(map[x][y]);

    int nx = dPos.first + x;
    int ny = dPos.second + y;
    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
        if(DFS(nx,ny)) {
            DP[x][y] = true;
            
        }
        else{
            DP[x][y] = false;
        }
    }
    else{
        DP[x][y] = true;
    }

    return DP[x][y];
}

void input(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input();

    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(DFS(i,j)) answer++;
            
        }
    }

   

    cout << answer << endl;

    return 0;
}