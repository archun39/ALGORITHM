#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,L,R;
int answer =0;

int map[50][50];
int unions[50][50];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int x, int y, int idx);
void printMap();

int main(){
    cin >> N >> L >> R;
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            cin >> map[row][col];
        }
    }

    while(true){
        for(int row=0; row<N; row++){
            for(int col=0; col<N; col++){
                unions[row][col] = -1;
            }
        }
        int idx = 0;
        for(int row=0; row<N; row++){
            for(int col=0; col<N; col++){
                if(unions[row][col] == -1){
                    bfs(row,col,idx);
                    idx++;
                }
            }
        }
        if(idx == N*N) break;
        answer++;
    }
    cout << answer << endl;
}

void bfs(int x, int y, int idx){
    vector<pair<int,int>> united;
    united.push_back({x,y});
    queue<pair<int,int>> q;
    q.push({x,y});

    unions[x][y] = idx;
    int totalPeople = map[x][y];
    int countNation = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<N && ny<N && unions[nx][ny] == -1){
                int tmp = abs(map[nx][ny] - map[x][y]);
                if(tmp>=L && tmp <=R){
                    q.push({nx,ny});
                    unions[nx][ny] = idx;
                    totalPeople += map[nx][ny];
                    countNation += 1;
                    united.push_back({nx,ny});
                }

            }
        }
    }

    for(int i=0; i<united.size(); i++){
        int x = united[i].first;
        int y = united[i].second;
        map[x][y] = totalPeople/countNation;
    }
}

void printMap(){
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            cout << map[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}