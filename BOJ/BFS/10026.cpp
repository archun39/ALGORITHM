#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
#define m 100
using namespace std;

char map[m][m];
bool visited[m][m];

int n;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};

void process(int r, int c){

    queue<pair<int,int>> q;

    q.push({r,c});
    
    char color;
    visited[r][c] = true;
    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;

        color = map[x][y];
        
        q.pop();

        //4방향탐색
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(visited[nx][ny]) continue;
                char nextColor = map[nx][ny];
                if(nextColor == color){
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }

    q = queue<pair<int,int>> ();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    pair<int,int> answer;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]) {
                process(i,j);
                answer.first += 1;
            }
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 'R') map[i][j] = 'G';
            visited[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]) {
                process(i,j);
                answer.second += 1;
            }
        }
    }
    cout << answer.first << " " << answer.second << endl;

    return 0;
}