#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N; //3<= N <= 6
char map[6][6];
char tmp[6][6];
vector<pair<int,int>> t;
vector<pair<int,int>>s;
int wall = 0;
bool found  = true;


bool detect();
void dfs(int wall);


int main() {
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> map[i][j];
            tmp[i][j] = map[i][j];
            if(map[i][j] == 'T') t.push_back({i,j});
            
            if(map[i][j] == 'S') s.push_back({i,j});
        }
    }
    
    dfs(wall);
    
    if(!found) cout << "YES" << endl;
    else cout << "NO" << endl;
    
   
}

void dfs(int wall){
    if(wall == 3){
        
        if(!detect()) found = false;
    }
    else{
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(map[i][j] == 'X'){
                    map[i][j] = 'O';
                    wall++;
                    dfs(wall);
                    map[i][j] = 'X';
                    wall--;
                }
            }
        }
    }
}

bool detect(){
    
    for(int i=0; i<t.size(); i++){
        int teacherX = t[i].first;
        int teacherY = t[i].second;
        //오른쪽
        for(int right=teacherY; right<N; right++){
            if(map[teacherX][right] == 'O') break;
            if(map[teacherX][right] == 'S') return true;
        }
        //왼쪽
        for(int left=teacherY; left>=0; left--){
            if(map[teacherX][left] == 'O') break;
            if(map[teacherX][left] == 'S') return true;
        }
        //위쪽
        for(int top=teacherX; top<N; top++){
            if(map[top][teacherY] == 'O') break;
            if(map[top][teacherY] == 'S') return true;
        }
        //오른쪽
        for(int bot=teacherX; bot>=0; bot--){
            if(map[bot][teacherY] == 'O') break;
            if(map[bot][teacherY] == 'S') return true;
        }
    }

    return false;

}
