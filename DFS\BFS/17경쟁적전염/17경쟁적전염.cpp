#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n , k;
int map[201][201] = {0};
int s,x,y;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
queue<pair<int,int>> q;
vector<tuple<int,int,int>> v;

void spread(int x, int y);
void printmap();

int main(){
    cin >> n >> k;
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] != 0){
               v.emplace_back(make_tuple(map[i][j],i,j));
               
            }
        }
    }
    cin >> s >> x >> y;

    sort(v.begin(),v.end());
    for(int i =0;i<v.size();i++){
        int fx = get<1>(v[i]);
        int fy = get<2>(v[i]);
        q.push({fx,fy});
    }
    
    for(int time = 0;time <s;time++){
        
        int size = q.size();
        
        for(int i = 0;i<size; i++){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            spread(a,b);
            //printmap();
            
        }

        
    }

    for(int i = 0;i<q.size();i++){
        q.pop();
    }
    
    cout << map[x-1][y-1] <<endl;;
    return 0;
    
}



void spread(int x, int y){
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0&&ny>=0&&nx<n&&ny<n){
            if(map[nx][ny] == 0){
                map[nx][ny] = map[x][y];
                q.push({nx,ny});
            }
        }
    }
}

void printmap(){
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

