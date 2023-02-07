//못품

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

int MAP[3][3];
int Crt[3][3] = {{1,2,3},{4,5,6,},{7,8,9}};
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};

bool correct(int r, int c,int num){
    if(Crt[r][c] == num) return true;
    return false;
}

int process(pair<int,int> pos){
    
    int count = 0;

    queue<pair<int,int>> q;

    q.push(pos);

    while(!q.empty()){
        
        int row = q.front().first;
        int col = q.front().second;
        q.pop();


    }

    return count;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    pair<int,int> pos;

    //init
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 0) pos = {i,j};
        }
    }

}