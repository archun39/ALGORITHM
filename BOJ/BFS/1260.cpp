#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
#define MAX 1000 + 1
using namespace std;

int n, m, v;
vector<vector<int>> list(MAX);
bool visited[MAX];

void init(){
    for(int i = 0; i <= n; i++){
        visited[i] = 0;
    }
}
void input(){
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++){
        int r, c;
        cin >> r >> c;
        list[r].push_back(c);
        list[c].push_back(r);
    }
}

void DFS(int num){
    
    cout << num << " ";
    visited[num] = true;

    for(int i = 0; i < list[num].size(); i++){
        int tmp = list[num][i];
        if(visited[tmp]) continue;

        DFS(tmp);
    }
}

void BFS(){
    queue<int> q;
    vector<int> ans;

    q.push(v);
    visited[v] = true;
    ans.push_back(v);
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = 0; i < list[now].size(); i++){
            int tmp = list[now][i];
            if(visited[tmp]) continue;
            q.push(tmp);
            visited[tmp] = true;
            ans.push_back(tmp);
        }
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input();
    for(int i = 0; i < MAX; i++){
        sort(list[i].begin(), list[i].end());
    }
    DFS(v);
    cout << endl;

    init();

    BFS();
}