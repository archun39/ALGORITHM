#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 20000 + 1
#define INF 10e8
using namespace std;

int n,m;
int startPos;

//w , v
vector<pair<int,int>> list[MAX];
int check[MAX];


void input(){
    cin >> n >> m >> startPos;
    for(int i = 0; i < m; i++){
        int u, v,w;
        cin >> u >> v >> w;
        list[u].push_back({w,v});
    }

    for(int i = 1; i <= n; i++) check[i] = INF;
}

void process(){
    priority_queue<pair<int,int>> pq;
    pq.push({0,startPos});
    check[startPos] = 0;

    while(!pq.empty()){
        int weight = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        for(int i = 0; i < list[now].size(); i++){
            int next = list[now][i].second;
            int nWeight = list[now][i].first;

            if(check[next] > weight + nWeight){
                check[next] = weight + nWeight;
                pq.push({-check[next],next});
            }
        }

    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    process();

    for(int i = 1; i <= n; i++){
        if(check[i] == INF) cout << "INF"<< endl;
        else cout<<check[i] <<endl;
    }
}