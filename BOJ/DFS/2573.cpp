#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'
#define MAX 300 + 1
using namespace std;

struct ice{
    int row;
    int col;
    int value;
};

bool isIce[MAX][MAX];
int map[MAX][MAX];
const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,1,-1,0};
int n, m;

vector<ice> info;

bool isSplit(){
    bool visited[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) visited[i][j] = false;
    }

    int cntIce = 0;
    //현재 얼음 수와 얼음에서 bfs로 탐지했을때 다르면 false 같으면 true
    int row, col;
    for(int i = 0; i < info.size(); i++){
        if(info[i].value != 0) {
            cntIce++;
            row = info[i].row;
            col = info[i].col;
        }
    }

    queue<pair<int,int>> q;

    q.push({row,col});
    visited[row][col] = true;

    int cnt = 1;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 && nr < n && nc >=0 && nc < m){
                if(map[nr][nc] == 0) continue;
                if(visited[nr][nc]) continue;
                q.push({nr,nc});
                visited[nr][nc] = true;
                cnt++;
            }
        }
    }
    
    return cntIce == cnt;

    
}

void afterYear(){  
    
    vector<int> decrease(info.size());
    vector<ice> newInfo;
    for(int i = 0; i < info.size(); i++){
        ice tmp = info[i];
        int cnt = 0;
        for(int j = 0; j < 4; j++){
            int nx = tmp.row + dx[j];
            int ny = tmp.col + dy[j];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(map[nx][ny] == 0 && !isIce[nx][ny]){
                    cnt++;
                }
            } 
        }
        decrease[i] = cnt;
    }
    for(int i = 0; i <info.size(); i++){
        info[i].value = max(0, info[i].value - decrease[i]);
        map[info[i].row][info[i].col] = info[i].value;
        if(info[i].value == 0) isIce[info[i].row][info[i].col] = false;
        else{
            ice tmp;
            tmp.row = info[i].row;
            tmp.col = info[i].col;
            tmp.value = info[i].value;
            newInfo.push_back(tmp);
        }
    }
    
    info = newInfo;
}

void printMap(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] != 0){
                ice tmp;
                tmp.row = i;
                tmp.col = j;
                tmp.value = map[i][j];
                info.push_back(tmp);
                isIce[i][j] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    input();
    
    int year = 0;
    while(true){
        
        afterYear();
        //printMap();
        year++;
        if(info.size() == 0 ){
            year = 0;
            //cout << "melt" << endl;
            break;
        }
        if(!isSplit()) {
            //cout << "split" << endl;
            break;
        }
        
    }
    cout << year << endl;


}