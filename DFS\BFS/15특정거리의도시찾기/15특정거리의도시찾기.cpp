#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m,k,x;
vector<int> road[300001];
vector<int> city(300001,-1);
int result[300001];

int idx = 0;

bool bfs(int x);


int main (){
    cin >> n >> m >> k >> x;
    int a;
    int b;
    
    for(int i = 0;i<m;i++){
        cin >> a >> b ;
        road[a].push_back(b);
    }
    city[x] = 0;
    if(bfs(x)){
        for(int i = 0;i<idx;i++){
            cout << result[i] << endl;
        }
    }
    else cout << -1 << endl;
    return 0;
}

bool bfs(int x){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int nownode = q.front();
        q.pop();
        
        for(int i = 0;i<road[nownode].size();i++){
            int nextnode = road[nownode][i];
            
            if(city[nextnode] == -1){
                city[nextnode] = city[nownode] + 1;
                q.push(nextnode);
            }
        }
    }
    bool check = false;
    for(int i = 1;i<n+1;i++){
        if(city[i] == k){
            result[idx++] = i;
            check = true;
        }
    }
    return check;
}